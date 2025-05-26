#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "bioma.h"
#include "utente.h"
using namespace std;
utente::utente(){
	insediamenti = 1;
	citta = 0;
	strade = 2;
	punteggio = 0;
	for (int i = 0; i < 6; ++i) {
		risorse[i] = 200;
	}

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
                   // giocatore1->stampa_numeri();
                    //giocatore1->stampa_risorse();
				
            }
        }
        window.clear();
        print(window, giocatore1, giocatore2);
    }
}

void utente::stampa_punteggio(sf::RenderWindow& window, int a) {
	sf::Font font;
	font.openFromFile("./media/arial.ttf");
	sf::Text text(font);
	text.setString(std::to_string(punteggio));
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	if (a == 1) {
		text.setPosition(sf::Vector2f(988, 118));
	}
	else {
		text.setPosition(sf::Vector2f(992, 385));
	}
	window.draw(text);
}

void utente::stampa_risorse_utente(sf::RenderWindow& window, int a) {
	string risorse_string = "Risorse: ";
	int y;
	int x[5] = { 988, 988, 988, 988, 988 };
	sf::Font font;
	font.openFromFile("./media/arial.ttf");
	sf::Text text(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	for (int i = 0; i < 6; ++i) {
		string risorse_string = std::to_string(punteggio);
		text.setString(risorse_string);
		text.setPosition(sf::Vector2f(x[i], y));
	}
	text.setPosition(sf::Vector2f(988, 158));
	window.draw(text);
}
/*
biomi: 1-5 biomi normali e 6 deserto, paralleli al tipo di risorsa
1: legno verdescuro
2: mattoni arancione
3: lana verdechiaro
4: minerale grigio
5: grano giallo qualcosa del genere
6: deserto
Strade (richiedono 1 mattone e 1 legno).
Villaggi (richiedono 1 mattone, 1 legno, 1 lana e 1 grano).
Città (richiedono 3 minerali e 2 grani, e sostituiscono un villaggio).
Carte sviluppo (richiedono 1 minerale, 1 lana e 1 grano).
*/
