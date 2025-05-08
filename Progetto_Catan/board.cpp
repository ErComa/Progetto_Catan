#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"

void inizializzazione_board() {
    int a;
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            a = 100 - i;
            switch (griglia[i][j]) {
            case '0':
                board[i][j] = nullptr;
                break;
            case 'l':
                coso * test = new coso('l',i);
                board[i][j] = test;
                break;
            case 's':
                coso * test = new coso('s', i);
                board[i][j] = test;
                break;
            case 'g':
                coso * test = new coso('g', i);
                board[i][j] = test;
                break;
            case 'v':
                coso * test = new coso('l', i);
                board[i][j] = test;
                break;
            }
        }
        std::cout << "board inizializzata";
    }
}
/*
posizione stampa esagono 1: 190,83
delta x = 141

per file sfasate:
120,205
*/
void print() {
    sf::Texture arancione;
    arancione.loadFromFile("./media/arancione.png");

    sf::Texture blu_giu;
    blu_giu.loadFromFile("./media/blu_giu.png");

    sf::Texture blu_su;
    blu_su.loadFromFile("./media/blu_su.png");

    sf::Texture blu_verticale;
    blu_verticale.loadFromFile("./media/blu_verticale.png");

    sf::Texture deserto;
    deserto.loadFromFile("./media/deserto.png");

    sf::Texture giallo;
    giallo.loadFromFile("./media/giallo.png");

    sf::Texture grigio;
    grigio.loadFromFile("./media/grigio.png");

    sf::Texture board;
    board.loadFromFile("./media/board.png");

    sf::Texture rosso_giu;
    rosso_giu.loadFromFile("./media/rosso_giu.png");

    sf::Texture rosso_su;
    rosso_su.loadFromFile("./media/rosso_su.png");

    sf::Texture rosso_verticale;
    rosso_verticale.loadFromFile("./media/rosso_verticale.png");

    sf::Texture verde;
    verde.loadFromFile("./media/verde.png");

    sf::Texture verdechiaro;
    verdechiaro.loadFromFile("./media/verdechiaro.png");

    for (int i = 0; i < 5;i++) {
        for (int t = 0; t < 5;t++) {

        }
    }
}