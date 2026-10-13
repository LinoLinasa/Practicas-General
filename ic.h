#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "postura.h"

using namespace std;

class ic : public postura {
public:
	void agregarpregunta() {
		pregunta.push_back("Cree que el estado no debe financiar a la iglesia?");
		pregunta.push_back("Cree que el estado no actuar con valores a la hora de gobernar?");
	}
	ic() : postura() {
		agregarpregunta();
	}
	~ic() {};

};