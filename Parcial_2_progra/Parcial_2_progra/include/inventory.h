#pragma once

/**
 * @file Inventa.hpp
 * @brief Definición de la clase Inventa, el gestor principal del inventario.
 * Implementa el patrón Sujeto (Subject) para notificar a los observadores sobre cambios.
 */

#include "produ.h"        ///< @brief Clase Producto.
#include "ObserverUwU.h"  ///< @brief Interfaz Observer.
#include "factoryProdu.h" ///< @brief Fábrica para crear objetos Produ.
#include "JASON13.h"      ///< @brief Clase para parsear datos (JSON).
#include "Header.h"       ///< @brief Cabeceras adicionales.

 /**
  * @class Inventa
  * @brief Clase que maneja la colección de productos, las operaciones de stock, y actúa como
  * el Sujeto central que notifica a los observadores (como el historial) sobre cualquier cambio.
  */
class Inventa {
public:
  /**
   * @brief Agrega un nuevo producto al inventario.
   * Utiliza factoryProdu para crear el objeto a partir de datos serializados.
   * Notifica a todos los observadores sobre la adición.
   * @param dato Objeto JASON13 que contiene los datos del nuevo producto.
   */
  void agregarProducto(const JASON13& dato) {
    // Crea el objeto Produ usando la Fábrica
    Produ nuevoProducto = factoryProdu::Crear(dato);
    // Almacena el producto en el mapa, usando su código como clave
    productos[nuevoProducto.getCode()] = nuevoProducto;

    // Notificar observadores: el objeto ha sido añadido
    for (auto& obs : observadores) {
      obs->update(nuevoProducto);
    }
  }

  /**
   * @brief Elimina un producto del inventario usando su código.
   * @param code Código del producto a eliminar.
   */
  void eliminarProducto(const std::string& code) {
    productos.erase(code);
    
  }

  /**
   * @brief Registra un observador para que sea notificado de futuros cambios.
   * @param obs Puntero a la instancia del observador (ObserverUwU).
   */
  void registrarObservador(ObserverUwU* obs) {
    observadores.push_back(obs);
  }

  /**
   * @brief Actualiza directamente la cantidad en stock de un producto.
   * Notifica a los observadores si el producto existe.
   * @param code Código del producto a actualizar.
   * @param nuevaCantidad Nuevo valor de stock.
   */
  void actualizarCan(const std::string& code, int nuevaCantidad) {
    if (productos.find(code) != productos.end()) {
      // Actualiza la cantidad
      productos[code].setCantidad(nuevaCantidad);
      // Notifica el cambio de estado
      for (auto& obs : observadores) {
        obs->update(productos[code]);
      }
    }
  }

  /**
   * @brief Procesa la venta de una cantidad de un producto.
   * Disminuye la cantidad en stock y notifica a los observadores.
   * @param code Código del producto vendido.
   * @param cantidadVendida Cantidad de unidades a descontar del stock.
   */
  void sell(const std::string& code, int cantidadVendida) {
    if (productos.find(code) != productos.end()) {
      // Calcula la nueva cantidad
      int nuevaCantidad = productos[code].getCantidad() - cantidadVendida;
      // Actualiza la cantidad
      productos[code].setCantidad(nuevaCantidad);
      // Notifica el cambio de estado (venta)
      for (auto& obs : observadores) {
        obs->update(productos[code]);
      }
    }
  }

  /**
   * @brief Obtiene el objeto Producto usando su código.
   * @param code Código del producto a buscar.
   * @return Produ El objeto Producto si se encuentra; un objeto Produ vacío si no existe.
   */
  Produ getProducto(const std::string& code) {
    if (productos.find(code) != productos.end()) {
      return productos[code];
    }
    return Produ(); // Retorna vacío si no existe
  }

private:
  /** @brief Contenedor principal de productos. Usa el código como clave para búsquedas rápidas. */
  std::unordered_map<std::string, Produ> productos;
  /** @brief Lista de punteros a objetos observadores que serán notificados de los cambios. */
  std::vector<ObserverUwU*> observadores;
};