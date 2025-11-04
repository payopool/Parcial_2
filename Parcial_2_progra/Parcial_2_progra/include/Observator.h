#pragma once
#include"producto.h"
class Observator {
public:
	virtual void actualizar(const Producto& producto) = 0;
	virtual   ~Observator() = default;

};