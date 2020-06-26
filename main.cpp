#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <locale.h>

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::ios;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "Soldado.h"
#include "Asalto.h"
#include "Soporte.h"

vector<Soldado*> ejercitoChina;
vector<Soldado*> ejercitoUSA;

void menuPrincipal();
void crearSoldado();
void eliminarSoldado();
void listarSoldados();

int main() {
	setlocale(LC_ALL,"spanish");
	while(true){
		menuPrincipal();
	}
	return 0;
}

void menuPrincipal(){
	int opcion;
	cout << "1. Crear Soldado" << endl
	<< "2. Eliminar Soldado" << endl
	<< "3. Listar Soldados" << endl
	<< "4. Guardar Soldados" << endl
	<< "5. Cargar Soldados" << endl
	<< "6. Simulación" << endl
	<< "7. Salir" << endl
	<< "Ingrese opcion: ";
	cin >> opcion;
	
	if(opcion != 7){
		cout << endl;
	}
	
	switch(opcion){
		case 1:{
			crearSoldado();
			break;
		}
		case 2:{
			eliminarSoldado();
			break;
		}
		case 3:{
			listarSoldados();
			break;
		}
		case 7:{
			for(int i=0; i<ejercitoChina.size();i++)
				delete ejercitoChina[i];
			
			for(int i=0; i<ejercitoUSA.size();i++)
				delete ejercitoUSA[i];
			exit(0);
		}
		default:{
			cout << "Opcion incorrecta..." << endl << endl;
			break;
		}
	}
}

void crearSoldado(){
	int opcionEjercito;
	cout << "1. Ejercito Chino" << endl
	<<  "2. Ejercito Gringo" << endl
	<< "Ingrese a que ejercito pertenece el soldado: ";
	cin >> opcionEjercito;
	
	while(opcionEjercito<1 || opcionEjercito>2){
		cout << endl << "Opción invalida, intente de nuevo." << endl
		<< "Ingrese a que ejercito pertenece el soldado: ";
		cin >> opcionEjercito;
	}
	cout << endl;
	
	string nombre;
	int ptsVida,ptsFuerza;
	cout << "Ingrese nombre: ";
	cin >> nombre;
	cout << "Ingrese puntos de vida: ";
	cin >> ptsVida;
	cout << "Ingrese pts fuerza: ";
	cin >> ptsFuerza;
	
	int tipoSoldado;
	cout << endl << "1. Soldado de Asalto" << endl
	<< "2. Soldado de Soporte" << endl
	<< "Ingrese el tipo de soldado: ";
	cin >> tipoSoldado;
	
	while(tipoSoldado<1 || tipoSoldado>2){
		cout << endl << "Opción invalida, intente de nuevo." << endl
		<< "Ingrese el tipo de soldado: ";
		cin >> tipoSoldado;
	}
	cout << endl;
	
	switch(tipoSoldado){
		case 1:{
			int velocidad,fuerzaExtra;
			cout << "Ingrese velocidad: ";
			cin >> velocidad;
			cout << "Ingrese fuerza extra: ";
			cin >> fuerzaExtra;
			cout << endl;
			
			switch(opcionEjercito){
				case 1:{
					ejercitoChina.push_back(new Asalto(nombre,ptsVida,ptsFuerza,velocidad,fuerzaExtra));
					cout << "Soldado de Asalto agregado al ejercito chino!" << endl << endl;
					break;
				}
				case 2:{
					ejercitoUSA.push_back(new Asalto(nombre,ptsVida,ptsFuerza,velocidad,fuerzaExtra));
					cout << "Soldado de Asalto agregado al ejercito gringo!" << endl << endl;
					break;
				}
			}
			break;
		}
		case 2:{
			int blindaje,camuflaje;
			cout << "Ingrese blindaje: ";
			cin >> blindaje;
			cout << "Ingrese camuflaje: ";
			cin >> camuflaje;
			cout << endl;
			
			switch(opcionEjercito){
				case 1:{
					ejercitoChina.push_back(new Soporte(nombre,ptsVida,ptsFuerza,blindaje,camuflaje));
					cout << "Soldado de Soporte agregado al ejercito chino!" << endl << endl;
					break;
				}
				case 2:{
					ejercitoUSA.push_back(new Soporte(nombre,ptsVida,ptsFuerza,blindaje,camuflaje));
					cout << "Soldado de Soporte agregado al ejercito gringo!" << endl << endl;
					break;
				}
			}
		}
	}
}

void eliminarSoldado(){
	int opcionEjercito;
	cout << "1. Ejercito Chino" << endl
	<< "2. Ejercito Gringo" << endl
	<< "Ingrese de que ejercito es el soldado: ";
	cin >> opcionEjercito;
	
	while(opcionEjercito<1 || opcionEjercito>2){
		cout << endl << "Opción invalida, intente de nuevo." << endl
		<< "Ingrese de que ejercito es el soldado: ";
		cin >> opcionEjercito;
	}
	cout << endl;
	
	switch(opcionEjercito){
		case 1:{
			if (ejercitoChina.size()==0){
				cout << "No hay soldados en este ejercito." << endl << endl;
			} else {
				int opcion;
				for(int i=0;i<ejercitoChina.size();i++){
					cout << (i+1) << ". Nombre: " << ejercitoChina[i]->getNombre() << endl;
				}
				cout << "Seleccione el soldado a ejecutar: ";
				cin >> opcion;
				opcion--;
				
				while(opcion<0 || opcion>=ejercitoChina.size()){
					cout << endl << "Soldado no encontrado, intente de nuevo." << endl
					<< "Seleccione el soldado a ejecutar: ";
					cin >> opcion;
					opcion--;
				}
				
				delete ejercitoChina[opcion];
				ejercitoChina.erase(ejercitoChina.begin()+opcion);
				cout << endl << "Has ejecutado al soldado, se le velara pronto..." << endl << endl;				
			}
						
			break;
		}
		case 2:{
			if (ejercitoUSA.size()==0){
				cout << "No hay soldados en este ejercito." << endl << endl;
			} else {
				int opcion;
				for(int i=0;i<ejercitoUSA.size();i++){
					cout << (i+1) << ". Nombre: " << ejercitoChina[i]->getNombre() << endl;
				}
				cout << "Seleccione el soldado a ejecutar: ";
				cin >> opcion;
				opcion--;
				
				while(opcion<0 || opcion>=ejercitoUSA.size()){
					cout << endl << "Soldado no encontrado, intente de nuevo." << endl
					<< "Seleccione el soldado a ejecutar: ";
					cin >> opcion;
					opcion--;
				}
				
				delete ejercitoUSA[opcion];
				ejercitoUSA.erase(ejercitoChina.begin()+opcion);
				cout << endl << "Has ejecutado al soldado, se le velara pronto..." << endl << endl;				
			}
			break;
		}
	}
}

void listarSoldados(){
	if(ejercitoChina.size()==0){
		cout << "No hay soldados en el ejercito chino." << endl;
	} else {
		cout << "Ejercito CHINA" << endl;
		for(int i=0;i<ejercitoChina.size();i++){
			cout << (i+1) << ". Nombre: " << ejercitoChina[i]->getNombre() << endl;
		}
		cout << endl;
	}
	if(ejercitoUSA.size()==0){
		cout << "No hay soldados en el ejercito gringo." << endl;
	} else {
		cout << "Ejercito USA" << endl;
		for(int i=0;i<ejercitoUSA.size();i++){
			cout << (i+1) << ". Nombre: " << ejercitoUSA[i]->getNombre() << endl;
		}
	}
	cout << endl;
}
