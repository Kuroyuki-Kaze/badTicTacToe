//Import headers necessary for the program to work
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

//Function to check the win codition
int wincheck(char **board) {

    //Win condition check mode: Sudden （一瞬）
    //If a win condition is found, immediately return true
    //Otherwise, return false

    //Row win condition check
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] != 32)) {
            return true;
        }
    }

    //Column win condition check
    for (int j = 0; j < 3; j++) {
        if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && (board[0][j] != 32)) {
            return true;
        }
    }

    //Diagonal win condition check
    if (((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[0][0] != 32)) || ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[0][2] != 32))) {
        return true;
    }
    
    return false;
}

//Function to check the draw condition
int drawcheck(char **board) {

    //Draw condition check mode: Resistence（耐久）
    //Check until none of the cells are spaces, then return true
    //Otherwise, return false.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 32) {
                return false;
            }
        }
    }

    return true;
}


//Board printer function
void printboard(char **board) {
    for (int i = 0; i < 3; i++) {
        printf("-------------\n");
        for (int j = 0; j < 3; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("-------------\n\n");
}

//Main game
int main() {
    int row = 0, column = 0;
    int turn = 0;
    int player = 0;
    int argA = 0, argB = 0;
    char **board;
    
    //Board initialization, dynamic
    board = (char **) malloc(3 * sizeof(char *));
    if (board == NULL) {
        printf("ERROR: Memory allocation failure.\n");
        printf("Exiting game.\n");
        return EXIT_FAILURE;
    }

    //Board row initialization, dynamic
    for (int i = 0; i < 3; i++) {
        board[i] = (char *) malloc(3 * sizeof(char));
        if (board[i] == NULL) {
            printf("ERROR: Memory allocation failure.\n");
            printf("Exiting game.\n");
            return EXIT_FAILURE;
        }

        //Baord population => space
        for (int j = 0; j < 3; j++) {
            board[i][j] = 32;
        }
    }
    
    //Verbose statuses
    printf("Board inititialized.\n");
    printf("Game started.\n\n");
    printf("Get three in a row to win!\n");
    printf("Player 1 is X, Player 2 is O.\n");
    printf("The valid range for row and column is 1-3!\n\n");

    //Game loop
    while (true) {

        //Variable resets
        argA = 0, argB = 0;
        player = turn % 2 + 1;

        //Player indicator, and board display
        printf("\nPlayer %d's turn!\n", player);
        printf("Board:\n");
        printboard(board);

        //Player validation loop
        while (true) {

            //Prompt and fetch row
            printf("Enter the row: ");
            argA = scanf("%d", &row);

            //Row validation loop
            while (true) {

                //TypeError handling
                if (argA != 1) {
                    printf("Bad input!\n\n");
                    fflush(stdin);
                    printf("Enter the row again: ");
                    argA = scanf("%d", &row);
                }

                //ValueError: Index Out Of Bounds handling
                else if (row < 1 || row > 3) {
                    printf("Row is not in the valid range!\n\n");
                    fflush(stdin);
                    printf("Enter the row again: ");
                    argA = scanf("%d", &row);
                }

                //If no error, continue forward
                else {
                    break;
                }
            }

            //Prompt and fetch column
            printf("Enter the column: ");
            argB = scanf("%d", &column);

            //Column validation loop
            while (true) {

                //TypeError handling
                if (argB != 1) {
                    printf("Bad input!\n\n");
                    fflush(stdin);
                    printf("Enter the column again: ");
                    argB = scanf("%d", &column);
                }

                //ValueError: Index out of bound handling
                else if (column < 1 || column > 3) {
                    printf("Column is not in the valid range!\n\n");
                    fflush(stdin);
                    printf("Enter the column again: ");
                    argA = scanf("%d", &column);
                }

                //If no error, continue forward
                else {
                    break;
                }
            }

            //Set "X" if player 1, and the cell isn't filled
            if (board[row - 1][column - 1] == 32 && player == 1) {
                board[row - 1][column - 1] = 88;
                break;
            }

            //Set "O" if player 2, and the cell isn't filled
            else if (board[row - 1][column - 1] == 32 && player == 2) {
                board[row - 1][column - 1] = 79;
                break;
            }

            //Otherwise, tell the player it has been filled and go back up
            else {
                printf("Cell has already been filled!\n\n");
                continue;
            }
        }

        //Check win
        if (wincheck(board)) {
            system("cls");
            printf("Board:\n");
            printboard(board);
            printf("Player %d has won the game!\n\n", player);
            break;
        }

        //Check draw
        else if (drawcheck(board)) {
            system("cls");
            printf("Board:\n");
            printboard(board);
            printf("Draw!\n\n");
            break;
        }

        //Increment turn
        else {
            turn++;
            system("cls");
        }
    }

    return EXIT_SUCCESS;
}