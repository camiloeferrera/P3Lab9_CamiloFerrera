#include "Asalto.h"

Asalto::Asalto(string nombre,int ptsVida,int ptsFuerza,int velocidad,int fuerzaExtra):Soldado(nombre,ptsVida,ptsFuerza)
{
	this->velocidad=velocidad;
	this->fuerzaExtra=fuerzaExtra;
}
Asalto::~Asalto()
{
}

int Asalto::getVelocidad(){
	return this->velocidad;
}
int Asalto::getFuerzaExtra(){
	return this->fuerzaExtra;
}

void Asalto::setPtsVida(bool asalto,int valorAtaque){
	if(asalto)
		this->ptsVida -= valorAtaque;
	else
		this->ptsVida -= valorAtaque/this->fuerzaExtra; 
}
int Asalto::valorAtaque(bool asalto){
	if(asalto)
		return this->fuerzaExtra*10;
	else
		return this->fuerzaExtra*(10+(this->velocidad*2));	
}
