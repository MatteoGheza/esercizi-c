#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

/*
	------------------------------------------------------------------------
	Ogni mattina entro le 10 i campeggiatori che hanno terminato il proprio
    soggiorno devono lasciare libera la piazzola che hanno occupato.
    Ciascun campeggiatore deve dichiarare:
    - il numero di giorni trascorsi al camping
    - il numero di persone formanti il gruppo
    - il tipo di abitacolo ('T': tenda, 'R': roulotte)
    - il tipo di veicolo ('A': auto, 'M': moto)
    Calcolare e stampare quanto deve pagare ciascun gruppo in base a questo
    listino prezzi:
    - euro 5 per persona al giorno
    - euro 4 per tenda al giorno
    - euro 4,50 per roulotte al giorno
    - euro 5.50 per auto al giorno
    - euro 3,50 per moto al giorno
	Matteo Gheza
	------------------------------------------------------------------------
*/

#define TASSA_GIORNALIERA_PERSONA 5.0

#define PREZZO_GIORNALIERO_TENDA 4
#define PREZZO_GIORNALIERO_ROULOTTE 4.5
#define PREZZO_GIORNALIERO_AUTO 5.5
#define PREZZO_GIORNALIERO_MOTO 3.5

int main(int argc, char *argv[]) {
    int nGiorni = 0, nPersone = 0;
    char tipoAbitacolo, tipoVeicolo;
    bool abitacoloValido, veicoloValido;
    float prezzoTot = 0, prezzoAPersona = 0;

    //Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("CALCOLO PREZZO CAMPEGGIO VacanzeFelici®\n");
    printf("Utilizzare questo programma alla fine del soggiorno per calcolare quanto ");
    printf("deve pagare ogni persona del tuo gruppo.\n\n");

    do {
        printf("Inserisci il numero di giorni trascorsi al camping: ");
        scanf("%d", &nGiorni);
    } while (nGiorni <= 0);

    do {
        printf("Inserisci il numero di persone formanti il gruppo: ");
        scanf("%d", &nPersone);
    } while (nPersone <= 0);

    prezzoTot = TASSA_GIORNALIERA_PERSONA * nPersone * nGiorni;

    do {
        printf("\nTipi di abitacolo selezionabili:\n");
        printf("T - tenda\nR - roulotte\n");
        printf("Inserisci il tipo di abitacolo in cui hai soggiornato: ");
        scanf(" %c", &tipoAbitacolo); //Lo spazio prima di %c è necessario https://stackoverflow.com/a/5241988
        switch (tipoAbitacolo)
        {
            case 'T': case 't':
                prezzoTot += PREZZO_GIORNALIERO_TENDA * nGiorni;
                abitacoloValido = true;
                break;

            case 'R': case 'r':
                prezzoTot += PREZZO_GIORNALIERO_ROULOTTE * nGiorni;
                abitacoloValido = true;
                break;
        
            default:
                printf("Tipologia di abitacolo non valida.\n");
                abitacoloValido = false;
                break;
        }
    } while (!abitacoloValido);

    do {
        printf("\nTipi di veicolo selezionabili:\n");
        printf("A - auto\nM - moto\n");
        printf("Inserisci il tipo di veicolo che hai utilizzato: ");
        scanf(" %c", &tipoVeicolo); //Lo spazio prima di %c è necessario https://stackoverflow.com/a/5241988
        switch (tipoVeicolo)
        {
            case 'A': case 'a':
                prezzoTot += PREZZO_GIORNALIERO_AUTO * nGiorni;
                veicoloValido = true;
                break;

            case 'M': case 'm':
                prezzoTot += PREZZO_GIORNALIERO_MOTO * nGiorni;
                veicoloValido = true;
                break;
        
            default:
                printf("Tipologia di veicolo non valida.\n");
                veicoloValido = false;
                break;
        }
    } while (!veicoloValido);

    prezzoAPersona = prezzoTot / nPersone;

    printf("\n\nIl prezzo totale per il soggiorno è di %.2f €\n", prezzoTot);
    printf("Ogni persona del gruppo deve pagare %.2f €\n", prezzoAPersona);

	return 0;
}
