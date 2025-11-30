#pragma once
#include"inventory.h"
#include"ServicioTicket.h"
#include"GasXD.h"
class FecadeSystem {
public:
	void comprarpro(Inventa& inventario, const std::string& code, int cantidad, Paguiño& metodoPago) {
		inventario.sell(code, cantidad);
		Produ producto = inventario.getProducto(code);
		Ticket::getInstance().generarTicke(producto, cantidad, metodoPago);

	}
};