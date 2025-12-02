/**
 * @file main.cpp
 * @brief Archivo principal que orquesta la ejecución del sistema de gestión de la GasolineraXD.
 * Aquí se inicializan las clases, se registran los observadores y se implementa el bucle del menú.
 */

#include "Header.h"
#include "inventory.h"
#include "warning.h"
#include "Histo.h"
#include "pagoStrategia}.h" // Nombre corregido
#include "ServicioTicket.h"
#include "GasXD.h"
#include "FecadeSystem.h"
#include "JASON13.h"

 /**
  * @brief Función principal del programa.
  *
  * Inicializa los módulos del sistema (inventario, alertas, historial y fachada),
  * registra observadores y ejecuta el menú interactivo para gestionar productos
  * y operaciones de la gasolinera.
  *
  * @return int Código de salida del programa (0 si finaliza correctamente).
  */
int main() {
  Inventa inventario;      ///< Módulo de inventario de productos.
  Warning alerta(5);       ///< Observador que genera alertas cuando el stock es bajo.
  Histo historial;         ///< Observador que registra el historial de operaciones.

  inventario.registrarObservador(&alerta);
  inventario.registrarObservador(&historial);

  FecadeSystem sistema;    ///< Fachada que simplifica las operaciones de compra.

  /**
   * @brief Bucle principal del menú.
   *
   * Permite al usuario seleccionar entre distintas operaciones:
   * - Agregar producto
   * - Comprar producto
   * - Cargar gasolina
   * - Mostrar historial
   * - Eliminar producto
   * - Actualizar cantidad
   * - Salir
   */
  int ele;
  do {
    system("cls");
    std::cout << "\n--- Bienabenido a GasolineriaXD ---\n";
    std::cout << " 1. Agregar producto\n";
    std::cout << " 2. Comprar producto\n";
    std::cout << " 3. Cargar gasolina\n";
    std::cout << " 4. Mostrar historial\n";
    std::cout << " 5. Eliminar producto\n";
    std::cout << " 6. Actualizar cantidad producto\n";
    std::cout << " 7. Salir\n";
    std::cout << "Opcion: ";
    std::cin >> ele;

    switch (ele) {
      /**
       * @brief Caso 1: Agregar producto al inventario.
       * Solicita datos del producto (nombre, precio, código, cantidad) y lo registra.
       */
    case 1: {
      std::string nombre, code;
      double prec;
      int cantida;
      std::cout << "Ingrese el nombre del producto: ";
      std::cin >> nombre;
      std::cout << "Ingrese el precio del producto: ";
      std::cin >> prec;
      std::cout << "Ingrese el codigo del producto: ";
      std::cin >> code;
      std::cout << "Ingrese la cantidad del producto: ";
      std::cin >> cantida;

      JASON13 dato;
      dato.set("nombre", nombre);
      dato.set("precio", prec);
      dato.set("codigo", code);
      dato.set("cantidad", cantida);

      inventario.agregarProducto(dato);
      std::cout << "Producto agregado con exito.\n";
      break;
    }
          /**
           * @brief Caso 2: Comprar producto.
           * Permite seleccionar un producto por código, cantidad y método de pago.
           */
    case 2: {
      std::string code;
      int cantidad, metodo;
      std::cout << "Ingrese el codigo del producto a comprar: ";
      std::cin >> code;
      std::cout << "Ingrese la cantidad a comprar: ";
      std::cin >> cantidad;
      std::cout << "Seleccione el metodo de pago (1. Efectivo, 2. Credito): ";
      std::cin >> metodo;

      efectivo pagoEfectivo;
      digital pagoDigital;

      if (metodo == 1) {
        sistema.comprarpro(inventario, code, cantidad, pagoEfectivo);
      }
      else {
        sistema.comprarpro(inventario, code, cantidad, pagoDigital);
      }
      break;
    }
          /**
           * @brief Caso 3: Cargar gasolina.
           * Solicita litros, precio por litro, método de pago y si se paga después.
           */
    case 3: {
      double litros, preciolitros;
      int metodo, pagaAfterInt;
      bool pagaAfter;
      std::cout << "Ingrese la cantidad de litros a cargar: ";
      std::cin >> litros;
      std::cout << "Ingrese el precio por litro: ";
      std::cin >> preciolitros;
      std::cout << "Seleccione el metodo de pago (1. Efectivo, 2. Credito): ";
      std::cin >> metodo;
      std::cout << "Pagar despues de cargar? (1. Si, 0. No): ";
      std::cin >> pagaAfterInt;

      pagaAfter = (pagaAfterInt == 1);
      efectivo pagoEfectivo;
      digital pagoDigital;
      GasXD gasolinera;

      if (metodo == 1) {
        gasolinera.cargarGas(litros, preciolitros, pagoEfectivo, pagaAfter);
      }
      else {
        gasolinera.cargarGas(litros, preciolitros, pagoDigital, pagaAfter);
      }
      break;
    }
          /**
           * @brief Caso 4: Mostrar historial de operaciones.
           */
    case 4: {
      historial.Mostrar();
      break;
    }
          /**
           * @brief Caso 5: Eliminar producto del inventario.
           * Solicita el código y elimina el producto correspondiente.
           */
    case 5: {
      std::string code;
      std::cout << "codigo a eliminar: ";
      std::cin >> code;
      inventario.eliminarProducto(code);
      std::cout << "Producto eliminado.\n";
      break;
    }
          /**
           * @brief Caso 6: Actualizar cantidad de un producto.
           * Solicita código y nueva cantidad para actualizar el inventario.
           */
    case 6: {
      std::string code;
      int cantidad;
      std::cout << "codigo: ";
      std::cin >> code;
      std::cout << "Nueva cantidad: ";
      std::cin >> cantidad;
      inventario.actualizarCan(code, cantidad);
      break;
    }
    }
    system("pause");
  } while (ele != 7);
  return 0;
};
