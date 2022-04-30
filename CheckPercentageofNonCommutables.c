// C Program to get the percentage of NonCommutables in a given vector
// Vec.h from https://github.com/Mashpoe/c-vector
// compile with the command gcc CheckPercentageofNonCommutables.c vec.c -o CheckPercentageofNonCommutables

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vec.h"

#define SIZE 3

// A utility function to print a vector
void printVector (int vec[])
{
    int n = vector_size(vec);
    for (int i = 0; i < n; i++)
        printf("%d ", vec[i]);
    printf("\n");
}

// A utility function to swap two integers
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Returns 1 if commutable, 0 if not commutable
int checkIfCommutable(int vec1[], int vec2[]) {
    int n = vector_size(vec1);

    for (int i = 0; i <= n; i++) {
        if (vec2[vec1[i]] == vec1[vec2[i]]) {
            ; // effectively passes
        }
        else {
            return 0;
        }
    return 1;
    }
}

// A utility function to find all possible permutations of a given vector.
// Takes in a vector, the starting index, and the ending index.
int permute(int vec[], int start, int end) {
    if (start == end) {
        printVector(vec);
        }
    else
    {
        for (int i = start; i<=end; i++) {
            swap((vec+i), (vec+start));
            permute(vec, start+1, end);
            swap((vec+i), (vec+start));

        }
    }
}

// Driver program to test above functions.
int main() {
int* num_vec = vector_create();
    for (int i = 1; i<=SIZE; i++) {
        vector_add(&num_vec, i);
    }
    int n = vector_size(num_vec);
    permute(num_vec, 0, n-1);
    //printVector(num_vec);
}