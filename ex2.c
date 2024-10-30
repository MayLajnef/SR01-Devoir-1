#include <stdio.h>
#include <stdlib.h>


void lire_notes(int N, int POINTS[]) {
    for (int i = 0; i < N; i++) {
        do {
            printf("Entrez la note de l'étudiant %d : ", i + 1);
            scanf("%d", POINTS + i);
        } while (POINTS[i] < 0 || POINTS[i] > 60);
    }
}



int main(int argc, char* argv[]) {
    int N;
    printf("Entrez le nombre d'étudiants : ");
    scanf("%d", &N);
    int POINTS[N];
    lire_notes(N, POINTS);
    
    for (int i=0; i < N; i++) {
        printf("POINTS[%d] = %d\n", i, POINTS[i]);
    }
    return 0;
}
