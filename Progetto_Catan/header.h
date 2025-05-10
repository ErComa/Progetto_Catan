#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"

//classi per la board
const int righe = 11;
const int colonne = 21;

char griglia[righe][colonne] = {
		{'o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o'},
		{'o','o','o','o','o','o','o','o','l','o','o','o','l','o','o','o','o','o','o','o','o'},
		{'o','o','o','o','o','g','v','s','v','g','v','s','v','g','v','s','o','o','o','o','o'},
		{'o','o','o','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','o','o','o'},
		{'o','o','o','g','v','s','v','g','v','s','v','g','v','s','v','g','v','s','o','o','o'},
		{'o','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','o'},
		{'o','o','o','s','v','g','v','s','v','g','v','s','v','g','v','s','v','g','o','o','o'},
		{'o','o','o','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','o','o','o'},
		{'o','o','o','o','o','g','v','s','v','g','v','s','v','g','v','s','o','o','o','o','o'},
		{'o','o','o','o','o','o','o','o','l','o','o','o','l','o','o','o','o','o','o','o','o'},
		{'o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o'},
};
int colori[19] = {210,209,208,207,206,205,204,203,202,201,200,199,198,197,196,195,194,193,192};
int tipo[19] = {4,    3,   1,   5,  2,  3,  2,  5,  1,  6,  1,  4,  1,  4,  5,  3,  2,  5,  3};
/*
biomi: 1-5 biomi normali e 6 deserto, paralleli al tipo di risorsa
1: legno verdescuro   
2: mattoni arancione  
3: LE PECORE verdechiaro 
4: iron grigio 
5: grano giallo qualcosa del genere  
6: deserto 
*/

int griglia[5][10] = {
	   {-1,-1,0,-1,0,-1,0,-1,-1,-1},
	   {-1,0,-1,0,-1,0,-1,0,-1,-1},
	   {0,-1,0,-1,0,-1,0,-1,0,-1},
	   {-1,0,-1,0,-1,0,-1,0,-1,-1},
	   {-1,-1,0,-1,0,-1,0,-1,-1,-1},
};

class bioma {
private:
	int type;
	int numero;
	int colore;
public:
	bioma(int a, int b, int c): type(a), numero(b),colore(c){}
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
	char stato;// tah se e villaggio o casa o boh
	int colore;// opacita pixel perche si
public:
	coso(char a, int b) : stato(a), colore(b) {}
	char get_stato() { return stato; }
	int get_colore() { return colore; }
	void set_colore(int a) { colore = a; }
};

class numero {
public:
	numero(int a) : num(a), assegnato(0){}
	int num;
	bool assegnato;
};

coso* board[11][21];
bioma* mappa[5][10];
numero* numeri[19];













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