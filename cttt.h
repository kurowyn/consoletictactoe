#ifndef CTTT_H
#define CTTT_H

#include <stdbool.h>
#include <stdlib.h>

#define COLS 3
#define ROWS 3
#define GRID ROWS * COLS

#define X 'X'
#define O 'O'

#define H_WIN(board, symbol) cmp_chars(COLS + 1, board[0], board[1], board[2], symbol) || \
					         cmp_chars(COLS + 1, board[3], board[4], board[5], symbol) || \
						     cmp_chars(COLS + 1, board[6], board[7], board[8], symbol)  

#define V_WIN(board, symbol) cmp_chars(COLS + 1, board[0], board[3], board[6], symbol) || \
						     cmp_chars(COLS + 1, board[1], board[4], board[7], symbol) || \
							 cmp_chars(COLS + 1, board[2], board[5], board[8], symbol)  

#define D_WIN(board, symbol) cmp_chars(COLS + 1, board[0], board[4], board[8], symbol) || \
						     cmp_chars(COLS + 1, board[2], board[4], board[6], symbol)  
                              

#define BOARD_WIN(board, symbol) H_WIN(board, symbol) || \
								 V_WIN(board, symbol) || \
								 D_WIN(board, symbol)

#define GAME_ON(board) (!(BOARD_WIN(board, X)) && !(BOARD_WIN(board, O)) && \
			 		   (!board_is_empty(board))) 

#define PAUSE system("pause")
#define CLR_SCR system("cls")
#define GAME_STATUS(board) printf("X: %d\tO: %d\tEMP: %d\tON: %d\t\n", BOARD_WIN(board, X),   \
							     			    				       BOARD_WIN(board, O),   \
							     									   board_is_empty(board), \
							      			    					   GAME_ON(board))

typedef struct {
	char symbol;
	int number;
	int square;
} Player;

typedef enum {PLAYER_1 = 1, PLAYER_2} Player_Number;

extern bool cmp_chars(const int char_count, ...);

extern Player player_init(const Player_Number pn);

extern bool board_is_empty(const char *board);

extern void board_show(const char *board);

extern void board_update(char *board, const Player *p);

extern void board_play(const char *board, Player *p);

extern void game_message(const char *board);

#endif // CTTT_H
