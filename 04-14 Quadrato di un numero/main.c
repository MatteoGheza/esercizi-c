#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	-------------------------------------------------------------------------------
	Creare un programma che mostra il quadrato di ogni numero fornito dall'utente,
    e si ferma all'inserimento di -1.
	Matteo Gheza
	-------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	float num, quadrato;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	printf("Calcolo del quadrato\nVerrà mostrato il quadrato dei numeri inseriti.\n");
    printf("Per interrompere l'esecuzione, inserire il numero '-1'.\n");

	printf("Inserisci un numero: ");
	scanf("%f", &num);
	while (num != -1) {
        quadrato = num*num;
        printf("%.2f\n", quadrato);

		printf("Inserisci un numero: ");
		scanf("%f", &num);
	}

	return 0;
}
