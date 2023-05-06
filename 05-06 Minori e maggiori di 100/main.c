#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	-------------------------------------------------
	Leggere un array di interi di 6 posizioni,
    e dire quanti numeri memorizzati nell’array sono
    inferiori e quanti superiori al numero 100
	Matteo Gheza
	-------------------------------------------------
*/

#define N_ELEM 6
#define VALORE_CENTRALE 100.0 //Inserire .0 se valore intero così si possono interire anche valori decimali in caso di necessità

int main(int argc, char *argv[]) {
	float num;
    int cMin = 0, cMag = 0, cUguali;

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

    printf("Verranno richiesti %d numeri.\n\n", N_ELEM);

    for (int i = 1; i <= N_ELEM; i++) {
        printf("Inserisci il %d° numero: ", i);
        scanf("%f", &num);

        if(num > VALORE_CENTRALE) {
            cMag++;
        } else if(num < VALORE_CENTRALE) {
            cMin++;
        }
    }
    cUguali = N_ELEM - cMag - cMin;
    
    printf("\nHai inserito %d elementi minori di %.2f e %d maggiori di %.2f.\n", cMin, VALORE_CENTRALE, cMag, VALORE_CENTRALE);
    if(cUguali == 1) {
        printf("Hai inserito anche 1 numero uguale a %.2f.\n", VALORE_CENTRALE);
    } else if(cUguali > 1) {
        printf("Hai inserito anche %d numeri uguali a %.2f.\n", cUguali, VALORE_CENTRALE);
    }

	return 0;
}
