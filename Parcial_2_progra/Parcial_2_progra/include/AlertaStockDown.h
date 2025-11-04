#pragma once
#include"Observator.h"
#include"Header.h"
class AlertaSatockDown : public Observator {
public:
	AlertaSatockDown(int umbral) : umbral(umbral) {}
	void actualizar(const Producto& producto) override {
		if (producto.getCantidad() < umbral) {
			std::cout << "Alerta: El producto " << producto.getNombre()
				<< " con codigo " << producto.getCodigo()
				<< " tiene un stock bajo: " << producto.getCantidad() << " unidades.\n";
		}
	}
private:
	int umbral;
};