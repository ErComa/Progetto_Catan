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
        {'o','o','o','o','o','o','o','o','l','o','o','o','l','o','o','o','o','o','o','o','o'},
        {'o','o','o','o','o','g','v','s','v','g','v','s','v','g','v','s','o','o','o','o','o'},
        {'o','o','o','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','o','o','o'},
        {'o','o','o','g','v','s','v','g','v','s','v','g','v','s','v','g','v','s','o','o','o'},
        {'o','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','o'},
        {'o','o','o','s','v','g','v','s','v','g','v','s','v','g','v','s','v','g','o','o','o'},
        {'o','o','o','o','o','o','l','o','o','o','l','o','o','o','l','o','o','o','o','o','o'},
        {'o','o','o','o','o','s','v','g','v','s','v','g','v','s','v','g','o','o','o','o','o'},
        {'o','o','o','o','o','o','o','o','l','o','o','o','l','o','o','o','o','o','o','o','o'},
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
    int a, counter, vertici, b;
    counter = 0;
    vertici = 0;

    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            a = 254 - counter;
            b = 190 - vertici;
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
            }
        }
    }
    std::cout << "board inizializzata" << std::endl;
}

void print(sf::RenderWindow& window) {
    int a, b, vertici, lati;
    a = 0;
    b = 0;
    // Caricamento delle texture
    sf::Texture blu_giu_texture;
    blu_giu_texture.loadFromFile("./media/blu_giu.png");
    sf::Texture blu_su_texture;
    blu_su_texture.loadFromFile("./media/blu_su.png");
    sf::Texture blu_verticale_texture;
    blu_verticale_texture.loadFromFile("./media/blu_verticale.png");
    sf::Texture rosso_giu_texture;
    rosso_giu_texture.loadFromFile("./media/rosso_giu.png");
    sf::Texture rosso_su_texture;
    rosso_su_texture.loadFromFile("./media/rosso_su.png");
    sf::Texture rosso_verticale_texture;
    rosso_verticale_texture.loadFromFile("./media/rosso_verticale.png");
    sf::Texture board_texture;
    board_texture.loadFromFile("./media/board.png");
    //creazione degli sprite
    sf::Sprite blu_giu_sprite(blu_giu_texture);
    sf::Sprite blu_su_sprite(blu_su_texture);
    sf::Sprite blu_verticale_sprite(blu_verticale_texture);
    sf::Sprite rosso_giu_sprite(rosso_giu_texture);
    sf::Sprite rosso_su_sprite(rosso_su_texture);
    sf::Sprite rosso_verticale_sprite(rosso_verticale_texture);
    sf::Sprite board_sprite(board_texture);
    //deltax 68, deltay 123
    //44 318
    board[5][4]->set_player('r');
    board[3][6]->set_player('r');
    window.draw(board_sprite);
    for (int i = 0; i < righe; ++i) {
		vertici = 0;
        lati = 0;
        if (i == 2 || i == 8) { vertici++; }
        for (int j = 0; j < colonne; ++j) {
         if (board[i][j] != nullptr){if (board[i][j]->get_stato() == 'v') { vertici++; }}
         if (board[i][j] == nullptr) { lati++;}
         switch (i) {
         case 1:
			 a = 122;
		    break;
         case 2:
             a = (318 - 123);
			 break;
		 case 4:
			 a = 318;
			 break;
		 case 3:
			 a = 240;
			 break;
		 case 6:
             a = (318 + 123);
			 break;
		 case 5:
			 a = 360;
			 break;
         case 8:
             a = (318 + 246);
             break;
		 case 7:
			 a = 483;
			 break;
         case 9:
             a = 605;
             break;
;         }
            b = 44 + ((j - 2-vertici) * 71);
            if (i == 2 && j <= 15) { b -= 2; a += 2; }
            if (i == 4 && j <= 15) { b -= 2;}
            if (i == 6 && j <= 15) { b -= 2;}
            if (i == 8 && j <= 14) { b -= 2; a -= 2;
            }
            if (board[i][j] != nullptr)
            {
                switch (board[i][j]->get_stato()) {
               case 'l':
                   b = (181 + ((j - lati) * 141));
                   if (i == 3 || i == 7) { b += 71;}
                   if (i == 1 || i == 9) {b += 141;}
                   if (i == 2 && j <= 15) { b -= 50;}
				   
                    switch (board[i][j]->get_player()) {
                    case 'o':
                        break;
                    case 'b':
                        blu_verticale_sprite.setPosition(sf::Vector2f(b, a));
                        window.draw(blu_verticale_sprite);
                        break;
                    case 'r':
                        std::cout << b << " " << a <<" j "<< j <<" i "<<i<< std::endl;
                        rosso_verticale_sprite.setPosition(sf::Vector2f(b, a));
                        window.draw(rosso_verticale_sprite);
                        break;
                    }
                    break;

                    break;
                case 's':
                    switch (board[i][j]->get_player()) {
                    case 'o':
                        break;
                    case 'b':
                        blu_su_sprite.setPosition(sf::Vector2f(b, a));
                        window.draw(blu_su_sprite);
                        break;
                    case 'r':
                        rosso_su_sprite.setPosition(sf::Vector2f(b, a));
                        window.draw(rosso_su_sprite);
                        break;
                    }
                    break;
                    break;
                case 'g':
                    switch (board[i][j]->get_player()) {
                    case 'o':
                        break;
                    case 'b':
                        blu_giu_sprite.setPosition(sf::Vector2f(b, a));
                        window.draw(blu_giu_sprite);
                        break;
                    case 'r':
                        rosso_giu_sprite.setPosition(sf::Vector2f(b, a));
                        window.draw(rosso_giu_sprite);
                        break;
                    }
                    break;

                    break;
                case 'v':

                    break;
                }
            }
        }
    }
    window.display();
}