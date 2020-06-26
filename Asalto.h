#ifndef ASALTO_H
#define ASALTO_H

#include "Soldado.h"
#include <iostream>
using std::cout;
using std::endl;

class Asalto : public Soldado
{
	public:
		Asalto(string,int,int,int,int);
		~Asalto();
		int getVelocidad();
		int getFuerzaExtra();
		
		void setPtsVida(bool,int);
		int valorAtaque(bool);
		
		size_t getSize();
		void imprimirAtributos();
	protected:
		int velocidad;
		int fuerzaExtra;
};

#endif
