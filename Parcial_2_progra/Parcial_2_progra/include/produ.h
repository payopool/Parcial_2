#pragma once

/**
 * @file Produ.hpp
 * @brief Definición de la clase Produ, que representa un producto en el sistema de inventario.
 */

 /**
  * @class Produ
  * @brief Contenedor de datos para un producto, incluyendo nombre, código, precio y cantidad en stock.
  */
class Produ {
public:
  /**
   * @brief Constructor por defecto (sin parámetros).
   * Inicializa el producto con valores predeterminados seguros.
   */
  Produ() : nombre(""), codigo(""), precio(0.0), cantidad(0) {}

  /**
   * @brief Constructor con todos los parámetros de inicialización.
   * @param n Nombre del producto.
   * @param p Precio unitario del producto.
   * @param c Código único de identificación del producto (ej. SKU o código de barras).
   * @param cant Cantidad inicial de unidades en stock.
   */
  Produ(std::string n, double p, std::string c, int cant)
    : nombre(n), precio(p), codigo(c), cantidad(cant) {
  }

  // -----------------------------------------------------------------
  // Getters (Métodos de Acceso)
  // -----------------------------------------------------------------

  /**
   * @brief Obtiene el nombre del producto.
   * @return std::string El nombre del producto.
   */
  std::string getName() const { return nombre; }

  /**
   * @brief Obtiene el código de identificación del producto.
   * @return std::string El código del producto.
   */
  std::string getCode() const { return codigo; }

  /**
   * @brief Obtiene el precio unitario del producto.
   * @return double El precio del producto.
   */
  double getPrec() const { return precio; }

  /**
   * @brief Obtiene la cantidad de unidades en stock del producto.
   * @return int La cantidad de unidades.
   */
  int getCantidad() const { return cantidad; } // Corregido de gaetCantidad

  // -----------------------------------------------------------------
  // Setters (Métodos de Modificación)
  // -----------------------------------------------------------------

  /**
   * @brief Establece la nueva cantidad de unidades en stock.
   * @param c Nueva cantidad de stock.
   */
  void setCantidad(int c) { cantidad = c; }

  /**
   * @brief Establece un nuevo precio unitario para el producto.
   * @param p Nuevo precio.
   */
  void setPrecio(double p) { precio = p; }

private:
  /** @brief Nombre descriptivo del producto. */
  std::string nombre;
  /** @brief Código único de identificación (SKU, código de barras). */
  std::string codigo;
  /** @brief Precio de venta unitario. */
  double precio;
  /** @brief Cantidad de unidades disponibles en inventario. */
  int cantidad;
};