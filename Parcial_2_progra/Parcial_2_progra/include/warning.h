#pragma once
#include "Header.h"
#include "ObserverUwU.h"

class Warning : public ObserverUwU {
public:
  ~Warning() = default;
  Warning(int umbral) : Unbral(umbral) {}

  void update(const Produ& producto) override {
    // Corregido gaetCantidad -> getCantidad
    if (producto.getCantidad() < Unbral) {
      std::cout << "Warning: El producto " << producto.getName()
        << " con codigo " << producto.getCode()
        << " tiene una cantidad baja de " << producto.getCantidad() << " unidades." << "\n";
    }
  }

private:
  int Unbral;
};


		

