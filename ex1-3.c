#include <stdio.h>

int main () {
    int p[4] = {1, -2, 3, 4};
    int* q = p;
    printf (" c=%d \n", *++q * *q++);
    printf (" c=%d \n", *q);
    // La valeur de retour de type integer est oubliée
}

/* OUTPUT:
c=4 
c=3 
*/

/* Explications:
*++q (pré-incrémentation) :
q pointe initialement sur p[0] (valeur 1).
Après ++q, q pointe sur p[1] (valeur -2).
L’expression devient alors :
*(p+1) * *q++ soit p[1] * *q++ soit -2 * *q++
Donc, la première déférence *++q donne -2.

*q++ (post-incrémentation) :
q pointe actuellement sur p[1] (valeur -2).
*q++ renvoie la valeur à l'adresse actuelle (soit -2) avant d’incrémenter le pointeur.
Après cette étape, q pointe désormais sur p[2] (valeur 3).

Multiplication :
Au moment de la multiplication, avant d'effectuer la post-incrémentation, l’expression est devenue :
-2 * -2
Le résultat est 4.

Nouvelle position du pointeur après l'expression :
Après l'exécution de l'expression, le pointeur q est incrémenté une seconde fois. q pointe maintement sur p[2] (valeur 3).
D'où, *q donne 3.
*/