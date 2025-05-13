#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "bioma.h"

bioma::bioma(int a, int b, int c) : type(a), numero(b), colore(c) {}
int bioma::get_type() { return type; }
int bioma::produzione_risorsa() {}