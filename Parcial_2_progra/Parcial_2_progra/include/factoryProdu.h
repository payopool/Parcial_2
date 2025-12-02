#pragma once

/**
 * @file factoryProdu.hpp
 * @brief Definición de la clase factoryProdu, que implementa el patrón Factory para crear objetos Produ a partir de datos serializados (JSON).
 */

#include "produ.h"  ///< @brief Incluye la definición de la clase Produ, el tipo de objeto que se va a crear.
#include "JASON13.h"///< @brief Incluye la definición de la clase JASON13, utilizada para parsear (analizar) los datos JSON.
#include "Header.h" ///< @brief Incluye cabeceras adicionales (propósito genérico).

 /**
  * @class factoryProdu
  * @brief Clase estática (Factory) responsable de construir objetos de tipo Produ
  * a partir de una estructura de datos JASON13.
  */
class factoryProdu {
public:
  /**
   * @brief Método estático que construye y retorna un objeto Produ.
   *
   * @param dato Objeto de la clase JASON13 que contiene los datos serializados (nombre, precio, cantidad, codigo).
   * @return Produ Un nuevo objeto Produ inicializado con los datos de entrada.
   * @throw std::runtime_error Si el objeto JASON13 no contiene todas las claves requeridas.
   */
  static Produ Crear(const JASON13& dato) {
    // Validamos que existan las llaves
    if (!dato.contains("nombre") || !dato.contains("precio") ||
      !dato.contains("cantidad") || !dato.contains("codigo")) {
      throw std::runtime_error("JSON incompleto: Faltan datos del producto");
    }

    // Extraemos los datos usando tu librería
    std::string nombre = dato.getString("nombre");
    double precio = dato.getDouble("precio");
    std::string codigo = dato.getString("codigo");
    int cantidad = dato.getInt("cantidad");

    // Retornamos el objeto construido
    // Se utiliza el constructor Produ(std::string n, double p, std::string c, int cant)
    return Produ(nombre, precio, codigo, cantidad);
  }
};