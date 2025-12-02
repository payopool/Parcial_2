#pragma once

/**
 * @file ObserverUwU.hpp
 * @brief Definición de la interfaz abstracta ObserverUwU, parte del patrón de diseño Observer.
 */

#include "produ.h" ///< @brief Incluye la definición de la clase Produ, ya que los observadores reciben actualizaciones sobre objetos de este tipo.

 /**
	* @class ObserverUwU
	* @brief Interfaz (clase abstracta pura) que define el método que deben implementar
	* todos los objetos que deseen observar cambios en los productos.
	*/
class ObserverUwU {
public:
	/**
	 * @brief Constructor por defecto.
	 */
	ObserverUwU() = default;

	/**
	 * @brief Destructor por defecto.
	 */
	~ObserverUwU() = default;

	/**
	 * @brief Método virtual puro que se ejecuta cuando el Sujeto notifica un cambio.
	 * Las clases derivadas (como Histo) DEBEN implementar esta función.
	 * * @param producto Referencia constante al objeto Produ que ha sido modificado o creado.
	 */
	virtual void update(const Produ& producto) = 0;
};