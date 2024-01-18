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

#include <MoveValid.h>
#include <CCtimer.h>

enum Piece {
	None = 8,
	King = 9,
	Queen = 10,
	Bishop = 11, 
	Knight = 12, 
	Rook = 13, 
	Pawn = 14,	
	
	White = 32, 
	Black = 64
};

enum State {
	Check, 
	CheckMate,
	StaleMate,
	Invalid,
	Play
};

struct GameState {
	enum Piece current;
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
		board[48+i] = Pawn | White;
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

// TODO: notate the board better
void DisplayBoard(enum Piece *board) {
	for (int i = 0; i<64; i++) {
		if (i%8==0) {
			printf("\n┏━━┓┏━━┓┏━━┓┏━━┓┏━━┓┏━━┓┏━━┓┏━━┓\n"); 
		}

		if (board[i] != 0) {
			printf("┃%d┃", board[i]);
		}	
		else if (board[i] == 0) {
			printf("┃  ┃");
		}	
	}	
}

void MoveValid(int from, int to, enum Piece *board, struct GameState *gamestate) {
	// TODO:
	// Check what piece is on board[from];
	// pass the validity check to a sub function {Piece}Valid() function in Valid.c
	// gamestate->state = {Piece}Valid(); 
}

void UpdateBoard(int from, int to, enum Piece *board) {
	int tmp = board[from];
	board[from] = 0;
	board[to]= tmp;
}

int main(void) {
	struct GameState gamestate;

	gamestate.current = White;
	gamestate.state = Play;
	gamestate.MoveCount = 1;

	enum Piece *board = calloc(64, sizeof(enum Piece));  
	SetDefault(board);
	
	while (gamestate.state != CheckMate || gamestate.state != StaleMate) {
		DisplayBoard(board);
		printf("%d> ", gamestate.current);
		int from, to; 
		
		if (scanf("%d %d", &from, &to) == EOF) {
			return EOF;
		}

		// TODO: start a timer. 

		if (/*MoveValid(piece, from, to, board, &gamestate)*/0==0) { 
			UpdateBoard(from, to, board);
		}
		else {
			break;
		}	
		
		gamestate.MoveCount+=1;	
		if (gamestate.MoveCount % 2 == 0) {
			gamestate.current = Black;
		}		
		else {
			gamestate.current = White;
		}
	
	}
	return 0;
}
