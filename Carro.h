#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

class Carro
{
public:
	Carro();
	Carro(string, string, string, string, string, string, string, string, string);
	~Carro();
	string toString() const;
	static bool escribirCarro(const Carro&, const char*);
	static vector<Carro> leerCarros(const char*);

	static const int MARCA_SIZE 	= 	20;
	static const int MODELO_SIZE	= 	15;
	static const int TIPO_SIZE 		= 	15;
	static const int YEAR_SIZE 		= 	4;
	static const int COLOR_SIZE 	= 	10;
	static const int MOTOR_SIZE 	=	4;
	static const int SERIE_SIZE 	=	25;
	static const int PLACA_SIZE		=	6;
	static const int ID_OWNER_SIZE	=	13;

private:
	string marca;
	string modelo;
	string tipo;
	string year;
	string color;
	string motor;
	string serie;
	string placa;
	string id_owner;
};