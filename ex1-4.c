#include <stdio.h>

int main () {
    int p[4] = {1, -2, 3, 4};
    int * q=p; // q pointe sur p[0] (valeur 1)
    int d = *q & *q++ | *q++;
    printf (" d=% d \n", d);
    printf (" q=% d \n" , *q);
    // Il manque la valeur de retour (de type integer) du main
}

/* OUTPUT:
 d=-1 
 q= 3 
*/

/* Explications:
*q déférence q qui pointe ici vers le premier élément du tableau qui est p[0] = 1. Donc, *q donne la valeur 1
*q++ applique une post-incrémentation à q. Donc, on déférence q avant de l'incrémenter. Actuellement, q pointe vers p[0] = 1, d'où *q++ donne la valeur 1.
*q &*q++ applique un ET logique pour chaque bit des 2 opérandes. Or, 0000 0001 & 0000 0001 = 0000 0001. D'où, le résultat de l'opération & : 0000 0001.
*q++ déférence q qui a déjà été incrémenté une première fois (post-incrémentation antérieure). Donc, *q++ retourne la valeur 
pointée par le pointeur actuel p[1] = -2, et applique une seconde post-incrémentation ultérieurement.
Pour obtenir le code binaire du nombre décimal -2, on effectue un complément à 2 de sa valeur absolue qui est 2.
CA2(0000 0010) = 1111 1101 + 0000 0001 = 1111 1110  (code binaire de -2)
*q & *q++ | *q++ applique un OU logique pour chaque bit des 2 opérandes.
0000 0001 | 1111 1110 = 1111 1111
On obtient comme résultat de l'expression complète : 1111 1111. On remarque que le bit de poids fort est 1.
Donc, on obtient un nombre négatif. Pour connaître sa valeur absolue, on fait un complément à 2 de ce résultat.
CA2(1111 1111) = 0000 0000 + 0000 0001 = 0000 0001 (code binaire de 1)
Donc, on obtient finalement -1. 
Puis, q est incrémenté une seconde fois, ce qui est dû à la dernière post-incrémentation. Donc, q pointe maintenant sur p[2] = 3.
Donc, la déférence *q du second affichage vaut 3.
*/