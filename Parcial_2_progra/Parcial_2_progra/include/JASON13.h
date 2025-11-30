#pragma once
#include "Header.h"
#include "produ.h" 

class JASON13 {
public:
  void set(const std::string& key, const std::string& value) { data[key] = value; }
  void set(const std::string& key, double value) { data[key] = std::to_string(value); }
  void set(const std::string& key, int value) { data[key] = std::to_string(value); }

  std::string getString(const std::string& key, const std::string& def = "") const {
    auto it = data.find(key);
    return it != data.end() ? it->second : def;
  }

  double getDouble(const std::string& key, double def = 0.0) const {
    auto it = data.find(key);
    if (it != data.end()) {
      try { return std::stod(it->second); }
      catch (...) { return def; }
    }
    return def;
  }

  int getInt(const std::string& key, int def = 0) const {
    auto it = data.find(key);
    if (it != data.end()) {
      try { return std::stoi(it->second); }
      catch (...) { return def; }
    }
    return def;
  }

  bool contains(const std::string& key) const {
    return data.find(key) != data.end();
  }

  // Método estático para guardar (Simplificado para devolver un objeto, no un vector)
  static JASON13 guardarProducto(const Produ& p) {
    JASON13 j;
    j.set("nombre", p.getName());
    j.set("precio", p.getPrec());
    j.set("codigo", p.getCode());
    j.set("cantidad", p.getCantidad());
    return j;
  }

private:
  std::unordered_map<std::string, std::string> data;
};