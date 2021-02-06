#include "Menu.h"
#include <iostream>
#include <cstdlib>

Menu::Menu(std::string titulo) {
	this->titulo = titulo;
}

void Menu::agregarOpcion(MenuOpcion opcion) {
	opciones.push_back(opcion);
}

void Menu::mostrar() {
	while (true) {
		int indice = 0;
		int seleccion;

		system("cls");
		std::cout << titulo << std::endl;

		for (MenuOpcion opcion : opciones) {
			std::cout << ++indice << ") " << opcion.obtenerEtiqueta() << std::endl;
		}

		std::cout << std::endl;
		std::cout << "selecciona una opcion: ";
		std::cin >> seleccion;

		if (std::cin.fail() || seleccion < 1 || seleccion > opciones.size()) {
			std::cin.clear();
			std::cin.ignore(9999, '\n');
			continue;
		}

		MenuOpcion seleccionada = opciones.at(seleccion - 1);

		std::cout << std::endl;
		seleccionada.llamar(this);
		std::cout << std::endl;
		system("pause");
	}
}