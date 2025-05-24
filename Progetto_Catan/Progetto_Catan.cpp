#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "bioma.h"
using namespace std;
sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "non so a cosa serve sta stringa ma se la tolgo non compila quindi la lasciamo qua");

int main()
{
    assegnazione_numeri();
    inizializzazione_board();
    inizializzazione_biomi();
    bool turno = 0;
    int stato_turno = 0;
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
                event_handler(window);
            }
        }
        window.clear();
        print(window);
    }
}