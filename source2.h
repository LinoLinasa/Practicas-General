#pragma once
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<ctime>
#include "clasecontroladora.h"

using namespace std;
using namespace System;

void ejerciciotiempo() {
	srand(time(nullptr));
	//para agregar ascii actual
	SetConsoleOutputCP(CP_UTF8);
	manager1* hi = new manager1;

	hi->jugar();
}