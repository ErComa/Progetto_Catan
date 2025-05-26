#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "bioma.h"
#include "utente.h"
#include <cstdlib>
#include <ctime>  
bioma* mappa[5][10];
coso* board[11][21];
numero* numeri[19];
char griglia[righe][colonne] = {
        {'o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o'},
        {'o','o','o','o','o','o','b','o','l','o','b','o','l','o','b','o','o','o','o','o','o'},
        {'o','o','o','o','o','g','v','s','v','g','v','s','v','g','v','s','o','o','o','o','o'},
        {'o','o','o','o','b','o','l','o','b','o','l','o','b','o','l','o','b','o','o','o','o'},
        {'o','o','o','g','v','s','v','g','v','s','v','g','v','s','v','g','v','s','o','o','o'},
        {'o','o','b','o','l','o','b','o','l','o','b','o','l','o','b','o','l','o','b','o','o'},
        {'o','o','o','s','v','g','v','s','v','g','v','s','v','g','v','s','v','g','o','o','o'},
        {'o','o','o','o','b','o','l','o','b','o','l','o','b','o','l','o','b','o','o','o','o'},
        {'o','o','o','o','o','s','v','g','v','s','v','g','v','s','v','g','o','o','o','o','o'},
        {'o','o','o','o','o','o','b','o','l','o','b','o','l','o','b','o','o','o','o','o','o'},
        {'o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o'},
};
int colori[19] = { 210,209,208,207,206,205,204,203,202,201,200,199,198,197,196,195,194,193,192 };
int tipo[19] = { 4,    3,   1,   5,  2,  3,  2,  5,  1,  6,  1,  4,  1,  4,  5,  3,  2,  5,  3 };
int griglia_biomi[5][10] = {
       {-1,-1,0,-1,0,-1,0,-1,-1,-1},
       {-1,0,-1,0,-1,0,-1,0,-1,-1},
       {0,-1,0,-1,0,-1,0,-1,0,-1},
       {-1,0,-1,0,-1,0,-1,0,-1,-1},
       {-1,-1,0,-1,0,-1,0,-1,-1,-1},
};

void assegnazione_numeri() {
    int array[19] = { 2,2,3,3,4,4,5,5,6,6,9,9,8,8,10,10,11,11,12 };
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
            bioma* test = new bioma(tipo[counter], numeri[numerocasuale]->num, colori[counter]);
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
            if (griglia_biomi[i][j] == 0) {
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
    int a, counter, vertici, b, biomi, c;
    counter = 0;
    vertici = 0;
    biomi=0;
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            a = 254 - counter;
            b = 190 - vertici;
            c = 210 - biomi;
            switch (griglia[i][j]) {
            case '0':
                board[i][j] = nullptr;
                break;
            case 'l':
                board[i][j] = new coso('l', a);
                counter++;
                break;
            case 's':
                board[i][j] = new coso('s', a);
                counter++;
                break;
            case 'g':
                board[i][j] = new coso('g', a);
                counter++;
                break;
            case 'v'://identificatore verticei: 190 in giu
                board[i][j] = new coso('v', b);
                vertici++;
                break;
			case 'b':
                board[i][j] = new coso(c, true);
                biomi++;
                break;
            }
        }
    }
    std::cout << "board inizializzata" << std::endl;
}

void print(sf::RenderWindow& window, utente* giocatore1, utente* giocatore2){
    sf::Texture board_punti_texture;
    board_punti_texture.loadFromFile("./media/board_punti.png");
    sf::Texture board_overlay_texture;
    board_overlay_texture.loadFromFile("./media/board_overlay.png");
   
    sf::Sprite board_punti_sprite(board_punti_texture);
    sf::Sprite board_overlay_sprite(board_overlay_texture);
    window.draw(board_overlay_sprite);
    overlay(window);
    window.draw(board_punti_sprite);
    print_vertici(window);
	print_numeri(window);
	giocatore1->stampa_punteggio(window, 1);  
    giocatore2->stampa_punteggio(window, 2);
    giocatore1->stampa_risorse_utente(window, 1);
    giocatore2->stampa_risorse_utente(window, 2);

    window.display();
}
