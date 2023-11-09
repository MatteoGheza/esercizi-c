#include <stdio.h>
#include <stdlib.h>

/*
	-----------------------------------------------------------------------
    ES1:
	Chiedi all'utente di inserire di inserire i 5 voti di informatica.
    Calcolare la media e definire il voto più alto e il più basso.
    Questi valori vengono solo stampati, mentre la media viene restituita.
    ES2:
    Chiedi voti di ogni materia. Calcola media.
    - Media < 6: 0 crediti
    - Media tra 6 e 7: 8 crediti
    - Media tra 8 e 10: 10 crediti
	Matteo Gheza
	-----------------------------------------------------------------------
*/

#define N_VOTI 5

float votiInf();
void trovaCrediti();

int main(int argc, char *argv[]) {
	float media = votiInf();
    
    printf("Media: %.2f.\n", media);

    trovaCrediti();

	return 0;
}

float votiInf() {
    float voto[N_VOTI];
    float media, min, max, somma;

    for (int i = 0; i < N_VOTI; i++) {
        printf("Voto informatica %d: ", i+1);
        scanf("%f", &voto[i]);
    }

    for (int i = 0; i < N_VOTI; i++) {
        if(voto[i] > max) {
            max = voto[i];
        }
        if(voto[i] < min) {
            min = voto[i];
        }
        somma += voto[i];
    }

    media = somma/N_VOTI;
    

    printf("Il voto più alto è %.2f.\n", max);
    printf("Il voto più basso è %.2f.\n", min);

    return media;    
}

void trovaCrediti() {
    float voto[N_VOTI];
    float media, somma;
    int crediti;

    for (int i = 0; i < N_VOTI; i++) {
        printf("Voto informatica %d: ", i+1);
        scanf("%f", &voto[i]);
    }

    for (int i = 0; i < N_VOTI; i++) {
        somma += voto[i];
    }

    media = somma/N_VOTI;

    if(media < 6) {
        printf("I tuoi crediti sono 0 quest'anno. Devi studiare di più.\n");
    } else if(media < 8) {
        printf("Hai 8 crediti per quest'anno.\n");
    } else {
        printf("Congratulazioni! Hai ottenuto 10 crediti per quest'anno.\n");
    }
}
