#pragma once
#include "produ.h"
#include "Header.h"
#include "pagoStrategia}.h"

class Ticket {
public:
  static Ticket& getInstance() {
    static Ticket instance;
    return instance;
  }

  void generarTicke(const Produ& producto, int cantidad, const Paguiño& metodoPago) {
    double total = producto.getPrec() * cantidad;
    std::cout << "----- TICKET DE COMPRA -----\n";
    std::cout << "Producto: " << producto.getName() << "\n";
    std::cout << "Codigo: " << producto.getCode() << "\n";
    std::cout << "Cantidad: " << cantidad << "\n";
    std::cout << "Precio unitario: " << producto.getPrec() << "\n";
    std::cout << "Total a pagar: " << total << "\n";
    std::cout << "Metodo de pago: " << metodoPago.nombre() << "\n";
    std::cout << "---------------------------\n";
  }

  void TicketGas(double litro, double precLitro, double total, const Paguiño& metodoPago) {
    std::cout << "----- TICKET DE COMPRA GASOLINA -----\n";
    std::cout << "Litros: " << litro << "\n";
    std::cout << "Precio por litro: " << precLitro << "\n";
    std::cout << "Total a pagar: " << total << "\n";
    std::cout << "Metodo de pago: " << metodoPago.nombre() << "\n";
    std::cout << "---------------------------\n";
  }

private:
  Ticket() = default;
};