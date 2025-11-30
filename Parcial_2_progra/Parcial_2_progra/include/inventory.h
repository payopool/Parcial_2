#pragma once
#include "produ.h"
#include "ObserverUwU.h"
#include "factoryProdu.h"
#include "JASON13.h" 
#include"Header.h"

class Inventa {
public:
  // AQUI estaba el error: cambiamos nlohmann::json por JASON13
  void agregarProducto(const JASON13& dato) {
    Produ nuevoProducto = factoryProdu::Crear(dato);
    productos[nuevoProducto.getCode()] = nuevoProducto;

    // Notificar observadores
    for (auto& obs : observadores) {
      obs->update(nuevoProducto);
    }
  }

  void eliminarProducto(const std::string& code) {
    productos.erase(code);
  }

  void registrarObservador(ObserverUwU* obs) {
    observadores.push_back(obs);
  }

  void actualizarCan(const std::string& code, int nuevaCantidad) {
    if (productos.find(code) != productos.end()) {
      productos[code].setCantidad(nuevaCantidad);
      for (auto& obs : observadores) {
        obs->update(productos[code]);
      }
    }
  }

  void sell(const std::string& code, int cantidadVendida) {
    if (productos.find(code) != productos.end()) {
      int nuevaCantidad = productos[code].getCantidad() - cantidadVendida;
      productos[code].setCantidad(nuevaCantidad);
      for (auto& obs : observadores) {
        obs->update(productos[code]);
      }
    }
  }

  Produ getProducto(const std::string& code) {
    if (productos.find(code) != productos.end()) {
      return productos[code];
    }
    return Produ(); // Retorna vacío si no existe
  }

private:
  std::unordered_map<std::string, Produ> productos;
  std::vector<ObserverUwU*> observadores;
};