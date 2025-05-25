#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "utente.h"
#include <vector>
using namespace std;
utente::utente(){
	insediamenti = 1;
	citta = 0;
	strade = 2;
	for (int i = 0; i < 6; ++i) {
		risorse[i] = 200;
	}

}
int utente::get_insediamenti() { return insediamenti; }
int utente::get_citta() { return citta; }
int utente::get_strade() { return strade; }
int utente::get_risorse(int a) { return risorse[a]; }
bool utente::piazza_insediamenti(int i, int j) {
	if (insediamenti > 0 && iniziale >0 && piazzamento_insediamenti(i, j)) {
		insediamenti--;
		return true;
	}
	if (risorse[1] > 0 && risorse[2] > 0 && risorse[3] > 0 && risorse[5] > 0 && piazzamento_insediamenti(i,j)) {
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
bool utente::piazza_strada(int i, int j) {
	if (strade > 0 && iniziale > 0 && piazzamento_strade(i, j)) {
		strade--;
		return true;
	}
	if (risorse[1] > 0 && risorse[2] > 0 && piazzamento_strade(i, j)) {
		risorse[1]--;
		risorse[2]--;
		return true;
	}
	else { return false; }
	
}
bool utente::piazza_citta(int i, int j) {
	if (risorse[4] > 3 && risorse[5] > 2&&piazzamento_citta(i,j)) {
		risorse[4]-=3;
		risorse[5]-=2;
		board[i][j]->set_tipo('c');
		return true;
	}
	else { return false; }
	
}
void utente::aggiungi_risorsa(int a) {
	risorse[a]++;
}

void utente::aggiungi_numero(int a) {
	numeri_.push_back(a);
}

void utente::aggiunta_risorsa(vector<int> numeri2, vector<int> risorse2) {
	int a;
	for (int i = 0; i < numeri2.size(); ++i) {
		cout << "funge diobestia";
		if(i<numeri_.size()){
			if (numeri_[i] == numeri2[i]) {
				cout << "risorsa aggiunta: " << i << endl;
				risorse[risorse2[i]]++;
			}
		}
	}
	
}
void utente::stampa_risorse() {
	cout << "Risorsa ";
	for (int i = 0; i < 6; ++i) {
		cout<< i << ": " << risorse[i]<<" ";
	}
	cout << endl;
}

void utente::stampa_numeri() {
	for (int i = 0; i < numeri_.size(); ++i) {
		cout << "Numero " << i << ": " << numeri_[i] << endl;
	}
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
