#pragma once
#include "Menu.h"
#include "Logger.h"

class Aplicacion {
public:
	Aplicacion();
	void iniciar();

private:
	Menu menu;
	Logger* logger = Logger::obtenerInstancia();
};
