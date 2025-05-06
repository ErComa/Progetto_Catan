#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"

//classi per la board
const int righe = 11;
const int colonne = 21;

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
/*
biomi: 1-5 biomi normali e 6 deserto, paralleli al tipo di risorsa
*/

int biomi[5][10] = {
		{-1, 0, 0, 0, -1},
		{0, 0, 0, 0, -1},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, -1},
		{-1, 0, 0, 0, -1}
};
class bioma {
private:
	int type;
	int risorsa;
public:
	bioma(int a, int b): type(a), risorsa(b){}
	int get_type() { return type; }
	int produzione_risorsa();
};

class utente {
private:
	int villaggi;
	int citta;
	int strade;
	int risorse[5];
public:
	utente();
	int get_villaggi() { return villaggi; }
	int get_citta() { return citta; }
	int get_strade() { return strade; }
	int get_risorse(int a) { return risorse[a]; }
	bool piazza_villaggio();
	bool piazza_strada();
	bool piazza_citta();
	void aggiungi_risorsa(int);
};

class coso {
protected:
	char stato;
	int colore;//player
public:
	coso(char a) : stato(a), colore(0) {}
	char get_stato() { return stato; }
	int get_colore() { return colore; }
	void set_colore(int a) { colore = a; }
};

coso* board[11][21];