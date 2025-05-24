#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"

bool piazzamento_insediamenti(int i, int j);
bool piazzamento_strade(int i, int j);
bool piazzamento_citta(int i, int j);
class utente {
private:
	int insediamenti;
	int citta;
	int strade;
	int risorse[6];
	std::vector<int> numeri;
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
};
