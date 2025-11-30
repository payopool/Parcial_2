#include "Header.h"
#include "inventory.h"
#include "warning.h"
#include "Histo.h"
#include "pagoStrategia}.h" // Nombre corregido
#include "ServicioTicket.h"
#include "GasXD.h"
#include "FecadeSystem.h"
#include "JASON13.h"

int main() {
  Inventa inventario;
  Warning alerta(5);
  Histo historial;

  inventario.registrarObservador(&alerta);
  inventario.registrarObservador(&historial);

  FecadeSystem sistema;

  // Ejemplo inicial (Opcional, si quieres iniciar con un producto default)
  // inventario.agregarProducto(JASON13::guardarProducto(Produ("Gasolina Magna", 22.5, "MAG01", 100)));

  int ele;
  do {
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

      // Solo una llamada es necesaria
      inventario.agregarProducto(dato);
      std::cout << "Producto agregado con exito.\n";
      break;
    }
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
    case 4: {
      historial.Mostrar();
      break;
    }
    case 5: {
      std::string code;
      std::cout << "codigo a eliminar: ";
      std::cin >> code;
      inventario.eliminarProducto(code);
      std::cout << "Producto eliminado.\n";
      break;
    }
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

  } while (ele != 7);
  return 0;
};

