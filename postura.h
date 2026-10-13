#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class postura {
protected:
	vector<string> pregunta;
public:
	postura() {
		pregunta = {};
	};
	~postura() {};
	virtual void agregarpregunta() {};
	void mostrarpregunta() {
		int n = rand() % pregunta.size();
		cout << pregunta[n];
	};
};
