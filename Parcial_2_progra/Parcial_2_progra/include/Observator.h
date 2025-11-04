#pragma once

#include "producto.h"

/**
 * @class Observator
 * @brief Interfaz abstracta para observar cambios en objetos Producto.
 *
 * Esta clase define una interfaz para los observadores que desean recibir notificaciones
 * cuando un objeto Producto cambia. Forma parte del patrón de diseño Observer.
 */
class Observator {
public:

  /**
   * @brief Método virtual puro que se llama cuando un Producto se actualiza.
   * @param producto Referencia constante al producto actualizado.
   */
  virtual void actualizar(const Producto& producto) = 0;

  /**
   * @brief Destructor virtual por defecto.
   */
  virtual ~Observator() = default;
};