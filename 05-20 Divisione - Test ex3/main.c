#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	---------------------------------------------------------------------------
	Definire un programma nel linguaggio C che risolva la seguente situazione:
    inserire un numero x che sia maggiore di 5 (se tale condizione non è
    rispettata chiedere nuovamente il valore). Chiedere all'utente di
    inserire y numeri interi.
    Calcolare la divisione tra ciascun valore y e il valore di x
    e stampare, ogni volta, i calcoli effettuati.
    Il programma termina quando viene inserito il valore -1 per y.
	Matteo Gheza
	---------------------------------------------------------------------------
*/

#define VALORE_MINIMO_DIVISORE 5
#define VALORE_STOP_INSERIMENTO -1

int main(int argc, char *argv[]) {
	float divisore, dividendoTmp, risultatoTmp;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Inserisci un numero, per il quale verranno divisi altri numeri. Sono ammessi decimali.\n");
    do {
        printf("Deve essere maggiore di %d. Inserisci il numero: ", VALORE_MINIMO_DIVISORE);
        scanf("%f", &divisore);
    } while (divisore < VALORE_MINIMO_DIVISORE);

    printf("\nVerrà richiesto di fornire alcuni numeri. Per fermare l'inserimento, inserisci \"%d\".\n", VALORE_STOP_INSERIMENTO);
    
    printf("Inserisci un numero: ");
    scanf("%f", &dividendoTmp);
    while (dividendoTmp != VALORE_STOP_INSERIMENTO) {
        risultatoTmp = dividendoTmp / divisore;
        printf("%.2f / %.2f = %.2f\n\n", dividendoTmp, divisore, risultatoTmp);

        printf("Inserisci un numero: ");
        scanf("%f", &dividendoTmp);
    }

	return 0;
}
