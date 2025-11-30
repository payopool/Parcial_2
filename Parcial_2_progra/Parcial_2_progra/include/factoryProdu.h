#pragma once
#include "produ.h"
#include "JASON13.h"
#include"Header.h"

class factoryProdu {
public:
  // Cambié MiniJson por JASON13
  static Produ Crear(const JASON13& dato) {
    // Validamos que existan las llaves
    if (!dato.contains("nombre") || !dato.contains("precio") ||
      !dato.contains("cantidad") || !dato.contains("codigo")) {
      throw std::runtime_error("JSON incompleto: Faltan datos del producto");
    }

    // Extraemos los datos usando tu librería
    std::string nombre = dato.getString("nombre");
    double precio = dato.getDouble("precio");
    std::string codigo = dato.getString("codigo");
    int cantidad = dato.getInt("cantidad");

    // Retornamos el objeto construido
    return Produ(nombre, precio, codigo, cantidad);
  }
};