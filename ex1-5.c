#include <stdio.h>

int main() {
    int a=-8, b=3;
    int c= ++a&&--b ? b--:a++;
    printf(" a=%d b=%d c=%d\n", a, b, c);
    // Il manque la valeur de de retour (de type integer) du main.
}

/* OUTPUT:
 a=-7 b=1 c=2
*/

/* Explications:
Examinons l'expression de c en respectant l'ordre de priorité des opérateurs :
1. Pré-incrémentation et Pré-décrémentation 
a est incrémenté et passe de -8 à -7.
b est décrémenté et passe de 3 à 2.
2. ET logique 
++a&&--b donne donc -7&&2.
Or, -7 est non nul, ce qui est donc vrai en C. De même, 2 est vrai.
Donc, le résultat de l'opérateur && est 1 (vrai).
3. Opérateur conditionnel ?:
L'évaluation de la condition ++a&&--b donne donc un résultat vrai.
Donc, on affecte à c la première expression (avant les :), qui est b--.
Comme il s'agit d'une post-décrémentation, c prend ici la valeur actuelle de b qui est 2.

Puis, b est à nouveau décrémenté et passe de 2 à 1.
D'où le résultat affiché :  a=-7 b=1 c=2.
*/