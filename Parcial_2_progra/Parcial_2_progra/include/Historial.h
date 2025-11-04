#pragma once

#include "Header.h"
#include "producto.h"

/**
 * @struct Transaccion
 * @brief Representa una operación realizada sobre un producto.
 *
 * Contiene información sobre el tipo de transacción, la cantidad involucrada,
 * el nombre del producto y su código.
 */
struct Transaccion {
  std::string tipo;   ///< Tipo de transacción (por ejemplo, "compra", "venta", "ajuste").
  int cantidad;       ///< Cantidad de unidades involucradas en la transacción.
  std::string nombre; ///< Nombre del producto.
  std::string codigo; ///< Código identificador del producto.
};

/**
 * @class historial
 * @brief Clase que registra y muestra el historial de transacciones realizadas sobre productos.
 */
class historial {
public:

  /**
   * @brief Agrega un nuevo registro de transacción al historial.
   * @param tipo Tipo de transacción.
   * @param cantidad Cantidad de unidades involucradas.
   * @param producto Producto sobre el cual se realiza la transacción.
   */
  void agreeRegistro(const std::string& tipo, int cantidad, const Producto& producto) {
    registros.push_back({ tipo, cantidad, producto.getNombre(), producto.getCodigo() });
  }

  /**
   * @brief Muestra en consola todos los registros del historial.
   */
  void mostrar() const {
    for (const auto& registro : registros) {
      std::cout << "Tipo: " << registro.tipo
        << ", Cantidad: " << registro.cantidad
        << ", Nombre: " << registro.nombre
        << ", Codigo: " << registro.codigo << "\n";
    }
  }

private:
  std::vector<Transaccion> registros; ///< Lista de transacciones registradas.
};