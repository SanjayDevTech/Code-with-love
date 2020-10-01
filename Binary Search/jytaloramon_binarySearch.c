/**
 * Binary search, or binary search, is a vector search algorithm that follows the division and conquest paradigm.
 * It assumes that the vector is ordered and performs successive divisions of the search space by comparing the searched element (key) with the element in the middle of the vector.
 * If the middle element of the vector for a key, a search ends successfully.
 * Otherwise, if the middle element comes before the searched element, then the search continues in the back half of the vector.
 * And finally, if the middle element comes after the key, the search continues in the previous half of the vector.
 * If the middle element does not match the key and the index from the beginning to the end, this means that the element does not exist in the list.
 * Complexity: worst - O (log n), medium - O (log n), best - O (1)
 * 
 * @author: Ytalo Ramon
 * @since: 01/10/2020
 * Ref.: Wikipédia
 * */

#include "stdio.h"
#include "stdlib.h"

#define MAX 15
#define MIDDLECAL(a, b)((a + b) / 2)

int *search(int value, int *vector, int startInterv, int endInterv);

int main(int argc, char const *argv[]){

    int vector[MAX] = {-1, 0, 1, 2, 4, 7, 10, 15, 20, 50, 74, 98, 100, 200, 300};

    int value, *resp;

    do {
        printf("Valor: ");
        scanf("%d", &value);

        resp = search(value, vector, 0, MAX);

        resp != NULL ? printf("Found: %d\n", *resp) : printf("Not Found!\n");
        printf("\n\n");
    } while(1);

    return 0;
}

int* search(int value, int *vector, int startInterv, int endInterv){
    int middle = MIDDLECAL(startInterv, endInterv);

    if (vector[middle] == value)
        return &vector[middle];

    if(endInterv - startInterv == 1)
        return NULL;

    return value < vector[middle] ? search(value, vector, startInterv, middle) : search(value, vector, middle, endInterv);
}