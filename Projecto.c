#include <stdio.h>
#include <stdlib.h>
#define true 1

int main() {
    char a[3][3] = {{32,32,32},{32,32,32},{32,32,32}};
    while (true) {
        // turn 1
        int r = 0, c = 0;
        // board printer
        for (int i = 1; i <= 3; i++) {
            printf("-------------\n");
            for (int j = 1; j <= 3; j++) {
                printf("| %c ", a[i-1][j-1]);
            }
            printf("|\n");
        }
        printf("-------------\n");
        
        printf("player 1\n");
        printf("Enter row y column: ");
        int args1 = scanf("%d%d", &r, &c);
        // error correction
        while (true) {
            if (args1 != 2) {
                printf("Bad input!\n");
                scanf("%*[^\n]");
                scanf("%*c");
                r = 0, c = 0;
                printf("Enter it again: ");
                scanf("%d%d", &r, &c);
            }
            else if (r < 1 || r > 3 || c < 1 || c > 3) {
                printf("Row or column out of range!\n");
                scanf("%*[^\n]");
                scanf("%*c");
                r = 0, c = 0;
                printf("Enter it again: ");
                scanf("%d%d", &r, &c);
            }
            else {
                break;
            }
        }
        while (true) {
            if (a[r-1][c-1] != 111 && a[r-1][c-1] != 120) {
                a[r-1][c-1] = 120;
                break;
            }
            else {
                printf("That cell is already filled!\n");
                r = 0, c = 0;
                printf("Enter it again: ");
                int args1 = scanf("%d%d", &r, &c);
                // error correction
                while (true) {
                    if (args1 != 2) {
                        printf("Bad input!\n");
                        scanf("%*[^\n]");
                        scanf("%*c");
                        r = 0, c = 0;
                        printf("Enter it again: ");
                        scanf("%d%d", &r, &c);
                    }
                    else if (r < 1 || r > 3 || c < 1 || c > 3) {
                        printf("Row or column out of range!\n");
                        scanf("%*[^\n]");
                        scanf("%*c");
                        r = 0, c = 0;
                        printf("Enter it again: ");
                        scanf("%d%d", &r, &c);
                    }
                    else {
                        break;
                    }
                }
            }
        }

        //turn 2
        r = 0;
        c = 0;
        //board printer
        for (int i = 1; i <= 3; i++) {
            printf("-------------\n");
            for (int j = 1; j <= 3; j++) {
                printf("| %c ", a[i-1][j-1]);
            }
            printf("|\n");
        }
        printf("-------------\n");

        printf("player 2\n");
        printf("Enter row y column: ");
        int args2 = scanf("%d%d", &r, &c);
        //error correction
        while (true) {
            if (args2 != 2) {
                printf("Bad input!\n");
                scanf("%*[^\n]");
                scanf("%*c");
                r = 0, c = 0;
                printf("Enter it again: ");
                scanf("%d%d", &r, &c);
            }
            else if (r < 1 || r > 3 || c < 1 || c > 3) {
                printf("Row or column out of range!\n");
                scanf("%*[^\n]");
                scanf("%*c");
                r = 0, c = 0;
                printf("Enter it again: ");
                scanf("%d%d", &r, &c);
            }
            else {
                break;
            }
        }
        while (true) {
            if (a[r-1][c-1] != 111 && a[r-1][c-1] != 120) {
                a[r-1][c-1] = 111;
                break;
            }
            else {
                printf("That cell is already filled!\n");
                r = 0, c = 0;
                printf("Enter it again: ");
                int args1 = scanf("%d%d", &r, &c);
                // error correction
                while (true) {
                    if (args1 != 2) {
                        printf("Bad input!\n");
                        scanf("%*[^\n]");
                        scanf("%*c");
                        r = 0, c = 0;
                        printf("Enter it again: ");
                        scanf("%d%d", &r, &c);
                    }
                    else if (r < 1 || r > 3 || c < 1 || c > 3) {
                        printf("Row or column out of range!\n");
                        scanf("%*[^\n]");
                        scanf("%*c");
                        r = 0, c = 0;
                        printf("Enter it again: ");
                        scanf("%d%d", &r, &c);
                    }
                    else {
                        break;
                    }
                }
            }
        }

    }
    return 0;
}