#pragma once
#include"produ.h"

class ObserverUwU {
	public:
	ObserverUwU() = default;
	~ObserverUwU() = default;
	virtual void update(const Produ& producto) = 0;
};