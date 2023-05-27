#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int matrix[9][3];

    for (int i = 0; i < 9; i++) {
        //Righe
        for (int j = 0; j < 3; j++) {
            //Colonne

            printf("Inserisci un numero: ");
            scanf("%d", &matrix[i][j]);
        }
    }
    

	return 0;
}
