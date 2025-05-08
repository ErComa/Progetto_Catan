#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"

void inizializzazione_board() {
    int a;
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            a = 100 - i;
            switch (griglia[i][j]) {
            case '0':
                board[i][j] = nullptr;
                break;
            case 'l':
                coso * test = new coso('l',i);
                board[i][j] = test;
                break;
            case 's':
                coso * test = new coso('s', i);
                board[i][j] = test;
                break;
            case 'g':
                coso * test = new coso('g', i);
                board[i][j] = test;
                break;
            case 'v':
                coso * test = new coso('l', i);
                board[i][j] = test;
                break;
            }
        }
        std::cout << "board inizializzata";
    }
}