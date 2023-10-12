#include <stdio.h>
#include <stdlib.h>

/*
	------------------------------------------------------------------
	Biglietti per il concerto
    - se num biglietti <4: no sconto
    - se num biglietti <10: sconto del 5
    - se num biglietti supera i 10: sconto del 10

    -il prezzo del biglietto è di 80 euro

    Scrivere:
    - procedura che definisca i prezzi
    - procedura di stampa del prezzo scontato
    - funzione che calcola il prezzo scontato

	Matteo Gheza
	------------------------------------------------------------------
*/

#define PREZZO 80

float calcolaPrezzoScontato(int sconto);

void calcolaPrezzi(int nBiglietti);
void stampaCostoBiglietti(float prezzo, int nBiglietti);

int main(int argc, char *argv[]) {
	int nBiglietti;

    printf("Calcolo prezzi biglietti concerto\n");
    
    printf("Quanti biglietti vuoi acquistare? ");
    scanf("%d", &nBiglietti);

    calcolaPrezzi(nBiglietti);

	return 0;
}

float calcolaPrezzoScontato(int sconto) {
    float prezzo = PREZZO;
    prezzo = prezzo - prezzo/100*sconto;
    return prezzo;
}

void calcolaPrezzi(int nBiglietti) {
    float cBigliettoScontato;
    int sconto;

    if (nBiglietti < 4) {
        sconto = 0;
        printf("Nessuno sconto applicato\n\n");
    } else {
        if (nBiglietti < 4) {
            sconto = 5;
        } else {
            sconto = 10;
        }
        printf("Applicato uno sconto del %d%%\n\n", sconto);
    }

    cBigliettoScontato = calcolaPrezzoScontato(sconto);

    stampaCostoBiglietti(cBigliettoScontato, nBiglietti);
}

void stampaCostoBiglietti(float prezzo, int nBiglietti) {
    float cBigliettiTot = prezzo * nBiglietti;

    printf("Il costo scontato di ogni biglietto è di %.2f€\n", prezzo);
    printf("Il costo totale da pagare è di %.2f€\n", cBigliettiTot);
}
