#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>

/*
	----------------------------------------------------------------------------
	Chiedere all'utente di inserire 5 numeri con la virgola
    (questi numeri rapprestentano le quantità di altrettanti prodotti).
    Il prezzo unitario è solo 1 e lo inserisce in input l'utente.
    Calcolare il prezzo totale e riportare qual è la quantità massima inserita.
	Matteo Gheza
	----------------------------------------------------------------------------
*/

#define N_PRODOTTI 5

int main(int argc, char *argv[]) {
	float prezzo_unit, prezzo_tot;
    int qnt[N_PRODOTTI], qnt_max = -1, qnt_min = INT_MAX;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Piattaforma per venditori delle nostre mele, provenienti dal Trentino\n\n");
    
    do {
        printf("Inserire prezzo unitario: ");
        scanf("%f", &prezzo_unit);
    } while (prezzo_unit <= 0);

    printf("Gli acquirenti per questa lista di ordini sono %d.\n", N_PRODOTTI);
    printf("Ora è necessario inserire le quantità di prodotto richiesta da ognuno.\n\n");

    for (int i = 0; i < N_PRODOTTI; i++) {
        do {
            printf("Quantità prodotti per cliente %d: ", i+1);
            scanf("%d", &qnt[i]);
        } while (qnt[i] <= 0);

        prezzo_tot += prezzo_unit * qnt[i];
        if(qnt[i] > qnt_max) qnt_max = qnt[i];
        if(qnt[i] < qnt_min) qnt_min = qnt[i];
    }

    printf("\nInserimento ordini completato.\n");
    printf("Incasso totale: %.2f Euro\n", prezzo_tot);
    printf("Quantità maggiore richiesta: %d\n", qnt_max);
    printf("Quantità minima richiesta: %d\n", qnt_min);

	return 0;
}
