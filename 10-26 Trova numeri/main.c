#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	------------------------------------------------------------------
	Realizzare un programma che risolva il seguente problema:
    - Dato un numero con la virgola in input definire se è positivo, negativo, nullo
    - Dato un numero intero in input definire se è pari o dispari
    - Dato un range definito dall'utente (2 input valMin e valMax) contare e stampare i valori pari presenti nel range
    - Dati tre numeri in ingresso definire numero MAX
    - Contare i numeri pari compresi tra -1 e 350 e moltiplicare il risultato ottenuto per il numero dei dispari presente nello stesso range
	Matteo Gheza
	------------------------------------------------------------------
*/

#define MIN_RANGE_DEFINITO -1
//#define MAX_RANGE_DEFINITO 5
#define MAX_RANGE_DEFINITO 350

void segnoNumeroDecimale(float num);
bool numeroInteroPari(int num);
void contaStampaRange(int valMin, int valMax);
float cercaMax(float n1, float n2, float n3);
int contaProdottoRange();

int main(int argc, char *argv[]) {
    int tmp = contaProdottoRange();
    printf("%d\n", tmp);
	return 0;
}

void segnoNumeroDecimale(float num) {
    if(num < 0) {
        printf("Il numero è negativo.\n");
    } else if(num == 0) {
        printf("Il numero è nullo.\n");
    } else {
        printf("Il numero è positivo.\n");
    }
}

bool numeroInteroPari(int num) {
    if(num % 2 == 0) {
        printf("Il numero è pari.\n");
        return true;
    } else {
        printf("Il numero è dispari.\n");
        return false;
    }
}

void contaStampaRange(int valMin, int valMax) {
    if(valMin % 2 == 1) {
        valMin++;
    }

    for (int i = valMin; i <= valMax; i = i+2) {
        printf("%d\n", i);
    }
    
}

float cercaMax(float n1, float n2, float n3) {
    if(n1 > n2 && n1 > n3) {
        printf("Il numero maggiore è %.2f", n1);
        return n1;
    } else if(n2 > n1 && n2 > n3) {
        printf("Il numero maggiore è %.2f", n2);
        return n2;
    } else {
        printf("Il numero maggiore è %.2f", n3);
        return n3;
    }
}

int contaProdottoRange() {
    int minPari, maxPari, minDispari, maxDispari, cPari, cDispari;
    float divisioneTmp;
    if(MIN_RANGE_DEFINITO % 2 != 0) {
        minPari = MIN_RANGE_DEFINITO + 1;
        minDispari = MIN_RANGE_DEFINITO;
    } else {
        minPari = MIN_RANGE_DEFINITO;
        minDispari = MIN_RANGE_DEFINITO + 1;
    }
    if(MAX_RANGE_DEFINITO % 2 != 0) {
        maxPari = MAX_RANGE_DEFINITO - 1;
        maxDispari = MAX_RANGE_DEFINITO;
    } else {
        maxPari = MAX_RANGE_DEFINITO;
        maxDispari = MAX_RANGE_DEFINITO - 1;
    }

    /**
     * Invece di utilizzare un'iterazione, ho voluto provare un approggio algoritmico,
     * in modo da ridurre la complessità computazionale dell'operazione.
     * 
     * Esempio per trovare algoritmo: range tra -1 e 5.
     * Numero di pari: 0,2,4: 3
     * Numero di dispari: -1,1,3,5: 4
     * 
     * minPari: 0   -   maxPari: 4
     * 
     * Risoluzione:
     * cPari = (max - min) / 2 + 1
     * Dividi per 2 la differenza (50% numeri pari) e aggiungi il numero 0 non considerato
    */

    divisioneTmp = (maxPari - minPari)/2 + 1;
    if((int)divisioneTmp == divisioneTmp) {
        cPari = divisioneTmp;
    } else {
        cPari = (int)divisioneTmp + 1;
    }

    divisioneTmp = (maxDispari - minDispari)/2 + 1;
    if((int)divisioneTmp == divisioneTmp) {
        cDispari = divisioneTmp;
    } else {
        cDispari = (int)divisioneTmp + 1;
    }

    printf("%d\n%d\n\n", cPari, cDispari);

    return cPari * cDispari;
}
