#pragma once
#include"Header.h"
class Producto {
public:

	Producto (std :: string nombre, double precio, int cantidad, std::string codigo)
		: nombre(nombre), precio(precio), cantidad(cantidad), codigo(codigo) {
	}
	Producto() : nombre(""), precio(0.0), cantidad(0), codigo("") {}

	std::string getNombre() const {
		return nombre;
	}
	double getPrecio() const {
		return precio;
	}
	int getCantidad() const {
		return cantidad;
	}
	std::string getCodigo() const {
		return codigo;
	}
	void setCantidad(int nuevaCantidad) {
		cantidad = nuevaCantidad;
	}
	void setPrecio(double nuevoPrecio) {
		precio = nuevoPrecio;
	}
private:
	std::string nombre;
	double precio;
	int cantidad;
	std::string codigo;
};