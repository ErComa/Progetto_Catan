#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"


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
	bool piazza_insediamenti();
	bool piazza_strada();
	bool piazza_citta();
	void aggiungi_risorsa(int);
	void aggiungi_insediamenti();
	void aggiungi_strade();
	void aggiungi_citta();
	void aggiungi_numero(int);
};
