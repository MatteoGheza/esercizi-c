#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------
	Chiedere all'utente di inserire una serie di numeri positivi. In caso di numero negativo richiedo il valore e lo stampo.
	Matteo Gheza
	------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	float num = 0; //Numero inserito dall'utente	

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");
	
	//Ripeti all'infinito, fino alla chiusura del programma
	while(1) {
		//Chiedi all'utente un numero
		printf("Inserisci un numero:\t");
		scanf("%f", &num);
		
		//Finché il numero è minore di 0, chiedi all'utente di inserirne uno nuovo che sia positivo
		while (num < 0) {
			printf("Il numero deve essere POSITIVO. Inserisci di nuovo un numero:\t");
			scanf("%f", &num);
		}
		
		//Stampa il numero inserito
		printf("Il numero inserito è %.2f\n", num);
	}
	
	//Non viene mai raggiunta la fine del programma, salvo errori gravi o chiusura forzata. Le istruzioni contenute nello while sono ripetute all'infinito.

	return 0;
}
