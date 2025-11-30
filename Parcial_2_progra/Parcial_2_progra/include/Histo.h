#pragma once
#include "produ.h"
#include "Header.h"
#include "ObserverUwU.h"

struct Trans {
  std::string tipe;
  int cantidad;
  std::string nombre;
  std::string codigo;
};

class Histo : public ObserverUwU {
public:
  void update(const Produ& pruducto) override {
    // Corregido gaetCantidad -> getCantidad
    Registros.push_back({ "actualizacion", pruducto.getCantidad(), pruducto.getName(), pruducto.getCode() });
  }
  void Mostrar() const {
    for (const auto& R : Registros) {
      std::cout << "Tipo de transaccion: " << R.tipe
        << ", Nombre del producto: " << R.nombre
        << ", Codigo del producto: " << R.codigo
        << ", Cantidad: " << R.cantidad << "\n";
    }
  }
private:
  std::vector<Trans> Registros;
};