#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "bioma.h"
using namespace std;

int id(sf::RenderWindow& window) {
    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    int x = localPosition.x;
    int y = localPosition.y;
	sf::Image image;
	image.loadFromFile("./media/board.png");
	sf::Color pixelColor = image.getPixel(sf::Vector2u(x, y));
	return pixelColor.a;	
}

void gioco(int colore) {
    int i, j;
    int stato =0;
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
					stato = 3;
				}
				else {
					stato = 1;
				}
            }
        }
    }
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 11; ++c) {
            if (mappa[r][c] != nullptr && mappa[r][c]->get_colore() == colore) {
                i = r;
                j = c;
				stato = 2;
            }
        }
    }
    switch (stato) {

    }
}
