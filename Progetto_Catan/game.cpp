#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "bioma.h"
#include "utente.h"
#include <vector>
using namespace std;
bool placing;
int oldy, oldx, current_ladro;
vector<int> gioco(int);
sf::Texture pulsante;
sf::Sprite pulsante_sprite(pulsante);
void inizializzazione_pulsante(sf::RenderWindow& window) {
    pulsante.loadFromFile("./media/pulsante.png");
}


int id(sf::RenderWindow& window) {
    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    int x = localPosition.x;
    int y = localPosition.y;
    if (x >= 0 && x <= 1100 && y >= 0 && y <= 800) {
        sf::Image image;
        image.loadFromFile("./media/board.png");
        sf::Color pixelColor = image.getPixel(sf::Vector2u(x, y));
        int a = pixelColor.a;
        if (a >= 212) { a--; }
        return a;
    }
    else { return -1; }
}

vector<int> gioco(int colore) {
    int i, j;
    int type;
    i = 0;
    j = 0;
    type = 0;
	vector<int> risorsa;
    /*
    lato: 1
	esagono: 2
    */
    if (colore != 0) {
        for (int r = 0; r < 11; ++r) {
            for (int c = 0; c < 21; ++c) {
                if (board[r][c] != nullptr ) {
                    if (board[r][c]->get_colore() == colore) {
                        i = r;
                        j = c;
                        if (board[r][c]->get_stato() == 'v') {
                            type = 3;
                        }
                        else {
                            type = 1;
                        }
                    }
                }
            }
        }
        for (int r = 0; r < 5; ++r) {
            for (int c = 0; c < 11; ++c) {
                if (mappa[r][c] != nullptr ) {
                    if (mappa[r][c]->get_colore() == colore) {
                        i = r;
                        j = c;
                        type = 2;
                    }
                }
            }
        }
    }
    if (colore == 150 ) { type = 4; }//pulsante turno
    
	risorsa = { i, j, type };
	return risorsa;
}
int Tiro_dadi() {
    int a = 0;
    srand(time(NULL));
    int dado1 = (std::rand() % 6) + 1; // valore tra 1 e 6
    int dado2 = (std::rand() % 6) + 1; // valore tra 1 e 6
    a = dado1 + dado2;
    if (a == 7) {
        cout << "Hai tirato un 7! nessuna risorsa viene prodotta " << endl;
        cout << "Clicca l'esagono su cui vuoi spostare il ladro" << endl; // per coma: meccanismo ladro
        //ladro();
        placing = true;
    }
    else {
        cout << "Tiro di dadi effettuato: la somma dei dadi e': " << a << endl;
    }
    return a;
}


void aggiungi_risorse(utente* giocatore1, utente* giocatore2) {
	int numero_estratto = Tiro_dadi();
    int tipo_risorsa;
	vector<int> numeri;
    if (numero_estratto != 7) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (mappa[i][j] != nullptr) {
                    if (mappa[i][j]->get_numero() == numero_estratto && mappa[i][j]->get_colore()!=current_ladro) {
                        numeri.push_back(mappa[i][j]->get_colore());

                    }
                }
            }
        }
        giocatore1->aggiunta_risorsa2(numeri);
        giocatore2->aggiunta_risorsa2(numeri);
    }
}
//1= red 2= blue
void aggiungi_colore(int i,int j, utente* giocatore1, utente* giocatore2) {
    int a, b;
    a = i+1;
    b = j;
    if (board[a][b] != nullptr) { if (board[a][b]->get_stato() == 'e') {if (turno == 'r') {giocatore1->aggiungi_numero(board[a][b]->get_colore()); } else {giocatore2->aggiungi_numero(board[a][b]->get_colore()); } } }
    a = i - 1;
    b = j +2;
    if (board[a][b] != nullptr) { if (board[a][b]->get_stato() == 'e') {if (turno == 'r') {giocatore1->aggiungi_numero(board[a][b]->get_colore()); } else {giocatore2->aggiungi_numero(board[a][b]->get_colore()); } } }
    a = i - 1;
    b = j - 2;
    if (board[a][b] != nullptr) { if (board[a][b]->get_stato() == 'e') {if (turno == 'r') {giocatore1->aggiungi_numero(board[a][b]->get_colore()); } else {giocatore2->aggiungi_numero(board[a][b]->get_colore()); } } }
    a = i - 1;
    b = j;
    if (board[a][b] != nullptr) { if (board[a][b]->get_stato() == 'e') {if (turno == 'r') {giocatore1->aggiungi_numero(board[a][b]->get_colore()); } else {giocatore2->aggiungi_numero(board[a][b]->get_colore()); } } }
    a = i + 1;
    b = j + 2;
    if (board[a][b] != nullptr) { if (board[a][b]->get_stato() == 'e') {if (turno == 'r') {giocatore1->aggiungi_numero(board[a][b]->get_colore()); } else {giocatore2->aggiungi_numero(board[a][b]->get_colore()); } } }
    a = i + 1;
    b = j - 2;
    if (board[a][b] != nullptr) { if (board[a][b]->get_stato() == 'e') {if (turno == 'r') {giocatore1->aggiungi_numero(board[a][b]->get_colore()); } else {giocatore2->aggiungi_numero(board[a][b]->get_colore()); } } }
}

