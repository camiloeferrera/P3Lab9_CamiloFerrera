#ifndef ASALTO_H
#define ASALTO_H

#include "Soldado.h"

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
	protected:
		int velocidad;
		int fuerzaExtra;
};

#endif
