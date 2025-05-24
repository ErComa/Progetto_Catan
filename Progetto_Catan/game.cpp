#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "bioma.h"
#include "utente.h"
#include <vector>
using namespace std;
vector<int> gioco(int);

int id(sf::RenderWindow& window) {
    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    int x = localPosition.x;
    int y = localPosition.y;
	sf::Image image;
	image.loadFromFile("./media/board.png");
	sf::Color pixelColor = image.getPixel(sf::Vector2u(x, y));
	int a = pixelColor.a;
    if (a >= 212) { a--; }
	return a;	
}

vector<int> gioco(int colore) {
    int i, j;
    int type;
	vector<int> risorsa;
    /*
    lato: 1
	esagono: 2
    */
    for (int r = 0; r < 11; ++r) {
        for (int c = 0; c < 21; ++c) {
            if (board[r][c] != nullptr && board[r][c]->get_colore() == colore) {
                i = r;
				j = c;
				if (board[r][c]->get_stato() == 'v') {
					type= 3;
				}
				else {
					type = 1;
				}
            }
        }
    }
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 11; ++c) {
            if (mappa[r][c] != nullptr && mappa[r][c]->get_colore() == colore) {
                i = r;
                j = c;
				type = 2;
            }
        }
    }
	risorsa = { i, j, type };
	return risorsa;
}

void event_handler(sf::RenderWindow& window, utente* giocatore1, utente* giocatore2) {
	int colore = id(window);
	vector<int> coso = gioco(colore);
	int risorsa = coso[2];
	int i = coso[0];
	int j = coso[1];
    
        switch (iniziale) {
        case 6:
            
            if (giocatore1->piazza_insediamenti(i, j)) {
				board[i][j]->set_player(turno);
                iniziale--;
            }
            break;
		case 5:
            if (giocatore2->piazza_strada(i, j)) {
                board[i][j]->set_player(turno);
				iniziale--;
            }
            break;
        case 4:
            if (giocatore2->piazza_strada(i, j)) {
                board[i][j]->set_player(turno);
                iniziale--;
                turno = 'b';
            }
            break;
		case 3:
            if (giocatore1->piazza_insediamenti(i, j)) {
                board[i][j]->set_player(turno);
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
            }
            break;

        }
    

}
