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

int note_max(int N, int POINTS[]) {
    int max = POINTS[0];
    for (int i = 1; i < N; i++) {
        if (POINTS[i] > max)
            max = POINTS[i];
    }
    return max;
}

int note_min(int N, int POINTS[]) {
    int min = POINTS[0];
    for (int i = 1; i < N; i++) {
        if (POINTS[i] < min)
            min = POINTS[i];
    }
    return min;
}

float moyenne_notes(int N, int POINTS[]) {
    int somme = 0;
    float moyenne;
    for (int i = 0; i < N; i++) {
        somme += POINTS[i];
    }
    moyenne = somme / (float) N;
    return moyenne;
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

    printf("La note maximale du devoir SR01 est de %d.\n", note_max(N, POINTS));
    printf("La note minimale du devoir SR01 est de %d.\n", note_min(N, POINTS));
    printf("La moyenne des notes du devoir SR01 est de %.2f.\n", moyenne_notes(N, POINTS));

    return 0;
}
