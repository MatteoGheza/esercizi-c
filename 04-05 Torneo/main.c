#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------
	Chiedere all'utente di inserire i gol segnati da 4 squadre,
    fino a quando l'utente decide di interrompere l'inserimento dati.
    Mostra all'utente quale squadra (A-D) ha vinto.
	Matteo Gheza
	------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	int golA = 0, golB = 0, golC = 0, golD = 0;
    int turno = 0, golTmp, max = -TMP_MAX;
    char vincitore, confermaContinuaInserimento;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Controlla quale squadra ha vinto\n\n");

	do {
        turno++;
        printf("%d° turno di partite\n", turno);

		printf("Inserisci i gol segnati dalla squadra A: ");
		scanf("%d", &golTmp);
        golA += golTmp;

        printf("Inserisci i gol segnati dalla squadra B: ");
		scanf("%d", &golTmp);
        golB += golTmp;

        printf("Inserisci i gol segnati dalla squadra C: ");
		scanf("%d", &golTmp);
        golC += golTmp;

        printf("Inserisci i gol segnati dalla squadra D: ");
		scanf("%d", &golTmp);
        golD += golTmp;        

		printf("Continuare con l'inserimento dei gol per il %d° turno? [s/N] ", turno+1);
		scanf(" %c", &confermaContinuaInserimento);
        
        printf("\n");
	} while (confermaContinuaInserimento == 's' || confermaContinuaInserimento == 'S');

    if(golA > max) {
        max = golA;
        vincitore = 'A';
    }
    if(golB > max) {
        max = golB;
        vincitore = 'B';
    }
    if(golC > max) {
        max = golC;
        vincitore = 'C';
    }
    if(golD > max) {
        max = golD;
        vincitore = 'D';
    }

    printf("\nLa squadra che ha vinto è la squadra %c, con %d gol in %d turni.\n", vincitore, max, turno);

	return 0;
}
