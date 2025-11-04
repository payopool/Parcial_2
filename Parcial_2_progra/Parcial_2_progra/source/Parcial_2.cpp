#include"Header.h"
#include"Inventario.h"
#include"AlertaStockDown.h"
#include"Historial.h"
#include<nlohmann/json.hpp>
int main() {
		Inventario inventario;
		historial historialTransacciones;
		AlertaSatockDown alertaBaja(5);
		inventario.registrarObservador(&alertaBaja);
		nlohmann::json producto1 = {
				{"nombre", "Gansito"},
				{"precio", 12.5},
				{"cantidad", 20},
				{"codigo", "A001"}
		};
		nlohmann::json producto2 = {
				{"nombre", "Mantecadas"},
				{"precio", 28},
				{"cantidad", 3},
				{"codigo", "B002"}
		};
		inventario.agregarProducto(producto1);
		inventario.agregarProducto(producto2);
		inventario.venderProducto("A001", 5);
		historialTransacciones.agreeRegistro("Venta", 5, Producto("Gansito", 12.5, 15, "A001"));
		inventario.actualizarCantidad("B002", 2);
		historialTransacciones.agreeRegistro("Actualizacion", -1, Producto("Mantecadas", 28, 2, "B002"));
		historialTransacciones.mostrar();
		return 0;
}
