#pragma once

/**
 * @file Histo.hpp
 * @brief Definición de la estructura Trans y la clase Histo, que actúa como observador
 * para registrar las transacciones y cambios de stock de los productos.
 */

#include "produ.h"      ///< @brief Incluye la definición de la clase Produ, el sujeto a observar.
#include "Header.h"     ///< @brief Incluye cabeceras adicionales (propósito genérico).
#include "ObserverUwU.h"///< @brief Incluye la interfaz abstracta Observer (ObserverUwU).

 /**
  * @struct Trans
  * @brief Estructura que almacena los datos de una única transacción o evento en el inventario.
  */
struct Trans {
  /** @brief Tipo de evento (ej. "venta", "reabastecimiento", "actualizacion"). */
  std::string tipe;
  /** @brief Cantidad de unidades involucradas o stock actual, dependiendo del tipo de evento. */
  int cantidad;
  /** @brief Nombre del producto involucrado. */
  std::string nombre;
  /** @brief Código de identificación único del producto. */
  std::string codigo;
};

/**
 * @class Histo
 * @brief Implementa la interfaz ObserverUwU para registrar el historial de cambios en el inventario.
 * Almacena cada evento como una estructura Trans.
 */
class Histo : public ObserverUwU {
public:
  /**
   * @brief Método de actualización llamado por el Sujeto (Produ o similar) cuando ocurre un cambio.
   * @param pruducto Referencia constante al objeto Produ que ha cambiado su estado.
   */
  void update(const Produ& pruducto) override {
    // Almacena una nueva transacción con el stock actual del producto.
    // Se asume que este 'update' es provocado por un cambio de cantidad.
    Registros.push_back({ "actualizacion", pruducto.getCantidad(), pruducto.getName(), pruducto.getCode() });
  }

  /**
   * @brief Muestra el historial completo de transacciones en la consola.
   */
  void Mostrar() const {
    for (const auto& R : Registros) {
      std::cout << "Tipo de transaccion: " << R.tipe
        << ", Nombre del producto: " << R.nombre
        << ", Codigo del producto: " << R.codigo
        << ", Cantidad: " << R.cantidad << "\n";
    }
  }
private:
  /** @brief Contenedor interno que almacena todas las estructuras de transacción registradas. */
  std::vector<Trans> Registros;
};