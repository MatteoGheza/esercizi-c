#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	----------------------------------------------------------------------------------------------------
	Visualizzare n termini, con n intero positivo fornito in ingresso, della successione di Fibonacci.

    Suggerimento: nella successione di Fibonacci i primi due termini
    sono 0 e 1, quelli successivi sono 1,2,3,5...: ogni termine si
    ricava addizionando i due precedenti
	Matteo Gheza
	----------------------------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	int n, tmp, fibPrimo = 0, fibSecondo = 1;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Inserisci un numero, superiore a 0, di elementi della sequenza di fibonacci che vuoi vedere.\n\n");

    do {
        printf("Inserisci il numero di termini: ");
        scanf("%d", &n);
    } while (n <= 0);

    for (int i = 0; i < n; i++) {
        printf("%d\n", fibPrimo);

        tmp = fibPrimo + fibSecondo;
        fibPrimo = fibSecondo;
        fibSecondo = tmp;
    }

	return 0;
}
