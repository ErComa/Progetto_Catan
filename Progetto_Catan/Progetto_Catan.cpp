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

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) { window.close(); }
            //evento mouse
            if (event->is<sf::Event::MouseButtonPressed>())
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                int x = localPosition.x;
                int y = localPosition.y;
				int colore = id(x, y);
                cout << colore << endl;
            }
        }
        window.clear();
        print(window);
    }
}