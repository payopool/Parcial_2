#pragma once

/**
 * @file FecadeSystem.hpp
 * @brief Definición de la clase FecadeSystem, que implementa el patrón Facade
 * para simplificar la interacción con subsistemas (Inventario, Tickets, Pagos).
 */

#include "inventory.h"      ///< @brief Subsistema de Inventario (Inventa).
#include "ServicioTicket.h" ///< @brief Subsistema para la gestión de tickets (Ticket).
#include "GasXD.h"          ///< @brief Definición de la clase de pago (Paguiño).

 /**
  * @class FecadeSystem
  * @brief Clase Facade que simplifica el proceso de "Comprar Producto",
  * coordinando operaciones entre el inventario, el generador de tickets y el método de pago.
  */
class FecadeSystem {
public:
  /**
   * @brief Procesa la compra de un producto, realizando la venta, obteniendo el producto y generando el ticket.
   *
   * @param inventario Referencia al objeto de Inventario (Inventa) para la gestión del stock.
   * @param code Código de identificación del producto a comprar.
   * @param cantidad Cantidad de unidades a comprar.
   * @param metodoPago Referencia al objeto que representa el método de pago utilizado (Paguiño).
   */
  void comprarpro(Inventa& inventario, const std::string& code, int cantidad, Paguiño& metodoPago) {
    // 1. Descuenta la cantidad del inventario
    inventario.sell(code, cantidad);

    // 2. Obtiene los detalles completos del producto vendido
    Produ producto = inventario.getProducto(code);

    // 3. Genera el ticket de compra usando una instancia única (Singleton)
    Ticket::getInstance().generarTicke(producto, cantidad, metodoPago);
  }
};