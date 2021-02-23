#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define TAM 99999

int main(){

    //define array and it's values
    int array[TAM], counter = 0;
    for(int i = 0; i < TAM; i++)
        array[i] = i + ++counter;

    //create random number
    srand(time(NULL));
    int randomNumber = array[rand() % TAM];
    printf("\nGenerated number: %d", randomNumber);

    int tries = 0;
    //normal way to do it (me if I ever become a programmer lmao)
    for(int i = 0; i < TAM; i++){
        if (array[i] == randomNumber)
            break;

        tries++;
    }
    
    printf("\nNormal way to do it: %d iterations", tries);
    tries = 1;

    //smart way to do it (I would never do something like this because I'm lazy
    int middlePos = TAM/2;
    while(array[middlePos - 1] != randomNumber) {
        static int anterior = 0;
        int divisor = round((float)abs(middlePos - anterior)/2.0);

        anterior = middlePos;
        if (randomNumber > array[middlePos - 1]) //always -1 because "middlePos" could have TAM as value
            middlePos += divisor; 
        else //if (randomNumber < array[middlePos - 1]) - always -1 because "middlePos" could have TAM as value
            middlePos -= divisor; 
        
        tries++;
    }

    printf("\nSmart way to do it -> %d iterations", tries);
    printf("\nThe number %d is on index %d", array[middlePos - 1], middlePos - 1);
}
