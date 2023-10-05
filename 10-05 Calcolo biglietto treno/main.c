#include <stdio.h>
#include <stdlib.h>

/*
	------------------------------------------------------------------
	Programma che calcola il costo del biglietto del treno.
    L'utente comunica l'età.
    Se minorenne, viaggia gratis
    Se ha meno di 30 anni, sconto 5%
    Se da 30 a 50 anni, sconto del 10%
    Altrimenti, sconto 15%
	Matteo Gheza
	------------------------------------------------------------------
*/

int calcolaSconto(int eta);
int calcolaPrezzoScontato(float prezzo, int sconto);
int calcolaPrezzoIvato(float prezzo);

void offertaBiglietti(int eta, float prezzo);

int main(int argc, char *argv[]) {
	int eta;
    float prezzo;

    printf("Calcolo del prezzo del biglietto, con tariffe agevolate\n\n");
    
    printf("Inserisci età: ");
    scanf("%d", &eta);

    printf("Inserisci prezzo iniziale biglietto: ");
    scanf("%f", &prezzo);

    offertaBiglietti(eta, prezzo);

	return 0;
}

int calcolaSconto(int eta) {
    int sconto = 15;

    if(eta < 18) {
        sconto = 100;
    } else if(eta < 30) {
        sconto = 5;
    } else if(eta < 50) {
        sconto = 10;
    }

    return sconto;
}

int calcolaPrezzoScontato(float prezzo, int sconto) {
    return prezzo - prezzo/100*sconto;
}

int calcolaPrezzoIvato(float prezzo) {
    return calcolaPrezzoScontato(prezzo, 22);
}

void offertaBiglietti(int eta, float prezzo) {
    int sconto = calcolaSconto(eta);
    float prezzoScontato = calcolaPrezzoScontato(prezzo, sconto);
    float prezzoIvato = calcolaPrezzoIvato(prezzoScontato);

    if(sconto == 100) {
        printf("\nHai diritto a viaggiare gratis.\n");
    } else if(sconto == 0) {
        printf("\nNon hai diritto ad uno sconto sulla tariffa.\n");
    } else {
        printf("\nHai diritto ad uno sconto del %d%%.\n", sconto);
    }

    printf("Il costo del biglietto (con IVA inclusa) è di %.2f€.\n", prezzoIvato);
}
