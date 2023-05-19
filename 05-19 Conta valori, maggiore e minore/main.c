#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------------------------
	Chiedere all'utente di inserire un numero con la virgola positivo (nel caso non lo
    fosse richiedi nuovamente). Chiedere all'utente di inserire n valori (l'inserimento
    termina quando l'utente inserisce il valore 3).
    Contare i valori maggiori rispetto al numero n e stampare il risultato calcolato.
	Matteo Gheza
	------------------------------------------------------------------------------------
*/

#define VALORE_STOP 3

int main(int argc, char *argv[]) {
	float nCentrale, nTemp;
    int cMaggiori = 0, cValori = 0;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    do {
        printf("Inserisci un numero positivo: ");
        scanf("%f", &nCentrale);
    } while (nCentrale < 0);    

    printf("Ora dovrai inserire una serie di numeri. Per interrompere la richiesta, inserisci il numero 3 (che NON sarà contato).\n");
    printf("Inserisci un numero: ");
    scanf("%f", &nTemp);

    while (nTemp != VALORE_STOP) {
        if(nTemp > nCentrale) cMaggiori++;
        cValori++;

        printf("Inserisci un numero: ");
        scanf("%f", &nTemp);
    }

    printf("\nHai inserito %d valori, di cui %d maggiori di %.2f.\n", cValori, cMaggiori, nCentrale);
    
	return 0;
}
