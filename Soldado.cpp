#include "Soldado.h"

Soldado::Soldado(string nombre,int ptsVida,int ptsFuerza)
{
	this->nombre=nombre;
	this->ptsVida=ptsVida;
	this->ptsFuerza=ptsFuerza;
}
Soldado::~Soldado()
{
}

string Soldado::getNombre(){
	return this->nombre;
}
int Soldado::getPtsVida(){
	return this->ptsVida;
}
int Soldado::getPtsFuerza(){
	return this->ptsFuerza;
}
