#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/*
    ----------------------------------------------------------------------
    Cifrare e decifrare delle stringhe con il C con il cifrario di Cesare
    Matteo Gheza
    ----------------------------------------------------------------------
*/

#define MAX_MSG_LEN 200

int main(int argc, char *argv[])
{
    char cmd, msg_plain[MAX_MSG_LEN], msg_cifr[MAX_MSG_LEN], c;
    int chiave, msg_len, tipo;
    bool cmd_valido, msg_solo_alfabeto = true;

    // Definisce la codifica da utilizzare, per permettere di mostrare in output caratteri accentati (UTF-8 e UTF-16)
    setlocale(LC_ALL, "");

    printf("Cifrario di Cesare\n\n");

    do {
        printf("Vuoi cifrare o decifrare il messaggio? Scrivi C per cifrare e D per decifrare.\n");
        scanf(" %c", &cmd);
        printf("\n");
        switch (cmd) {
            case 'c': case 'C':
                cmd_valido = true;

                printf("Inserisci il messaggio da cifrare: ");
                //scanf("%s", msg_plain); Non funzione se la stringa inserita contiene spazi
                getchar(); fgets(msg_plain, MAX_MSG_LEN, stdin);

                printf("Inserisci la chiave: ");
                scanf("%d", &chiave);

                msg_len = strlen(msg_plain);

                for (int i = 0; i < msg_len; i++) {
                    c = msg_plain[i];

                    if(isalpha(c)) {
                        if(islower(c)) {
                            //Caratteri minuscoli
                            msg_cifr[i] = ( (c - 'a' + chiave) % 26 ) + 'a';
                        } else {
                            //Caratteri maiuscoli
                            msg_cifr[i] = ( (c - 'A' + chiave) % 26 ) + 'A';
                        }
                    } else {
                        //Caratteri non presenti nell'alfabeto a-z/A-Z
                        msg_solo_alfabeto = false;
                        msg_cifr[i] = c;
                    }
                }

                if(!msg_solo_alfabeto) {
                    printf("\nATTENZIONE: il messaggio da cifrare contiene lettere non presenti nell'alfabeto a-z/A-Z.\n");
                    printf("Caratteri di quel tipo non vengono cifrati, e rimangono in chiaro anche nel messaggio cifrato!\n");
                }

                printf("\nMessaggio cifrato:\n%s\n", msg_cifr);
                break;

            case 'd': case 'D':
                cmd_valido = true;

                printf("Inserisci il messaggio da decifrare: ");
                //scanf("%s", msg_cifr); Non funzione se la stringa inserita contiene spazi
                getchar(); fgets(msg_cifr, MAX_MSG_LEN, stdin);

                printf("Inserisci la chiave: ");
                scanf("%d", &chiave);

                msg_len = strlen(msg_cifr);

                for (int i = 0; i < msg_len; i++) {
                    c = msg_cifr[i];

                    if(isalpha(c)) {
                        if(islower(c)) {
                            //Caratteri minuscoli
                            msg_plain[i] = ( (c - 'a' - chiave) % 26 ) + 'a';
                        } else {
                            //Caratteri maiuscoli
                            msg_plain[i] = ( (c - 'A' - chiave) % 26 ) + 'A';
                        }
                    } else {
                        //Caratteri non presenti nell'alfabeto a-z/A-Z
                        msg_plain[i] = c;
                    }
                }

                printf("\nMessaggio in chiaro:\n%s\n", msg_plain);
                break;

            default:
                cmd_valido = false;
                printf("Comando non valido.\n\n");
                break;
        }
    } while (!cmd_valido);

    return 0;
}
