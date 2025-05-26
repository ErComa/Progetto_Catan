#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "bioma.h"
#include "utente.h"
using namespace std;
sf::RenderWindow window(sf::VideoMode({ 1100, 800 }), "non so a cosa serve sta stringa ma se la tolgo non compila quindi la lasciamo qua");

int stato_turno;
int iniziale;
char turno;
int main()
{
    window.setFramerateLimit(60);
    stato_turno = 0;
    iniziale = 6;
    turno = 'r';
    placing = 0;
    oldx = 0;
    oldy = 0;
    current_ladro = 0;
	utente* giocatore1 = new utente();
	utente* giocatore2 = new utente();
    assegnazione_numeri();
    inizializzazione_board();
    inizializzazione_biomi();
	inizializzazione_pulsante(window);
   
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) { window.close(); }
            //evento mouse
            if (event->is<sf::Event::MouseButtonPressed>())
            {
               
                    event_handler(window, giocatore1, giocatore2);
                   // giocatore1->stampa_numeri();
                    //giocatore1->stampa_risorse();
				
            }
        }
       
        window.clear();
        print(window, giocatore1, giocatore2);
		tasto(window, 0);
    }
}
