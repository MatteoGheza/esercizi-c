#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------
	Matteo Gheza
	------------------------------------------------------------------
*/

#define SCONTO_PENSIONATI 10
#define SCONTO_STUDENTI 15
#define SCONTO_DISOCCUPATI 25

int main(int argc, char *argv[]) {
    char tipo;
    float sconto = 0;
    float prezzo;

    //Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	printf("Calcolo costo biglietto\n\n");
	
    printf("------------------\n");
    printf("P - Pensionato\n");
    printf("S - Studente\n");
    printf("D - Disoccupato\n");
    printf("NIENTE - No sconto\n");
    printf("------------------\n");
	printf("Inserisci tipologia utente: ");
	scanf("%c", &tipo);

    printf("\nPrezzo del biglietto: ");
    scanf("%f", &prezzo);
	
	switch (tipo)
    {
        case 'p': case 'P':
            printf("Pensionato");
            sconto = SCONTO_PENSIONATI;
            break;

        case 's': case 'S':
            printf("Studente");
            sconto = SCONTO_STUDENTI;
            break;

        case 'd': case 'D':
            printf("Disoccupato");
            sconto = SCONTO_DISOCCUPATI;
            break;

        default:
            printf("Nessuno sconto applicato");
            break;
    }

    if(sconto > 0) {
        printf("\n\nLo sconto per la categoria inserita è del %f %% ", sconto);
    }

    prezzo = prezzo * sconto / 100;
    printf("L'utente deve pagare %.2f euro per il biglietto.", prezzo);

	return 0;
}
