#pragma once
#include <vector>
#include "MenuOpcion.h"

class MenuOpcion;

class Menu {
public:
	Menu() = default;
	Menu(std::string titulo);
	void agregarOpcion(MenuOpcion opcion);
	void mostrar();

private:
	std::string titulo;
	std::vector<MenuOpcion> opciones;
};
