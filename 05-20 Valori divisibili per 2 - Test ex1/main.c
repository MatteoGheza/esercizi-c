#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	---------------------------------------------------------------------------
	Definire un programma nel linguaggio C che risolva la seguente situazione:
    inserire un numero x di valori interi e calcolare quanti fra questi
    sono divisibili per 2.
    Stampare a video il valore trovato.
	Matteo Gheza
	---------------------------------------------------------------------------
*/

#define N_DIVISORE 2

int main(int argc, char *argv[]) {
    /*
        Ho utilizzato una sola variabile, num, riassegnata ad ogni iterazione, per risparmiare
        memoria, dato che i numeri non devono essere utilizzati in altre aree del programma
        in seguito.
    */
	int x, num, cDivisibili = 0;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Verrà richiesto l'inserimento di una lista di numeri interi.\n");
    do {
        printf("Fornire il conteggio totale degli elementi che verranno inseriti: ");
        scanf("%d", &x);
    } while (x < 0);

    /*
        Ho utilizzato un for, con indice che parte da 1, in modo da mostrare all'utente
        anche la posizione in una lista (inesistente) dell'elemento che viene inserito.
    */
    for (int i = 1; i <= x; i++) {
        printf("Inserisci il %d° numero: ", i);
        scanf("%d", &num);

        if(num % N_DIVISORE == 0) cDivisibili++;
    }

    printf("Sono stati inseriti %d numeri, di cui %d divisibili per %d.\n", x, cDivisibili, N_DIVISORE);    

	return 0;
}
