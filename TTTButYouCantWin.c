#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define true 1
#define false 0

void try_to_win(char **board) {
    if (board[1][1] == 32) {
        board[1][1] = 79;
    }
    else if (board[2][0] == 32) {
        board[2][0] == 79;
    }
    else if (board[0][2] == 32 && board[1][1]) {
        board[1][1] == 79;
    }
}

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

int main() {
    int r = 0, c = 0;
    char **b;
    int turn = 0;
    int player = 0;
    int arg1 = 0, argA = 0, argB = 0;

    b = (char **) malloc(3 * sizeof(char *));
    if (b == NULL) {
        printf("ERROR: Memory allocation failed. Failure at: b.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 3; i++) {
        b[i] = (char *) malloc (3 * sizeof(char));
        if (b[i] == NULL) {
            printf("ERROR: Memory allocation failed. Failure at: b[%d]", i);
        }

        for (int j = 0; j < 3; j++) {
            b[i][j] = 32;
        }
    }

    printf("Board init.\n");
    printf("This gamed is hella rigged, so don't even try.\n");
    printf("Valid range is 1-3.\n\n");

    printf("Choose the player (1 or 2): ");
    arg1 = scanf("%d", &player);
    while (true) {
        if (arg1 != 1) {
            printf("Bad player input.\n\n");
            fflush(stdin);
            printf("Enter player again: ");
            arg1 = scanf("%d", &player);
        }
        else if (player != 1 && player != 2) {
            printf("Invalid input.\n\n");
            fflush(stdin);
            printf("Enter player again: ");
            arg1 = scanf("%d", &player);
        }
        else {
            break;
        }
    }

    

    while (true) {
        if (turn % 2 == 0) {
            argA = 0;
            
            if (player == 1) {
                //Player indicator, and board display
                printf("\nPlayer's turn!\n");
                printf("Board:\n");
                printboard(b);

                //Player validation loop
                while (true) {

                    //Prompt and fetch row
                    printf("Enter the row: ");
                    argA = scanf("%d", &r);

                    //Row validation loop
                    while (true) {

                        //TypeError handling
                        if (arg1 != 1) {
                            printf("Bad input!\n\n");
                            fflush(stdin);
                            printf("Enter the row again: ");
                            argA = scanf("%d", &r);
                        }

                        //ValueError: Index Out Of Bounds handling
                        else if (r < 1 || r > 3) {
                            printf("Row is not in the valid range!\n\n");
                            fflush(stdin);
                            printf("Enter the row again: ");
                            argA = scanf("%d", &r);
                        }

                        //If no error, continue forward
                        else {
                            break;
                        }
                    }

                    //Prompt and fetch column
                    printf("Enter the column: ");
                    argB = scanf("%d", &c);

                    //Column validation loop
                    while (true) {

                        //TypeError handling
                        if (argB != 1) {
                            printf("Bad input!\n\n");
                            fflush(stdin);
                            printf("Enter the column again: ");
                            argB = scanf("%d", &c);
                        }

                        //ValueError: Index out of bound handling
                        else if (c < 1 || c > 3) {
                            printf("Column is not in the valid range!\n\n");
                            fflush(stdin);
                            printf("Enter the column again: ");
                            argB = scanf("%d", &c);
                        }

                        //If no error, continue forward
                        else {
                            break;
                        }
                    }

                    //Set "X" if player 1, and the cell isn't filled
                    if (b[r - 1][c - 1] == 32) {
                        b[r - 1][c - 1] = 88;
                        break;
                    }

                    //Otherwise, tell the player it has been filled and go back up
                    else {
                        printf("Cell has already been filled!\n\n");
                        continue;
                    }
                }

                //Check win
                if (wincheck(b)) {
                    system("cls");
                    printf("Board:\n");
                    printboard(b);
                    printf("Player %d has won the game!\n\n", player);
                    break;
                }

                //Check draw
                else if (drawcheck(b)) {
                    system("cls");
                    printf("Board:\n");
                    printboard(b);
                    printf("Draw!\n\n");
                    break;
                }

                //Increment turn
                else {
                    turn++;
                    system("cls");
                }
            }
            else {
                printf("\nComputer's turn!\n");
                printf("Board:\n\n");
                printboard(b);

                try_to_win(b);
            }
        }
    }

}