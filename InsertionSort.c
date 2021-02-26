#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define TAM 99999

//good at small arrays
int main(){
    srand(time(NULL));

    int array[TAM];
    for(int i = 0; i < TAM; i++)
        array[i] = rand() % TAM;

    for(int i = 0; i < TAM; i++)
        printf("%d ", array[i]);

    for (int i = 1; i < TAM; i++) { 
        int value = array[i];

        int j = i;
        while (--j >= 0 && array[j] > value)
            array[j + 1] = array[j]; 

        array[j + 1] = value; 
    } 

    printf("\n\n\n\n");
    for(int i = 0; i < TAM; i++)
        printf("%d ", array[i]);
}
