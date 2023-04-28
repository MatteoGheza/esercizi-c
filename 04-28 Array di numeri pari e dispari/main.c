#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	-----------------------------------------------------------------------------
	Realizza un array di x numeri, fallo popolare dall'utente e conta i num
    pari e dispari.
	Matteo Gheza
	-----------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	int sommaPari = 0, sommaDispari = 0, n;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    do {
        printf("Quanti numeri vuoi inserire? ");
        scanf("%d", &n);
    } while (n <= 0);

    int numeri[n];

    for (int i = 0; i < n; i++) {
        printf("Inserisci il numero %d:\t", i+1);
        scanf("%d", &numeri[i]);

        if(numeri[i] % 2) {
            sommaPari++;
        } else {
            sommaDispari++;
        }
    }

    printf("Hai inserito %d numeri pari e %d numeri dispari.\n", sommaPari, sommaDispari);

	return 0;
}
