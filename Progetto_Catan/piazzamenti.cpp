#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "header.h"
#include "bioma.h"
#include "utente.h"
using namespace std;

bool piazzamento_insediamenti(int i, int j) {
	int a, b;
	if (board[i][j] == nullptr) {
		return false;
	}
	if (iniziale > 0) {
		if (board[i][j]->get_stato() == 'v' && board[i][j]->get_player() == 'o') {
			return true;
		}
	}
	else {
		if (board[i][j]->get_player() == 'o') {
			a = i + 1;
			b = j;
			if (a <= 11) { if (board[a][b] != nullptr) { if (board[i][j]->get_stato() != 'e' && board[a][b]->get_player() == turno) {return true; }}}
			a = i - 1;
			b = j;
			if (a <= 11) {if (board[a][b] != nullptr) {if (board[i][j]->get_stato() != 'e' && board[a][b]->get_player() == turno) {return true; }}}
			a = i;
			b = j + 1;
			if (b <= 21) {if (board[a][b] != nullptr) {if (board[i][j]->get_stato() != 'e' && board[a][b]->get_player() == turno) {return true; }}}
			a = i;
			b = j - 1;
			if (b <= 21) {if (board[a][b] != nullptr) {if (board[i][j]->get_stato() != 'e' && board[a][b]->get_player() == turno) {return true; }}}
			return false;
		}
	}
	return false;
}
bool piazzamento_strade(int i, int j) {
	int a, b;
	if (board[i][j] == nullptr) {
		return false;
	}
		if (board[i][j]->get_stato() == 's' || board[i][j]->get_stato() == 'g') {
			if(board[i][j]->get_player() == 'o'){
				a = i;
				b = j+1;
				if (b <= 21) { if (board[a][b] != nullptr) { if (board[a][b]->get_player() == turno) {return true; } } }
				a = i;
				b = j-1;
				if (b <= 21) {if (board[a][b] != nullptr) { if (board[a][b]->get_player() == turno) {return true; } }}
				return false;
			}
		}		
		if (board[i][j]->get_stato() == 'l') {
			if (board[i][j]->get_player() == 'o') {
				a = i + 1;
				b = j;
				if (a <= 11) { if (board[a][b] != nullptr) { if (board[a][b]->get_player() == turno) {return true; } } }
				a = i - 1;
				b = j;
				if (a <= 11) { if (board[a][b] != nullptr) { if (board[a][b]->get_player() == turno) {return true; } } }
				return false;
			}
		}
		return false;
	}


bool piazzamento_citta(int i, int j) {
	if (board[i][j] == nullptr) {
		return false;
	}
	if (board[i][j]->get_stato() == 'v' && board[i][j]->get_player() == turno) {
		return true;
	}
	return false;

}