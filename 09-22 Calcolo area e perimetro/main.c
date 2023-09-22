#include <stdio.h>
#include <stdlib.h>

/*
	------------------------------------------------------------------
	Calcolo dell'area e perimetrodel quadrato, usando delle funzioni
	Matteo Gheza
	------------------------------------------------------------------
*/

float perimetroQuadrato(float lato);
float areaQuadrato(float lato);

int main(int argc, char *argv[]) {
    float lato, perimetro, area;

	printf("Calcolo dell'area e del perimetro del quadrato\n\n");

    printf("Inserisci misura del lato del quadrato: ");
    scanf("%f", &lato);

    perimetro = perimetroQuadrato(lato);
    printf("\nIl perimetro del quadrato inserito è di %.2f.", perimetro);

    area = areaQuadrato(lato);
    printf("\nL'area del quadrato inserito è di %.2f.\n", area);

	return 0;
}

float perimetroQuadrato(float lato) {
    return lato*4;
}

float areaQuadrato(float lato) {
    return lato*lato;
}
