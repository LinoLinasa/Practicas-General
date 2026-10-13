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
		delete dcquest;
		delete dlquest;
		delete ilquest;
		delete icquest;
		delete cquest;
	};

	//gets
	int getdcn() { return dcn; };
	int getdln() { return dln; };
	int geticn() { return icn; };
	int getiln() { return iln; };
	int getcn() { return cn; };

	void encuesta();
	void mostrarresultados();
};

//void manager::mostrarreporte() {
//	string resultado;
//	if (dcn > dln && dcn > icn && dcn > iln && dcn > cn) {
//		resultado = "Derecha conservadora";
//	}
//	else if (dln > dcn && dln > icn && dln > iln && dln > cn) {
//		resultado = "Derecha liberal";
//	}
//	else if (icn > dcn && icn > dln && icn > iln && icn > cn) {
//		resultado = "Izquierda conservadora";
//	}
//	else if (iln > dcn && iln > dln && iln > icn && iln > cn) {
//		resultado = "Izquierda liberal";
//	}
//	else if (cn > dcn && cn > dln && cn > icn && cn > iln) {
//		resultado = "Centro";
//	}
//	cout << "Su inclinacion politica es: < " << resultado << " >";
//	system("pause>0");
//}
void manager::encuesta() {
	int n = 1;
	char op1,
		op2,
		op3,
		op4,
		op5;
	int p_dc = 0, p_dl = 0, p_ic = 0, p_il = 0, p_c = 0;
	
	cout << endl << "\t\t Robot Politico." << endl;
	cout << endl << "\t Responda las siguientes preguntas." << endl;
	cout << ".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
	dcquest->mostrarpregunta(); cout << "Si [S/s] / No [N/n] :"; cin >> op1; n++;
	dlquest->mostrarpregunta(); cout << "Si [S/s] / No [N/n] :"; cin >> op2; n++;
	icquest->mostrarpregunta(); cout << "Si [S/s] / No [N/n] :"; cin >> op3; n++;
	ilquest->mostrarpregunta(); cout << "Si [S/s] / No [N/n] :"; cin >> op4; n++;
	cquest->mostrarpregunta();  cout << "Si [S/s] / No [N/n] :";cin >> op5; n++;
	if (op1 == 's' || op1 == 'S') p_dc++;
	if (op2 == 's' || op2 == 'S') p_dl++;
	if (op3 == 's' || op3 == 'S') p_ic++;
	if (op4 == 's' || op4 == 'S') p_il++;
	if (op5 == 's' || op5 == 'S') p_c++;

	// Determinación de la inclinación con valor por defecto
	string resultado = "Centro";
	int maxPuntos = p_c;

	if (p_dc > maxPuntos) { maxPuntos = p_dc; resultado = "Derecha conservadora"; }
	if (p_dl > maxPuntos) { maxPuntos = p_dl; resultado = "Derecha liberal"; }
	if (p_ic > maxPuntos) { maxPuntos = p_ic; resultado = "Izquierda conservadora"; }
	if (p_il > maxPuntos) { maxPuntos = p_il; resultado = "Izquierda liberal"; }

	// Incrementar el conteo general de encuestados para el Reporte Total
	if (resultado == "Derecha conservadora") dcn++;
	else if (resultado == "Derecha liberal") dln++;
	else if (resultado == "Izquierda conservadora") icn++;
	else if (resultado == "Izquierda liberal") iln++;
	else cn++;

	cout << endl << "------------------------------------------" << endl;
	cout << "Su inclinacion politica puede ser: " << resultado << endl;
	cout << "------------------------------------------" << endl;
	cout << "\nPresione una tecla para volver al menu...";
	_getch();
}

void manager::mostrarresultados() {
	system("cls");
	cout << endl << "\t\t Robot Politico." << endl;
	cout << endl << "\t\t Reporte." << endl;
	cout << ".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-." << endl;
	cout << "IZQ Liberal : <" << iln << ">" << endl;
	cout << "IZQ Conservadora  <:" << icn << ">"<< endl;
	cout << "DER Liberal  <:" << dln << ">"<< endl;
	cout << "DER Conservadora : <" << dcn <<  ">"<<endl;
	cout << "Centro : <" << cn << ">"<< endl; 
	cout << "[Presione una tecla para ir al menu]";
	while (true) {
		if (kbhit()) {
			return;
		}
	}
};