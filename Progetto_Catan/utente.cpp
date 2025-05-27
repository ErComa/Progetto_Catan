#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "bioma.h"
#include "utente.h"
#include <vector>
using namespace std;
utente::utente() {
	insediamenti = 1;
	citta = 0;
	strade = 2;
	punteggio = 0;
	for (int i = 0; i < 6; ++i) {
		risorse[i] = 200;
	}
}
int utente::get_insediamenti() { return insediamenti; }
int utente::get_citta() { return citta; }
int utente::get_strade() { return strade; }
int utente::get_risorse(int a) { return risorse[a]; }
bool utente::piazza_insediamenti(int i, int j) {
	if (insediamenti > 0 && iniziale > 0 && piazzamento_insediamenti(i, j)) {
		insediamenti--;
		punteggio++;
		return true;
	}
	if (risorse[1] > 0 && risorse[2] > 0 && risorse[3] > 0 && risorse[5] > 0 && piazzamento_insediamenti(i, j)) {
		risorse[1]--;
		risorse[2]--;
		risorse[3]--;
		risorse[5]--;
		punteggio++;
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
	if (risorse[4] > 3 && risorse[5] > 2 && piazzamento_citta(i, j)) {
		risorse[4] -= 3;
		risorse[5] -= 2;
		board[i][j]->set_tipo('c');
		punteggio++;
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
		if (!trovato) { numeri_.push_back(a); }
	}
	int identifica_risorsa(int a) {
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
						break;
					case 2: // mattoni
						risorse[2]++;
						break;
					case 3: // lana
						risorse[3]++;
						break;
					case 4: // minerale
						risorse[4]++;
						break;
					case 5: // grano
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
			cout << i << ": " << risorse[i] << " ";
		}
		cout << endl;
	}

	void utente::stampa_numeri() {
		cout << "Numero ";
		for (int i = 0; i < numeri_.size(); ++i) {
			cout << " " << numeri_[i];
		}
		cout << endl;
	}
	void utente::stampa_punteggio(sf::RenderWindow& window, int a ) {
		int x, y;
		x = 982;
		if (a == 1) { y = 99; }
		else { y = 419; }
		sf::Font font;
		font.openFromFile("./media/arial.ttf");
		sf::Text text(font);
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::White);
		text.setPosition(sf::Vector2f(x, y));
		text.setString(std::to_string(punteggio));
		window.draw(text);

	}
	void utente::stampa_risorse_utente(sf::RenderWindow& window, int a) {
		int array1[5] = { 924,945,914,954,929 };
		int x, y;
		sf::Font font;
		font.openFromFile("./media/arial.ttf");
		sf::Text text(font);
		text.setCharacterSize(14);
		text.setFillColor(sf::Color::White);
		
		for (int i = 0;i < 5;i++) {
			y = 166 + i * 26;
			if (a == 1) { x = array1[i];y = 166 + i * 26;
			}
			else {x = array1[i]-1;y = 487 + i * 26;
			}
			text.setPosition(sf::Vector2f(x, y));
			text.setString(std::to_string(risorse[i]));
			window.draw(text);
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
