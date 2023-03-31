#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	--------------------------------------------------------------------------------------------------------
	Le vocali preferite dai bambini
    Una maestra chiede ai bambini quale sia la loro vocaleScelta preferita.
    Realizzare un programma che chieda ad ogni bambino di inserire la sua vocale preferita,
    e che mostri alla fine dell'inserimento la vocale con maggior numero di preferenze.

    In questa implementazione, ho provato ad usare una matrice di interi per la conta, ma non è
    la struttura dati ideali, dato che utilizza interi come chiavi, quindi mi richiede di complicare
    eccessivamente il codice.
    In C++ avrei potuto usare map, o una struttura dati simile, e in C avrei potuto usare uno
    struct, ma ancora una volta il codice sarebbe diventato troppo complesso.
	Matteo Gheza
	--------------------------------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    char vocaleScelta, confermaContinuaInserimento;

    int contaVocale[5], elementoContaVocale;

    char vocalePreferita;
    int votiVocalePreferita;

    //Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    do {
        printf("\nInserisci la vocale che preferisci: ");
        scanf(" %c", &vocaleScelta);

        if (vocaleScelta == 'a' || vocaleScelta == 'A') {
            elementoContaVocale = 0;
        } else if (vocaleScelta == 'e' || vocaleScelta == 'E') {
            elementoContaVocale = 1;
        } else if (vocaleScelta == 'i' || vocaleScelta == 'I') {
            elementoContaVocale = 2;
        } else if (vocaleScelta == 'o' || vocaleScelta == 'O') {
            elementoContaVocale = 3;
        } else if (vocaleScelta == 'u' || vocaleScelta == 'U') {
            elementoContaVocale = 4;
        }
        contaVocale[elementoContaVocale]++;

        printf("Continuare con l'inserimento [s/N]: ");
        scanf(" %c", &confermaContinuaInserimento);
    } while (confermaContinuaInserimento == 's' || confermaContinuaInserimento == 'S');

    for (int i = 0; i < 5; i++)
    {
        if(contaVocale[i] > votiVocalePreferita) {
            votiVocalePreferita = contaVocale[i];

            if(i == 0) {
                vocalePreferita = 'A';
            } else if(i == 1) {
                vocalePreferita = 'E';
            } else if(i == 2) {
                vocalePreferita = 'I';
            } else if(i == 3) {
                vocalePreferita = 'O';
            } else if(i == 4) {
                vocalePreferita = 'U';
            }
        }
    }

    printf("La vocale preferita è %c, con %d voti.\n", vocalePreferita, votiVocalePreferita);

	return 0;
}
