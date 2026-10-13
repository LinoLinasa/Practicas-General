#pragma once
#include "postura.h"
#include "dc.h"
#include "dl.h"
#include "ic.h"
#include "il.h"
#include "c.h"

class manager {
protected:
	int dcn;
	int dln;
	int icn;
	int iln;
	int cn;
	dc* dcquest;
	dl* dlquest;
	il* ilquest;
	ic* icquest;
	c* cquest;
public:
	manager() {
		dcn = 0;
		dln = 0;
		icn = 0;
		iln = 0;
		cn = 0;
		dcquest = new dc;
		dlquest = new dl;
		ilquest = new il;
		icquest = new ic;
		cquest = new c;
	};
	~manager() {
	};

	//gets
	int getdcn() { return dcn; };
	int getdln() { return dln; };
	int geticn() { return icn; };
	int getiln() { return iln; };
	int getcn() { return cn; };

	void encuesta();
	void mostrarreporte();
	void mostrarresultados();
};

void manager::mostrarreporte() {
	string resultado;
	if (dcn > dln && dcn > icn && dcn > iln && dcn > cn) {
		resultado = "Derecha conservadora";
	}
	else if (dln > dcn && dln > icn && dln > iln && dln > cn) {
		resultado = "Derecha liberal";
	}
	else if (icn > dcn && icn > dln && icn > iln && icn > cn) {
		resultado = "Izquierda conservadora";
	}
	else if (iln > dcn && iln > dln && iln > icn && iln > cn) {
		resultado = "Izquierda liberal";
	}
	else if (cn > dcn && cn > dln && cn > icn && cn > iln) {
		resultado = "Centro";
	}
	cout << "Su inclinacion politica es: " << resultado;
}
void manager::encuesta() {
	int n = 1;
	char op1,
		op2,
		op3,
		op4,
		op5;
	
	cout << endl << "\t\t Robot Politico." << endl;
	cout << endl << "\t Responda las siguientes preguntas." << endl;
	cout << ".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
	dcquest->mostrarpregunta(); cin >> op1; n++;
	dlquest->mostrarpregunta();cin >> op2; n++;
	icquest->mostrarpregunta();cin >> op3; n++;
	ilquest->mostrarpregunta();cin >> op4; n++;
	cquest->mostrarpregunta(); cin >> op5; n++;
	if (op1 == 's' || op1 == 'S') {
		dcn++;
	}
	if (op2 == 's' || op2 == 'S') {
		dln++;
	}
	if (op3 == 's' || op3 == 'S') {
		icn++;
	}
	if (op4 == 's' || op4 == 'S') {
		iln++;
	}
	if (op5 == 's' || op5 == 'S') {
		cn++;
	}
	mostrarreporte();
}

void manager::mostrarresultados() {
	system("cls");
	cout << endl << "\t\t Robot Politico." << endl;
	cout << endl << "\t\t Reporte." << endl;
	cout << ".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-." << endl;
	cout << "IZQ Liberal :" << iln << endl;
	cout << "IZQ Conservadora :" << icn << endl;
	cout << "DER Liberal :" << dln << endl;
	cout << "DER Conservadora :" << dcn << endl;
	cout << "Centro :" << cn << endl; 
	cout << "[Presione una tecla para ir al menu]";
	while (true) {
		if (kbhit()) {
			return;
		}
	}
};