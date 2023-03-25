#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	-------------------------------------------------------------------------------------------
	Chiedi all'utente di inserire quanti n chilometri ha percorso con x litri di benzina.
    Il programma calcola e stampa quanti chilometri percorre una moto con 1 litro di benzina.
	Matteo Gheza
	-------------------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	float chilometriPercorsi = 0, litriConsumati = 0;
    float chilometriPerLitro = 0;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Calcola quanti chilometri percorre una moto con 1L di benzina\n");
    do {
        printf("Inserisci i chilometri percorsi: ");
        scanf("%f", &chilometriPercorsi);
    } while (chilometriPercorsi <= 0);
    do {
        printf("Inserisci i litri consumati: ");
        scanf("%f", &litriConsumati);
    } while (litriConsumati <= 0);

    chilometriPerLitro = chilometriPercorsi / litriConsumati;

    printf("Con 1L di benzina, la tua moto percorrerà %.2f chilometri.\n", chilometriPerLitro);

	return 0;
}
