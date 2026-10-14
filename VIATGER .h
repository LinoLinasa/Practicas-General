#pragma once
#include "viajero.h"

class VIATGER : public viajero {
public:
    VIATGER(bool tiempo, int x, int y, int llegarx, int llegary) : viajero("", tiempo, x, y, 0, 0, llegarx, llegary, 'V') {
        asignarmensaje();
    }
    ~VIATGER() {};

    void asignarmensaje () override {
        if (tiempo) { mensaje = "El virus Covid19 sólo fue una epidemia"; }
        else { mensaje = "viajes tripulados a marte"; }
    }
    void dibujar() {
        string hola[] = {

        "  @  ",
        "(-█-)",
        "  ┴  "
        };
        for (int i = 0; i < 3; i++)
        {
            Console::SetCursorPosition(x, y + i); cout << hola[i];
        }
    }
};