#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------
	Chiedo all'utente di inserire tre numeri.
	Calcolo la media.
	<6  INSUFFICIENTE
	>=6 SUFFICIENTE
	>7  BUONO
	>8  OTTIMO
	
	Matteo Gheza
	------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	float v1, v2, v3 = 0;
	float media = 0;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	printf("Calcola la media di 3 voti forniti dall'utente\n");
	
	printf("Inserisci il primo voto: ");
	scanf("%f", &v1);
	printf("Inserisci il secondo voto: ");
	scanf("%f", &v2);
	printf("Inserisci il terzo voto: ");
	scanf("%f", &v3);
	
	media = (v1 + v2 + v3)/3;
	
	printf("\n\nIl tuo risultato è: ");
	if(media > 8) {
		printf("OTTIMO");
	} else if(media > 7) {
		printf("BUONO");
	} else if(media >= 6) {
		printf("SUFFICIENTE");
	} else {
		printf("INSUFFICIENTE");
	}
	printf("\nLa media è di %.2f.\n\n", media);

	//Blocca l'esecuzione del programma per permettere all'utente di leggere l'output
	//quando il programma viene eseguito "standalone"
	system("pause");

	return 0;
}
