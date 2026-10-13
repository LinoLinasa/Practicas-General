#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "postura.h"

using namespace std;

class il : public postura {
public:
	void agregarpregunta() {
		pregunta.push_back("Cree que el estado no debe financiar a la iglesia?");
		pregunta.push_back("Cree que el estado debe tomar en cuenta a los valores de todas las iglesias a la hora de gobernar?");
	} 
	il() : postura() {
		agregarpregunta();
	}
	~il() {};
};
