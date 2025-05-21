#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "bioma.h"
using namespace std;

int id(int x, int y) {
	sf::Image image;
	image.loadFromFile("./media/board.png");
	sf::Color pixelColor = image.getPixel(sf::Vector2u(x, y));
	return pixelColor.a;	
}