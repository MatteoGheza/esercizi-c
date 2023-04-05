#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------------------------------
	Le vocali preferite dai bambini
    Una maestra chiede ai bambini quale sia la loro vocaleScelta preferita.
    Realizzare un programma che chieda ad ogni bambino di inserire la sua vocale preferita,
    e che mostri alla fine dell'inserimento la vocale con maggior numero di preferenze.

	Matteo Gheza
	------------------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    char vocaleScelta, confermaContinuaInserimento;

    int contaA = 0, contaE = 0, contaI = 0, contaO = 0, contaU = 0;

    char vocalePreferita;
    int votiVocalePreferita;

    //Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    do {
        printf("Inserisci la vocale che preferisci: ");
        scanf(" %c", &vocaleScelta);

        if (vocaleScelta == 'a' || vocaleScelta == 'A') {
            contaA++;
        } else if (vocaleScelta == 'e' || vocaleScelta == 'E') {
            contaE++;
        } else if (vocaleScelta == 'i' || vocaleScelta == 'I') {
            contaI++;
        } else if (vocaleScelta == 'o' || vocaleScelta == 'O') {
            contaO++;
        } else if (vocaleScelta == 'u' || vocaleScelta == 'U') {
            contaU++;
        }

        printf("Continuare con l'inserimento [s/N]: ");
        scanf(" %c", &confermaContinuaInserimento);
    } while (confermaContinuaInserimento == 's' || confermaContinuaInserimento == 'S');

    if(contaA > votiVocalePreferita) {
        votiVocalePreferita = contaA;
        vocalePreferita = 'A';
    }
    if(contaE > votiVocalePreferita) {
        votiVocalePreferita = contaE;
        vocalePreferita = 'E';
    }
    if(contaI > votiVocalePreferita) {
        votiVocalePreferita = contaI;
        vocalePreferita = 'I';
    }
    if(contaO > votiVocalePreferita) {
        votiVocalePreferita = contaO;
        vocalePreferita = 'O';
    }
    if(contaU > votiVocalePreferita) {
        votiVocalePreferita = contaU;
        vocalePreferita = 'U';
    }

    printf("La vocale preferita è %c, con %d voti.\n", vocalePreferita, votiVocalePreferita);

	return 0;
}
