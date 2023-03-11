#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
	//Dichiara le variabili che conterranno gli input dell'utente
	float base = 0;
	float altezza = 0;
	
	//Dichiara le variabili necessarie al programma per eseguire i calcoli richiesti
	float area = 0;
	float perimetro = 0;
	
	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");
	
	//Chiedi all'utente i dati necessari (diagonale minore, diagonale maggiore, lato)
	printf("Inserisci misura della base: ");
	scanf("%f", &base);
	
	printf("Inserisci misura dell'altezza: ");
	scanf("%f", &altezza);
	
	//Calcola area e perimetro e li mostra all'utente
	area = base * altezza;
	printf("L'area è di %.2f\t", area);
	
	perimetro = base * 2 + altezza * 2;
	printf("Il perimetro è di %.2f\n", perimetro);
	
	system("pause");
	
	return 0;
}
