#pragma once
#include "Header.h"

class Paguiño {
public:
  virtual ~Paguiño() = default;
  virtual bool proces(double monto) = 0;
  virtual std::string nombre() const = 0;
};

class efectivo : public Paguiño {
public:
  bool proces(double monto) override {
    std::cout << "Pago en efectivo procesado por un monto de: " << monto << "\n";
    return true;
  }
  std::string nombre() const override {
    return "Efectivo";
  }
};

class digital : public Paguiño {
public:
  bool proces(double monto) override {
    std::cout << "Pago credito procesado por un monto de: " << monto << "\n";
    return true;
  }
  std::string nombre() const override {
    return "Credito";
  }
};