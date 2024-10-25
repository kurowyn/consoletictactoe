#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
typedef struct{char player_symbol;int player_square;} player_t;
enum PLAYERS {PLAYER_1 = 1, PLAYER_2 = 2};
char tictactoe_board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

int *return_remaining_squares(void){ // What if we just returned a struct?
    int *remaining_squares = malloc(sizeof(int) * 10);
    int j = 1;
    for(int i = 0; i < 9; i++){
        if(tictactoe_board[i] == ' '){
            remaining_squares[j] = i + 1;
            j++;
        }
    }
    remaining_squares[0] = j;
    return remaining_squares;
}

int in_array(int *arr, int arr_len, int element){ // Not a truly general solution.
    int i = 1, element_found = FALSE;
    while(i < arr_len && element_found == FALSE){
        if(arr[i] == element){
            element_found = TRUE;
        }
        i++;
    }
    return element_found;
}

int check_win(const char symbol){ // There could be some tictactoe win algorithm hiding out there.
    for(int i = 0; i < 3; i++){
        if(tictactoe_board[i * 3] == symbol && tictactoe_board[1 + i * 3] == symbol && tictactoe_board[2 + i * 3] == symbol ||
           tictactoe_board[i] == symbol && tictactoe_board[i + 3] == symbol && tictactoe_board[i + 6] == symbol ||
           tictactoe_board[0] == symbol && tictactoe_board[4] == symbol  && tictactoe_board[8] == symbol ||
           tictactoe_board[2] == symbol && tictactoe_board[4] == symbol  && tictactoe_board[6] == symbol){
           return TRUE;
           }
        }
    return FALSE;
}

void print_board(void){
    for(int i = 0; i < 3; i++){
        printf("|%c|%c|%c|\n", tictactoe_board[i * 3],
                               tictactoe_board[i * 3 + 1],
                               tictactoe_board[i * 3 + 2]);
    }
}

void update_board(const char symbol, int square){
    tictactoe_board[square - 1] = symbol;
}

void play(player_t player_1, player_t player_2, int current_player_turn){
    player_t current_player = (current_player_turn == PLAYER_1) ? player_1 : player_2;
    if(!check_win(player_1.player_symbol) && !check_win(player_2.player_symbol)){
        while(TRUE){
            system("cls");
            print_board();
            printf("Current turn: %c\nSelect a square: ", current_player.player_symbol);
            scanf("%d", &current_player.player_square);
            if(in_array(return_remaining_squares(), return_remaining_squares()[0] + 1, current_player.player_square)){
                break;
            }
        }
        update_board(current_player.player_symbol, current_player.player_square);
        }
}
void main(){
    player_t player_1, player_2;
    while(TRUE){
        system("cls");
        printf("\nPlayer 1 Symbol ('X' or 'O'): "); //indicate the symboles
        player_1.player_symbol = toupper(fgetc(stdin)); // pass lowercase characters for easier input for user
        if((int)player_1.player_symbol == (int)'X' || (int)player_1.player_symbol == (int)'O'){
            break;
        }
    }
    player_2.player_symbol = (char)((int)'X' + (int)'O' - (int)player_1.player_symbol);
    printf("Player 2 Symbol: %c\n", player_2.player_symbol);
    system("pause");

    while(TRUE){
        play(player_1, player_2, PLAYER_1);
        play(player_1, player_2, PLAYER_2);
        if(check_win(player_1.player_symbol) || check_win(player_2.player_symbol)){
            system("cls");
            print_board();
            printf("Player %c Has Won!\n", (check_win(player_1.player_symbol)) ? player_1.player_symbol : player_2.player_symbol);
            break;
        }
        if(!check_win(player_1.player_symbol) && !check_win(player_2.player_symbol) && return_remaining_squares()[0] == 0){
            system("cls");
            print_board();
            printf("Draw.");
            break;
        }
    }
    printf("Thank you for playing! Till next time.\nSingle player mode coming soon.");
}
