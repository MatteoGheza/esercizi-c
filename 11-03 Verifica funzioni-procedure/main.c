#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	-----------------------------------------------------------------------------------------------------
	Realizzzare un programma con seguenti metodi e funzioni:
	Matteo Gheza
	-----------------------------------------------------------------------------------------------------
*/

//Definizione di valori utilizzati
#define N_NUMERI_DA_INSERIRE 100 //Quanti numeri deve inserire l'utente nella funzione del punto 5 "contaMaggiori"
#define N_NUMERO_MINORE 10 //Conta i numeri maggiori di questo, nella funzione del punto 5 "contaMaggiori"

/*
2.  Definire una funzione che dati due numeri interi in input b ed e (che rappresentano
    rispettivamente la base e l'esponente) definire un metodo che permetta di calcolare b alla e
*/
int elevamentoPotenza(int b, int e);

/*
3.  Definire una funzione che dati i valori delle basi e altezza in input permetta di
    calcolare l'area del trapezio
*/
float areaTrapezio(float baseMaggiore, float baseMinore, float altezza);

/*
4.  Definire una funzione che data l'area del trapezio in input ne stampi il valore a video
*/
void stampaArea(float area);

/*
5.  Definire una funzione che chieda all'utente di inserire 100 numeri interi e restituisca il
    conteggio dei numeri maggiori di 10
*/
int contaMaggiori();

/*
6.  Definire una funzione che chieda all'utente il voto di informatica che restituisca quanto segue:
    - Se il voto è inferiore a 6, restituire "mettiti a studiare informatica"
    - Se il voto è compreso tra 6 e 7, restituire "sufficiente, ma puoi fare di più"
    - Se il voto è compreso tra 7 e 8, retituire "Bravo/a"
    - Se il voto è superiore a 8, restituire "Continua così"
*/
void processaVotoInformatica();

int main(int argc, char *argv[]) {
	/**
     * Codice nel main usato solo per testare funzionamento delle funzioni e delle procedure,
     * con valori hard-coded come test.
     */
    int rInt;
    float rFloat;

    //2
    rInt = elevamentoPotenza(2,3);
    printf("%d\n", rInt);

    //3
    rFloat = areaTrapezio(1,2,4);

    //4
    stampaArea(rFloat);

    //5
    contaMaggiori();

    //6
    processaVotoInformatica();

	return 0;
}

//Punto 2
int elevamentoPotenza(int b, int e) {
    /*
    //Metodo alternativo:
    float r = 1;
    for (int i = 0; i < e; i++) {
        r = r*b;
    }
    return r;
    */
   
    return pow(b, e);
}

//Punto 3
float areaTrapezio(float baseMaggiore, float baseMinore, float altezza) {
    return (baseMinore+baseMaggiore)*altezza/2;
}

//Punto 4
void stampaArea(float area) {
    printf("L'area del trapezio è %.2f.\n", area);
}

//Punto 5
int contaMaggiori() {
    int conta = 0, tmp;

    printf("Ora ti verrranno chiesti %d numeri INTERI.\n", N_NUMERI_DA_INSERIRE);
    for (int i = 0; i < N_NUMERI_DA_INSERIRE; i++) {
        printf("Inserisci il %d° numero: ", i+1);
        scanf("%d", &tmp);
        if(tmp > N_NUMERO_MINORE) {
            conta++;
        }
    }
    
    return conta;
}

//Punto 6
void processaVotoInformatica() {
    float voto; //Per permettere voti come 8.5  7.25 etc.
    printf("Inserisci voto informatica: ");
    scanf("%f", &voto);

    if(voto < 6) {
        printf("mettiti a studiare informatica\n");
    } else if(voto < 7) {
        printf("sufficiente, ma puoi fare di più\n");
    } else if(voto < 8) {
        printf("Bravo/a\n");
    } else {
        printf("Continua così\n");
    }

    /**
     * Utilizzo una procedura invece di una funzione perchè è necessario solo
     * stampare a video, e in C non è possibile ritornare in modo sicuro delle stringhe.
    */
}
