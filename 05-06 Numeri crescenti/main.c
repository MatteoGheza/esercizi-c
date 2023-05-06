#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

/*
	-------------------------------------------------
	Leggere un array di interi di 10 posizioni,
    e dire se i valori memorizzati nell’array sono
    memorizzati in modo crescente.
	Matteo Gheza
	-------------------------------------------------
*/

#define N_ELEM 10

int main(int argc, char *argv[]) {
	float nPrec, nAttuale;
    bool crescenti = true;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Verranno richiesti %d numeri.\n\n", N_ELEM);

    printf("Inserisci il 1° numero: ");
    scanf("%f", &nPrec);

    for (int i = 2; i <= N_ELEM; i++) {
        printf("Inserisci il %d° numero: ", i);
        scanf("%f", &nAttuale);

        if(nAttuale < nPrec) crescenti = false;
        nPrec = nAttuale;
    }

    if(crescenti) {
        printf("\nTutti i numeri che hai inserito sono in ordine crescente.\n");
    } else {
        printf("\nNon tutti i numeri che hai inserito sono in ordine crescente.\n");
    }

	return 0;
}
