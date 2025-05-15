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

extern bioma* mappa[5][10];


/*
biomi: 1-5 biomi normali e 6 deserto, paralleli al tipo di risorsa
1: legno verdescuro
2: mattoni arancione
3: LE PECORE verdechiaro
4: iron grigio
5: grano giallo qualcosa del genere
6: deserto
*/

