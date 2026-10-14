#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include "Inclinacion politica.h"
#include <ctime>

using namespace std;

inline char menu() {

	int n = 1;
	char op;

	cout << endl << "\t Robot Politico." << endl;
	cout << endl << "\t Menu." << endl;
	cout << ".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-." << endl;
	cout << "[" << n << "] : Ingresa Datos" << endl; n++;
	cout << "[" << n << "] : Reporte Total" << endl; n++;
	cout << "[" << n << "] : Salir" << endl; n++;
	cout << endl << "Elija una opcion :"; cin >> op;

	return op;
}

inline void ejerciciopostura() {
	char op;
	manager* si = new manager;
	srand(time(nullptr));
	bool salir = true;
	while (salir) {
		system("cls");
		op = menu();
		switch (op) {
		case '1':
			si->encuesta();
			break;
		case '2':
			si->mostrarresultados();
			break;
		case '3':
			salir = false;
			break;
		}
	}
}
//vector<string> pregunta
//pregunta.push_back("hola como estas");
/*
	vector<int> vect = { 1,2,3,4 };

	for(vector<int>::iterator it = vect.begin(); it != vect.end(); ++it){
		cout << *it << endl;
	}

	for(auto it = vect.begin(); it != vect.end(); ++it){
		cout << *it << endl;
	}

*/