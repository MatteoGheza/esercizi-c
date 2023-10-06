#include <stdio.h>
#include <stdlib.h>

/*
	------------------------------------------------------------------
	Calcolo della spesa
    - Se acquisto >= 10€ e < 20€ --> 5% sconto
    - Se acquisto >= 20€ e < 50€ --> 10% sconto
    - Se acquisto >= 50€ --> 12% sconto
    Funzioni:
    - calcolaPScontato
    - calcolaPConIva
    Procedure:
    - assegnaSconto
    - stampaRisultato
	Matteo Gheza
	------------------------------------------------------------------
*/

#define IVA 4

float calcolaPScontato(float prezzo, float sconto);
float calcolaPConIva(float prezzo);

void assegnaSconto(float prezzo);
void stampaRisultato(float prezzo);

int main(int argc, char *argv[]) {
    float prezzo;

	printf("Calcolo della spesa\n\n");

    printf("Inserisci il prezzo: ");
    scanf("%f", &prezzo);

    assegnaSconto(prezzo);

	return 0;
}

float calcolaPScontato(float prezzo, float sconto) {
    return prezzo - prezzo/100*sconto;
}

float calcolaPConIva(float prezzo) {
    return prezzo + prezzo/100*IVA;
}

void assegnaSconto(float prezzo) {
    int sconto = 0;
    float prezzoTot;

    if(prezzo >= 50) {
        sconto = 12;
    } else if(prezzo >= 20) {
        sconto = 10;
    } else if(prezzo >= 10) {
        sconto = 5;
    }

    prezzoTot = calcolaPScontato(prezzo, sconto);
    prezzoTot = calcolaPConIva(prezzoTot);

    stampaRisultato(prezzoTot);
}

void stampaRisultato(float prezzo) {
    printf("Il prezzo da pagare è %.2f.\n", prezzo);
}
