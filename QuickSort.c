#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define TAM 99999

//good on big arrays
//literally copied this from geeksfromgeeks
//didn't understand the algorithm at all
void quicksort(int number[TAM],int first,int last){

    if (first >= last)
        return;

    int pivot = first;
    int i = first;
    int j = last;

    while(i < j) {
        while(number[i] <= number[pivot] && i < last)
            i++;

        while(number[j] > number[pivot])
            j--;

        if(i < j){
            int temp = number[i];
            number[i] = number[j];
            number[j] = temp;
        }
    }

    int temp = number[pivot];
    number[pivot] = number[j];
    number[j] = temp;

    quicksort(number, first, j - 1);
    quicksort(number, j + 1, last);
}

int main(){
    srand(time(NULL));

    int array[TAM];
    for(int i = 0; i < TAM; i++)
        array[i] = rand() % TAM;

    //for(int i = 0; i < TAM; i++)
    //    printf("%d ", array[i]);

    quicksort(array, 0, TAM - 1);

    //printf("\n\n\n");
    for(int i = 0; i < TAM; i++)
        printf("%d ", array[i]);
}


