#include <stdio.h>

int main() {
    int A=20, B=5, C=-10, D=2;
    printf("%d \n", A&&B ||!0&&C++&&!D++);
    printf("C=%d D=%d \n", C, D);
    // La valeur de retour de type integer est oubliée
}

/*
Pour calculer A&&B ||!0&&C++&&!D++, on réalise chaque opération en respectant l'ordre de priorité.
1) Négation : !0 = 1 et !D = !2 = 0
2) Incrémentation : C++ = -10+1 = -9 et !D++ = !D +1 = 0+1 = 1
3) ET logique : A&&B = 20&&5 = 1 et !0&&C++&&!D++ = 1&&(-9)&&1 = 1
4) OU logique : A&&B ||!0&&C++&&!D++ = 1 || 1 = 1
Donc, A&&B ||!0&&C++&&!D++ = 1
Ensuite, comme on applique à C et à D des incrémentations postfixées,
leurs valeurs restent inchangées.
Donc, C = -10 et D = 2.
C'est ce qui explique le résultat obtenu à l'exécution :

1 
C=-10 D=2 

*/