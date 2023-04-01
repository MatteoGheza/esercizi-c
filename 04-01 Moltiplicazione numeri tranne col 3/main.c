#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	----------------------------------------------------------------------------
	Creare un programma che esegue il prodotto dei numeri positivi in input.
	Se il numero inserito è uguale a 3, termina il ciclo e mostra il prodotto.
	Matteo Gheza
	----------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	float num, prodotto = 1;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	printf("Calcolo del prodotto di numeri positivi\nInserire il numero 3 per terminare l'inserimento.\n");

	printf("Inserisci un numero da moltiplicare: ");
	scanf("%f", &num);
	while (num != 3) {
		prodotto = prodotto * num;

		printf("Inserisci un numero da moltiplicare: ");
		scanf("%f", &num);
	}

	printf("Il prodotto dei numeri inseriti è %.2f.\n", prodotto);

	return 0;
}
