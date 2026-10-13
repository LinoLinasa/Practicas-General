#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "postura.h"

using namespace std;

class c : public postura {
public:
	void agregarpregunta() {
		pregunta.push_back("Te consideras de mente abierta?");
		pregunta.push_back("Eres socialmente sencible?");
	}
	c() : postura() {
		agregarpregunta();
	}
	~c() {};

};