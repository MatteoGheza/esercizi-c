#include <stdio.h>
#include <stdlib.h>

/*
	------------------------------------------------------------------
	Biglietti per il cinema
    - se età <10 entri gratis
    - se età compresa tra 10 e 18 ridotto: paghi 5 euro
    - se età compresa tra 19 e 29: paghi 6.5 euro
    - altrimenti paghi 8 euro

    - se il numero di biglietti acquistati è minore o pari a 5 --> sconto del 12%
    - altrimenti sconto del 14

    Scrivere:
    - procedura che definisca i prezzi
    - procedura di stampa del prezzo scontato
    - funzione che calcola il prezzo scontato

    Assunzioni:
    - Si considera l'età di chi prende i biglietti, non l'età di ognuno dei clienti che ricevono i biglietti
	Matteo Gheza
	------------------------------------------------------------------
*/

float calcolaPrezzoScontato(float prezzo, int sconto);

void calcolaPrezzi(int eta, int nBiglietti);
void stampaCostoBiglietti(float prezzo, int nBiglietti);

int main(int argc, char *argv[]) {
	int eta, nBiglietti;

    printf("Calcolo prezzi biglietti cinema\n");

    printf("Quanti anni hai? ");
    scanf("%d", &eta);
    
    printf("Quanti biglietti vuoi acquistare? ");
    scanf("%d", &nBiglietti);

    calcolaPrezzi(eta, nBiglietti);

	return 0;
}

float calcolaPrezzoScontato(float prezzo, int sconto) {
    return prezzo - prezzo/100*sconto;
}

void calcolaPrezzi(int eta, int nBiglietti) {
    float cBiglietto, cBigliettoScontato;
    int sconto;

    if (eta < 10) {
        cBigliettoScontato = 0;
        printf("Sotto i 10 anni, entri gratis!\n\n");
    } else { //Per eseguire calcolo sconto solo per cBiglietto > 0
        if (eta <= 18) {
            cBiglietto = 5;
            printf("Tariffa ridotta\n\n");
        } else if (eta <= 29) {
            cBiglietto = 6.5;
            printf("Ingresso intero giovani\n\n");
        } else {
            cBiglietto = 8;
            printf("Ingresso intero adulti\n\n");
        }

        if (nBiglietti <= 5) {
            sconto = 12;
            printf("Applicato uno sconto del 12%%\n\n");
        } else {
            sconto = 14;
            printf("Applicato uno sconto del 14%%\n\n");
        }

        cBigliettoScontato = calcolaPrezzoScontato(cBiglietto, sconto);
    }

    stampaCostoBiglietti(cBigliettoScontato, nBiglietti);
}

void stampaCostoBiglietti(float prezzo, int nBiglietti) {
    float cBigliettiTot = prezzo * nBiglietti;

    printf("Il costo scontato di ogni biglietto è di %.2f€\n", prezzo);
    printf("Il costo totale da pagare è di %.2f€\n", cBigliettiTot);
}
