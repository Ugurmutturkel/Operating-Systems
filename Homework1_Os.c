#include <stdio.h>
#include <stdbool.h>

#define numrows 4
#define namelength 2
/**
 * Board holds the matchsticks and rows 
 */
struct Board {
    int rows[numrows];
    int sticks;
};
/**
 * player holds a booelan to see if it is a player or computer
 */
struct Player{
    bool playorcomp;
};
/**
 * This function helps the play funciton start and stop by giving it a boolean value
 *
 * @param board 
 * 
 * @return totalsticks
 */
bool start(struct Board board){
    int totalsticks = 0;
    for(int i = 0; i < numrows; i++ ){
        if (board.rows[i] < 0){
            return true;// if the numrows are smaller than 0 the game has ended
        }
        totalsticks += board.rows[i];//counts the total number of sticsk
    }
    return totalsticks == 0;//if the sticks end the game ends
}
/**
 * This function makes the game playable
 * it takes the start function to see if the game has ended or not
 * makes the player choose rows and matchsticks then removes the amount of sticks from the chosen row
 * changes players at the end of the turn
 *
 * @param Board, Player pointer, Player pointer
 * 
 * @return board
 */
struct Board play(struct Board board, struct Player *Player1, struct Player *Player2){
    struct Player *firsttoplay = Player1;
    struct Player *secondtoplay = Player2;
    int row,sticktopull;
    bool move = true;
    while(!start(board)){
        
        while(move){
            if (firsttoplay == Player1){
            printf("Player 1's turn\n");
            } 
            else {
            printf("Player 2's turn\n");
            }
            printf("Choose a row ");
            scanf("%d", &row);
            printf("Choose the number of matchsticks to remove ");
            scanf("%d", &sticktopull);
            if(row > 0 && sticktopull > 0 && row < numrows && sticktopull <= board.rows[row]){
                board.rows[row] -= sticktopull;
                move = false; // players move ended 
            }
            else {
                printf("Invalid move\n");
            }
            printboard(board);
        }
        move = true;//other player now can make a move

        if(firsttoplay == Player1){
            firsttoplay = Player2;
        }
        else{
            firsttoplay = Player1;
        } 
    }
    if (firsttoplay == Player1){
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }
    return board;
}
/**
 * This function prints the matchsticks for the game to be played with, the play function calls it to print every turn
 *
 * @param board 
 */
void printboard(struct Board board){
    for(int i = 0; i < numrows; i++ ){
        printf("%*s", numrows - i, "");//%*s is a format specifier that makes the function print a string of characters with the amount of given value which is numrows - i and the string is empty so this makes the empty spots on the left for the board
        for(int j = 0; j < board.rows[i]; j++){
            printf("I");
        }
        printf("\n");
    }
}
/**
 * This function starts a game with 2 players by initializing both players and calling the print and play functions
 *
 */
void playhuman() {

    // Initialize the board and players
    struct Board board;
    
    board.rows[0] = 0;
    board.rows[1] = 1;
    board.rows[2] = 3;
    board.rows[3] = 5;
    struct Player Player1 = {true};
    struct Player Player2 = {true};

    // Play the game
    
    printboard(board);
    play(board, &Player1, &Player2);
}

int main(){
    playhuman();
    return 0;
}