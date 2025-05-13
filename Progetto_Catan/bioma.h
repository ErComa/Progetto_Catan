#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"

class bioma {
private:
	int type;
	int numero;
	int colore;
public:
	bioma(int, int, int);
	int get_type();
	int produzione_risorsa();
};

bioma* mappa[5][10];
