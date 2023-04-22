#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*
	------------------------------------------------------------------
	Un numero x che rappresenta la base delle potenze da calcolare;
    Un numero positivo n che indica il numero di potenze da calcolare.
    Il programma deve calcolare le prime n potenze del numero x.

    Esempi:
      Input: x = 3    n = 5    Output: 1, 3, 9, 27, 81.
      Input: x = 2      n = 4  Output: 1, 2, 4, 8.
	
    Matteo Gheza
	------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    int n = 0;
	double x = 0, risultato = 0;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Calcolo della potenza di un numero\n");

    printf("Inserisci la base: ");
    scanf("%lf", &x);

    printf("Inserisci l'esponente: ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        risultato = pow(x, i);
        printf("%.2f ", risultato);
    }

    printf("\n");        

	return 0;
}
