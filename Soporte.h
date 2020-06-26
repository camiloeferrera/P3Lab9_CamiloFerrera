#ifndef SOPORTE_H
#define SOPORTE_H

#include "Soldado.h"

class Soporte : public Soldado
{
	public:
		Soporte(string,int,int,int,int);
		~Soporte();
		int getBlindaje();
		int getCamuflaje();
		
		void setPtsVida(bool,int);
		int valorAtaque(bool);
	protected:
		int blindaje;
		int camuflaje;
};

#endif
