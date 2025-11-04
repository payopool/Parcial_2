#pragma once

#include "Observator.h"
#include "Header.h"

/**
 * @class AlertaSatockDown
 * @brief Observador que genera una alerta cuando el stock de un producto cae por debajo de un umbral.
 *
 * Esta clase implementa la interfaz Observator y se activa cuando la cantidad de un producto
 * es menor al valor definido como umbral. Imprime una alerta en consola.
 */
class AlertaSatockDown : public Observator {
public:

  /**
   * @brief Constructor que establece el umbral de alerta.
   * @param umbral Valor mínimo de cantidad para activar la alerta.
   */
  AlertaSatockDown(int umbral) : umbral(umbral) {}

  /**
   * @brief Método que se llama cuando un producto se actualiza.
   *
   * Si la cantidad del producto es menor al umbral, se imprime una alerta.
   * @param producto Referencia constante al producto actualizado.
   */
  void actualizar(const Producto& producto) override {
    if (producto.getCantidad() < umbral) {
      std::cout << "Alerta: El producto " << producto.getNombre()
        << " con codigo " << producto.getCodigo()
        << " tiene un stock bajo: " << producto.getCantidad() << " unidades.\n";
    }
  }

private:
  int umbral; ///< Umbral mínimo de cantidad para activar la alerta.
};