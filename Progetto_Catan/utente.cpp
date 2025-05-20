#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "utente.h"
using namespace std;
utente::utente(){
	insediamenti = 2;
	citta = 0;
	strade = 2;
	for (int i = 0; i < 5; ++i) {
		risorse[i] = 0;
	}

}
int utente::get_insediamenti() { return insediamenti; }
int utente::get_citta() { return citta; }
int utente::get_strade() { return strade; }
int utente::get_risorse(int a) { return risorse[a]; }
bool utente::piazza_insediamenti() {
	if (insediamenti > 0) {
		insediamenti--;
		return true;
	}
	else { return false; }
}
bool utente::piazza_strada() {
	if (strade > 0) {
		strade--;
		return true;
	}
	else { return false; }
}
bool utente::piazza_citta() {
	if (citta > 0) {
		citta--;
		return true;
	}
	else { return false; }
}
void utente::aggiungi_risorsa(int a) {
	risorse[a]++;
}
void utente::aggiungi_insediamenti() {
	insediamenti++;
}
void utente::aggiungi_strade() {
	strade++;
}
void utente::aggiungi_citta() {
	citta++;
}
void utente::aggiungi_numero(int a) {
	numeri.push_back(a);
}
