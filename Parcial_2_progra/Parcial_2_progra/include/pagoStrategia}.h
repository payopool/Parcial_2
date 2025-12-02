#pragma once

/**
 * @file Paguiño.hpp
 * @brief Implementación del patrón Strategy para métodos de pago.
 */

#include "Header.h" // Incluye cabeceras adicionales.

 /**
  * @class Paguiño
  * @brief Clase abstracta base (Estrategia) que define la interfaz común para todos los métodos de pago.
  */
class Paguiño {
public:
  /**
   * @brief Destructor virtual para asegurar la correcta liberación de memoria de las clases derivadas.
   */
  virtual ~Paguiño() = default;

  /**
   * @brief Método virtual puro para procesar un pago.
   * @param monto Cantidad de dinero a procesar.
   * @return bool Verdadero si el procesamiento fue exitoso, falso en caso contrario.
   */
  virtual bool proces(double monto) = 0;

  /**
   * @brief Método virtual puro para obtener el nombre del método de pago.
   * @return std::string Nombre del método de pago.
   */
  virtual std::string nombre() const = 0;
};

/**
 * @class efectivo
 * @brief Implementación concreta del método de pago en efectivo.
 */
class efectivo : public Paguiño {
public:
  /**
   * @brief Procesa el pago en efectivo (simula la transacción).
   * @param monto Cantidad a pagar.
   * @return bool Siempre devuelve true (simulación de pago exitoso).
   */
  bool proces(double monto) override {
    std::cout << "Pago en efectivo procesado por un monto de: " << monto << "\n";
    return true;
  }

  /**
   * @brief Retorna el nombre del método: "Efectivo".
   * @return std::string El nombre del método de pago.
   */
  std::string nombre() const override {
    return "Efectivo";
  }
};

/**
 * @class digital
 * @brief Implementación concreta del método de pago digital (tarjeta de crédito/débito).
 */
class digital : public Paguiño {
public:
  /**
   * @brief Procesa el pago digital (simula la transacción).
   * @param monto Cantidad a pagar.
   * @return bool Siempre devuelve true (simulación de pago exitoso).
   */
  bool proces(double monto) override {
    std::cout << "Pago credito procesado por un monto de: " << monto << "\n";
    return true;
  }

  /**
   * @brief Retorna el nombre del método: "Credito".
   * @return std::string El nombre del método de pago.
   */
  std::string nombre() const override {
    return "Credito";
  }
};