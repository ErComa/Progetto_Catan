#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "utente.h"
using namespace std;
utente::utente(){}
int utente::get_villaggi() { return villaggi; }
int utente::get_citta() { return citta; }
int utente::get_strade() { return strade; }
int utente::get_risorse(int a) { return risorse[a]; }

