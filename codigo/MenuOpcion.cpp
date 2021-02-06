#include "MenuOpcion.h"

MenuOpcion::MenuOpcion(): MenuOpcion("", noopFunction) {}

MenuOpcion::MenuOpcion(std::string const& etiqueta): MenuOpcion(etiqueta, noopFunction) {}

MenuOpcion::MenuOpcion(std::string const& etiqueta, MenuOpcionCallback const& callback) {
	this->etiqueta = etiqueta;
	this->callback = callback;
}

std::string MenuOpcion::obtenerEtiqueta(){
	return etiqueta;
}

void MenuOpcion::llamar(Menu* menu) {
	callback(menu);
}
