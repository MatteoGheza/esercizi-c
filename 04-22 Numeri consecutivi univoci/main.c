#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------
	Far inserire una serie numerica di interi fermandosi quando
    viene inserito due volte consecutive lo stesso numero.
	Matteo Gheza
	------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	int nElem = 0, lastNum, num;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Inserisci una serie di numeri, dove due elementi consecutivi devono essere univoci.\n");
    printf("L'inserimento si ferma quando questa indicazione non viene rispettata.\n\n");

    printf("Inserisci un numero: ");
    scanf("%d", &num);

    //Race condition del primo num inserito, che può essere uguale al valore di lastNum,
    //al quale non è ancora stato assegnato un valore preso dai dati inseriti
    while (nElem == 0 || num != lastNum) {
        lastNum = num;
        nElem++;

        printf("Inserisci un numero: ");
        scanf("%d", &num);
    }

    printf("I due numeri inseriti sono uguali (=%d).\nHai inserito %d elementi, escludendo l'ultimo inserito.\n", num, nElem);

	return 0;
}
