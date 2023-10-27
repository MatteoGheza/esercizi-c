#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	----------------------------------------------------------------------------------
	Creare un programma che risolva il seguente problema:
    - Data la tipologia di figura geometrica (q=quadrato, r=rettangolo)
      Calcolare l'area della figura scelta
    - Data la tipologia di figura geometrica (q=quadrato, r=rettangolo)
      calcolare il perimetro della figura scelta
    - Data la tipologia di figura geometrica (i=iscoscele, e=equilatero, s=scaleno)
      comunicare tipo di triangolo scelto e calcolare il perimetro della figura
    - Definire la stampa per entrambi i valori ritornati
	Matteo Gheza
	----------------------------------------------------------------------------------
*/

float areaQuadrato(float lato);
float areaRettangolo(float l1, float l2);

float perimetroQuadrato(float lato);
float perimetroRettangolo(float base, float altezza);
float perimetroTriangoloIsoscele(float base, float lObliquo);
float perimetroTriangoloEquilatero(float lato);
float perimetroTriangoloScaleno(float l1, float l2, float l3);

void stampaRisultato(float risultato);

void calcolaAreaFigura(char tipo);
void calcolaPerimetroFigura(char tipo, bool permettiTriangolo);

int main(int argc, char *argv[]) {
    char tipo;

	printf("Calcolo dell'area e del perimetro di una figura");

    printf("\nInserisci una figura per calcolarne l'area.\nFigure permesse:\n");
    printf("- q: Quadrato\n");
    printf("- r: Rettangolo\n");
    printf("Seleziona tipologia della figura: ");
    scanf(" %c", &tipo);

    calcolaAreaFigura(tipo);

    printf("\nInserisci una figura per calcolarne il perimetro.\nFigure permesse:\n");
    printf("- q: Quadrato\n");
    printf("- r: Rettangolo\n");
    printf("Seleziona tipologia della figura: ");
    scanf(" %c", &tipo);

    calcolaPerimetroFigura(tipo, false);

    printf("\nInserisci un tipo di triangolo per calcolarne il perimetro.\nFigure permesse:\n");
    printf("- i: Isoscele\n");
    printf("- e: Equilatero\n");
    printf("- s: Scaleno\n");
    printf("Seleziona tipologia di triangolo: ");
    scanf(" %c", &tipo);

    calcolaPerimetroFigura(tipo, true);

	return 0;
}

float areaQuadrato(float lato) {
    return lato*lato;
}
float areaRettangolo(float l1, float l2) {
    return l1*l2;
}

float perimetroQuadrato(float lato) {
    return lato*4;
}
float perimetroRettangolo(float base, float altezza) {
    return (base+altezza)*2;
}
float perimetroTriangoloIsoscele(float base, float lObliquo) {
    return base+lObliquo*2;
}
float perimetroTriangoloEquilatero(float lato) {
    return lato*3;
}
float perimetroTriangoloScaleno(float l1, float l2, float l3) {
    return l1+l2+l3;
}

void stampaRisultato(float risultato) {
    printf("\n%.2f\n\n", risultato);
}

void calcolaAreaFigura(char tipo) {
    float area;
    if(tipo == 'q') {
        float lato;
        printf("Inserisci misura del lato: ");
        scanf("%f", &lato);

        area = areaQuadrato(lato);
    } else if(tipo == 'r') {
        float base, altezza;
        printf("Inserisci misura della base: ");
        scanf("%f", &base);
        printf("Inserisci misura dell'altezza: ");
        scanf("%f", &altezza);

        area = areaRettangolo(base, altezza);
    } else {
        printf("\nLa tipologia di figura selezionata non è valida. Riprova.\n");
    }

    stampaRisultato(area);
}

/**
 * Inserito parametro "triangoli" perchè la procedura lavora in 2 modalità:
 * - calcolo perimetro quadrato o rettangolo
 * - calcolo perimetro triangolo rettangolo, equilatero o scaleno
*/
void calcolaPerimetroFigura(char tipo, bool triangoli) {
    float perimetro;
    if(!triangoli && tipo == 'q') {
        float lato;
        printf("Inserisci misura del lato: ");
        scanf("%f", &lato);

        perimetro = perimetroQuadrato(lato);
    } else if(!triangoli && tipo == 'r') {
        float base, altezza;
        printf("Inserisci misura della base: ");
        scanf("%f", &base);
        printf("Inserisci misura dell'altezza: ");
        scanf("%f", &altezza);

        perimetro = perimetroRettangolo(base, altezza);
    } else if(triangoli && tipo == 'i') {
        printf("Hai selezionato un triangolo isoscele.\n");

        float base, lObliquo;
        printf("Inserisci misura base: ");
        scanf("%f", &base);
        printf("Inserisci misura lato obliquo: ");
        scanf("%f", &lObliquo);

        perimetro = perimetroTriangoloIsoscele(base, lObliquo);
    } else if(triangoli && tipo == 'e') {
        printf("Hai selezionato un triangolo equilatero.\n");

        float lato;
        printf("Inserisci misura del lato: ");
        scanf("%f", &lato);

        perimetro = perimetroTriangoloEquilatero(lato);
    } else if(triangoli && tipo == 's') {
        printf("Hai selezionato un triangolo scaleno.\n");

        float l1, l2, l3;
        printf("Inserisci misura lato 1: ");
        scanf("%f", &l1);
        printf("Inserisci misura lato 2: ");
        scanf("%f", &l2);
        printf("Inserisci misura lato 3: ");
        scanf("%f", &l3);

        perimetro = perimetroTriangoloScaleno(l1, l2, l3);
    } else {
        printf("\nLa tipologia di figura selezionata non è valida. Riprova.\n");
    }

    stampaRisultato(perimetro);
}
