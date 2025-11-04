#pragma once
#include "producto.h"
#include<nlohmann/json.hpp>
class productofactory {
public:
	static Producto Crear(const nlohmann::json& data) {
		return Producto(
			data["nombre"],
			data["precio"],
			data["cantidad"],
			data["codigo"]
			);
	}

};