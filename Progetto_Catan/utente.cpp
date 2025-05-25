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
	bool trovato = false;
	for (int i = 0; i < numeri_.size(); ++i) {
		if (numeri_[i] == a) {
			trovato = true;
		}
	}
	if(!trovato){ numeri_.push_back(a); }
}
int identifica_risorsa(int a) {
	cout << "identificazione risorsa " << endl;
	for (int i = 0; i < 19; ++i) {
		if (a == colori[i]) {
			return tipo[i];
		}
	}
}
void utente::aggiunta_risorsa2(vector<int> numeri2) {
	int b;
	for (int i = 0; i < numeri2.size(); i++) {
		for (int x = 0; x < numeri_.size(); x++) {
			if (numeri2[i] == numeri_[x]) {
				b = identifica_risorsa(numeri2[i]);
				switch (b) {
				case 1: // legno
					risorse[1]++;
					cout << "Aggiunta legno" << endl;
					break;
				case 2: // mattoni
					risorse[2]++;
					cout << "Aggiunta mattoni" << endl;
					break;
				case 3: // lana
					risorse[3]++;
					cout << "Aggiunta lana" << endl;
					break;
				case 4: // minerale
					cout << "Aggiunta minerale" << endl;
					risorse[4]++;
					break;
				case 5: // grano
					cout << "Aggiunta grano" << endl;
					risorse[5]++;
					break;
				case 6: // deserto, non aggiunge risorsa
					break;
				default:
					cout << "Errore nell'aggiunta delle risorse" << endl;
				}
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
	cout << "Numero ";
	for (int i = 0; i < numeri_.size(); ++i) {
		cout << " "<< numeri_[i];
	}
	cout << endl;
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
