#include <stdio.h>
#include <stdlib.h>

/*
	------------------------------------------------------------------
	Programma che definisca il seguente problema:
    - calcolare il costo del prodotto data qta e prezzo
    - calcolare lo sconto del costo in base alle seguenti condizioni:
        . se qta è minore di 10, sconto 10%
        . se qta è compresa tra 11 e 20, sconto 4%
        . altrimenti sconto 5%
    - definire stampa del valore calcolato
	Matteo Gheza
	------------------------------------------------------------------
*/

float calcolaPrezzoScontato(float prezzo, int sconto);
float calcolaPrezzoTot(float prezzo, int qta);

void trovaPrezzoScontato(float prezzo, int qta);
void stampaRisultato(float prezzo);

int main(int argc, char *argv[]) {
	int qta;
    float prezzoUnitario;

    printf("Calcolo del costo del prodotto\n");

    printf("Inserisci quantità: ");
    scanf("%d", &qta);

    printf("Inserisci prezzo: ");
    scanf("%f", &prezzoUnitario);

    trovaPrezzoScontato(prezzoUnitario, qta);

	return 0;
}

float calcolaPrezzoScontato(float prezzo, int sconto) {
    return prezzo - prezzo/100*sconto;
}

float calcolaPrezzoTot(float prezzo, int qta) {
    return prezzo * qta;
}

void trovaPrezzoScontato(float prezzo, int qta) {
    float prezzoScontato, prezzoTot;
    int sconto = 5;

    if (qta < 10) {
        sconto = 10;
    } else if (qta < 20) {
        sconto = 4;
    }
    printf("\nSconto del %d%% applicato.\n", sconto);

    prezzoScontato = calcolaPrezzoScontato(prezzo, sconto);
    prezzoTot = calcolaPrezzoTot(prezzoScontato, qta);

    stampaRisultato(prezzoTot);
}

void stampaRisultato(float prezzo) {
    printf("\nIl prezzo scontato è di %.2f euro.\n", prezzo);
}
