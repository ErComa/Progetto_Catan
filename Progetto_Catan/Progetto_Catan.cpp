#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
using namespace std;
sf::RenderWindow window(sf::VideoMode({ 800, 800 }), "non so a cosa serve sta stringa ma se la tolgo non compila quindi la lasciamo qua");
int main()
{
    int x, y;
    sf::Texture texture;
    if (!texture.loadFromFile("./board.png")) {
        return -1; // Errore nel caricare la texture
    }
    sf::Image image;
    image.loadFromFile("board.png");
    sf::Sprite sprite(texture);


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

                std::cout << "Pixel a (" << x << ", " << y << "): "
                    << "R=" << static_cast<int>(pixelColor.r) << " "
                    << "G=" << static_cast<int>(pixelColor.g) << " "
                    << "B=" << static_cast<int>(pixelColor.b) << " "
                    << "A=" << static_cast<int>(pixelColor.a) << "\n";
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}
