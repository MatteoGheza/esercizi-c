#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------------------------------
	Per aumentare il numero di visitatori di una mostra, si decide di far pagare il biglietto
	di ingresso differenziato in base all'età. Precisamente:
	- Inferiore a 5 anni: Gratuito
	- Fino a 10 anni €1
	- Da 11 a 17 anni €1,50
	- Da 18 a 26 anni €2
	- Oltre 26 anni €3
	Matteo Gheza
	------------------------------------------------------------------------------------------
*/

/*
  Per "età" nelle costanti inserite in seguito si intende l'età minima richiesta per essere considerati
  appartenenti a quella fascia di prezzo.
  Per "costo" si intende il costo del biglietto per la fascia di età.
  Non viene considerata la "fascia 0", di persone di età inferiore a quella richiesta per la 1°
  fascia d'età, che entreranno gratis.
*/
#define ETA_FASCIA_1 5
#define COSTO_FASCIA_1 1.0

#define ETA_FASCIA_2 11
#define COSTO_FASCIA_2 1.50

#define ETA_FASCIA_3 18
#define COSTO_FASCIA_3 2.0

#define ETA_FASCIA_4 27
#define COSTO_FASCIA_4 3.0

int main(int argc, char *argv[])
{
	int eta = 0;
	float cBiglietto = 0;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	printf("Trova il costo del biglietto della mostra\n");
	do
	{
		printf("Inserisci l'età del visitatore (in anni): ");
		scanf("%d", &eta);
	} while (eta <= 0);

	if (eta >= ETA_FASCIA_2) {
		if (eta >= ETA_FASCIA_3) {
			if (eta >= ETA_FASCIA_4) {
				cBiglietto = COSTO_FASCIA_4;
			} else {
				cBiglietto = COSTO_FASCIA_3;
			}
		} else {
			cBiglietto = COSTO_FASCIA_2;
		}
	} else {
		if (eta >= ETA_FASCIA_1) cBiglietto = COSTO_FASCIA_1;
	}

	if(cBiglietto > 0) {
		printf("Il biglietto costa €%.2f\n", cBiglietto);
	} else {
		printf("Il visitatore entra gratis, ha meno di %d anni.\n", ETA_FASCIA_1);
	}

	return 0;
}
