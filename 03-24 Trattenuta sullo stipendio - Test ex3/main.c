#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

/*
	------------------------------------------------------------------------------------------------------------------------
	Sullo stipendio dei dipendenti di una ditta viene applicata una trattenuta fiscale in base alla seguente tabella:
	- Scaglione 1: Trattenuta 5%
	- Scaglione 2: Trattenuta 10%
	- Scaglione 3: Trattenuta 15%
	- Scaglione 4: Trattenuta 25%
	- Scaglione 5: Trattenuta 35%
	Dato in input lo scaglione di appartenenza di un dipendente, calcola la trattenuta da versare.
	Matteo Gheza
	------------------------------------------------------------------------------------------------------------------------
*/

#define TRATTENUTA_SCAGLIONE_1 5.0
#define TRATTENUTA_SCAGLIONE_2 10.0
#define TRATTENUTA_SCAGLIONE_3 15.0
#define TRATTENUTA_SCAGLIONE_4 25.0
#define TRATTENUTA_SCAGLIONE_5 35.0

int main(int argc, char *argv[]) {
	int scaglione = 0;
	bool scaglioneValido = false;
	float stipendio = 0, trattenuta = 0, stipendioSenzaTrattenuta = 0;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	printf("Calcolo trattenuta fiscale sullo stipendio.\n");
	do {
		printf("Inserisci lo stipendio: ");
		scanf("%f", &stipendio);
	} while (stipendio <= 0);

	do {
		printf("Inserisci lo scaglione di appartenenza (1-5): ");
		scanf("%d", &scaglione);
		switch (scaglione) {
			case 1:
				trattenuta = stipendio * TRATTENUTA_SCAGLIONE_1 / 100;
				scaglioneValido = true;
				break;

			case 2:
				trattenuta = stipendio * TRATTENUTA_SCAGLIONE_2 / 100;
				scaglioneValido = true;
				break;

			case 3:
				trattenuta = stipendio * TRATTENUTA_SCAGLIONE_3 / 100;
				scaglioneValido = true;
				break;

			case 4:
				trattenuta = stipendio * TRATTENUTA_SCAGLIONE_4 / 100;
				scaglioneValido = true;
				break;

			case 5:
				trattenuta = stipendio * TRATTENUTA_SCAGLIONE_5 / 100;
				scaglioneValido = true;
				break;
		
			default:
				printf("Scaglione inserito non valido. Riprova.\n");
				break;
		}
	} while (!scaglioneValido);

	stipendioSenzaTrattenuta = stipendio - trattenuta;
	
	printf("La trattenuta da versare è di €%.2f\n", trattenuta);
	printf("Lo stipendio senza la trattenuta fiscale è di €%.2f\n", stipendioSenzaTrattenuta);

	return 0;
}
