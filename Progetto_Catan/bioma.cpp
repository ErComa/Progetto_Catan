#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>   
#include <ctime>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "bioma.h"
using namespace std;

bioma::bioma(int a, int b, int c) : type(a), numero(b), colore(c) {}
int bioma::get_type() { return type; }
int bioma::Tiro_dadi() {
	int a = 0;
    srand(time(NULL));
    int dado1 = (std::rand() % 6) + 1; // valore tra 1 e 6
    int dado2 = (std::rand() % 6) + 1; // valore tra 1 e 6
	a = dado1 + dado2;
	if (a == 7) {
		cout << "Hai tirato un 7! nessuna risorsa viene prodotta " << endl;
		cout << "Clicca l'esagono su cui vuoi spostare il ladro" << endl; // per coma: meccanismo ladro
		//ladro();
	}
	else {
		cout << "Tiro di dadi effettuato: la somma dei dadi e': " << a << endl;
	}
    return a;
}
