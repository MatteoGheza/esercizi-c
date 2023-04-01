#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	----------------------------------------------------------------------------------------------
	Creare un programma che chieda all'utente i voti di informatica, e alla fine dell'inserimento
    mostri la media.
	Matteo Gheza
	----------------------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	float voto, sommaVoti, media;
	int nVoti;
	char confermaContinuaInserimento;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	printf("Calcolo della media dei voti\n");

	do {
		printf("Inserisci il voto: ");
		scanf("%f", &voto);

		sommaVoti += voto;
		nVoti++;

		printf("Continuare con l'inserimento dei voti? [s/N] ");
		scanf(" %c", &confermaContinuaInserimento);
	} while (confermaContinuaInserimento == 's' || confermaContinuaInserimento == 'S');

	media = sommaVoti / nVoti;
	printf("La media dei %d voti che hai preso è %.2f.\n", nVoti, media);

	return 0;
}
