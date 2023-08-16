/*
    cchess: chess engine in C
    Copyright (C) 2023 aryalaadi123 @ gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>

enum Piece {
	None = 0,
	King = 1,
	Queen = 2,
	Bishop = 3, 
	Knight = 4, 
	Rook = 5, 
	Pawn = 6,	
	
	White = 8, 
	Black = 16
};

enum State {
	Check, 
	CheckMate,
	StaleMate,
	Play
};

enum Color {
	A,
	B
};

struct GameState {
	enum Color current;
	enum State state;
	int MoveCount; 
};

void SetDefault(enum Piece *board) {
	board[0] = Rook | Black; 
	board[1] = Knight | Black;
	board[2] = Bishop | Black;
	board[3] = Queen | Black;
	board[4] = King | Black;
	board[5] = Bishop | Black;
	board[6] = Knight | Black;
	board[7] = Rook | Black;
	
	for (int i=0; i<8; i++) {
		board[8+i] = Pawn | Black;
	}
	for (int i=0; i<8; i++) {
		board[47+i] = Pawn | White;
	}

	board[56] = Rook | White;
	board[57] = Knight | White;
	board[58] = Bishop | White;
	board[59] = Queen | White;
	board[60] = King | White;
	board[61] = Bishop | White;
	board[62] = Knight | White;
	board[63] = Rook | White;
}

void DisplayBoard(enum Piece *board) {
	// ???	
}

int main(void) {
	struct GameState gamestate;

	gamestate.current = White;
	gamestate.state = Play;
	gamestate.MoveCount = 0;

	enum Piece *board = calloc(0, sizeof(enum Piece)*64);  
	SetDefault(board);
	DisplayBoard(board);
}
