#include "Aplicacion.h"
#include "MenuOpcion.h"

Aplicacion::Aplicacion() {
	menu.agregarOpcion(MenuOpcion("Ingresar personas", [this](Menu* menu) {
		logger->info("opcion seleccionada: 'Ingresar personas'");
	}));

	menu.agregarOpcion(MenuOpcion("Eliminar personas", [this](Menu* menu) {
		logger->info("opcion seleccionada: 'Eliminar personas'");
		}));

	menu.agregarOpcion(MenuOpcion("Guardar en archivo", [this](Menu* menu) {
		logger->info("opcion seleccionada: 'Guardar en archivo'");
	}));

	menu.agregarOpcion(MenuOpcion(std::string("Salir"), [this](Menu* menu) {
		logger->info("seleccionado la opcion salir");
		exit(0);
	}));
}	

void Aplicacion::iniciar() {
	logger->info("aplicacion iniciada");
	menu.mostrar();
}