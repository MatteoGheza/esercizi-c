#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>

/*
	------------------------------------------------------------------
	Chiedi all'utente di scegliere una tipologia di triangolo, chiedi i dati richiesti e trova area e perimetro
	Matteo Gheza
	------------------------------------------------------------------
*/

/*
Cosa ho cercato su Google:
- funzioni per elevamento a potenza e radice quadrata con la libreria math.h
- formula di Erone (meglio non dirlo a Lisi, ma non me la ricordavo...)
- switch
- true e false in C
*/

int main(int argc, char *argv[]) {
    char tipo;
    bool tipoValido = true;
    
    float lato1, lato2, lato3 = 0;
    double area, perimetro = 0; //Utilizzo il tipo double dato che è richiesto dalla funzione pow della libreria math.h

	//Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
	setlocale(LC_ALL, "");

	printf("CALCOLO AREA E PERIMETRO TRIANGOLI\n\n");
	printf("Tipologie di triangolo:\n");
	printf("---------------------------\n");
	printf("1. Triangolo Equilatero (E)\n");
	printf("2. Triangolo Isoscele (I)\n");
	printf("3. Triangolo Scaleno (S)\n");
	printf("4. Triangolo Rettangolo (R)\n");
	printf("---------------------------\n");
	printf("NB: per 'Triangolo Rettangolo' si intende un triangolo di cui si conoscono base e lato obliquo,\n");
	printf("e che è presente un angolo di 90°\n\n");
	
	printf("Seleziona tipo di triangolo (inserisci la lettera corrispondente): ");
	scanf("%c", &tipo);

	switch(tipo) {
		case 'E': case 'e':
			printf("Inserisci la misura del lato: ");
			scanf("%f", &lato1);
			
			area = sqrt(3)/4 * pow(lato1, 2);

			perimetro = lato1 * 3;

			break;
		
		case 'I': case 'i':
			printf("Inserisci la misura del primo lato: ");
			scanf("%f", &lato1);
			printf("Inserisci la misura del secondo lato: ");
			scanf("%f", &lato2);
			
			area = lato1 * sqrt( pow(lato2, 2) - pow(lato1/2, 2) ) / 2;

			perimetro = lato1 + lato2 * 2;

			break;
			
		case 'S': case 's':
			printf("Inserisci la misura del primo lato: ");
			scanf("%f", &lato1);
			printf("Inserisci la misura del secondo lato: ");
			scanf("%f", &lato2);
			printf("Inserisci la misura del terzo lato: ");
			scanf("%f", &lato3);
			
			//In questo caso, calcolo prima il perimetro, dato che è richiesto dalla formula di Erone
			perimetro = lato1 + lato2 + lato3;
			
			area = sqrt(perimetro/2 * (perimetro/2 - lato1) * (perimetro/2 - lato2) * (perimetro/2 - lato3));
			
			break;
			
		case 'R': case 'r':
			printf("Inserisci la misura del primo lato: ");
			scanf("%f", &lato1);
			printf("Inserisci la misura del lato obliquo: ");
			scanf("%f", &lato2);
			
			lato3 = sqrt( pow(lato2, 2) - pow(lato1, 2) ); //Uso il teorema di Pitagora
			
			area = lato1 * lato3 / 2; //Lato 3 in questo caso è l'altezza, quindi uso la formula generica per l'area
			
			perimetro = lato1 + lato2 + lato3;
			
			break;
		
		default:
			tipoValido = false;
			printf("Tipologia inserita non valida.\n");
			break;
	}
	
	if(tipoValido) {
		printf("\n\nRisultati:\n");
		printf("Area: %.2f\t", area);
		printf("Perimetro: %.2f\n\n", perimetro);
	}

	//Blocca l'esecuzione del programma per permettere all'utente di leggere l'output
	//quando il programma viene eseguito "standalone"
	system("pause");

	return 0;
}
