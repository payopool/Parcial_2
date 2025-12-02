#pragma once

/**
 * @file JASON13.hpp
 * @brief Definición de la clase JASON13, una utilidad simple para almacenar y recuperar datos
 * en formato clave-valor, similar a JSON, utilizando strings como almacenamiento base.
 */
#include "Header.h" ///< @brief Incluye cabeceras adicionales (propósito genérico).
#include "produ.h"  ///< @brief Incluye la definición de la clase Produ, utilizada para el método 'guardarProducto'.

 /**
  * @class JASON13
  * @brief Implementación simplificada para la serialización y deserialización de datos.
  * Utiliza un mapa de strings para almacenar todos los valores internamente.
  */
class JASON13 {
public:
  // -----------------------------------------------------------------
  // Setters (Serialización)
  // -----------------------------------------------------------------

  /**
   * @brief Almacena un valor de tipo string asociado a una clave.
   * @param key La clave (nombre del campo).
   * @param value El valor de tipo string.
   */
  void set(const std::string& key, const std::string& value) { data[key] = value; }

  /**
   * @brief Almacena un valor de tipo double, convirtiéndolo a string.
   * @param key La clave.
   * @param value El valor de tipo double.
   */
  void set(const std::string& key, double value) { data[key] = std::to_string(value); }

  /**
   * @brief Almacena un valor de tipo int, convirtiéndolo a string.
   * @param key La clave.
   * @param value El valor de tipo int.
   */
  void set(const std::string& key, int value) { data[key] = std::to_string(value); }

  // -----------------------------------------------------------------
  // Getters (Deserialización)
  // -----------------------------------------------------------------

  /**
   * @brief Recupera un valor como string.
   * @param key La clave del dato.
   * @param def Valor por defecto a retornar si la clave no existe.
   * @return std::string El valor asociado o el valor por defecto.
   */
  std::string getString(const std::string& key, const std::string& def = "") const {
    auto it = data.find(key);
    return it != data.end() ? it->second : def;
  }

  /**
   * @brief Recupera un valor y lo convierte a double.
   * Intenta convertir el string almacenado a un double.
   * @param key La clave del dato.
   * @param def Valor por defecto a retornar si la clave no existe o la conversión falla.
   * @return double El valor convertido o el valor por defecto.
   */
  double getDouble(const std::string& key, double def = 0.0) const {
    auto it = data.find(key);
    if (it != data.end()) {
      try { return std::stod(it->second); }
      catch (...) { return def; }
    }
    return def;
  }

  /**
   * @brief Recupera un valor y lo convierte a int.
   * Intenta convertir el string almacenado a un int.
   * @param key La clave del dato.
   * @param def Valor por defecto a retornar si la clave no existe o la conversión falla.
   * @return int El valor convertido o el valor por defecto.
   */
  int getInt(const std::string& key, int def = 0) const {
    auto it = data.find(key);
    if (it != data.end()) {
      try { return std::stoi(it->second); }
      catch (...) { return def; }
    }
    return def;
  }

  /**
   * @brief Verifica si una clave existe en el mapa de datos.
   * @param key La clave a buscar.
   * @return bool Verdadero si la clave está presente, falso en caso contrario.
   */
  bool contains(const std::string& key) const {
    return data.find(key) != data.end();
  }

  // -----------------------------------------------------------------
  // Método Estático de Serialización
  // -----------------------------------------------------------------

  /**
   * @brief Serializa un objeto Produ en un objeto JASON13.
   * @param p La referencia constante al objeto Produ a serializar.
   * @return JASON13 Un nuevo objeto JASON13 con los datos del producto.
   */
  static JASON13 guardarProducto(const Produ& p) {
    JASON13 j;
    j.set("nombre", p.getName());
    j.set("precio", p.getPrec());
    j.set("codigo", p.getCode());
    j.set("cantidad", p.getCantidad());
    return j;
  }

private:
  /** @brief El contenedor interno que almacena todas las claves y valores como strings. */
  std::unordered_map<std::string, std::string> data;
};