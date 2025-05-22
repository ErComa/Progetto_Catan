#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "utente.h"
using namespace std;
utente::utente(){
	insediamenti = 1;
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
	if (risorse[1] > 0 && risorse[2] > 0 && risorse[3] > 0 && risorse[5] > 0) {
		risorse[1]--;
		risorse[2]--;
		risorse[3]--;
		risorse[5]--;
		return true;
	}
	else {
		return false;
	}
}
bool utente::piazza_strada() {
	if (strade > 0) {
		strade--;
		return true;
	}
	if (risorse[1] > 0 && risorse[2] > 0) {
		risorse[1]--;
		risorse[2]--;
		return true;
	}
	else { return false; }
	
}
bool utente::piazza_citta() {
	if (risorse[4] > 3 && risorse[5] > 2) {
		risorse[4]-=3;
		risorse[5]-=2;
		return true;
	}
	else { return false; }
	
}
void utente::aggiungi_risorsa(int a) {
	risorse[a]++;
}

void utente::aggiungi_numero(int a) {
	numeri.push_back(a);
}

/*
biomi: 1-5 biomi normali e 6 deserto, paralleli al tipo di risorsa
1: legno verdescuro
2: mattoni arancione
3: lana verdechiaro
4: minerale grigio
5: grano giallo qualcosa del genere
6: deserto
Strade (richiedono 1 mattone e 1 legno).
Villaggi (richiedono 1 mattone, 1 legno, 1 lana e 1 grano).
Città (richiedono 3 minerali e 2 grani, e sostituiscono un villaggio).
Carte sviluppo (richiedono 1 minerale, 1 lana e 1 grano).
*/
