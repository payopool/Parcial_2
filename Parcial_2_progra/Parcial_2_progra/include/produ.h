#pragma once
#include <string>

class Produ {
public:
  // Constructor por defecto
  Produ() : nombre(""), codigo(""), precio(0.0), cantidad(0) {}

  // Constructor con parámetros
  Produ(std::string n, double p, std::string c, int cant)
    : nombre(n), precio(p), codigo(c), cantidad(cant) {
  }

  // Getters
  std::string getName() const { return nombre; }
  std::string getCode() const { return codigo; }
  double getPrec() const { return precio; }
  int getCantidad() const { return cantidad; } // Corregido de gaetCantidad

  // Setters
  void setCantidad(int c) { cantidad = c; }
  void setPrecio(double p) { precio = p; }

private:
  std::string nombre;
  std::string codigo;
  double precio;
  int cantidad;
};