/**
 * Reads values from user to build a 10x10 matrix.
*/
void buildMatrix(int matrix[10][10]);

/**
 * Reads user input for nodes 'i' and 'j'.
 * Prints 'True' if a path from node 'i' to 'j' exists.
 * Otherwise, prints 'False'.
*/
void pathExists(int matrix[10][10]);

/**
 * Reads user input for nodes 'i' and 'j'.
 * Returns shortest path from node 'i' to 'j'.
 * If no path exists, returns -1.
*/
int getShortPath(int matrix[10][10], int flag);

/**
 * Sets all matrix values to 0. 
*/
void resetMatrix(int matrix[10][10]);

/**
 * Assistant recursive function.
 * Returns 1 if a path between node 'i' and 'j' exists.
 * Otherwise, returns 0.
 * 
 * 'root' is the original value of 'i' entered by user.
 * 'flag' is 1 if it's the first method call. Otherwise, 0.
*/
int pathExistsRec(int i, int j, int matrix[10][10], int root, int flag);

/**
 * Assistant function.
 * Prints out matrix state.
*/
void printMatrix(int matrix[10][10]);

/**
 * Assistant function.
 * Copies contents of 'original' into 'newCopy'.
*/
void copyMatrix(int newCopy[10][10], int original[10][10]);

