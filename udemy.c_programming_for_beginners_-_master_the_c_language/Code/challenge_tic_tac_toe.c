#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char square[3][3] = {
                    {'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}
                };
int player_turn = 0;
char player_icon;
int size[2] = {sizeof(square) / (sizeof(char) * 3), 3};
char position; 

/* Function Prototypes */
char check_for_win(char icon);
void mark_board();
bool tie();


int main()
{
    int i;
    printf("  Tic Tac Toe\n");
    mark_board();
    while (true){
        if (player_turn % 2 == 0) player_icon = 'O';
        else player_icon = 'X';
        printf("Player %c: ",player_icon);
        scanf("%c",&position);
        getchar();
        for (int i = 0; i < 3; i++){
            for (int ii = 0; ii < 3; ii++){
                if (square[i][ii] == position) {
                    square[i][ii] = player_icon;
                }
            }
        }
        printf("\n");
        system("clear");
        mark_board();
        player_turn += 1;
        if (check_for_win('O') != false){
            printf("\nCongratulations O wins!");
            break;
        }
        else if (check_for_win('X') != false){
            printf("\nCongratulations X wins!");
            break;
        }

        if (tie()) {
            printf("\nIt's a tie");
            break;
        }
    }

    return 0;
}

void mark_board(){
    for (int i = 0; i < 3; i++){
        for (int ii = 0; ii < 3; ii++){
            ii != 2 ? printf("  %c  |",square[i][ii]) : printf("  %c",square[i][ii]);
        }
        if (i != 2) printf("\n---------------\n");
    }
    printf("\n");
}

char check_for_win(char icon){
    if (square[0][0] == icon && square[1][0] == icon && square[2][0] == icon) return icon; // vertical
    if (square[0][1] == icon && square[1][1] == icon && square[2][1] == icon) return icon; // vertical
    if (square[0][2] == icon && square[1][2] == icon && square[2][2] == icon) return icon; // vertical
    if (square[0][0] == icon && square[0][1] == icon && square[0][2] == icon) return icon; // horizontal
    if (square[1][0] == icon && square[1][1] == icon && square[1][2] == icon) return icon; // horizontal
    if (square[2][0] == icon && square[2][1] == icon && square[2][2] == icon) return icon; // horizontal
    if (square[0][0] == icon && square[1][1] == icon && square[2][2] == icon) return icon; // diagonal
    if (square[2][0] == icon && square[1][1] == icon && square[0][2] == icon) return icon; // diagonal
    return false;
}

bool tie(){
    bool t = true;
    for (int i = 0; i < size[0]; i++){
        for (int ii = 0; ii < size[1]; ii++){
            if (square[i][ii] == '1' || square[i][ii] == '2' || square[i][ii] == '3' || 
                square[i][ii] == '4' || square[i][ii] == '5' || square[i][ii] == '6' ||
                square[i][ii] == '7' || square[i][ii] == '8' || square[i][ii] == '9' ) 
            t = false;
        }
    }
    return t; 
}

/* Output: 
  Tic Tac Toe
  1  |  2  |  3
---------------
  4  |  5  |  6
---------------
  7  |  8  |  9
Player O: 1
  O  |  2  |  3
---------------
  4  |  5  |  6
---------------
  7  |  8  |  9
Player X: 2   
  O  |  X  |  3
---------------
  4  |  5  |  6
---------------
  7  |  8  |  9
Player O: 3
  O  |  X  |  O
---------------
  4  |  5  |  6
---------------
  7  |  8  |  9
Player X: 4  
  O  |  X  |  O
---------------
  X  |  5  |  6
---------------
  7  |  8  |  9
Player O: 5     
  O  |  X  |  O
---------------
  X  |  O  |  6
---------------
  7  |  8  |  9
Player X: 6  
  O  |  X  |  O
---------------
  X  |  O  |  X
---------------
  7  |  8  |  9
Player O: 7  
  O  |  X  |  O
---------------
  X  |  O  |  X
---------------
  O  |  8  |  9

Congratulations O wins!
*/
