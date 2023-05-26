#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	---------------------------------------------------------------------------
	Definire un programma nel linguaggio C che risolva la seguente situazione:
    inserire 5 numeri che rappresentano i valori di altrettante età.
    Stampare quanti sono i soggetti che possono andare in pensione e quanti
    no. (Per andare in pensione è necessario avere almeno 65 anni)
	Matteo Gheza
	---------------------------------------------------------------------------
*/

#define N_ETA_DA_INSERIRE 5 //Numero di età che verranno richieste all'utente
#define ETA_PENSIONE 65 //Anni minimi necessari per andare in pensione
#define ETA_MAX 110 //Età massima che si può inserire; se viene inserito un valore maggiore, si chiede di reinserire il dato

int main(int argc, char *argv[]) {
	int etaTmp, cPensionabili = 0, cNonPensionabili;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Verrà richiesta l'età di %d persone, e verrà mostrato il conteggio dei soggetti che\n", N_ETA_DA_INSERIRE);
    printf("hanno raggiunto la data minima per andare in pensione (%d anni).\n\n", ETA_PENSIONE);

    for (int i = 1; i <= N_ETA_DA_INSERIRE; i++) {
        do {
            printf("Inserire l'età della %d° persona: ", i);
            scanf("%d", &etaTmp);
        } while (etaTmp < 0 || etaTmp > ETA_MAX);

        if(etaTmp >= ETA_PENSIONE) {
            cPensionabili++;
            //printf("La persona ha raggiunto l'età minima per la pensione.\n");
        }
    }

    printf("È stata inserita l'età di %d persone; ", N_ETA_DA_INSERIRE);
    if(cPensionabili == N_ETA_DA_INSERIRE) {
        printf("tutte hanno raggiunto l'età minima per richiedere la pensione.\n");
    } else if (cPensionabili == 0) {
        printf("nessuna di loro ha raggiunto l'età pensionabile.\n");
    } else {
        cNonPensionabili = N_ETA_DA_INSERIRE - cPensionabili;
        if(cPensionabili == 1) {
            printf("solo una ha l'età per richiedere la pensione, le altre (%d) no.\n", cNonPensionabili);
        } else {
            printf("%d hanno l'età per richiedere la pensione, le altre (%d) no.\n", cPensionabili, cNonPensionabili);
        }
    }

	return 0;
}
