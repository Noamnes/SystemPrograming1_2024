#include <stdio.h>
#define max_weight 20
#define num_of_items 5
#define max_name 21

void printArr(int arr[],int len);
void printItems(char items[num_of_items][max_name]);
int knapSack(int weights[], int values[] , int selected_bool[]);
int max(int a, int b);

int main(){
    char items[num_of_items][max_name];
    int values[num_of_items];
    int weights[num_of_items];
    int result[num_of_items] = {0};

    // getting the input:
    for(int i=0; i<num_of_items; i++){
        // getting: name, value, weight 
        scanf("%s",&items[i][0]);
        scanf("%d",&values[i]);
        scanf("%d",&weights[i]);
    }

    int maximum_profit = knapSack(weights, values, result);

    printf("Maximum profit: %d\n", maximum_profit);
    printf("Selected items:");
    for(int i=0; i<num_of_items; i++){
        if(result[i]==1){
            printf(" %s",items[i]);
        }
    }

    // debug:
    // printf("\n\n  debug:\n");
    // printItems(items);
    // printf("\n");
    // printArr(values, sizeof(values)/sizeof(values[0]));
    // printf("\n");
    // printArr(weights, sizeof(weights)/sizeof(weights[0]));
    // printf("\n");
    // printItems(items);
    return 0;
}


// aid functions:

void printItems(char items[num_of_items][max_name]){
    for(int i=0; i<num_of_items; i++){
        printf("%s",items[i]);
        printf(" ");
    }
}

void printArr(int arr[],int len){
    printf("[");
    for(int i=0; i<len-1;i++){
        printf("%d,", arr[i]);
    }
    printf("%d]",arr[len-1]);
}

// solution:

int knapSack(int weights[], int values[], int selected_bool[]) {
    int i, w;
    int K[num_of_items + 1][max_weight + 1];

    // Build table K[][]
    for (i = 0; i <= num_of_items; i++) {
        for (w = 0; w <= max_weight; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // stores the result of Knapsack
    int result = K[num_of_items][max_weight];

    // Find which items are selected
    w = max_weight;
    for (i = num_of_items; i > 0 && result > 0; i--) {
        if (result == K[i - 1][w])
            continue;
        else {
            // This item is included.
            selected_bool[i - 1] = 1;
            // Since this weight is included its
            // value is deducted
            result = result - values[i - 1];
            w = w - weights[i - 1];
        }
    }

    return K[num_of_items][max_weight];
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
