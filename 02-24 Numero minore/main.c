#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------
	Trova il numero minore tra 3 forniti dall'utente
	Matteo Gheza
	------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	float a, b, c = 0;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	printf("Trova il numero minore\n");
	
	printf("Inserisci il 1° numero: ");
	scanf("%f", &a);
	printf("Inserisci il 2° numero: ");
	scanf("%f", &b);
	printf("Inserisci il 3° numero: ");
	scanf("%f", &c);
	
	printf("\nIl numero maggiore è: ");
	if(a < b) {
		if(a < c) {
			printf("1° numero, %.2f", a);
		} else {
			printf("3° numero, %.2f", c);
		}
	} else {
		if(b < c) {
			printf("2° numero, %.2f", b);
		} else {
			printf("3° numero, %.2f", c);
		}
	}
	
	printf("\n");

	//Blocca l'esecuzione del programma per permettere all'utente di leggere l'output
	//quando il programma viene eseguito "standalone"
	system("pause");

	return 0;
}
