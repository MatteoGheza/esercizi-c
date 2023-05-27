#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------
	Per ogni riga, voti di varie materie (per un singolo studente):
    Italiano, Matematica, Informatica, Storia
    Calcolo della media per ogni materia.
	Matteo Gheza
	------------------------------------------------------------------
*/

#define N_MATERIE 4
#define N_VOTI 4

int main(int argc, char *argv[]) {
	float voti[N_MATERIE][N_VOTI], 
        sVotiMateria = 0, sVotiTot = 0,
        mediaMateria, mediaComplessiva;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Verranno richiesti i %d voti per %d materie di uno studente, e verrà calcolata in automatico la media.\n", N_VOTI, N_MATERIE);
    printf("Viene considerato che per \"voto\" si intende un numero (decimale o intero) compreso tra (o uguale a) 0 e 10.\n");

    for (int i = 0; i < N_MATERIE; i++) {
        printf("\nMateria numero %d:\n", i+1);
        sVotiMateria = 0;
        for (int j = 0; j < N_VOTI; j++) {
            do {
                printf("Inserisci il %d° voto: ", j+1);
                scanf("%f", &voti[i][j]);
            } while (voti[i][j] < 0 || voti[i][j] > 10);
            
            sVotiMateria += voti[i][j];
        }
        mediaMateria = sVotiMateria / N_VOTI;
        printf("La media dei voti della materia è %.2f.\n\n", mediaMateria);

        sVotiTot += sVotiMateria;
    }

    mediaComplessiva = sVotiTot / (N_MATERIE * N_VOTI);
    printf("La media complessiva (dei voti) è:\t%.2f\n", mediaComplessiva);

	return 0;
}
