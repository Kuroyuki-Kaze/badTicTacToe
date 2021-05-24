#include <stdio.h>
#include <stdlib.h>
#define true 1

int main() {
    //Initial board
    int a = 32, b = 32, c = 32, d = 32, e = 32, f = 32, g = 32, h = 32, i = 32;

    //Verbose Status
    printf("\nBoard initialized.\n");
    printf("Game started.\n");
    printf("Get three in a row to win!\n");
    printf("The valid range for row and column is 1-3!\n\n");

    //Game loop
    while (true) {
        int row = 0, column = 0;
        int r = 0;
        int badflag = 0;

        //Player 1
        printf("Player 1's turn:\n");
        printf("Board:\n\n");
        printf("-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n\n", a, b, c, d, e, f, g, h, i);
        
        //Player 1 validation loop
        do {

            //Value Reset
            r = 0;
            row = 0, column = 0;
            badflag = 0;

            //Prompt user to give row
            printf("Enter the row: ");

            //Get row
            int arg1a = scanf("%d", &row);
            scanf("%*[^\n]");
            scanf("%*c");

            //Error handling
            while (true) {

                //TypeError handling
                if (arg1a != 1) {
                    printf("Bad input!\n\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                    printf("Enter row again: ");
                    arg1a = scanf("%d", &row);
                }

                //ValueError: Index out of range error handling
                else if (row < 1 || row > 3) {
                    printf("Row or column is not in the valid range!\n\n");
                    printf("Enter row again: ");
                    row = 0;
                    arg1a = scanf("%d", &row);
                }

                //End error handling
                else {
                    break;
                }
            }

            //Prompt user to input the column
            printf("Enter the column: ");

            //Get column
            int arg1b = scanf("%d", &column);
            scanf("%*[^\n]");
            scanf("%*c");

            //Column error handling
            while (true) {

                //TypeError handling
                if (arg1b != 1) {
                    printf("Bad input!\n\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                    printf("Enter column again: ");
                    arg1b = scanf("%d", &column);
                }

                //ValueError: Index out of bounds handling
                else if (column < 1 || column > 3) {
                    printf("Row or column is not in the valid range!\n\n");
                    printf("Enter column again: ");
                    column = 0;
                    arg1b = scanf("%d", &column);
                }

                //End error handling
                else {
                    break;
                }
            }

            //2D -> 1D mapping
            r = 3 * (row-1) + (column-1);

            //Board setting
            switch (r)
            {
            case 0:

                //If the cell is not filled, fill with the symbol "x"
                if (a == 32) {
                    a = 120;
                }

                //Otherwise, tell the user that it is already filled
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 1:
                if (b == 32) {
                    b = 120;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 2:
                if (c == 32) {
                    c = 120;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 3:
                if (d == 32) {
                    d = 120;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 4:
                if (e == 32) {
                    e = 120;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 5:
                if (f == 32) {
                    f = 120;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 6:
                if (g == 32) {
                    g = 120;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 7:
                if (h == 32) {
                    h = 120;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 8:
                if (i == 32) {
                    i = 120;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            }
        } while (badflag != 0);

        //Win condition check
        if ((a == b && b == c && a != 32) || (d == e && e == f && d != 32) || (g == h && h == i && g != 32 ) || (a == d && d == g && a != 32) || (b == e && e == h && b != 32) || (c == f && f == i && c != 32) || (a == e && e == i && a != 32) || (c == e && e == g && c != 32)) {
            printf("-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n\n", a, b, c, d, e, f, g, h, i);
            printf("Player 1 has won!\n");
            break;
        }

        //Draw condition check
        else if (a != 32 && b != 32 && c != 32 && d != 32 && e != 32 && f != 32 && g != 32 && h != 32 && i != 32) {
            printf("-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n\n", a, b, c, d, e, f, g, h, i);
            printf("Draw!\n");
            break;
        }

        //Player 2
        printf("Player 2's turn:\n");
        printf("Board:\n\n");
        printf("-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n\n", a, b, c, d, e, f, g, h, i);
        
        //Player 2 validation loop
        do {
            //Value Reset
            r = 0;
            row = 0, column = 0;
            badflag = 0;

            //Prompt user to input row
            printf("Enter the row: ");

            //Get row
            int arg2a = scanf("%d", &row);
            scanf("%*[^\n]");
            scanf("%*c");

            //Row error handling
            while (true) {

                //TypeError handling
                if (arg2a != 1) {
                    printf("Bad input!\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                    printf("Enter row again: ");
                    arg2a = scanf("%d", &row);
                }

                //ValueError: Index out of bounds error handling
                else if (row < 1 || row > 3) {
                    printf("Row or column is not in the valid range!\n");
                    printf("Enter row again: ");
                    row = 0;
                    arg2a = scanf("%d", &row);
                }

                //End error handling
                else {
                    break;
                }
            }

            //Prompt user to input the column
            printf("Enter the column: ");

            //Get column
            int arg2b = scanf("%d", &column);
            scanf("%*[^\n]");
            scanf("%*c");

            //Column error handling
            while (true) {
                

                //TypeError handling
                if (arg2b != 1) {
                    printf("Bad input!\n");
                    scanf("%*[^\n]");
                    scanf("%*c");
                    printf("Enter column again: ");
                    arg2b = scanf("%d", &column);
                }

                //ValueError: Index out of bounds error handling
                else if (column < 1 || column > 3) {
                    printf("Row or column is not in the valid range!\n");
                    printf("Enter column again: ");
                    column = 0;
                    arg2b = scanf("%d", &column);
                }

                //End error handling
                else {
                    break;
                }
            }


            r = 3 * (row-1) + (column-1);

            //Board setting
            switch (r)
            {
            case 0:
                //If cell is not filled, fill the cell with symbol "o"
                if (a == 32) {
                    a = 111;
                }

                //Otherwise, tell the user that it is already filled
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 1:
                if (b == 32) {
                    b = 111;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 2:
                if (c == 32) {
                    c = 111;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 3:
                if (d == 32) {
                    d = 111;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 4:
                if (e == 32) {
                    e = 111;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 5:
                if (f == 32) {
                    f = 111;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 6:
                if (g == 32) {
                    g = 111;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 7:
                if (h == 32) {
                    h = 111;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            case 8:
                if (i == 32) {
                    i = 111;
                }
                else {
                    printf("Cell has been already filled!\n\n");
                    badflag = 1;
                }
                break;
            }
        } while (badflag != 0);

        //Win check
        if ((a == b && b == c && a != 32) || (d == e && e == f && d != 32) || (g == h && h == i && g != 32 ) || (a == d && d == g && a != 32) || (b == e && e == h && b != 32) || (c == f && f == i && c != 32) || (a == e && e == i && a != 32) || (c == e && e == g && c != 32)) {
            printf("-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n\n", a, b, c, d, e, f, g, h, i);
            printf("Player 2 has won!\n");
            break;
        }

        //Draw condition check
        else if (a != 32 && b != 32 && c != 32 && d != 32 && e != 32 && f != 32 && g != 32 && h != 32 && i != 32) {
            printf("-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n| %c | %c | %c |\n-------------\n\n", a, b, c, d, e, f, g, h, i);
            printf("Draw!\n");
            break;
        }
    }

    //Game end
    return 0;
}