#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "viajero.h"
#include "VIATGER .h"
#include "KANAKA.h"
#include "UTAZU.h"

using namespace std;
using namespace System;

class manager1 {
private:
    vector<viajero*> listaViajeros;
    int numViajeros;
    int contadorTiempo;
    int tiempoAgujero;

public:
    manager1() {
        Console::CursorVisible = false;
        numViajeros = (rand() % 3) + 1;
        contadorTiempo = 0;
        tiempoAgujero = 180;

        inicializar();
    }

    ~manager1() {
        for (size_t i = 0; i < listaViajeros.size(); i++) {
            delete listaViajeros[i];
        }
        listaViajeros.clear();
    }

    void inicializar() {
        int anchoPantalla = 100;
        int seccion = anchoPantalla / numViajeros;

        for (int i = 0; i < numViajeros; i++) {
            // Posición inicial centrada en la sección
            int posX = (i * seccion) + (seccion / 2) - 2;
            int posY = 10;

            // Coordenadas del punto de llegada (fondo de pantalla)
            int llegarX = (i * seccion) + (seccion / 2) - 1;
            int llegarY = 22;

            bool provienePasado = (rand() % 2 == 0);

            // Selección aleatoria del tipo de viajero
            int tipoRandom = rand() % 3;
            if (tipoRandom == 0) {
                listaViajeros.push_back(new VIATGER(provienePasado, posX, posY, llegarX, llegarY));
            }
            else if (tipoRandom == 1) {
                listaViajeros.push_back(new KANAKA(provienePasado, posX, posY, llegarX, llegarY));
            }
            else {
                listaViajeros.push_back(new UTAZU(provienePasado, posX, posY, llegarX, llegarY));
            }
        }
    }

    void dibujarEscenario() {
        system("cls");

        // Título de la pantalla
        Console::SetCursorPosition(38, 0);
        Console::ForegroundColor = ConsoleColor::Yellow;
        cout << "MAQUINA DEL TIEMPO";
        Console::ResetColor();

        // División vertical de la pantalla si hay 2 o 3 viajeros
        int anchoPantalla = 100;
        int seccion = anchoPantalla / numViajeros;

        if (numViajeros > 1) {
            Console::ForegroundColor = ConsoleColor::DarkGray;
            for (int i = 1; i < numViajeros; i++) {
                int col = i * seccion;
                for (int fila = 2; fila < 24; fila++) {
                    Console::SetCursorPosition(col, fila);
                    cout << "|";
                }
            }
            Console::ResetColor();
        }

        // Dibujar metas y viajeros en su posición inicial
        for (auto v : listaViajeros) {
            v->dibujarpuntodellegada();
            v->dibujar();
        }
    }

    void dibujarAgujeroGusano() {
        Console::SetCursorPosition(85, 1);
        Console::ForegroundColor = ConsoleColor::Red;
        cout << "(■) AGUJERO DE GUSANO";
        Console::ResetColor();
    }

    void jugar() {
        dibujarEscenario();

        bool finJuego = false;
        string mensajeExito = "";

        // Leyenda de ayuda de controles
        Console::SetCursorPosition(2, 25);
        Console::ForegroundColor = ConsoleColor::DarkYellow;
        cout << "Controles -> VIATGER [W,A,S,D] | KANAKA [Flechas/I,J,K,L] | UTAZU [8,4,5,6/T,F,G,H]";
        Console::ResetColor();

        while (!finJuego) {
            // 1. Contador de tiempo para la condición de derrota (Agujero de Gusano)
            contadorTiempo++;
            if (contadorTiempo >= tiempoAgujero) {
                dibujarAgujeroGusano();
                Console::SetCursorPosition(2, 24);
                Console::ForegroundColor = ConsoleColor::Red;
                cout << "¡Un agujero de gusano ha aparecido y absorbio a todos los viajeros!";
                Console::ResetColor();
                finJuego = true;
                break;
            }

            // 2. Evento de teclado
            if (_kbhit()) {
                char tecla = _getch();

                if (tecla == 224 || tecla == 0) { // Manejo de teclas especiales (Flechas direccionales)
                    tecla = _getch();
                }

                // Mover los viajeros
                for (auto v : listaViajeros) {
                    v->mover(tecla);

                    // 3. Validar condición de victoria (Llegar al punto final)
                    if (v->llego()) {
                        mensajeExito = v->getmensaje();
                        finJuego = true;
                        break;
                    }
                }
            }

            Sleep(50); // Mantiene una velocidad de juego estable
        }

        // Desplegar el mensaje traído por el viajero si cumplió la misión
        if (!mensajeExito.empty()) {
            Console::SetCursorPosition(2, 24);
            Console::ForegroundColor = ConsoleColor::Green;
            cout << "¡MENSAJE ENTREGADO!: \"" << mensajeExito << "\"";
            Console::ResetColor();
        }

        Console::SetCursorPosition(2, 26);
        cout << "\nPresione una tecla para finalizar...";
        _getch();
    }
};