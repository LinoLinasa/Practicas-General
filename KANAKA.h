#pragma once
#include "viajero.h"

class KANAKA : public viajero {
public:
    KANAKA(bool tiempo, int x, int y, int llegarx, int llegary) : viajero("", tiempo, x, y, 0, 0, llegarx, llegary, 'K') {
        asignarmensaje();
    }
    ~KANAKA() {};

    void asignarmensaje() override {
        if (tiempo) { mensaje = "Christian Cueva no se perdió el penal en el mundial Rusia 2018";}
        else { mensaje = "el 2035 habrá otra pandemia";}
    }

    void dibujar() {
        string hola[] = {
        "  @  ",
        "|=▒=|",
        "  ╩"
        };
        for (int i = 0; i < 3; i++)
        {
            Console::SetCursorPosition(x, y + i); cout << hola[i];
        }
    }
};