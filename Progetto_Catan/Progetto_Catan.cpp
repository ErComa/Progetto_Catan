#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
using namespace std;
sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "non so a cosa serve sta stringa ma se la tolgo non compila quindi la lasciamo qua");


void stampaColori() {
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 21; ++j) {
            if (board[i][j] != nullptr)
                cout << board[i][j]->colore;
            else
                cout << "..."; // Usa "." o "" per le celle vuote
        }
        cout << endl;
    }
}

int main()
{
    int x, y;
    sf::Texture texture;
    if (!texture.loadFromFile("./media/board.png")) {
        return -1; // Errore nel caricare la texture
    }
    sf::Image image;
    image.loadFromFile("./media/board.png");
    sf::Sprite sprite(texture);
    assegnazione_numeri();
    inizializzazione_board();
    inizializzazione_biomi();
    stampaColori();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) { window.close(); }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
                x = localPosition.x;
                y = localPosition.y;
                sf::Color pixelColor = image.getPixel(sf::Vector2u(x, y));

                std::cout << "Pixel a (" << x << ", " << y << ")"
                    << "A=" << static_cast<int>(pixelColor.a) << "\n";
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}
