#ifndef SOPORTE_H
#define SOPORTE_H

#include "Soldado.h"
#include <iostream>
using std::cout;
using std::endl;

class Soporte : public Soldado
{
	public:
		Soporte(string,int,int,int,int);
		~Soporte();
		int getBlindaje();
		int getCamuflaje();
		
		void setPtsVida(bool,int);
		int valorAtaque(bool);
		
		size_t getSize();
		void imprimirAtributos();
	protected:
		int blindaje;
		int camuflaje;
};

#endif
