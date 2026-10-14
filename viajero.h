#pragma once
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
using namespace System;

class viajero {
protected:
	string mensaje;
	bool tiempo;
	int x, y, dx, dy;
	int llegarx, llegary;
	char tipo;

public:
	viajero(string mensaje, bool tiempo, int x, int y, int dx, int dy, int llegarx, int llegary, char tipo)
		: mensaje(mensaje), tiempo(tiempo), x(x), y(y), dx(dx), dy(dy), llegarx(llegarx), llegary(llegary), tipo(tipo) {
	}

	virtual ~viajero() {}
	virtual void asignarmensaje() {}
	virtual void dibujar() {}
	// SOLUCIÓN AL LNK1120: Implementar getmensaje
	string getmensaje() {
		return mensaje;
	}

	void borrar() {
		// SOLUCIÓN A LA ADVERTENCIA C6201: Definir tamaño [3] explícito
		string hola[3] = {
			"      ",
			"      ",
			"      "
		};
		for (int i = 0; i < 3; i++) {
			Console::SetCursorPosition(x, y + i);
			cout << hola[i];
		}
	}

	// SOLUCIÓN LÓGICA AL MOVIMIENTO:
	// Recibimos la tecla real desde manager1, y usamos this->tipo para saber quién se mueve.
	void mover(char tecla) {
		borrar(); // Borramos la posición antigua antes de mover

		if (this->tipo == 'V') {
			if (tecla == 'W' || tecla == 'w') y--;
			if (tecla == 'A' || tecla == 'a') x--;
			if (tecla == 'S' || tecla == 's') y++;
			if (tecla == 'D' || tecla == 'd') x++;
		}
		else if (this->tipo == 'K') {
			// Soporta tanto las flechas direccionales (72, 75, 80, 77) como I,J,K,L
			if (tecla == 72 || tecla == 'I' || tecla == 'i') y--;
			if (tecla == 75 || tecla == 'J' || tecla == 'j') x--;
			if (tecla == 80 || tecla == 'K' || tecla == 'k') y++;
			if (tecla == 77 || tecla == 'L' || tecla == 'l') x++;
		}
		else if (this->tipo == 'U') {
			if (tecla == '8' || tecla == 'T' || tecla == 't') y--;
			if (tecla == '4' || tecla == 'F' || tecla == 'f') x--;
			if (tecla == '5' || tecla == 'G' || tecla == 'g') y++;
			if (tecla == '6' || tecla == 'H' || tecla == 'h') x++;
		}

		// Límites de pantalla para que no se escapen
		if (x < 1) x++;
		if (x > 90) x--; // Reducido a 90 para que no rompa el borde de manager1
		if (y < 2) y++;
		if (y > 25) y--;

		dibujar(); // Dibujamos al viajero en su nueva posición
	}

	bool llego() {
		// Damos un pequeño margen de 1 espacio en X para que sea más fácil "colisionar" con la meta
		return (x >= llegarx - 1 && x <= llegarx + 1 && y >= llegary - 1 && y <= llegary + 1);
	}

	void dibujarpuntodellegada() {
		Console::SetCursorPosition(llegarx, llegary);
		Console::ForegroundColor = ConsoleColor::Yellow;
		cout << ".O.";
		Console::ResetColor();
	}
};