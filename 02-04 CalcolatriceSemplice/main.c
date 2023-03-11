#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	Chiedo all'utente numeri interi e
	calcolo le 4 operazioni fondamentali
	(somma, differenza, moltiplicazione, divisione)
	Stampo i 4 risultati calcolati
*/

int main(int argc, char *argv[]) {
	float n1 = 0, n2 = 0;
	float somma = 0, diff = 0, prodotto = 0, rapporto = 0;
	
	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	printf("Calcolatrice Semplice\n\n");
	
	printf("Inserisci il primo numero:\t");
	scanf("%f", &n1);
	
	printf("Inserisci il secondo numero:\t");
	scanf("%f", &n2);
	
	printf("\nRisultati:\n");
	
	somma = n1 + n2;
	printf("Somma:\t%.2f\n", somma);
	
	diff = n1 - n2;
	printf("Differenza:\t%.2f\n", diff);
	
	prodotto = n1 * n2;
	printf("Prodotto:\t%.2f\n", prodotto);
	
	if(n2 == 0) {
		printf("Divisione:\tIMPOSSIBILE! Il divisore � 0.\n");
	} else {
		rapporto = n1 / n2;
		printf("Divisione:\t%.2f\n", rapporto);
	}

	return 0;
}
