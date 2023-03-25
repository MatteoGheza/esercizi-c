#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*
	------------------------------------------------------------------
	Il professor Random ha un'età casuale tra 20 e 60 anni.
    Realizzare un programma che permetta all'utente di provare a indovinare l'età del professore.
    L'utente avrà a disposizione illimitati tentativi in cui:
    - Se l'utente inserisce il numero scelto dal computer,
      il programma mostrerà la scritta "Hai vinto!" e terminerà la sua esecuzione.
    - Se l'utente inserisce un numero più piccolo rispetto a quello pensato dal computer,
      il programma mostrerà la scritta "Il prof Random è più vecchio"
    - Se l'utente inserisce un numero più grande rispetto a quello pensato dal computer,
      il programma mostrerà la scritta "Il prof Random è più giovane"
    BONUS: conteggio dei tentativi
	Matteo Gheza
	------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	int etaRandom = 0, etaInserita = 0, tentativi = 0;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Benvenuto nel programma che ti permette di indovinare l'età del prof Random.\n");
    printf("Ricorda che il prof ha età compresa tra 20 e 60 anni.\n\n");

    srand(time(NULL));
    etaRandom = 20 + rand() % 41; //Trova un numero random tra 0 e 40 e somma 20.

    do {
        printf("Inserisci l'età che pensi il prof possa avere: ");
        scanf("%d", &etaInserita);
        
        if (etaInserita > etaRandom) {
            printf("Il prof Random è più giovane\n");
        } else if (etaInserita < etaRandom) {
            printf("Il prof Random è più vecchio\n");
        }

        tentativi++;
    } while (etaInserita != etaRandom);

    printf("\nHai vinto!\nL'età del prof Random è %d.\nHai indovinato ", etaRandom);
    if(tentativi == 1) {
        printf("al primo tentativo, che fortuna!\n");
    } else {
        printf("in %d tentativi.\n", tentativi);
    }

	return 0;
}