void event_handler(sf::RenderWindow& window, utente* giocatore1, utente* giocatore2) {
    int colore = id(window);
    if (colore == -1) {
        return;
    }
    vector<int> coso = gioco(colore);
    int risorsa = coso[2];
    int i = coso[0];
    int j = coso[1];
	int type = coso[2];
    if (!placing) {
        if (coso[2] != 0) {
            switch (iniziale) {
            case 6:
                if (giocatore1->piazza_insediamenti(i, j)) {
                    board[i][j]->set_player(turno);
                    aggiungi_colore(i, j, giocatore1, giocatore2);
                    iniziale--;
                }
                break;
            case 5:
                if (giocatore1->piazza_strada(i, j)) {
                    board[i][j]->set_player(turno);
                    iniziale--;
                }
                break;
            case 4:
                if (giocatore1->piazza_strada(i, j)) {
                    board[i][j]->set_player(turno);
                    iniziale--;
                    turno = 'b';
                }
                break;
            case 3:
                if (giocatore2->piazza_insediamenti(i, j)) {
                    board[i][j]->set_player(turno);
                    aggiungi_colore(i, j, giocatore1, giocatore2);
                    iniziale--;
                }
                break;
            case 2:
                if (giocatore2->piazza_strada(i, j)) {
                    board[i][j]->set_player(turno);
                    iniziale--;
                }
                break;
            case 1:
                if (giocatore2->piazza_strada(i, j)) {
                    board[i][j]->set_player(turno);
                    iniziale--;
                    turno = 'r';
                    stato_turno = 1;
                    return;
                }
                break;

            }
            /*
            1: generazione risorse
            2: piazzamento edifici
            3: piazzamento strade
            */
            if (iniziale == 0) {
                switch (turno) {
                case 'r':

                    if (giocatore1->piazza_insediamenti(i, j) || giocatore1->piazza_strada(i, j) || giocatore1->piazza_citta(i, j)) {
                        cout << "1 " << endl;
                        if (giocatore1->piazza_insediamenti(i, j)) { aggiungi_colore(i, j, giocatore1, giocatore2); }
                        cout << "4 " << endl;
                        board[i][j]->set_player(turno);
                        turno = 'b';
                    }
                    break;
                case 'b':
                    if (giocatore2->piazza_insediamenti(i, j) || giocatore2->piazza_strada(i, j) || giocatore2->piazza_citta(i, j)) {
                        cout << "2 " << endl;
                        if (giocatore2->piazza_insediamenti(i, j)) { aggiungi_colore(i, j, giocatore1, giocatore2); }
                        cout << "3 " << endl;
                        board[i][j]->set_player(turno);
                        turno = 'r';
                        aggiungi_risorse(giocatore1, giocatore2);
                    }
                    break;
                }
            }
        }
    }
    else {
        if (type == 2) {
            for (int r = 0; r < 5; ++r) {
                for (int c = 0; c < 11; ++c) {
                    if (mappa[r][c] != nullptr) {
                        if (mappa[r][c]->get_colore() == colore) {
                            mappa[r][c]->set_ladro(true);
                            if (oldx != 0 && oldy != 0) {
                                mappa[oldy][oldx]->set_ladro(false); // rimuove il ladro dal vecchio esagono
                            }
							oldx = c;
							oldy = r;
                            current_ladro = colore;
                            placing = false;

                        }
                    }
                }
            }
        }
    }
	if (type == 4&&iniziale==0) { // pulsante turno
		if (turno == 'r') {
			turno = 'b';
		}
		else {
			turno = 'r';
			aggiungi_risorse(giocatore1, giocatore2);
		}
	}
}

void tasto(sf::RenderWindow& window, int a) {
    sf::Texture pulsante;
   pulsante.loadFromFile("./media/pulsante.png");
    sf::Sprite pulsante_sprite(pulsante);
    int colore = id(window);
	if (colore == -1) {
		return;
	}
    if(colore==150){
		window.draw(pulsante_sprite);
        if (a == 0) { window.display(); }
    }

}