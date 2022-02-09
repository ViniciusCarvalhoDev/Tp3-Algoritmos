#include <string>
#include "Cell.h"

Cell::Cell() { 
	this->caminho = ""; 
	this->valor = 0; 
}

Cell::Cell(int valor, std::string caminho) 
{ 
	this->valor = valor, 
	this->caminho = caminho; 
} 
