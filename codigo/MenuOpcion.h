#pragma once
#include <string>
#include <functional>
#include "Menu.h"

class Menu;

typedef std::function<void(Menu* menu)> MenuOpcionCallback;

class MenuOpcion {
public:
	MenuOpcion();
	MenuOpcion(std::string const& etiqueta);
	MenuOpcion(std::string const& etiqueta, MenuOpcionCallback const& callback);
	std::string obtenerEtiqueta();
	void llamar(Menu *menu);

private:
	std::string etiqueta;
	MenuOpcionCallback callback;
	MenuOpcionCallback noopFunction = [](Menu *menu){};
};
