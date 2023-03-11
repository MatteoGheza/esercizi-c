#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------
	Chiedi all'utente un numero e restituisci il nome del mese
	corrispondente
	Matteo Gheza
	------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	int mese = 0;
	

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	printf("Inserisci un numero compreso tra 1 e 12: ");
	scanf("%d", &mese);

	switch(mese) {
		case 1:
			printf("Gennaio");
			break;
		case 2:
			printf("Febbraio");
			break;
		case 3:
			printf("Marzo");
			break;
		case 4:
			printf("Aprile");
			break;
		case 5:
			printf("Maggio");
			break;
		case 6:
			printf("Giugno");
			break;
		case 7:
			printf("Luglio");
			break;
		case 8:
			printf("Agosto");
			break;
		case 9:
			printf("Settembre");
			break;
		case 10:
			printf("Ottobre");
			break;
		case 11:
			printf("Novembre");
			break;
		case 12:
			printf("Dicembre");
			break;
		default:
			printf("Numero inserito non valido.");
	}
	printf("\n\n");

	return 0;
}
