#include <stdio.h>
#include "my_mat.h"

/**
 * Reads user input.
 * Calls necessary functions.
*/
int main(){

    char c; // Stores user input. Used to call methods.

    int quit = 0; // Used to break out of 'while' loop.

    int matrix[10][10]; // Represents graph.

    resetMatrix(matrix);

    while (quit != 1){
        
        //printf("Enter choice here: ");
        scanf("%c", &c);

        switch(c){

            case 'A':
                buildMatrix(matrix);
                break;

            case 'B':
                pathExists(matrix);
                break;

            case 'C':
                getShortPath(matrix, 1);
                break;

            case 'D':
                quit = 1;
                break;

            case 'P':
                printMatrix(matrix);
                break;
        }
    }

    //printf("\n");
    return 0;
}