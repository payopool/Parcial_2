#pragma once
#include "produ.h"
#include "Header.h" // Ahora incluye <ctime> y <chrono>
#include "pagoStrategia}.h"

/**
 * @brief Obtiene la fecha y hora actual formateada como una cadena de texto.
 *
 * Utiliza las funciones estándar de la librería C (<ctime>) para mayor compatibilidad.
 *
 * @return std::string La fecha y hora actual en formato YYYY-MM-DD HH:MM:SS.
 */
std::string getCurrentDateTime() {
  // Obtiene el tiempo actual como un valor time_t
  time_t now = time(0);

  // Convierte el valor time_t a una estructura tm local
  // (std::localtime devuelve un puntero a un objeto estático, por lo que no requiere manejo de memoria)
  struct tm* ltm = std::localtime(&now);

  // Buffer para almacenar la cadena de fecha formateada
  char buf[100];

  // Formatea la estructura tm en el formato deseado
  // %Y: Año (ej. 2025), %m: Mes (01-12), %d: Día (01-31), %H: Hora (00-23), %M: Minuto (00-59), %S: Segundo (00-59)
  std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ltm);

  // Retorna la cadena formateada
  return buf;
}

/**
 * @class Ticket
 * @brief Clase Singleton encargada de generar tickets de compra.
 *
 * La clase Ticket centraliza la generación de comprobantes de compra tanto de productos
 * como de gasolina, incluyendo fecha, hora, detalles del producto y método de pago.
 */
class Ticket {
public:
  /**
   * @brief Obtiene la instancia única de la clase Ticket (patrón Singleton).
   *
   * @return Ticket& Referencia a la instancia única de Ticket.
   */
  static Ticket& getInstance() {
    static Ticket instance;
    return instance;
  }

  /**
   * @brief Genera un ticket de compra para un producto.
   *
   * @param producto Objeto de tipo Produ que contiene los datos del producto.
   * @param cantidad Cantidad de unidades compradas.
   * @param metodoPago Estrategia de pago utilizada (efectivo, crédito, etc.).
   */
  void generarTicke(const Produ& producto, int cantidad, const Paguiño& metodoPago) {
    double total = producto.getPrec() * cantidad;
    std::cout << "----- TICKET DE COMPRA -----\n";
    std::cout << "Fecha y Hora: " << getCurrentDateTime() << "\n";
    std::cout << "Producto: " << producto.getName() << "\n";
    std::cout << "Codigo: " << producto.getCode() << "\n";
    std::cout << "Cantidad: " << cantidad << "\n";
    std::cout << "Precio unitario: " << producto.getPrec() << "\n";
    std::cout << "Total a pagar: " << total << "\n";
    std::cout << "Metodo de pago: " << metodoPago.nombre() << "\n";
    std::cout << "---------------------------\n";
  }

  /**
   * @brief Genera un ticket de compra para gasolina.
   *
   * @param litro Cantidad de litros cargados.
   * @param precLitro Precio por litro de gasolina.
   * @param total Total a pagar por la carga.
   * @param metodoPago Estrategia de pago utilizada (efectivo, crédito, etc.).
   */
  void TicketGas(double litro, double precLitro, double total, const Paguiño& metodoPago) {
    std::cout << "----- TICKET DE COMPRA GASOLINA -----\n";
    std::cout << "Fecha y Hora: " << getCurrentDateTime() << "\n";
    std::cout << "Litros: " << litro << "\n";
    std::cout << "Precio por litro: " << precLitro << "\n";
    std::cout << "Total a pagar: " << total << "\n";
    std::cout << "Metodo de pago: " << metodoPago.nombre() << "\n";
    std::cout << "---------------------------\n";
  }

private:
  /**
   * @brief Constructor privado para implementar el patrón Singleton.
   */
  Ticket() = default;
};