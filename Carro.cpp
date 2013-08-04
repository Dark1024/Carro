#include "Carro.h"

Carro::Carro() {}

Carro::Carro(string marca, string modelo, string tipo, string year, string color, string motor, string serie, string placa, string id_owner) {
	this->marca = marca.substr(0, MARCA_SIZE);
	this->modelo = modelo.substr(0, MODELO_SIZE);
	this->tipo = tipo.substr(0, TIPO_SIZE);
	this->year = year.substr(0, YEAR_SIZE);
	this->color = color.substr(0, COLOR_SIZE);
	this->motor = motor.substr(0, MOTOR_SIZE);
	this->serie = serie.substr(0, SERIE_SIZE);
	this->placa = placa.substr(0, PLACA_SIZE);
	this->id_owner = id_owner.substr(0, ID_OWNER_SIZE);
}

Carro::~Carro() {}

string Carro::toString() const {
	stringstream ss;

	ss 	<< marca << " "
		<< modelo << " "
		<< tipo << " "
		<< year << " "
		<< color << " "
		<< motor << " "
		<< serie << " "
		<< placa << " "
		<< id_owner << "\n";

	return ss.str();	
}

bool Carro::escribirCarro(const Carro& car, const char* nombre_archivo) {
	ofstream archivo_carros(nombre_archivo, ios::out | ios::app);

	if (!archivo_carros.good()) {
		return false;
	}

	stringstream ss;

	ss 	<< car.marca << ","
		<< car.modelo << ","
		<< car.tipo << ","
		<< car.year << ","
		<< car.color << ","
		<< car.motor << ","
		<< car.serie << ","
		<< car.placa << ","
		<< car.id_owner << "\n";
	int bytes = car.marca.size() + car.modelo.size() + car.tipo.size()
				+ car.year.size() + car.color.size() + car.motor.size()
				+ car.serie.size() + car.placa.size() + car.id_owner.size() + 9;  
	archivo_carros.write(ss.str().c_str(), bytes);

	if (!archivo_carros.good()) {
		return false;
	}

	archivo_carros.close();
	return true;
}

vector<Carro> Carro::leerCarros(const char* nombre_archivo) {
	ifstream archivo_carros(nombre_archivo);
	vector<Carro> carros;

	while (archivo_carros.good()) {
		char* buffer = new char[256];
		archivo_carros.getline(buffer, 256);
		
		Carro* nuevo_carro = new Carro();

		const char* result = strtok(buffer, ",");
		
		if (result) {
			nuevo_carro->marca = result;
		} else {
			break;
		}

		result = strtok(NULL, ",");

		if (result) {
			nuevo_carro->modelo = result;
		} else {
			break;
		}

		result = strtok(NULL, ",");

		if (result) {
			nuevo_carro->tipo = result;
		} else {
			break;
		}

		result = strtok(NULL, ",");

		if (result) {
			nuevo_carro->year = result;
		} else {
			break;
		}

		result = strtok(NULL, ",");

		if (result) {
			nuevo_carro->color = result;
		} else {
			break;
		}

		result = strtok(NULL, ",");

		if (result) {
			nuevo_carro->motor = result;
		} else {
			break;
		}

		result = strtok(NULL, ",");

		if (result) {
			nuevo_carro->serie = result;
		} else {
			break;
		}

		result = strtok(NULL, ",");

		if (result) {
			nuevo_carro->placa = result;
		} else {
			break;
		}

		result = strtok(NULL, ",");

		if (result) {
			nuevo_carro->id_owner = result;
		} else {
			break;
		}

		carros.push_back(*nuevo_carro);
		delete buffer;
	}
	archivo_carros.close();
	
	return carros;
}