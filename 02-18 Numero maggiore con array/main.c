#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------
	Trova il numero maggiore tra 3 forniti dall'utente
	Matteo Gheza
	------------------------------------------------------------------
*/

//Uso una costante per permettere di modificare il comporamento del codice più velocemente
#define LEN 3 //Lunghezza della lista di numeri

int main(int argc, char *argv[]) {
	float num[LEN];
	int i = 0;
	int indexMax = 0;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	printf("Trova il numero maggiore\n");
	
	for(i = 0; i < LEN; i++) {
		printf("Inserisci il %d° numero: ", i+1); //Stampo i+1 perché gli indici degli array partono dallo 0
		scanf("%f", &num[i]);
	}
	
	for(i = 0; i < LEN; i++) {
		if(num[i] > num[indexMax])  {
			indexMax = i;
		}
	}
	
	printf("\nIl numero maggiore è il %d°: %.2f\n", indexMax+1, num[indexMax]); //Stampo indexMax+1 perché gli indici degli array partono dallo 0

	//Blocca l'esecuzione del programma per permettere all'utente di leggere l'output
	//quando il programma viene eseguito "standalone"
	system("pause");

	return 0;
}
