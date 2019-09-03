#include "knapsack_data.h"



knapsack_data::knapsack_data(string pth)
{
	_file = pth;
	ifstream ifile(pth.c_str(), ios::in);
	if (ifile.fail()) {
		cout << "Error en archivo: " << pth << endl;
		system("pause");
		exit(0);
	}

	ifile >> _nObj;
	ifile >> _capacity;

	_profits = new int[_nObj];
	_weights = new int[_nObj];
	for (int i = 0; i < _nObj; i++) {
		ifile >> _profits[i];
		ifile >> _weights[i];
	}
	print_data();
	ifile.close();
}


knapsack_data::~knapsack_data()
{
	delete _profits;
	delete _weights;
}

void knapsack_data::print_data() {
	cout << "Archivo: " << _file << endl;
	cout << "Numero de objetos: " << _nObj << endl;
	cout << "Capacidad: " << _capacity << endl;

	cout << "Objeto \t Beneficio \t Peso \t" << endl;

	for (int i = 0; i < _nObj; i++) {
		cout << i+1 << "\t" << _profits[i] << "\t" << _weights[i] << endl;
	}
	
}