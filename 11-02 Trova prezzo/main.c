#include <stdio.h>
#include <stdlib.h>

/*
	------------------------------------------------------------------
	Definire funzioni e procedure per risolvere il seguente problema:
    - Dati prezzo e quantità in input calcolare il prezzo del prodotto
    - Dato il costo in input calcolare il prezzo scontanto sapendo che:
        se il costo è minore a 20 --> non è applicato scontanto
        se il costo è compreso tra 20 e 40 --> sconto applicato 2%
        se il costo è compreso tra 40 e 60 --> sconto applicato 4%
        oltre i 60                         --> sconto applicato 6%
    - Dati il costo e l'età in input stabilire il valore di iva da applicare
        se età inferiore a 18 --> iva 3%
        se età inferiore a 30 (maggiore di 18) --> iva 10%
        se maggiore di 30 --> iva 22%
    - Dati il costo e valore di iva calcolare il prezzo maggiorato della tassa   
    - Dato il costo in input stamparne il valore
	Matteo Gheza
	------------------------------------------------------------------
*/

float costo(float prezzoUnit, int qta);
float prezzoScontato(float costo);
void iva(float costo, int eta);
float prezzoTassato(float costo, int iva);
void stampaCosto(float costo);

float calcolo(int crediti, int nAlunni);

int main(int argc, char *argv[]) {
	

	return 0;
}

float costo(float prezzoUnit, int qta) {
    return prezzoUnit * qta;
}

float prezzoScontato(float costo) {
    float ps;

    if(costo < 20) {
        ps = costo;
    } else if(costo < 40) {
        ps = costo - (costo/100*2);
    } else if(costo < 60) {
        ps = costo - (costo/100*4);
    } else {
        ps = costo - (costo/100*6);
    }

    return ps;
}

void iva(float costo, int eta) {
    int i;

    if(eta < 18) {
        i = 3;
    } else if(eta < 30) {
        i = 10;
    } else {
        i = 22;
    }

    printf("\nIva applicata del %d%%\n", i);
}

float prezzoTassato(float costo, int iva) {
    return costo + costo*iva/100;
}

void stampaCosto(float costo) {
    printf("Il valore calcolato: %.2f\n", costo);
}

float calcolo(int crediti, int nAlunni) {
    int conteggio=0, creditoStudente=0;

    for (int i = 0; i < nAlunni; i++)
    {
        printf("Il tuo credito\n");
        scanf("%d", &creditoStudente);
        if(crediti == creditoStudente) {
            conteggio++;
        }
    }
    
    return conteggio;
}

/*
                                         _ __
        ___                             | '  \
   ___  \ /  ___         ,'\_           | .-. \        /|
   \ /  | |,'__ \  ,'\_  |   \          | | | |      ,' |_   /|
 _ | |  | |\/  \ \ |   \ | |\_|    _    | |_| |   _ '-. .-',' |_   _
// | |  | |____| | | |\_|| |__    //    |     | ,'_`. | | '-. .-',' `. ,'\_
\\_| |_,' .-, _  | | |   | |\ \  //    .| |\_/ | / \ || |   | | / |\  \|   \
 `-. .-'| |/ / | | | |   | | \ \//     |  |    | | | || |   | | | |_\ || |\_|
   | |  | || \_| | | |   /_\  \ /      | |`    | | | || |   | | | .---'| |
   | |  | |\___,_\ /_\ _      //       | |     | \_/ || |   | | | |  /\| |
   /_\  | |           //_____//       .||`      `._,' | |   | | \ `-' /| |
        /_\           `------'        \ |   AND        `.\  | |  `._,' /_\
                                       \|       THE          `.\
                                            _  _  _  _  __ _  __ _ /_
                                           (_`/ \|_)/ '|_ |_)|_ |_)(_
                                           ._)\_/| \\_,|__| \|__| \ _)
                                                           _ ___ _      _
                                                          (_` | / \|\ ||__
                                                          ._) | \_/| \||___

      /b_,dM\__,_
    _/MMMMMMMMMMMm,
   _YMMMMMMMMMMMM(
  `MMMMMM/   /   \   _   ,    
   MMM|  __  / __/  ( |_|
   YMM/_/# \__/# \    | |_)arry
   (.   \__/  \__/     ___  
     )       _,  |    '_|_)
_____/\     _   /       | otter
    \  `._____,'
     `..___(__
              ``-.
                  \
              gnv  )
*/


/*
         ___ . .  _                                                                                             
"T$$$P"   |  |_| |_                                                                                             
 :$$$     |  | | |_                                                                                             
 :$$$                                                      "T$$$$$$$b.                                          
 :$$$     .g$$$$$p.   T$$$$b.    T$$$$$bp.                   BUG    "Tb      T$b      T$P   .g$P^^T$$  ,gP^^T$$ 
  $$$    d^"     "^b   $$  "Tb    $$    "Tb    .s^s. :sssp   $$$     :$; T$$P $^b.     $   dP"     `T :$P    `T
  :$$   dP         Tb  $$   :$;   $$      Tb  d'   `b $      $$$     :$;  $$  $ `Tp    $  d$           Tbp.   
  :$$  :$;         :$; $$   :$;   $$      :$; T.   .P $^^    $$$    .dP   $$  $   ^b.  $ :$;            "T$$p.  
  $$$  :$;         :$; $$...dP    $$      :$;  `^s^' .$.     $$$...dP"    $$  $    `Tp $ :$;     "T$$      "T$b 
  $$$   Tb.       ,dP  $$"""Tb    $$      dP ""$""$" "$"$^^  $$$""T$b     $$  $      ^b$  T$       T$ ;      $$;
  $$$    Tp._   _,gP   $$   `Tb.  $$    ,dP    $  $...$ $..  $$$   T$b    :$  $       `$   Tb.     :$ T.    ,dP 
  $$$;    "^$$$$$^"   d$$     `T.d$$$$$P^"     $  $"""$ $"", $$$    T$b  d$$bd$b      d$b   "^TbsssP" 'T$bgd$P  
  $$$b.____.dP                                 $ .$. .$.$ss,d$$$b.   T$b.                                       
.d$$$$$$$$$$P                                                         `T$b.

                                             _______________________
   _______________________-------------------                       `\
 /:--__                                                              |
||< > |                                   ___________________________/
| \__/_________________-------------------                         |
|                                                                  |
 |                       THE LORD OF THE RINGS                      |
 |                                                                  |
 |      "Three Rings for the Elven-kings under the sky,             |
  |        Seven for the Dwarf-lords in their halls of stone,        |
  |      Nine for Mortal Men doomed to die,                          |
  |        One for the Dark Lord on his dark throne                  |
  |      In the Land of Mordor where the Shadows lie.                 |
   |       One Ring to rule them all, One Ring to find them,          |
   |       One Ring to bring them all and in the darkness bind them   |
   |     In the Land of Mordor where the Shadows lie.                |
  |                                              ____________________|_
  |  ___________________-------------------------                      `\
  |/`--_                                                                 |
  ||[ ]||                                            ___________________/
   \===/___________________--------------------------
*/
