#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "postura.h"

using namespace std;

class dc : public postura {
public:
	void agregarpregunta() {
		pregunta.push_back("Cree que el estado debe financiar a la iglesia?");
		pregunta.push_back("Cree que el estado debe actuar con valores a la hora de gobernar?");
	}
	dc() : postura() {
		agregarpregunta();
	}
	~dc() {};

};