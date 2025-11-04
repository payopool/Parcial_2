#pragma once

#include "producto.h"
#include <nlohmann/json.hpp>

/**
 * @class productofactory
 * @brief Clase encargada de crear instancias de Producto a partir de datos JSON.
 */
class productofactory {
public:

  /**
   * @brief Crea un objeto Producto a partir de un objeto JSON.
   *
   * El JSON debe contener las claves: "nombre", "precio", "cantidad" y "codigo".
   *
   * @param data Objeto JSON con los datos del producto.
   * @return Producto creado con los datos proporcionados.
   */
  static Producto Crear(const nlohmann::json& data) {
    return Producto(
      data["nombre"],
      data["precio"],
      data["cantidad"],
      data["codigo"]
    );
  }

};