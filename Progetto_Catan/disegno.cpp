#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "bioma.h"
#include "utente.h"
#include <cstdlib>
#include <ctime>  

using namespace std;

void overlay(sf::RenderWindow& window) {
    int a, b, vertici, lati, vertici_counter;
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
    sf::Texture board_punti_texture;
    board_punti_texture.loadFromFile("./media/board_punti.png");
    sf::Texture board_overlay_texture;
    board_overlay_texture.loadFromFile("./media/board_overlay.png");
    //creazione degli sprite
    sf::Sprite blu_giu_sprite(blu_giu_texture);
    sf::Sprite blu_su_sprite(blu_su_texture);
    sf::Sprite blu_verticale_sprite(blu_verticale_texture);
    sf::Sprite rosso_giu_sprite(rosso_giu_texture);
    sf::Sprite rosso_su_sprite(rosso_su_texture);
    sf::Sprite rosso_verticale_sprite(rosso_verticale_texture);
    sf::Sprite board_sprite(board_texture);
    sf::Sprite board_punti_sprite(board_punti_texture);
    sf::Sprite board_overlay_sprite(board_overlay_texture);
    //deltax 68, deltay 123
    //44 318
    window.draw(board_overlay_sprite);
    for (int i = 0; i < righe; ++i) {
        vertici = 0;
        lati = 0;
        vertici_counter = 0;
        if (i == 2 || i == 8) { vertici++; }
        for (int j = 0; j < colonne; ++j) {
            if (board[i][j] != nullptr) {if(board[i][j]->get_stato_bioma() != true) if (board[i][j]->get_stato() == 'v') { vertici++; } }
            {
                if (board[i][j] == nullptr) {lati++; } else { if (board[i][j]->get_stato_bioma() == true) { lati++; }
                }
            }
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
                ;
            }
            b = 44 + ((j - 2 - vertici) * 71);
            if (i == 2 && j <= 15) { b -= 2; a += 2; }
            if (i == 4 && j <= 15) { b -= 2; }
            if (i == 6 && j <= 15) { b -= 2; }
            if (i == 8 && j <= 14) {
                b -= 2; a -= 2;
            }
            if (board[i][j] != nullptr)
                if (board[i][j]->get_stato_bioma() != true) {
                    {
                        switch (board[i][j]->get_stato()) {
                        case 'l':
                            b = (181 + ((j - lati) * 141));
                            if (i == 3 || i == 7) { b += 71; }
                            if (i == 1 || i == 9) { b += 141; }
                            if (i == 2 && j <= 15) { b -= 50; }

                            switch (board[i][j]->get_player()) {
                            case 'o':
                                break;
                            case 'b':
                                blu_verticale_sprite.setPosition(sf::Vector2f(b, a));
                                window.draw(blu_verticale_sprite);
                                break;
                            case 'r':
                                //std::cout << b << " " << a <<" j "<< j <<" i "<<i<< std::endl;
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
    }
}
void print_vertici(sf::RenderWindow& window) {
    //y: 193 deltay1 37  deltay2 83
    //x: 175 deltax = 69
    int a, b;
    a = 0;
    b = 0;
    int f = 37;
    int g = 83;
    int vertici_counter;

    sf::Texture casa_rossa_texture;
    casa_rossa_texture.loadFromFile("./media/casa_rossa.png");
    sf::Texture casa_blu_texture;
    casa_blu_texture.loadFromFile("./media/casa_blu.png");
    sf::Texture villaggio_rosso_texture;
    villaggio_rosso_texture.loadFromFile("./media/villaggio_rosso.png");
    sf::Texture villaggio_blu_texture;
    villaggio_blu_texture.loadFromFile("./media/villaggio_blu.png");
    sf::Sprite casa_rossa_sprite(casa_rossa_texture);
    sf::Sprite casa_blu_sprite(casa_blu_texture);
    sf::Sprite villaggio_rosso_sprite(villaggio_rosso_texture);
    sf::Sprite villaggio_blu_sprite(villaggio_blu_texture);

    for (int i = 0; i < righe; ++i) {
        vertici_counter = 0;
        for (int j = 0; j < colonne; ++j) {

            if (board[i][j] != nullptr) {
                if (board[i][j]->get_stato() == 'v') {
                    if (board[i][j]->get_stato_bioma() != true) {
                        b = 175 + 71 * vertici_counter + 69;
                        vertici_counter++;
                        if (i == 2) { if ((vertici_counter % 2) == 1) { a = 193 + f; } else { a = 193; } }
                        if (i == 4) { b -= 69;if ((vertici_counter % 2) == 1) { a = 193 + 2 * f + g; } else { a = 193 + f + g; } }
                        if (i == 6) { b -= 69;if ((vertici_counter % 2) == 1) { a = 193 + 2 * f + 2 * g; } else { a = 193 + 3 * f + 2 * g; } }
                        if (i == 8) { if ((vertici_counter % 2) == 1) { a = 193 + 3 * f + 3 * g; } else { a = 193 + 4 * f + 3 * g; } }

                        switch (board[i][j]->get_player()) {
                        case 'b':
                            switch (board[i][j]->get_tipo()) {
                            case 'c':
                                casa_blu_sprite.setPosition(sf::Vector2f(b, a));
                                window.draw(casa_blu_sprite);
                                break;
                            case 'v':
                                villaggio_blu_sprite.setPosition(sf::Vector2f(b, a));
                                window.draw(villaggio_blu_sprite);
                                break;
                            }
                            break;
                        case 'r':
                            switch (board[i][j]->get_tipo()) {
                            case 'c':
                                casa_rossa_sprite.setPosition(sf::Vector2f(b, a));
                                window.draw(casa_rossa_sprite);
                                break;
                            case 'v':
                                villaggio_rosso_sprite.setPosition(sf::Vector2f(b, a));
                                window.draw(villaggio_rosso_sprite);
                                break;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}

void print_numeri(sf::RenderWindow& window) {
    int a, x, y, counter;
    sf::Texture due_texture;
    due_texture.loadFromFile("./media/2.png");
    sf::Sprite due_sprite(due_texture);
	sf::Texture tre_texture;
	tre_texture.loadFromFile("./media/3.png");
	sf::Sprite tre_sprite(tre_texture);
	sf::Texture quattro_texture;
	quattro_texture.loadFromFile("./media/4.png");
	sf::Sprite quattro_sprite(quattro_texture);
	sf::Texture cinque_texture;
	cinque_texture.loadFromFile("./media/5.png");
	sf::Sprite cinque_sprite(cinque_texture);
	sf::Texture sei_texture;
	sei_texture.loadFromFile("./media/6.png");
	sf::Sprite sei_sprite(sei_texture);
	sf::Texture otto_texture;
	otto_texture.loadFromFile("./media/8.png");
	sf::Sprite otto_sprite(otto_texture);
	sf::Texture nove_texture;
	nove_texture.loadFromFile("./media/9.png");
    sf::Sprite nove_sprite(nove_texture);
    sf::Texture dieci_texture;
    dieci_texture.loadFromFile("./media/10.png");
    sf::Sprite dieci_sprite(dieci_texture);
    sf::Texture undici_texture;
    undici_texture.loadFromFile("./media/11.png");
    sf::Sprite undici_sprite(undici_texture);
    sf::Texture dodici_texture;
    dodici_texture.loadFromFile("./media/12.png");
    sf::Sprite dodici_sprite(dodici_texture);



    // deltay =121 y inizale 58 + y
    // deltax = 130 x inziale 25 +x
    for (int i = 0; i < 5; ++i) {
		counter = 0;
        for (int j = 0; j < 10; ++j) {
            if (griglia_biomi[i][j] == 0) {
                if (i == 0 || i == 4) { x = 235 + (counter * 140); }//260
                if (i == 1 || i == 3) { x = 165 + (counter * 140); }//180
                if (i == 2) { x = 95 + (counter * 140); }
                cout << counter <<" x: "<<x<< endl;
				y = 150 + (i * 121);
				a = mappa[i][j]->get_numero();
                switch (a) {
				case 2:
					due_sprite.setPosition(sf::Vector2f(x, y));
					window.draw(due_sprite);
					break;
				case 3:
					tre_sprite.setPosition(sf::Vector2f(x, y));
					window.draw(tre_sprite);
					break;
				case 4:
					quattro_sprite.setPosition(sf::Vector2f(x, y));
					window.draw(quattro_sprite);
					break;
				case 5:
					cinque_sprite.setPosition(sf::Vector2f(x, y));
					window.draw(cinque_sprite);
					break;
				case 6:
					sei_sprite.setPosition(sf::Vector2f(x, y));
					window.draw(sei_sprite);
					break;
				case 8:
					otto_sprite.setPosition(sf::Vector2f(x, y));
					window.draw(otto_sprite);
					break;
				case 9:
					nove_sprite.setPosition(sf::Vector2f(x, y));
					window.draw(nove_sprite);
					break;
				case 10:
					dieci_sprite.setPosition(sf::Vector2f(x, y));
					window.draw(dieci_sprite);
					break;
				case 11:
					undici_sprite.setPosition(sf::Vector2f(x, y));
					window.draw(undici_sprite);
					break;
				case 12:
					dodici_sprite.setPosition(sf::Vector2f(x, y));
					window.draw(dodici_sprite);
					break;
                }
                counter++;
			}
           
            }
        cout << "fine riga " << endl;
        }
    cout << "fine chiamata funzione";
    }

/*
{-1,-1,0,-1,0,-1,0,-1,-1,-1},
{-1,0,-1,0,-1,0,-1,0,-1,-1},
{0,-1,0,-1,0,-1,0,-1,0,-1},
{-1,0,-1,0,-1,0,-1,0,-1,-1},
{-1,-1,0,-1,0,-1,0,-1,-1,-1},
 */