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

enum Type {
	King,
	Queen,
	Bishop, 
	Knight, 
	Rook, 
	Pawn 	
};

enum State {
	Check, 
	CheckMate,
	StaleMate,
	Play
};

enum Player {
	White, 
	Black
};

struct Posititon {
	int x; // 0-7 (a-b) 
	int y; // 0-7 (1-8)
};

struct Piece {
	enum Type type; 
	enum Player player;
	struct Posititon position;
};

struct GameState {
	enum Player current;
	enum State state;
	int MoveCount; 
};

void SetDefault(struct Piece *board) {
	for (int i=1; i<=32; i++) {
		// White Pawns
		if (i>7&&i<16) {
			board[i].type = Pawn;
			board[i].player = White;
			board[i].position.y = 1; 
			board[i].position.x = 8-i;
		}	
		// Black Pawns	
		if (i>23) {
			board[i].type = Pawn;
			board[i].player = Black; 
			board[i].position.y = 6;
			board[i].position.x = 32-i;
		}
		// White Pieces 
		if (i<8) {
			board[i].player = White;
			board[i].position.y = 0;
			board[i].position.x = i-1;
		}
		// Black Pieces 
		if (i>15&&i<24) {
			board[i].player = Black;
			board[i].position.y = 7;
			board[i].position.x = 32-i; 
		}
	}	

	// Remaning Piece types 
	board[1].type = Rook;
	board[8].type = Rook;
	board[2].type = Knight; 
	board[7].type = Knight;
	board[3].type = Bishop;
	board[6].type = Bishop;
	board[4].type = Queen; 
	board[5].type = King;

	board[17].type = Rook;
	board[24].type = Rook;
	board[18].type = Knight; 
	board[23].type = Knight; 
	board[19].type = Bishop;
	board[22].type = Bishop;
	board[20].type = Queen;
	board[21].type = King;	
}

DisplayBoard(struct Piece *board) {
	// ???	
}

int main(void) {
	struct GameState gamestate;

	gamestate.current = White;
	gamestate.state = Play;
	gamestate.MoveCount = 0;

	struct Piece *board = malloc(sizeof(struct Piece)*32);  
	SetDefault(board);
	DisplayBoard(board);
}
