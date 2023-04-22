#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>

/*
	------------------------------------------------------------------
	Leggere una serie di numeri interi passati dall'utente,
    fermandosi al primo numero che rende la serie non crescente e
    restituendo quanti numeri erano stati inseriti.
	Matteo Gheza
	------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	int nElem = 0, lastNum, num = INT_MIN;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Inserisci una serie di numeri.\nPer interrompere l'inserimento, la sequenza non deve più essere crescente.\n\n");

    do {
        lastNum = num;

        printf("Inserisci un numero: ");
        scanf("%d", &num);

        nElem++;
    } while(num >= lastNum);

    printf("La sequenza non è più crescente.\nHai inserito %d elementi.\n", nElem-1);

	return 0;
}
