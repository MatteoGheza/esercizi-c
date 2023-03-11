#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
	------------------------------------------------------------------
	Chiedere all'utente 10 numeri e stampare solo i numeri >5
	Matteo Gheza
	------------------------------------------------------------------
*/

#define LEN 10 //Lunghezza della lista di numeri
#define MAGG_DI 5 //Verranno stampati solo i numeri maggiori di questa costante

int main(int argc, char *argv[]) {
	int i = 0; //Variabile temporanea usata nei cicli for
	float numeri[LEN]; //Lista di numeri di tipo float, di lunghezza specificata nella costante LEN

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");
	
	printf("Inserisci %d numeri:\n", LEN);
	
	//Chiedi all'utente dei numeri, per riempire la lista numeri
	for(i = 0; i < LEN; i++) {
		printf("%d° numero:\t", i+1);
		scanf("%f", &numeri[i]);
	}
	
	printf("\nI numeri maggiori di %d sono:\n", MAGG_DI);
	
	//Stampa tutti i numeri contenuti in numeri maggiori di MAGG_DI
	for(i = 0; i < LEN; i++) {
		if(numeri[i] > 5) {
			printf("Il %d° numero: %.2f\n", i+1, numeri[i]);
		}
	}

	//Blocca l'esecuzione del programma per permettere all'utente di leggere l'output
	//quando il programma viene eseguito "standalone"
	system("pause");

	return 0;
}
