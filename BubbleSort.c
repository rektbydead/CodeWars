#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define TAM 100

//awful on long arrays
int main(){
    srand(time(NULL));

    int array[TAM];
    for(int i = 0; i < TAM; i++)
        array[i] = rand() % TAM;

    for(int i = 0; i < TAM; i++)
        printf("%d ", array[i]);
    
     clock_t start_clk = clock();

    int swap;
    do {
        swap = 0;
        for(int i = 0; i < TAM - 1; i++) {
            if (array[i] > array [i + 1]) {
        
                int aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
                swap = 1;
            }
        }
    } while (swap == 1);


    for(int i = 0; i < TAM; i++)
        printf("%d ", array[i]);
}
