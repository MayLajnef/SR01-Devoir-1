# include <stdio.h>

int main () {
    int a=-8 , b =3;
    // Décalage à droite de a par (2 ^ b) bits
    a >>=2^b; // a = a >> (2 ^ b);
    printf(" a=%d \n", a);
    // Il manque la valeur de retour (de type integer) du main.
}

/* OUTPUT: 
a=-4 
*/

/* Explications:
Examinons l'expression de c en respectant l'ordre de priorité des opérateurs :
1. L'opérateur ^ (XOR binaire)
En C, 2 ^ b est une opération XOR (OU exclusif) binaire entre les bits de 2 et b=3. D'où :
2 ^ b = 0000 0010 ^ 0000 0011 = 000 0001
2. L'opérateur de décalage à droite >>
On décale le code binaire de a=-8 d'1 place (car on a obtenu 2 ^ b = 1) à droite. Or,
CA2(0000 1000) = 1111 0111 + 0000 0001 = 1111 1000 (code binaire de -8)
D'où : 
a >> (2^b) = 1111 1000 >> 1 = 1111 1100
On obtient un résultat final négatif car le bit de poids fort est 1. Sa valeur absolue est donnée par son complément à 2.
CA2(1111 1100) = 0000 0011 + 0000 0001 = 0000 0100 (code binaire de 4).
Puis, on affecte à a la valeur ainsi obtenue qui est -4.
Donc, finalement, on obtient a=-4, ce qui est cohénrent avec l'affichage.
*/