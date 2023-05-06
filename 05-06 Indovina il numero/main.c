#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*
	------------------------------------------------------------------
	Scrivere un programma che chiede un numero all’utente
    poi estrae 5 numeri compresi tra 1 e 90 compresi
    (tipo la tombola) e dice se è uscito il
    numero inserito dall’utente.
	Matteo Gheza
	------------------------------------------------------------------
*/

#define N_MIN 1 //Deve essere un numero intero positivo
#define N_MAX 90 //Deve essere un numero intero positivo, maggiore di N_MIN
#define N_ESTRAZIONI 5

int main(int argc, char *argv[]) {
    //In questo esercizio non uso le matrici dato che non necessario per risparmiare memoria
	int nUtente, nComputer;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    //Inizializza la generazione di numeri casuali che verrà usato dalla funzione rand()
    srand(time(NULL));

    printf("Inserisci un numero per tentare la fortuna!\n");
    printf("Ci saranno 5 estrazioni di numeri compresi tra 1 e 60 estremi compresi.\n\n");

    do {
        printf("Inserisci il numero scelto. Ricorda, deve essere compreso tra %d e %d (estremi compresi).\n", N_MIN, N_MAX);
        scanf("%d", &nUtente);
    } while (nUtente < N_MIN || nUtente > N_MAX);

    printf("\n");

    for (int i = 1; i <= N_ESTRAZIONI; i++) {
        printf("ESTRAZIONE #%d\n", i);
        nComputer = (rand() % (N_MAX - N_MIN + 1)) + N_MIN;

        if(nUtente == nComputer) {
            printf("HAI VINTO! Congratulazioni!\n");
            return 0;
        }
    }

    //Se viene raggiunta questa parte del programma, l'utente non ha vinto.
    printf("\nMi dispiace, non hai vinto. Ritenta e sarai più fortunato.\n");
    
	return 0;
}
