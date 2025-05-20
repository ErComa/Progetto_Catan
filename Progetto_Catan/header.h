#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"

//classi per la board
const int righe = 11;
const int colonne = 21;

void inizializzazione_board();
void inizializzazione_biomi();
void assegnazione_numeri();
void print(sf::RenderWindow& window);

extern char griglia[righe][colonne];
extern int colori[19];
extern int tipo[19];
extern int griglia_biomi[5][10];

class coso {
protected:
	char stato;// tah se e villaggio o casa o boh
	int colore;// opacita pixel perche si
	char player;
public:
	coso(char a, int b) : stato(a), colore(b), player('r') {}
	char get_stato() { return stato; }
	int get_colore() { return colore; }
	void set_colore(int a) { colore = a; }
	char get_player() { return player; }
	void set_player(char a) { player = a; }
	void set_stato(char a) { stato = a; }
};

class numero {
public:
	numero(int a) : num(a), assegnato(0){}
	int num;
	bool assegnato;
};

extern coso* board[11][21];
extern numero* numeri[19];













/*
board completa da implementare se ho tempo
char griglia[righe][colonne] = {
		{'o','o','o','o','v','s','v','g','v','s','v','g','v','s','v','g','v','o','o','o','o'},
		{'o','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','o'},
		{'o','o','v','s','v','g','v','s','v','g','v','s','v','g','v','s','v','g','v','s','o'},
		{'o','o','l','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','l','o','o'},
		{'v','s','v','g','v','s','v','g','v','s','v','g','v','s','v','g','v','s','v','g','v'},
		{'l','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','l'},
		{'v','g','v','s','v','g','v','s','v','g','v','s','v','g','v','s','v','g','v','s','v'},
		{'o','o','l','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','l','o','o'},
		{'o','o','v','g','v','s','v','g','v','s','v','g','v','s','v','g','v','s','v','o','o'},
		{'o','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','o'},
		{'o','o','o','o','v','g','v','s','v','g','v','s','v','g','v','s','v','o','o','o','o'},
};
*/