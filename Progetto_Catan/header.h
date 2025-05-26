#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "utente.h"

//classi per la board
const int righe = 11;
const int colonne = 21;

void inizializzazione_board();
void inizializzazione_biomi();
void assegnazione_numeri();
void print(sf::RenderWindow& window);
int id(sf::RenderWindow& window);
void overlay(sf::RenderWindow& window);
void print_vertici(sf::RenderWindow& window);
void event_handler(sf::RenderWindow& window,utente* giocatore1,utente* giocatore2);
void print_numeri(sf::RenderWindow& window);

extern char griglia[righe][colonne];
extern int colori[19];
extern int tipo[19];
extern int griglia_biomi[5][10];
extern char turno;
extern int stato_turno;
extern int iniziale;
extern bool placing;
extern int oldx, oldy, current_ladro;


class coso {
protected:
	char stato;// vertice l s g
	int colore;// opacita pixel perche si
	char player;// colore del player r b 
	char tipo;// casa o villaggio
	bool stato_bioma;
public:
	coso(char a, int b) : stato(a), colore(b), player('o'),tipo('v'), stato_bioma(false) {}
	coso(int a, bool b) : colore(a), stato_bioma(b), stato('e') {}
	char get_stato() { return stato; }
	int get_colore() { return colore; }
	void set_colore(int a) { colore = a; }
	char get_player() { return player; }
	void set_player(char a) { player = a; }
	void set_stato(char a) { stato = a; }
	char get_tipo() { return tipo; }
	void set_tipo(char a) { tipo = a; }
	bool get_stato_bioma() { return stato_bioma; }
};

class numero {
public:
	numero(int a) : num(a), assegnato(0){}
	int num;
	bool assegnato;
};

extern coso* board[11][21];
extern numero* numeri[19];
