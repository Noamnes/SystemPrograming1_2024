#include <stdio.h>

void resetMatrix(int matrix[10][10]){

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void buildMatrix(int matrix[10][10]){

    int value; // Stores user input.

    for (size_t i = 0; i < 10; i++)
    {  
        //printf("Line %zu \n", i);

        for (size_t j = 0; j < 10; j++)
        {
            // Skip if a value (entered by user) exists.
            //if (matrix[i][j] != 0) continue;

            //printf("\nNode %zu to %zu --> ", i, j);
            scanf("%d", &value);

            // In case user wishes to skip this line.
            if (value < 0) break;

            matrix[i][j] = value;
            //matrix[j][i] = value; 
        }
        
    }
    
}

int pathExistsRec(int i, int j, int matrix[10][10], int root, int flag){

    // Checking for direct path from node 'i' to 'j'.
    if (matrix[i][j] != 0 || i == j) return 1;

    // Breaking out of possible loop.
    if (i == root && flag == 0) return 0;

    for (size_t index = 0; index < 10; index++)
    {
        if (matrix[i][index] != 0 && index != i){
            if (pathExistsRec(index, j, matrix, root, 0) == 1) return 1;
        }
    }
    
    return 0;
}

void copyMatrix(int newCopy[10][10], int original[10][10]){

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {  
            if (original[i][j] == 0 && i != j){
                
                newCopy[i][j] = -1;
                continue;
            }

            newCopy[i][j] = original[i][j];
        }
        
    }
    
}

int getShortPath(int rootMatrix[10][10], int flag){

    int matrix[10][10];
    copyMatrix(matrix, rootMatrix); // Creating a custom made copy of the original matrix ('rootMatrix').

    int i, j; // Matrix index values. Represent graph nodes.
    
    // Initialization.
    i = 0;
    j = 0;

    int sum; // Used to save distance between nodes.

    //printf("Enter values 'i' 'j' for nodes: ");
    scanf("%d %d", &i, &j);

    // Using Floyd-Warshall Algorithm.
    for (size_t k = 0; k < 10; k++)
    {
        for (size_t i = 0; i < 10; i++)
        {
            for (size_t j = 0; j < 10; j++)
            {
                // -1 is equivilent to infinity.

                if (matrix[i][k] == -1 || matrix[k][j] == -1) continue;

                sum = matrix[i][k] + matrix[k][j];

                if (matrix[i][j] == -1 || matrix[i][j] > sum) matrix[i][j] = sum;
            }
            
        }
        
    }

    int shortestRoute = matrix[i][j];

    if (shortestRoute == 0) shortestRoute = -1;
    
    // Checking if program should print out a message.
    if (flag == 1) printf("%d\n", shortestRoute);
    
    return shortestRoute;
}

void pathExists(int matrix[10][10]){

    if (getShortPath(matrix, 0) != -1){
        printf("True\n");
    } else{
        printf("False\n");
    }
    //printf("\n");
}

void printMatrix(int matrix[10][10]){

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

