#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "bioma.h"
#include "utente.h"
using namespace std;
sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "non so a cosa serve sta stringa ma se la tolgo non compila quindi la lasciamo qua");
int stato_turno;
int iniziale;
char turno;
int main()
{
    stato_turno = 0;
    iniziale = 6;
    turno = 'r';
	utente* giocatore1 = new utente();
	utente* giocatore2 = new utente();
    assegnazione_numeri();
    inizializzazione_board();
    inizializzazione_biomi();
    // controllo numeri
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (mappa[i][j] != nullptr) {
                std::cout << mappa[i][j]->get_numero() << " ";
            }
            else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
	// controllo colori
    for (int riga = 0; riga < 5; ++riga) {
        for (int col = 0; col < 10; ++col) {
            if (mappa[riga][col] != nullptr) {
                cout << mappa[riga][col]->get_colore();
            }
            else { cout << " "; }
        }
            cout <<endl;
    }

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) { window.close(); }
            //evento mouse
            if (event->is<sf::Event::MouseButtonPressed>())
            {
               
                    event_handler(window, giocatore1, giocatore2);
                
				
            }
        }
        window.clear();
        print(window);
    }
}