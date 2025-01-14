#include "cttt.h"

int main(void){
	char board[COLS * ROWS] = {'1', '2','3','4','5','6','7','8','9'};
		
	Player p1, p2;

	while(true){
		p1 = player_init(PLAYER_1);	
		p2 = player_init(PLAYER_2);	
		if(p1.symbol != p2.symbol){
			break;
		}
	}
	
	while(GAME_ON(board)){
		board_show(board);
		if(GAME_ON(board)){
			board_play(board, &p1);
		}
		board_update(board, &p1);

		board_show(board);
		if(GAME_ON(board)){
			board_play(board, &p2);
		}
		board_update(board, &p2);
	}

	board_show(board);
	game_message(board);	

	return EXIT_SUCCESS;
}
