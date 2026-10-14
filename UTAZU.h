#pragma once
#include "viajero.h"

class UTAZU : public viajero {
public:
    UTAZU(bool tiempo, int x, int y, int llegarx, int llegary) : viajero("", tiempo, x, y, 0, 0, llegarx, llegary, 'V') {
        asignarmensaje();
    }
    ~UTAZU() {};

    void asignarmensaje() override {
        if (tiempo) { mensaje = "La educación en nuestro país es similar al primer mundo "; }
        else { mensaje = "el 2033 es un año con buena economía"; }
    }
    void dibujar() {
        string hola[] = {
        "  0  ",
        "<=▓=>",
        "  ╩"
        };
        for (int i = 0; i < 3; i++)
        {
            Console::SetCursorPosition(x, y + i); cout << hola[i];
        }
    }
};