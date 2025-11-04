#pragma once
#include"Header.h"
#include"producto.h"
struct Transaccion {
	std::string tipo;
	int cantidad;
	std::string nombre;
	std::string codigo;
};
class historial {
public:
	void agreeRegistro(const std::string& tipo, int cantidad, const Producto& producto) {
		registros.push_back({ tipo, cantidad, producto.getNombre(), producto.getCodigo() 
			}
		);
	}
	void mostrar() const {
		for (const auto& registro : registros) {
			std::cout << "Tipo: " << registro.tipo
				<< ", Cantidad: " << registro.cantidad
				<< ", Nombre: " << registro.nombre
				<< ", Codigo: " << registro.codigo << "\n";
		}
	}
private:
	std::vector<Transaccion> registros;

};