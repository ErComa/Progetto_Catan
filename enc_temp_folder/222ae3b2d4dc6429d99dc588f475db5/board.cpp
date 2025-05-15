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
        {'o','o','o','o','o','g','v','s','v','g','v','s','v','g','v','s','o','o','o','o','o'},
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
                board[i][j] = new coso('l', b);
                vertici++;
                break;
            }
        }
    }
    std::cout << "board inizializzata"<<std::endl;
}

void print(sf::RenderWindow& window) {
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
	//190 83, deltax 142, deltay 123
    //332 206
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            if(board[i][j]!= nullptr)
            {
                switch (board[i][j]->get_stato()) {
                case 'l':
					switch (board[i][j]->get_player()) {
                    case 'o':
						break;
					case 'b':
						blu_verticale_sprite.setPosition(sf::Vector2f(190 + (j * 142), 83 + (i * 123)));
						window.draw(blu_verticale_sprite);
						break;
					case 'r':
						rosso_verticale_sprite.setPosition(sf::Vector2f(190 + (j * 142), 83 + (i * 123)));
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
                        blu_su_sprite.setPosition(sf::Vector2f(190 + (j * 142), 83 + (i * 123)));
                        window.draw(blu_su_sprite);
                        break;
                    case 'r':
                        rosso_su_sprite.setPosition(sf::Vector2f(190 + (j * 142), 83 + (i * 123)));
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
                        blu_giu_sprite.setPosition(sf::Vector2f(190 + (j * 142), 83 + (i * 123)));
                        window.draw(blu_giu_sprite);
                        break;
                    case 'r':
                        rosso_giu_sprite.setPosition(sf::Vector2f(190 + (j * 142), 83 + (i * 123)));
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