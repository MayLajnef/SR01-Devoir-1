#include <stdio.h>

/*
int main () {
    int A=20 , B =5;
    int C = !--A / ++!B; // error: lvalue required as increment operand
    printf (" A=% d B=% d c=% d \n", A,B, C);
    // La valeur de retour de type integer est oubliée
}
*/

/*
!B est une rvalue. C'est un résultat d’une opération logique (retournant soit 0, soit 1).
Comme ce résultat n'est pas une variable, il est impossible de le modifier et donc de lui appliquer ++.
*/

// Correction
int main() {
    int A = 20, B = 5;
    int notB = !B; // notB = !5 = 0
    int C = !--A/ ++notB; // C = !19 / ++0 = 0/1 = 0
    printf (" A=% d B=% d C=%d \n", A, B, C);
    return 0;
}