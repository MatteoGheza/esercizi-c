#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	-------------------------------------------------------------------------
	Dato il numero di studenti di una classe, data la media di ogni studente
    in input, definire il credito di ogni studente sapendo che:
    - se la media è compresa tra 6 e 8, credito 5
    - se la media è compresa tra 9 e 10, credito 10
	Matteo Gheza
	-------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	float media = 0;
    int nStudenti = 0, credito = 0;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Calcolo del credito data la media\n");
    do {
        printf("Inserisci il numero di studenti: ");
        scanf("%d", &nStudenti);
    } while (nStudenti <= 0);

    printf("\n");
    for (int i = 0; i < nStudenti; i++) {
        printf("Inserisci media dello studente: ");
        scanf("%f", &media);

        if(media < 6) {
            printf("Media non sufficiente, calcolo non necessario.\n");
        } else if(media < 9) {
            credito = 5;
        } else {
            credito = 10;
        }
        printf("Credito: %d\n\n", credito);
    }

	return 0;
}
