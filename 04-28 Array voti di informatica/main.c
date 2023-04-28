#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	-----------------------------------------------------------------------------
	Realizza un array di 10 voti di informatica, chiedi all'utente di popolarlo,
    calcola la somma
	Matteo Gheza
	-----------------------------------------------------------------------------
*/

#define N_VOTI 10

int main(int argc, char *argv[]) {
	int somma = 0;
    float media;

    int voti[N_VOTI];

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Calcolo media voti informatica\n\n");

    for (int i = 0; i < N_VOTI; i++) {
        printf("Inserisci il voto %d:\t", i+1);
        scanf("%d", &voti[i]);

        somma += voti[i];
    }

    media = somma / N_VOTI;
    printf("\nLa media dei voti inseriti è %.2f.\n", media);

    if(media >= 6) {
        printf("PROMOSSO/A\n");
    } else {
        printf("BOCCIATO/A\n");
    }

	return 0;
}
