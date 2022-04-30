// C Program to shuffle a given vector
// Vec.h from https://github.com/Mashpoe/c-vector
// compile with the command gcc PseudoRandom.c vec.c -o PseudoRandom
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vec.h"

#define SIZE 10

// A utility function to swap two integers
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize (int vec[])
{   
    int n = vector_size(vec);

    // Use a different seed value so that we don't get same
    // result each time we run this program
    srand ( time(NULL) );
 
    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
 
        // Swap vec[i] with the element at random index
        swap(&vec[i], &vec[j]);
    }
}

// Returns 1 if commutable, 0 if not commutable
int checkIfCommutable(int vec1[], int vec2[]) {
    int n = vector_size(vec1);

    for (int i = 1; i <= n; i++) {
        if (vec2[vec1[i]] == vec1[vec2[i]]) {
            ; // effectively passes
        }
        else {
            return 1;
        }
    return 0;
    }
}

// Driver program to test above functions.
int main() {
    int* num_vec1 = vector_create();
    int* num_vec2 = vector_create();

    for (int i = 0; i<=SIZE; i++) {
        vector_add(&num_vec1, i);
        vector_add(&num_vec2, i);
    }

    randomize(num_vec1);
    randomize(num_vec2);

    
    int n = vector_size(num_vec1);
    for (int i = 0; i <= n - 1; i++) {
        int value = checkIfCommutable(num_vec1, num_vec2);
        if (value == 1) {
            printf("is commutable\n");
        }
        else if(value == 0) {
            printf("is not commutable\n");
        }
    }

    return 0;
}