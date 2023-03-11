#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------
	Chiedere all'utente di inserire una serie di numeri positivi, effettuare la loro somma e stampare il risultato finale
	Matteo Gheza
	------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
	float num = 0; //Il numero inserito dall'utente
	float somma = 0; //La somma dei numeri positivi inseriti

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	do {
		somma += num;
		printf("Inserisci un numero positivo. Per interrompere l'inserimento, inserire un numero negativo:\t");
		scanf("%f", &num);
	} while(num >= 0);
	
	printf("\nLa somma dei numeri positivi inseriti è:\t%.2f\n", somma);

	//Blocca l'esecuzione del programma per permettere all'utente di leggere l'output
	//quando il programma viene eseguito "standalone"
	system("pause");

	return 0;
}
