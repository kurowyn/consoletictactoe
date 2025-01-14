#include <stdio.h>
#include <stdarg.h>
#include "cttt.h"

extern bool
cmp_chars(const int char_count, ...){
	va_list ap;	
	va_start(ap, char_count);

	char first_char = va_arg(ap, int);

	for(int i = 0; i < char_count - 1; i++){
		char next_char = va_arg(ap, int);
		if(first_char != next_char){
			return false;
		}
	}

	va_end(ap);
	return true;
}

extern bool
board_is_empty(const char *board){
	for(int i = 0; i < GRID; i++){
		if(board[i] != X &&	board[i] != O){
			return false;
		}
	}	
	return true;
}

extern void
board_show(const char *board){
	CLR_SCR;
	GAME_STATUS(board);
	for(int i = 0; i < ROWS; i++){
		printf("|%c|%c|%c|\n", board[i * 3],	
							   board[i * 3 + 1],
							   board[i * 3 + 2]);
	}	
}

extern void 
board_update(char *board, const Player *p){
	board[p->square - 1] = p->symbol;
}

// TODO: fix input (replace scanf).
extern void
board_play(const char *board, Player *p){
	while(true){
		printf("%c Square: ", p->symbol);
		scanf(" %d", &p->square);
		if(board[p->square - 1] != X && board[p->square - 1] != O){
			break;	
		}
	}
}

extern Player
player_init(const Player_Number pn){
  char symbol;

	while(true){
		CLR_SCR;
		printf("Player %d Symbol: ", pn);
		scanf(" %c", &symbol);
		if(symbol == X || symbol == O){
			break;
		}	
	}

	return (Player){.symbol = symbol, .number = pn};	
}

extern void
game_message(const char *board){
	board_show(board);
	if(BOARD_WIN(board, X)){
		printf("X has won!\n");
	} 
	else if(BOARD_WIN(board, O)){
		printf("O has won!\n");
	}
}
