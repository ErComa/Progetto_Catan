#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include <cstdlib>
#include <ctime>  

void assegnazione_numeri() {
    int array[19] = {2,2,3,3,4,4,5,5,6,6,9,9,8,8,10,10,11,11,12 };
    for (int i = 0;i < 19;i++) {
        numero* test = new numero(array[i]);
        numeri[i] = test;
    }
}

//identificatore biomi: canale alfa 210 a scendere
//tipo numero colore
void scegli_bioma(int i, int j, int counter) {
    bool a = 0;
    while (a == 0) {
        int numerocasuale = std::rand() % 19;
        if (numeri[numerocasuale]->assegnato != 1) {
            bioma * test = new bioma(tipo[counter], numeri[numerocasuale]->num,colori[counter]);
            mappa[i][j] = test;
            numeri[numerocasuale]->assegnato = 1;
            a = true;
        }
    }
}

void inizializzazione_biomi() {
    std::srand(std::time(nullptr));
    int counter = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (griglia[i][j] == 0) {
                scegli_bioma(i, j, counter);
                counter++;
           }
            else {
                mappa[i][j] = nullptr;
            }
            }
        }

}

void inizializzazione_board() {
    int a, counter;
    counter = 0;
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            a = 254 - counter;
            switch (griglia[i][j]) {
            case '0':
                board[i][j] = nullptr;
                break;
            case 'l':
                coso * test = new coso('l',a);
                board[i][j] = test;
                counter++;
                break;
            case 's':
                coso * test = new coso('s', a);
                board[i][j] = test;
                counter++;
                break;
            case 'g':
                coso * test = new coso('g', a);
                board[i][j] = test;
                counter++;
                break;
            case 'v':
                coso * test = new coso('l', i);//identificatore verticei: 190 in giu
                board[i][j] = test;
                break;
            }
        }
        std::cout << "board inizializzata";
    }
}

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