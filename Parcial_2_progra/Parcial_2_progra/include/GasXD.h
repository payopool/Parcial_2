#pragma once

/**
 * @file GasXD.hpp
 * @brief Definición de la clase GasXD, que gestiona la lógica de la transacción de carga de combustible.
 */

#include "ServicioTicket.h" ///< @brief Incluye la definición del servicio de Tickets (Ticket y sus dependencias).

 /**
	* @class GasXD
	* @brief Clase de control que maneja el proceso completo de cargar gasolina, incluyendo el cálculo,
	* la lógica de pago (antes o después) y la generación del ticket, asumiendo que el método de pago
	* se gestiona externamente o está definido en el alcance del método 'proces'.
	*/
class GasXD {
public:
	/**
	 * @brief Procesa la carga de gasolina y gestiona el pago y la emisión del ticket.
	 *
	 * @param litros Cantidad de litros de gasolina cargados.
	 * @param preciolitros Precio por litro de la gasolina.
	 * @param pago Referencia al objeto Paguiño que procesa el pago.
	 * @param pagaAfter Bandera que indica si el pago se realiza después (true) o antes (false) de la carga.
	 * @return bool Verdadero si la carga (y el pago, si aplica) fue exitosa, falso en caso de pago fallido.
	 */
	bool cargarGas(double litros, double preciolitros, Paguiño& pago, bool pagaAfter) {
		// Calcula el monto total a pagar
		double total = litros * preciolitros;

		if (pagaAfter) {
			// Lógica para el pago DESPUÉS de cargar la gasolina
			std::cout << "Cargando " << litros << " litros de gasolina a " << preciolitros << " por litro. Total a pagar despues: " << total << "\n";
			// Se asume que la carga procede. El ticket se genera para el cobro posterior.
			Ticket::getInstance().TicketGas(litros, preciolitros, total, pago);
			return true;
		}
		else {
			// Lógica para el pago ANTES de cargar la gasolina
			// Llama al método procesar del objeto Paguiño.
			if (pago.proces(total)) {
				// Pago exitoso: procede con la carga
				std::cout << "Cargando " << litros << " litros de gasolina a " << preciolitros << " por litro. Total pagado: " << total << "\n";
				// Genera el ticket después del pago exitoso
				Ticket::getInstance().TicketGas(litros, preciolitros, total, pago);
				return true;
			}
			else {
				// Pago fallido
				std::cout << "Pago fallido. No se puede cargar gasolina.\n";
				return false;
			}
		}
	}
};