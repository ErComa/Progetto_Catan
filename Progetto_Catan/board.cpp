#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"

void inizializzazione_board() {
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            switch (griglia[i][j]) {
            case '0':
                board[i][j] = nullptr;
                break;
            case 'l':
                coso * test = new coso('l');
                board[i][j] = test;
                break;
            case 's':
                coso * test = new coso('s');
                board[i][j] = test;
                break;
            case 'g':
                coso * test = new coso('g');
                board[i][j] = test;
                break;
            case 'v':
                coso * test = new coso('l');
                board[i][j] = test;
                break;
            }
        }
        std::cout << "board inizializzata";
    }
}