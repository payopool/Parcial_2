#pragma once
#include "ServicioTicket.h"
class GasXD {
public:
	bool cargarGas(double litros, double preciolitros, Paguiño& pago, bool pagaAfter) {
				double total = litros * preciolitros;
		if (pagaAfter) {
			std::cout << "Cargando " << litros << " litros de gasolina a " << preciolitros << " por litro. Total a pagar despues: " << total << "\n";
			Ticket::getInstance().TicketGas(litros, preciolitros, total, pago);
			return true;
		}
		else {
			if (pago.proces(total)) {
				std::cout << "Cargando " << litros << " litros de gasolina a " << preciolitros << " por litro. Total pagado: " << total << "\n";
				Ticket::getInstance().TicketGas(litros, preciolitros, total, pago);
				return true;
			}
			else {
				std::cout << "Pago fallido. No se puede cargar gasolina.\n";
				return false;
			}
		}
	}
};