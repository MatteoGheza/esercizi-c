#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
	//Dichiara le variabili che conterranno gli input dell'utente
	float dMin = 0;
	float dMag = 0;
	float lato = 0;
	
	//Dichiara le variabili necessarie al programma per eseguire i calcoli richiesti
	float area = 0;
	float perimetro = 0;
	
	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");
	
	//Chiedi all'utente i dati necessari (diagonale minore, diagonale maggiore, lato)
	printf("Inserisci misura della diagonale minore: ");
	scanf("%f", &dMin);
	
	printf("Inserisci misura della diagonale maggiore: ");
	scanf("%f", &dMag);
	
	printf("Inserisci misura del lato: ");
	scanf("%f", &lato);
	
	//Calcola area e perimetro e li mostra all'utente
	area = (dMin * dMag) / 2;
	printf("L'area è di %.2f\t", area);
	
	perimetro = lato * 4;
	printf("Il perimetro è di %.2f\n", perimetro);
	
	return 0;
}
