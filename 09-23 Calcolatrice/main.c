#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	------------------------------------------------------------------
	Semplice calcolatrice
	Matteo Gheza
	------------------------------------------------------------------
*/

float somma(float n1, float n2);
float differenza(float n1, float n2);
float prodotto(float n1, float n2);
float divisione(float n1, float n2);

void stampaRisultato(float n1, float n2, char tipo);

int main(int argc, char *argv[]) {
    char tipo;
    float n1, n2, risultato;

	printf("CALCOLATRICE\n\n");

    printf("Inserisci il 1° numero: ");
    scanf("%f", &n1);

    printf("Inserisci il 2° numero: ");
    scanf("%f", &n2);

    printf("\nInserisci tipo operazione.\n");
    printf("+ Somma, - Differenza, * Moltiplicazione, / Divisione\n");
    scanf(" %c", &tipo);

    stampaRisultato(n1, n2, tipo);

	return 0;
}

float somma(float n1, float n2) {
    return n1 + n2;
}

float differenza(float n1, float n2) {
    return n1 - n2;
}

float prodotto(float n1, float n2) {
    return n1 * n2;
}

float divisione(float n1, float n2) {
    if(n2 == 0) return 0;
    return n1 / n2;
}

void stampaRisultato(float n1, float n2, char tipo) {
    float risultato;
    bool valido = true;

    printf("\nRisultato:\n");

    switch (tipo) {
        case '+':
            risultato = somma(n1, n2);
            break;

        case '-':
            risultato = differenza(n1, n2);
            break;

        case '*': case 'x':
            risultato = prodotto(n1, n2);
            break;

        case '/':
            if(n2 == 0) {
                valido = false;
                printf("Impossibile dividere per 0.\n");
            } else {
                risultato = divisione(n1, n2);
            }
            break;
    
        default:
            valido = false;
            printf("Tipo di operazione non valido.\n");
            break;
    }

    if(valido) {
        printf("%.2f %c %.2f = %.2f\n", n1, tipo, n2, risultato);
    }
}
