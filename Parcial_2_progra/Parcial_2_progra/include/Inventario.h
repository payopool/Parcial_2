#pragma once
#include"producto.h"
#include"Observator.h"
#include"Header.h"
#include"FactoryProducto.h"
#include<nlohmann/json.hpp>
class Inventario {
	public:
		void agregarProducto(const nlohmann::json& data) {
			Producto producto = productofactory::Crear(data);
			productos[producto.getCodigo()] = producto;
			for (auto& observador : observadores) {
				observador->actualizar(producto);
			}
		}
		void eliminarProducto(const std::string& codigo) {
			productos.erase(codigo);
		}
		void actualizarCantidad(const std::string& codigo, int nuevaCantidad) {
			if (productos.find(codigo) != productos.end()) {
				productos[codigo].setCantidad(nuevaCantidad);
				for (auto& observador : observadores) {
					observador->actualizar(productos[codigo]);
				}
			}
		}
		void registrarObservador(Observator* observador) {
			observadores.push_back(observador);
		}
		void venderProducto(const std::string& codigo, int cantidad) {
			if (productos.find(codigo) != productos.end()) {
				int cantidadActual = productos[codigo].getCantidad();
				if (cantidadActual >= cantidad) {
					productos[codigo].setCantidad(cantidadActual - cantidad);
					for (auto& observador : observadores) {
						observador->actualizar(productos[codigo]);
					}
				}
			}
		}
		void notificarCambios(const std::string& codigo) {
			if (productos.find(codigo) != productos.end()) {
				for (auto& observador : observadores) {
					observador->actualizar(productos[codigo]);
				}
			}
		}
private:
	std::unordered_map<std::string, Producto> productos;
	std::vector<Observator*> observadores;
};