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
    srand(time(NULL));
    int dado1 = (std::rand() % 6) + 1; // valore tra 1 e 6
    int dado2 = (std::rand() % 6) + 1; // valore tra 1 e 6
	cout << "Tiro di dadi effettuato: valore1: " << dado1 << " valore2: " << dado2 << endl;
    return dado1 + dado2;
}
