#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------
    Ricevuto come input il prezzo P di un prodotto si deve:
    - Se P < 10 non ci sono tasse
    - Se 10 <= p < 100 Tassa 16%
    - Se P >= 100 applicare tassa fissa 21%
    Visualizzare il prezzo finale tassato.
	Matteo Gheza
	------------------------------------------------------------------
*/

#define PREZZO_MIN_1 10 //Prezzo minimo richiesto per l'applicazione della tassa 1
#define TASSA_1 16

#define PREZZO_MIN_2 100 //Prezzo minimo richiesto per l'applicazione della tassa 2
#define TASSA_2 21

int main(int argc, char *argv[]) {
    //Uso double invece di float per permettere il funzionamento con numeri molto grandi
    float prezzo;
    float tassa = 0;

    //Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	printf("Calcolo prezzo tassato\n\n");

    //Chiedi di inserire il prezzo fino a quando viene inserito un valore corretto (>0)
    do {
        printf("Inserisci prezzo non tassato: ");
	    scanf("%f", &prezzo);
    } while (prezzo <= 0);

    if(prezzo >= PREZZO_MIN_2) {
        tassa = TASSA_2;
    } else if(prezzo >= PREZZO_MIN_1) {
        tassa = TASSA_1;
    }

    //Applica la tassa al prezzo, sommandola al prezzo
    prezzo += prezzo * tassa / 100;

    if(tassa != 0) {
        //I caratteri '%%' servono solo per mostrare il simbolo di % senza utilizzare la formattazione di printf
        printf("È stata applicata una tassa del %.2f%%.\n", tassa);
    } else {
        printf("Il prezzo non è tassato.\n");
    }

    printf("Il prezzo finale è di %.2f euro.\n", prezzo);

	return 0;
}
