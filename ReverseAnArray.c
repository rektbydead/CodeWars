#include <stdio.h>

#define TAM 10

//easy peasy lemon squeezy
int main(){
    int array[TAM];
    for(int i = 0; i < TAM; i++)
        array[i] = i + 1;

    for(int i = 0; i < TAM; i++)
        printf("%d ", array[i]);
    
    for(int i = 0; i < TAM/2; i++) {
        int aux = array[i];
        array[i] = array[(TAM - 1) - i]; //(TAM - 1) because arrays ends at TAM - 1 not TAM
        array[(TAM - 1) - i] = aux;
    }

    printf("\n");
    for(int i = 0; i < TAM; i++)
      printf("%d ", array[i]);
}
