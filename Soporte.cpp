#include "Soporte.h"

Soporte::Soporte(string nombre,int ptsVida,int ptsFuerza,int blindaje,int camuflaje):Soldado(nombre,ptsVida,ptsFuerza)
{
	this->blindaje=blindaje;
	this->camuflaje=camuflaje;
}
Soporte::~Soporte()
{
}

int Soporte::getBlindaje(){
	return this->blindaje;
}
int Soporte::getCamuflaje(){
	return this->camuflaje;
}

void Soporte::setPtsVida(bool asalto,int valorAtaque){
	if(asalto)
		this->ptsVida -= valorAtaque/(this->blindaje*2);
	else
		this->ptsVida -= valorAtaque;	
}
int Soporte::valorAtaque(bool asalto){
	if(asalto)
		return this->ptsFuerza*(15+this->camuflaje);
	else
		return this->ptsFuerza*10;	
}
