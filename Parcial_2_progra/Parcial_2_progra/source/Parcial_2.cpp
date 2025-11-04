#include "Header.h"
#include "Inventario.h"
#include "AlertaStockDown.h"
#include "Historial.h"
#include <nlohmann/json.hpp>

/**
 * @brief Función principal del programa.
 *
 * Crea un inventario de productos, registra un observador de alerta por bajo stock,
 * realiza operaciones como agregar, vender, actualizar y eliminar productos, y registra
 * dichas acciones en un historial de transacciones.
 *
 * @return int Código de salida del programa (0 si finaliza correctamente).
 */
int main() {
  Inventario inventario;
  historial historialTransacciones;
  AlertaSatockDown alertaBaja(5);
  inventario.registrarObservador(&alertaBaja);

  nlohmann::json producto1 = {
      {"nombre", "Gansito"},
      {"precio", 12.5},
      {"cantidad", 20},
      {"codigo", "A001"}
  };

  nlohmann::json producto2 = {
      {"nombre", "Mantecadas"},
      {"precio", 28},
      {"cantidad", 3},
      {"codigo", "B002"}
  };

  nlohmann::json producto3 = {
      {"nombre", "Fanta 3L"},
      {"precio", 32},
      {"cantidad", 5},
      {"codigo", "C003"}
  };

  // Agrega productos al inventario
  inventario.agregarProducto(producto1);
  inventario.agregarProducto(producto2);
  inventario.agregarProducto(producto3);

  // Realiza una venta y registra la transacción
  inventario.venderProducto("A001", 5);
  historialTransacciones.agreeRegistro("Venta", 5, Producto("Gansito", 12.5, 15, "A001"));

  // Actualiza la cantidad de un producto y registra la acción
  inventario.actualizarCantidad("B002", 2);
  historialTransacciones.agreeRegistro("Actualizacion", 1, Producto("Mantecadas", 28, 3, "B002"));

  // Otra venta
  inventario.venderProducto("A001", 1);

  // Elimina un producto y registra la eliminación
  inventario.eliminarProducto("C003");
  historialTransacciones.agreeRegistro("Eliminacion", 0, Producto("Fanta 3L", 32, 0, "C003"));

  // Notifica a los observadores sobre un cambio manual
  inventario.notificarCambios("C003");

  // Muestra el historial de transacciones
  historialTransacciones.mostrar();

  return 0;
}
