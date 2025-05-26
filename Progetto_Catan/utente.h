#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include <vector>
#include <string>

bool piazzamento_insediamenti(int i, int j);
bool piazzamento_strade(int i, int j);
bool piazzamento_citta(int i, int j);
class utente {
private:
	int insediamenti;
	int citta;
	int strade;
	int risorse[6];
	int punteggio;
	std::vector<int> numeri_;
public:
	utente();
	int get_insediamenti();
	int get_citta();
	int get_strade();
	int get_risorse(int );
	bool piazza_insediamenti(int, int);
	bool piazza_strada(int, int);
	bool piazza_citta(int, int);
	void aggiungi_risorsa(int);
	void aggiungi_numero(int);
	void aggiunta_risorsa2(std::vector<int>);
	void stampa_risorse();
	void aggiungi_punteggio(int a) { punteggio += a; }
    void stampa_punteggio(sf::RenderWindow& window, int);
	void stampa_risorse_utente(sf::RenderWindow& window, int);
	void stampa_numeri();
};
