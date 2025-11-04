#pragma once

#include "producto.h"
#include "Observator.h"
#include "Header.h"
#include "FactoryProducto.h"
#include <nlohmann/json.hpp>

/**
 * @class Inventario
 * @brief Gestiona una colección de productos y notifica a los observadores sobre cambios relevantes.
 *
 * Esta clase permite agregar, eliminar, actualizar y vender productos. Utiliza el patrón Observer
 * para notificar a los observadores registrados cuando ocurre una modificación en los productos.
 */
class Inventario {
public:

  /**
   * @brief Agrega un nuevo producto al inventario a partir de datos JSON.
   *
   * También notifica a todos los observadores registrados sobre el nuevo producto.
   * @param data Objeto JSON con los datos del producto.
   */
  void agregarProducto(const nlohmann::json& data) {
    Producto producto = productofactory::Crear(data);
    productos[producto.getCodigo()] = producto;
    for (auto& observador : observadores) {
      observador->actualizar(producto);
    }
  }

  /**
   * @brief Elimina un producto del inventario según su código.
   * @param codigo Código del producto a eliminar.
   */
  void eliminarProducto(const std::string& codigo) {
    productos.erase(codigo);
  }

  /**
   * @brief Actualiza la cantidad de un producto específico.
   *
   * Si el producto existe, se actualiza su cantidad y se notifica a los observadores.
   * @param codigo Código del producto.
   * @param nuevaCantidad Nueva cantidad a asignar.
   */
  void actualizarCantidad(const std::string& codigo, int nuevaCantidad) {
    if (productos.find(codigo) != productos.end()) {
      productos[codigo].setCantidad(nuevaCantidad);
      for (auto& observador : observadores) {
        observador->actualizar(productos[codigo]);
      }
    }
  }

  /**
   * @brief Registra un nuevo observador para recibir notificaciones de cambios.
   * @param observador Puntero al objeto observador.
   */
  void registrarObservador(Observator* observador) {
    observadores.push_back(observador);
  }

  /**
   * @brief Realiza una venta de un producto, reduciendo su cantidad.
   *
   * Si hay suficiente stock, se descuenta la cantidad vendida y se notifica a los observadores.
   * @param codigo Código del producto.
   * @param cantidad Cantidad a vender.
   */
  void venderProducto(const std::string& codigo, int cantidad) {
    if (productos.find(codigo) != productos.end()) {
      int cantidadActual = productos[codigo].getCantidad();
      if (cantidadActual >= cantidad) {
        productos[codigo].setCantidad(cantidadActual - cantidad);
        for (auto& observador : observadores) {
          observador->actualizar(productos[codigo]);
        }
      }
    }
  }

  /**
   * @brief Notifica manualmente a los observadores sobre un cambio en un producto.
   * @param codigo Código del producto que ha cambiado.
   */
  void notificarCambios(const std::string& codigo) {
    if (productos.find(codigo) != productos.end()) {
      for (auto& observador : observadores) {
        observador->actualizar(productos[codigo]);
      }
    }
  }

private:
  std::unordered_map<std::string, Producto> productos; ///< Mapa de productos indexados por su código.
  std::vector<Observator*> observadores;               ///< Lista de observadores registrados.
};