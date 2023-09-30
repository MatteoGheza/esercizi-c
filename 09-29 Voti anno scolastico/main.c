#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	------------------------------------------------------------------
	Chiedi all'utente di inserire i voti per un anno scolastico.
    Calcola media totale e per periodo.
    Stampare il credito ottenuto durante l'anno scolastico.
    BONUS: supporto per medie parziali quadrimestre
    BONUS: utilizzo degli array
	Matteo Gheza
	------------------------------------------------------------------
*/

#define N_VOTI_PER_PERIODO 2
#define N_PERIODI 2 //2 Quadrimestri
#define NOME_PERIODO "Quadrimestre"

float calcolaMedia(float voti[N_VOTI_PER_PERIODO*N_PERIODI], int nVoti);
int calcolaCrediti(float media);
bool controllaRecupero(float media);

void stampaMediaPeriodo(int periodo, float voti[N_VOTI_PER_PERIODO]);
void stampaComplessivaAnno(float voti[N_PERIODI][N_VOTI_PER_PERIODO]);

int main(int argc, char *argv[]) {
	float voti[N_PERIODI][N_VOTI_PER_PERIODO];

    printf("Calcolo dei voti dell'Anno Scolastico in informatica\n\n");

    for (int periodo = 0; periodo < N_PERIODI; periodo++) {
        printf("%d° %s\n", periodo+1, NOME_PERIODO);

        for (int voto = 0; voto < N_VOTI_PER_PERIODO; voto++) {
            printf("Inserisci il %d° voto: ", voto+1);
            scanf("%f", &voti[periodo][voto]);
        }
    }

    for (int periodo = 0; periodo < N_PERIODI; periodo++) {
        stampaMediaPeriodo(periodo, voti[periodo]);
    }

    stampaComplessivaAnno(voti);    

	return 0;
}

//Funzioni
float calcolaMedia(float voti[N_VOTI_PER_PERIODO*N_PERIODI], int nVoti) {
    int somma = 0;

    for (int i = 0; i < nVoti; i++) {
        somma += voti[i];
    }

    return somma/nVoti;
}

int calcolaCrediti(float media) {
    int mediaIntero, crediti;
    float mediaDecimale;

    if (media < 6) {
        crediti = 0;
    } else if (media == 6) {
        crediti = 7;
    } else if (media < 7) {
        crediti = 8;
    } else if (media < 8) {
        crediti = 9;
    } else if (media < 9) {
        crediti = 10;
    } else {
        crediti = 11;
    }

    mediaIntero = (int) media;
    mediaDecimale = media - mediaIntero;

    if (mediaDecimale >= 0.6) {
        crediti++;
    }

    return crediti;
}

bool controllaRecupero(float media) {
    return media < 6;
}

//Procedure
void stampaMediaPeriodo(int periodo, float voti[N_VOTI_PER_PERIODO]) {
    float media;

    media = calcolaMedia(voti, N_VOTI_PER_PERIODO);

    printf("\nLa media complessiva del %d° %s è di %.2f.", periodo+1, NOME_PERIODO, media);
}

void stampaComplessivaAnno(float voti[N_PERIODI][N_VOTI_PER_PERIODO]) {
    float votiComplessivi[N_VOTI_PER_PERIODO*N_PERIODI], media;
    int i = 0, crediti;
    bool recuperoNecessario;

    for (int periodo = 0; periodo < N_PERIODI; periodo++) {
        for (int voto = 0; voto < N_VOTI_PER_PERIODO; voto++) {
            votiComplessivi[i] = voti[periodo][voto];
            i++;
        }
    }

    media = calcolaMedia(votiComplessivi, N_VOTI_PER_PERIODO*N_PERIODI);
    crediti = calcolaCrediti(media);
    recuperoNecessario = controllaRecupero(media);

    printf("\nLa media complessiva di informatica è di %.2f.", media);
    printf("\nHai ottenuto un credito scolastico di %d.", crediti);

    if (recuperoNecessario) {
        printf("\nE' necessario un recupero.\n");
    } else {
        printf("\nNon è necessario recuperare.\n");
    }
}
