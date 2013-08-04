#include <iostream>
#include <cstdlib>
#include <sstream>
#include <limits>
#include "Carro.h"
using namespace std;

/* Constantes necesaras para el programa */
const char* NOMBRE_ARCHIVO = "autos.car";
int menu_principal();

int main(int argc, char* argv[]) {
	/* Menú principal */
	while (true) {
		int opcion = menu_principal();

		switch(opcion) {
			case 1:
			{
				string marca,
					   modelo,
					   tipo,
					   year,
					   color,
					   motor,
					   serie,
					   placa,
					   id_owner;
				cout << "Ingrese la marca: ";
				getline(cin, marca);
				cout << "Ingrese el modelo: ";
				getline(cin, modelo);
				cout << "Ingrese el tipo: ";
				getline(cin, tipo);
				cout << "Ingrese el año: ";
				getline(cin, year);
				cout << "Ingrese el color: ";
				getline(cin, color);
				cout << "Ingrese el motor: ";
				getline(cin, motor);
				cout << "Ingrese la serie: ";
				getline(cin, serie);
				cout << "Ingrese la placa: ";
				getline(cin, placa);
				cout << "Ingrese el ID del dueño: ";
				getline(cin, id_owner);

				Carro nuevo_carro(marca, modelo, tipo, year, color, motor, serie, placa, id_owner);

				Carro::escribirCarro(nuevo_carro, NOMBRE_ARCHIVO);
			}
			break;

			case 2:
			{
				vector<Carro> carros = Carro::leerCarros(NOMBRE_ARCHIVO);

				cout << "----------------- Lista de carros -----------------" << endl;
				for (int i = 0; i < carros.size(); i++) {
					cout << carros[i].toString();
				}
				cout << "--------------------------------------------------" << endl;
			}
			break;
		}

		if (opcion == 3) {
			break;
		}
	}
	return 0;
}

int menu_principal() {
	int opcion;
	
	const int MAX_OPCION = 3;
	const int MIN_OPCION = 1;

	while (true) {
		stringstream ss;
		string input;

		cout << "\t1.\tAgregar carro" << endl
			 << "\t2.\tListar carros" << endl
			 << "\t3\tSalir" << endl
			 << "Elija una opción: ";
		getline(cin, input);
		ss << input;

		if (ss >> opcion) { 
			if (!(opcion >= MIN_OPCION && opcion <= MAX_OPCION)) {
				cerr << "Opción inválida" << endl;
			} else {
				break;
			}
		} else {
			cerr << "Opción inválida" << endl;
		}
	}

	return opcion;
}