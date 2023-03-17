#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	----------------------------------------------------------------------
	Simuliamo la definizione dello scontrino di una spesa online.
    All'utente chiediamo:
    - Numero di articoli che vogliono comprare, sapendo che 1 <= n <= 100
    - Chiedo il prezzo e la quantità totale
    - Stampo il costo finale che l'utente deve pagare

    PARTE 2:
    - Se n. articoli < 20 --> applica sconto del 10%
    - Se n. articoli < 50 --> applica sconto del 12%
	Matteo Gheza
	----------------------------------------------------------------------
*/

#define N_MAX_PRODOTTI 100 //Numero massimo di prodotti acquistabili per spesa

#define ARTICOLI_MAX_1 20 //N. articoli massimo per applicazione dello sconto 1
#define SCONTO_1 10.0

#define ARTICOLI_MAX_2 50 //N. articoli massimo per applicazione dello sconto 2
#define SCONTO_2 12.0

int main(int argc, char *argv[]) {
    int nArt = 0;
    float prezzoArt = 0, prezzoTot = 0;
    float percentualeSconto = 0; //percentualeSconto è float per permettere l'uso di sconti di percentuale decimale
    int qntArt = 0;

    //Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("SPESA ONLINE CostaPoco®\n\n");
    do {
        printf("Per non indebitarti con tutti i rincari prezzi che ci sono, puoi acquistare al massimo %d articoli.\n", N_MAX_PRODOTTI);
        printf("Se il numero di articoli che acquisti è inferiore a %d, verrà applicato uno sconto del %.2f%%\n", ARTICOLI_MAX_1, SCONTO_1);
        printf("Se il numero di articoli che acquisti è inferiore a %d, verrà applicato uno sconto del %.2f%%\n", ARTICOLI_MAX_2, SCONTO_2);
        printf("\nInserisci il numero di articoli acquistati: ");
        scanf("%d", &nArt);
    } while(nArt < 1 || nArt > N_MAX_PRODOTTI);
    printf("\n");

    for (int i = 1; i <= nArt; i++)
    {   
        do {
            printf("Inserisci il prezzo del %d ° articolo: ", i);
            scanf("%f", &prezzoArt);
        } while (prezzoArt <= 0);
        do {
            printf("Inserisci la quantità acquistata: ");
            scanf("%d", &qntArt);
        } while (qntArt <= 0);
        printf("\n");

        prezzoTot += prezzoArt * qntArt;
    }

    if(nArt < ARTICOLI_MAX_1) percentualeSconto = SCONTO_1;
    if(nArt < ARTICOLI_MAX_2) percentualeSconto = SCONTO_2;

    prezzoTot = prezzoTot - prezzoTot * percentualeSconto / 100;

    printf("Il totale della spesa è di %.2f €\n", prezzoTot);
    if(percentualeSconto > 0) {
        //I caratteri '%%' servono solo per mostrare il simbolo di % senza utilizzare la formattazione di printf
        printf("È stato applicato uno sconto del %.2f%%\n", percentualeSconto);
    }
    printf("Grazie per averci scelto per i tuoi acquisti.\n");   

	return 0;
}
