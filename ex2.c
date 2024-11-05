#include <stdio.h>
#include <stdlib.h>
#define NB_TRANCHES 7

// Question 1
void lire_notes(int N, int POINTS[]) {
    if (N<=0)
    {
        printf("Erreur d'entrée !\n");
        return;
    }
    int note;
    for (int i = 0 ; i < N ; i++)
    {
        printf("Donner la note de l'etudiant %d: ", i+1);
        if ((scanf("%d", &note) != 1) || note < 0 || note > 60)
        {
            printf("Il faut entrer une note valide (entier positif inférieur à 60) !\n");
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
    if (!tab || N<=0)
    {
        printf("Erreur d'entree !\n");
        return 1;
    }
    int max = tab[0];
    for (int i = 1; i < N; i++) {
        if (tab[i] > max)
            max = tab[i];
    }
    return max;
}

int note_min(int N, int POINTS[]) {
    if (!POINTS || N<=0)
    {
        printf("Erreur d'entrée !\n");
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
    if (!POINTS || N<=0)
    {
        printf("Erreur d'entrée !\n");
        return 1;
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
    if (!POINTS || N<=0)
    {
        printf("Erreur d'entrée !\n");
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
    if (!notes) {
        printf("Le tableau des tranches de notes est vide !\n");
        return;
    }
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
    if (!notes) {
        printf("Le tableau des tranches de notes est vide !\n");
        return;
    }
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
    int N = 0, choix;
    int* NOTES = NULL;
    int* POINTS = NULL;
    do {
        printf("\n\nMenu: \n");
        printf("1. Lire les notes des étudiants, et les afficher \n");
        printf("2. Afficher la note maximale, la note minimale et la moyenne des notes des étudiants \n");
        printf("3. Afficher les tranches de notes \n");
        printf("4. Générer le graphique en nuage de points représentant les notes\n");
        printf("5. Générer le graphique en bâtons représentant les notes\n");
        printf("0. Quitter\n");

        printf("Quelle option choisissez vous ? ");
        scanf("%d", &choix);
        printf("-----------------------------------------------------------------\n");

        switch (choix) 
        {
        case 1:
            // Saisie du nombre d'étudiants
            int tentative;
            do {
                tentative = 0;
                printf("Entrez le nombre d'étudiants : ");
                if ((scanf("%d", &N) != 1) || N <= 0) {
                    printf("\nSaisie invalide ! Le nombre d'étudiants doit être un entier strictement positif. Veuillez réessayer.\n");
                    tentative++;
                }
            } while (tentative != 0);
            printf("\n");

            // Allocation mémoire dynamique des tableaux POINTS et NOTES
            POINTS = (int*)malloc(N * sizeof(int));
            NOTES = (int*)calloc(NB_TRANCHES, sizeof(int));
            if (!POINTS || !NOTES) {
                printf("Erreur d'allocation mémoire !\n");
                free(POINTS);
                free(NOTES);
                return 1;
            }

            lire_notes(N, POINTS);

            printf("\nAffichage des notes :\n");
            for (int i=0; i < N; i++) {
                printf("POINTS[%d] = %d\n", i, POINTS[i]);
            }

            remplir_notes(N, POINTS, NOTES);
            break;
        case 2:
            if (POINTS)
                affiche_statistiques(N, POINTS);
            else printf("Veuillez d'abord entrer les notes des étudiants avec l'option 1.\n");
            break;
        case 3:
            if (NOTES) {
                printf("Affichage des tranches de notes :\n");
                printf("%d note(s) dans la %dère tranche (allant de %d à %d).\n", NOTES[0], 1, 0, 9);
                for (int i=1; i < NB_TRANCHES-1; i++) 
                {
                    printf("%d note(s) dans la %dème tranche (allant de %d à %d).\n", NOTES[i], i+1, i*10, i*10 + 9);
                }
                printf("%d note(s) dans la %dème tranche (celle des notes égales à %d).\n", NOTES[NB_TRANCHES-1], NB_TRANCHES, 10*(NB_TRANCHES-1));
            }
            else printf("Veuillez d'abord entrer les notes des étudiants avec l'option 1.\n");
            break;
        case 4:
            if (NOTES)
                affichage_NOTES_points(NOTES);
            else printf("Veuillez d'abord entrer les notes des étudiants avec l'option 1.\n");
            break;
        case 5:
            if (NOTES)
                affichage_NOTES_batons(NOTES);
            else printf("Veuillez d'abord entrer les notes des étudiants avec l'option 1.\n");
            break;
        case 0:
            printf("Au revoir...\n");
            break;
        default:
            printf("Option saisie invalide. Veuillez entrer un entier dans {0, 1, 2, 3, 4, 5}. Recommencez !\n");
        }   
    } while (choix !=0);

    // Libération de la mémoire allouée dynamiquement
    free(POINTS);
    free(NOTES);

    return 0;
} 
