#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "bioma.h"
using namespace std;
int gioco(int);

int id(sf::RenderWindow& window) {
    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    int x = localPosition.x;
    int y = localPosition.y;
	sf::Image image;
	image.loadFromFile("./media/board.png");
	sf::Color pixelColor = image.getPixel(sf::Vector2u(x, y));
	return pixelColor.a;	
}

int gioco(int colore) {
    int i, j;
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
					return 3;
				}
				else {
					return 1;
				}
            }
        }
    }
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 11; ++c) {
            if (mappa[r][c] != nullptr && mappa[r][c]->get_colore() == colore) {
                i = r;
                j = c;
				return 2;
            }
        }
    }
}

void event_handler(sf::RenderWindow& window) {
	int colore = id(window);
	int risorsa = gioco(colore);
    switch (stato_turno) {
    case 0:

        break;
    }

}
