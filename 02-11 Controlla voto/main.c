#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------
	11 Febbraio - Controlla voto
	Matteo Gheza
	------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	float voto = 0;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	printf("Controlla il voto di informatica: � sufficiente o insufficiente?\n");
	
	printf("Inserisci il voto di informatica: ");
	scanf("%f", &voto);
	
	if(voto >= 6) {
		if(voto >= 7) {
			if(voto >= 8) {
				if(voto >= 9) {
					printf("BRAVA PROF\n");
				} else {
					printf("BRAVO/A\n");
				}
		    } else {
				printf("DISCRETO\n");
		    }
		} else {
			printf("SUFFICIENTE\n");
		}
	} else {
		printf("INSUFFICIENTE\n");
	}

	return 0;
}

