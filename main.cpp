#include <conio.h>
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
#include <random>
#include <time.h>

#include "Soldado.h"
#include "Asalto.h"
#include "Soporte.h"

vector<Soldado*> ejercitoChina;
vector<Soldado*> ejercitoUSA;

void menuPrincipal();
void crearSoldado();
void eliminarSoldado();
void listarSoldados();
void guardarSoldados();
void simulacion();
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
	
	/*if(opcion != 7){
		cout << endl;
	}*/
	
	system("cls");
	
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
		case 4:{
			//guardarSoldados();
			break;
		}
		case 6:{
			simulacion();
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
			cout << "Opcion incorrecta..." << endl;
			break;
		}
	}
	char tecla;
	cout << endl << "Presiona cualquier tecla para continuar: ";
	tecla = getch();
	system("cls");
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
					cout << "Soldado de Asalto agregado al ejercito chino!" << endl;
					break;
				}
				case 2:{
					ejercitoUSA.push_back(new Asalto(nombre,ptsVida,ptsFuerza,velocidad,fuerzaExtra));
					cout << "Soldado de Asalto agregado al ejercito gringo!" << endl;
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
					cout << "Soldado de Soporte agregado al ejercito chino!" << endl;
					break;
				}
				case 2:{
					ejercitoUSA.push_back(new Soporte(nombre,ptsVida,ptsFuerza,blindaje,camuflaje));
					cout << "Soldado de Soporte agregado al ejercito gringo!" << endl;
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
				cout << "No hay soldados en este ejercito." << endl;
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
				cout << endl << "Has ejecutado al soldado, se le velara pronto..." << endl;	
			}
						
			break;
		}
		case 2:{
			if (ejercitoUSA.size()==0){
				cout << "No hay soldados en este ejercito." << endl;
			} else {
				int opcion;
				for(int i=0;i<ejercitoUSA.size();i++){
					cout << (i+1) << ". Nombre: " << ejercitoUSA[i]->getNombre() << endl;
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
				ejercitoUSA.erase(ejercitoUSA.begin()+opcion);
				cout << endl << "Has ejecutado al soldado, se le velara pronto..." << endl;				
			}
			break;
		}
	}
}

void listarSoldados(){
	if(ejercitoChina.size()==0){
		cout << "No hay soldados en el ejercito chino." << endl;
		if (ejercitoUSA.size()!=0)
			cout << endl;
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
}

void guardarSoldados(){
	ofstream binaryFile("SoldadosChinos.bin",ios::binary|ios::trunc);
	if(!binaryFile.is_open()){
		cout << "No se pudo abrir el archivo";
		exit(1);
	}
	
	size_t tempSize=0;
	
	/*for(int i=0;i<ejercitoChina.size();i++){
		Soldado soldado = new Soldado (ejercitoChina[i]->getNombre)
		tempSize = ejercitoChina[i]->getSize();
		binaryFile.write((char*)&tempSize,sizeof(size_t));
		binaryFile.write(ejercitoChina[1],tempSize)
	}*/
	
	binaryFile.close();
	cout << "Soldados chinos guardados exitosamente!" << endl << endl;
}
void simulacion(){
	if(ejercitoChina.size()==0 || ejercitoUSA.size() == 0){
		cout << "No hay suficientes soldados para combatir..." << endl;
	} else {
		int bajasChinas=0,bajasGringas=0;
		while(true){
			srand((int)time(0));
			//China y USA seleccinaran el soldado a combatir de sus ejercitos
			int china = rand() % ejercitoChina.size();
			int usa = rand() % ejercitoUSA.size();
			
			//Punteros que nos ayudaran a definir si los soldados son de asalto o de soporte
			Asalto* ptChina = dynamic_cast<Asalto*>(ejercitoChina[china]);
			Asalto* ptUsa = dynamic_cast<Asalto*>(ejercitoUSA[usa]);
			
			//booleanos que definiran si los soldados seleccionados son de asalto
			bool chinaAsalto = true; 
			bool usaAsalto = true;
			
			//si los punteros son 0, entonces los booleanos seran cambiados a false ya que los soldados no son de asalto.
			if(ptChina==0 )
				chinaAsalto = false;
			if(ptUsa==0)
				usaAsalto = false;
			
			// los soldados seleccionados se pelean entre si
			ejercitoUSA[usa]->setPtsVida(chinaAsalto,ejercitoChina[china]->valorAtaque(usaAsalto));
			ejercitoChina[china]->setPtsVida(usaAsalto,ejercitoUSA[usa]->valorAtaque(chinaAsalto));		
				
			
			if(ejercitoUSA[usa]->getPtsVida()<=0){
				delete ejercitoUSA[usa];
				ejercitoUSA.erase(ejercitoUSA.begin()+usa);
				bajasGringas++;
			}
			if(ejercitoChina[china]->getPtsVida()<=0){
				delete ejercitoChina[china];
				ejercitoChina.erase(ejercitoChina.begin()+china);
				bajasChinas++;
			}
			
			// si un ejercito se queda sin soldados se acaba la guerra
			if(ejercitoChina.size()==0 || ejercitoUSA.size()==0)
				break;
		}
		
		if(ejercitoChina.size()==0 && ejercitoUSA.size()!=0){
			cout << "Ha ganado Estados Unidos! VIVA TRUMP!" << endl << endl;
		} else if (ejercitoUSA.size()==0 && ejercitoChina.size()!=0){
			cout << "Ha ganado China! VIVA HUAWEI!" << endl << endl;
		} else {
			cout << "EMPATE!!!" << endl << endl;
		}
		cout << "Bajas Chinas: " << bajasChinas << endl
		<< "Bajas Gringas: " << bajasGringas << endl << endl
		<< "Sobrevivientes Chinos: " << ejercitoChina.size() << endl
		<< "Sobrevivientes Gringos: " << ejercitoUSA.size() << endl;
	}
}
