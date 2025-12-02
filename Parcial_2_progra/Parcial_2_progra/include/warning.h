#pragma once

/**
 * @file Warning.hpp
 * @brief Definición de la clase Warning, un observador que emite alertas de stock bajo.
 */

#include "Header.h"      ///< @brief Cabeceras generales.
#include "ObserverUwU.h" ///< @brief Interfaz Observer que esta clase debe implementar.

 /**
  * @class Warning
  * @brief Observador concreto que vigila los niveles de stock de los productos.
  * Si la cantidad de un producto cae por debajo de un umbral definido, imprime una advertencia.
  */
class Warning : public ObserverUwU {
public:
  /**
   * @brief Destructor por defecto.
   */
  ~Warning() = default;

  /**
   * @brief Constructor que inicializa el sistema de alertas.
   * @param umbral El número mínimo de unidades. Si el stock baja de este número, se activa la alerta.
   */
  Warning(int umbral) : Unbral(umbral) {}

  /**
   * @brief Método de actualización llamado por el Sujeto (Inventa) cuando cambia un producto.
   * Verifica si la cantidad del producto es crítica.
   * @param producto Referencia constante al producto modificado.
   */
  void update(const Produ& producto) override {
    // Verifica si la cantidad actual es menor al límite establecido (Unbral)
    if (producto.getCantidad() < Unbral) {
      std::cout << "Warning: El producto " << producto.getName()
        << " con codigo " << producto.getCode()
        << " tiene una cantidad baja de " << producto.getCantidad() << " unidades." << "\n";
    }
  }

private:
  /** @brief Valor límite que define cuándo el stock se considera "bajo". */
  int Unbral;
};

		

