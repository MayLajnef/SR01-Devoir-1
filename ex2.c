#include <stdio.h>
#include <stdlib.h>
#define NB_TRANCHES 7

// Question 1
void lire_notes(int N, int POINTS[]) {
    if (N<=0)
    {
        printf("Erreur d'entree !\n");
        return;
    }
    int note;
    for (int i = 0 ; i < N ; i++)
    {
        printf("Donner la note de l'etudiant %d: ", i+1);
        if ((scanf("%d", &note) != 1) || note < 0 || note > 60)
        {
            printf("Il faut entrer une note valide (entier positif inferieur a 60) !\n");
            i--;
        } else {
            note = (int)note;
            *(POINTS + i) = note;
        }
        while (getchar() != '\n');
    }
}

// Question 2
int max(int N, int tab[]) {
    if (N<=0)
    {
        printf("Erreur d'entree !\n");
        return -1;
    }
    int max = tab[0];
    for (int i = 1; i < N; i++) {
        if (tab[i] > max)
            max = tab[i];
    }
    return max;
}

int note_min(int N, int POINTS[]) {
    if (N<=0)
    {
        printf("Erreur d'entree !\n");
        return -1;
    }
    int min = POINTS[0];
    for (int i = 1; i < N; i++) {
        if (POINTS[i] < min)
            min = POINTS[i];
    }
    return min;
}

float moyenne_notes(int N, int POINTS[]) {
    if (N<=0)
    {
        printf("Erreur d'entree !\n");
        return -1;
    }
    int somme = 0;
    float moyenne;
    for (int i = 0; i < N; i++) {
        somme += POINTS[i];
    }
    moyenne = somme / (float) N;
    return moyenne;
}

void affiche_statistiques(int N, int POINTS[]) {
    printf("La note maximale du devoir SR01 est de %d.\n", max(N, POINTS));
    printf("La note minimale du devoir SR01 est de %d.\n", note_min(N, POINTS));
    printf("La moyenne des notes du devoir SR01 est de %.2f.\n", moyenne_notes(N, POINTS));
}

// Question 3
void remplir_notes(int N, int POINTS[], int NOTES[]) {
    if (N<=0)
    {
        printf("Erreur d'entree !\n");
        return;
    }
    for (int i = 0; i < N; i++) {
        if (POINTS[i] >= 60) NOTES[6]++;
        else if (POINTS[i] >= 50) NOTES[5]++;
        else if (POINTS[i] >= 40) NOTES[4]++;
        else if (POINTS[i] >= 30) NOTES[3]++;
        else if (POINTS[i] >= 20) NOTES[2]++;
        else if (POINTS[i] >= 10) NOTES[1]++;
        else NOTES[0]++;
    }
}

// Question 4
void affichage_NOTES_points(int *notes)
{
    printf("\n       Graphique en nuage de points représentant les notes\n\n");
    const int MAXN = max(NB_TRANCHES, notes); // Nombre maximal de notes dans n'importe laquelle des tranches
    for (int i = MAXN; i >= 0; i--)  // Il y a autant de lignes que le nombre maximal de notes dans une des tranches
    {
        if (i == 0)     // On fait un affichage différent pour la ligne 0 (avec des +--+)
        {
            printf("   ");  // On affiche 3 espaces pour aligner le graphique au lieu d'afficher "0 >"
            for (int j = 0; j < NB_TRANCHES; j++) // On traite chaque tranche de notes
            {
                if (notes[j] == 0)  // S'il n'y a pas de note pour la jème tranche, on affiche un +-o-+ sinon on affiche +-----
                    printf("+-o---");
                else printf("+-----");
            }
        }
        else    // Si on est pas à la ligne 0 on affiche normalement
        {
            printf("%d >", i);      // On affiche le numéro de la ligne
            for (int j = 0; j < NB_TRANCHES ; j++)   // Pour chaque tranche de notes, on affiche un point qui correspond au nombre de notes pour cette tranche
            {
                if (notes[j] == i) // Si le nombre de notes de la jème tranche est égal à i,  j'affiche un o à la ligne i, sinon on affiche des espaces
                    printf("  o   ");
                else printf("      ");
            }
            printf("\n\n");   // Nouvelle ligne ; on passe à la ligne suivante de numéro inférineur (plus bas) 
        }
    }
    printf("+\n   | 0-9 ");     // On fait un affichage spécifique pour la tranche | 0-9
    for (int i = 1; i < NB_TRANCHES-1; i++)     // Pour les autres tranches on affiche |10-19 |20-29 etc... C'est fait automatiquement en fonction de NB_TRANCHES
    {
        printf("|%d-%d", i * 10, i * 10 + 9);
    }
    printf("| %d  |\n", (NB_TRANCHES-1)*10);        // 60 est un peu particulier donc on le met en dehors de la boucle
}

// Question 5
void affichage_NOTES_batons(int *notes) {
    printf("\n       Graphique en bâtons représentant les notes\n\n");
    const int MAXN = max(NB_TRANCHES, notes); // Nombre maximal de notes dans n'importe laquelle des tranches
    for (int i = MAXN; i >= 0; i--)  // Il y a autant de lignes que le nombre maximal de notes dans une des tranches
    {
        if (i == 0)     // On fait un affichage différent pour la ligne 0 (avec des +--+)
        {
            printf("   ");  // On affiche 3 espaces pour aligner le graphique au lieu d'afficher "0 >"
            for (int j = 0; j < NB_TRANCHES; j++) // On traite chaque tranche de notes
            {
                printf("+-----");
            }
        }
        else    // Si on est pas à la ligne 0 on affiche normalement
        {
            printf("%d >", i);     // On affiche le numéro de la ligne
            for (int j = 0; j < NB_TRANCHES ; j++)   // Pour chaque tranche de notes, on affiche un bâton de hauteur égale au nombre de notes pour cette tranche
            {
                if (notes[j] >= i && notes[j] != 0) // Si le nombre de notes de la jème tranche est non nul et supérieur à i,  j'affiche un ##### à la ligne i, sinon on affiche des espaces
                    printf(" #### ");
                else printf("      ");
            }
            printf("\n\n");   // Nouvelle ligne ; on passe à la ligne suivante de numéro inférineur (plus bas) 
        }
    }
    printf("+\n   | 0-9 ");     // On fait un affichage spécifique pour la tranche 0-9 parce que c'est la seule qui a qu'un chifre pour chaque nombre (0 a un chiffre et 10 a deux chiffres)
    for (int i = 1; i < NB_TRANCHES-1; i++)     // Pour les autres tranches on affiche |10-19 |20-29 etc... C'est fait automatiquement en fonction de NB_TRANCHES
    {
        printf("|%d-%d", i * 10, i * 10 + 9);
    }
    printf("| %d  |\n", (NB_TRANCHES-1)*10);        // 60 est un peu particulier donc on le met en dehors de la boucle
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
    
    affiche_statistiques(N, POINTS);
    
    int NOTES[NB_TRANCHES] = {};
    remplir_notes(N, POINTS, NOTES);
    for (int i=0; i < NB_TRANCHES; i++) {
        printf("NOTES[%d] = %d\n", i, NOTES[i]);
    }

    affichage_NOTES_points(NOTES);
    affichage_NOTES_batons(NOTES);

    return 0;
} 
