#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*
	------------------------------------------------------------------
	L'utente deve inserire il voto che spera di ottenere nella verifica, che è un numero casuale generato
    dal computer con la funzione random.
    Se il voto inserito è giusto, informa l'utente che ha indovinato, altrimenti chiedi di inserire un
    voto più alto o più basso a seconda del voto inserito.
	Matteo Gheza
	------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	int votoRandom = 0, votoStimato = 0;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Benvenuto nel programma che ti permette di indovinare il voto che hai preso.\n\n");

    srand(time(NULL));
    votoRandom = 1 + rand() % 10; //Trova un numero random tra 0 e 10.

    do {
        printf("Inserisci il voto che pensi di avere: ");
        scanf("%d", &votoStimato);
        
        if (votoStimato < 0) {
            printf("Non esistono voti sotto lo 0, per tua fortuna\n");
        } else if (votoStimato > 10) {
            printf("Non esistono voti così alti, è già tanto se arrivi al 10\n");
        } else if (votoStimato > votoRandom) {
            printf("Illuso/a! Il tuo voto è più brutto di così...\n");
        } else if (votoStimato < votoRandom) {
            printf("Suvvia, un po' di fiducia!\n");
        }
    } while (votoStimato != votoRandom);

    printf("\nHai indovinato! Lo so che è dura da accettare, ma hai preso preso %d.\n", votoRandom);

	return 0;
}
