#include <stdio.h>
#include <stdlib.h>

/*
	--------------------------------------------------------------------
	Esercizio di calcolo della media, risolto utilizzando funzioni in C
	per verificarne il funzionamento.
	Matteo Gheza
	--------------------------------------------------------------------
*/

float calcoloMedia(int n1, int n2, int n3);
void chiediDatiCalcolaMedia();

int main(int argc, char *argv[]) {
	chiediDatiCalcolaMedia();

	return 0;
}

//Funzione, esegue un'operazione e restituisce dei valori
float calcoloMedia(int n1, int n2, int n3) {
	float media;

	media = (n1+n2+n3)/3;

	return media;
}

//Procedura, non restituisce valori
void chiediDatiCalcolaMedia() {
	int n1=0,n2=0,n3=0;
	float media;

	printf("Calcola la media\n\n");

	printf("Inserisci il numero 1: ");
	scanf("%d", &n1);
	printf("\nInserisci il numero 2: ");
	scanf("%d", &n2);
	printf("\nInserisci il numero 3: ");
	scanf("%d", &n3);

	media = calcoloMedia(n1, n2, n3);

	printf("\n\nLa media è %.2f", media);
}
