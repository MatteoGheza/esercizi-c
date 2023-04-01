#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	----------------------------------------------------------------------------
	Creare un programma che esegue la somma dei numeri positivi in input.
	Se il numero inserito non è positivo, termina il ciclo e mostra la somma.
	Matteo Gheza
	----------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	float num, somma;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	printf("Calcolo della somma di numeri positivi\nInserire un numero negativo per terminare l'inserimento.\n");

	printf("Inserisci un numero da sommare: ");
	scanf("%f", &num);
	while (num >= 0) {
		somma += num;

		printf("Inserisci un numero da sommare: ");
		scanf("%f", &num);
	}

	printf("La somma dei numeri inseriti è %.2f.\n", somma);

	return 0;
}
