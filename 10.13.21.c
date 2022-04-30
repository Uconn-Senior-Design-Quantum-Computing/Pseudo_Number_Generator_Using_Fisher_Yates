// C Program to
// Vec.h from https://github.com/Mashpoe/c-vector
// compile with the command gcc 10.13.21.c vec.c -o 10.13.21

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "vec.h"

#define SIZE 3
#define POSS_PERM 6 // x! / (x / y) = 5! / (5-5)! (Where X is number of digits possible and Y is length of combination)
int permutations[POSS_PERM][SIZE];

int count = 0;

void addToPermutations(int vector_int) {
    int i, j;
    for(i=0; i<count; i++) {
       for(j=0;j<SIZE;j++) {
           permutations[count][j] = vector_int;
    }
   }
}

void printMatrixOfPermutations() {
    for(int i=0; i<POSS_PERM; i++) {
        for(int j=0;j<SIZE;j++) {
            printf("%d ", permutations[i][j]);
            if(j==2){
                printf("\n");
         }
        }
       }
}

// A utility function to swap two integers
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// A utility function to print a vector
void printVector (int vec[])
{
    int n = vector_size(vec);
    for (int i = 0; i < n; i++)
        printf("%d ", vec[i]);
    printf("\n");
}

 // A function to generate a random permutation of a vector
void randomize ( int vec[])
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
        if (count > 0) {
            printVector(vec);
            printf("\n");
            for (int i = 0; i<=SIZE-1; i++) {
                printf("VEC[i] = %d\n", vec[i]);
                //addToPermutations(vec[i]);
                }
        }
        count+=1;
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

// Driver program to test above function.
int main()
{
    int* num_vec = vector_create();
    for (int i = 1; i<=SIZE; i++) {
        vector_add(&num_vec, i);
    }
    randomize (num_vec);
    // Print vector with the first group of added ints
    printVector(num_vec);

    int n = vector_size(num_vec);
    permute(num_vec, 0, n-1);
    printMatrixOfPermutations();
    return 0;
}