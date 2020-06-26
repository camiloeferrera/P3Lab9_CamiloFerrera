#ifndef SOLDADO_H
#define SOLDADO_H

#include <string>
using std::string;

class Soldado
{
	public:
		Soldado(string,int,int);
		~Soldado();
		string getNombre();
		int getPtsVida();
		int getPtsFuerza();
		
		virtual void setPtsVida(bool,int) = 0;
		virtual int valorAtaque(bool) = 0;
		virtual size_t getSize() = 0;
	protected:
		string nombre;
		int ptsVida;
		int ptsFuerza;
};

#endif
