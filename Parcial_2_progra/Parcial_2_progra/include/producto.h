#pragma once
#include "Header.h"

/**
 * @class Producto
 * @brief Representa un producto con nombre, precio, cantidad y código.
 */
class Producto {
public:

  /**
   * @brief Constructor con parámetros.
   * @param nombre Nombre del producto.
   * @param precio Precio del producto.
   * @param cantidad Cantidad disponible del producto.
   * @param codigo Código identificador del producto.
   */
  Producto(std::string nombre, double precio, int cantidad, std::string codigo)
    : nombre(nombre), precio(precio), cantidad(cantidad), codigo(codigo) {
  }

  /**
   * @brief Constructor por defecto.
   */
  Producto() : nombre(""), precio(0.0), cantidad(0), codigo("") {}

  /**
   * @brief Obtiene el nombre del producto.
   * @return Nombre como std::string.
   */
  std::string getNombre() const {
    return nombre;
  }

  /**
   * @brief Obtiene el precio del producto.
   * @return Precio como double.
   */
  double getPrecio() const {
    return precio;
  }

  /**
   * @brief Obtiene la cantidad disponible del producto.
   * @return Cantidad como int.
   */
  int getCantidad() const {
    return cantidad;
  }

  /**
   * @brief Obtiene el código del producto.
   * @return Código como std::string.
   */
  std::string getCodigo() const {
    return codigo;
  }

  /**
   * @brief Establece una nueva cantidad para el producto.
   * @param nuevaCantidad Nueva cantidad a asignar.
   */
  void setCantidad(int nuevaCantidad) {
    cantidad = nuevaCantidad;
  }

  /**
   * @brief Establece un nuevo precio para el producto.
   * @param nuevoPrecio Nuevo precio a asignar.
   */
  void setPrecio(double nuevoPrecio) {
    precio = nuevoPrecio;
  }

private:
  std::string nombre;   /**< Nombre del producto */
  double precio;        /**< Precio del producto */
  int cantidad;         /**< Cantidad disponible */
  std::string codigo;   /**< Código identificador */
};