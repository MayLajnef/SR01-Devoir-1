#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ex3.h"

#define MAX_RESTAURANTS 100
#define FILE_NAME "restau.txt"

// Fonction pour lire les restaurants depuis un fichier
int lire_restaurant(char *chemin, Restaurant restaurants[]) {
    FILE *file = fopen(chemin, "r");
    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
        return 0;  
    }
    // Initialisation du compteur
    int i = 0;
    char ligne[500];  
    while (fgets(ligne, sizeof(ligne), file) != NULL) {  
        // Lecture ligne par ligne avec sscanf
        sscanf(ligne, "%[^;]; %[^;]; (x=%lf, y=%lf); {%[^}]}", 
               restaurants[i].nom_restaurant, 
               restaurants[i].adresse_restaurant, 
               &restaurants[i].position_restaurant.x, 
               &restaurants[i].position_restaurant.y, 
               restaurants[i].specialite);
        i++;
        if (i >= MAX_RESTAURANTS) break;  
    }
    fclose(file);
    return i;  // Retourne le nombre de restaurants lus
}

// Fonction pour insérer un restaurant dans le fichier
void inserer_restaurant(Restaurant restaurant) {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Erreur d'ouverture du fichier");
        return;
    }
    

    fprintf(file, "%s; %s;(x=%.2lf, y=%.2lf); {%s}\n", restaurant.nom_restaurant, restaurant.adresse_restaurant,
            restaurant.position_restaurant.x, restaurant.position_restaurant.y, restaurant.specialite);
    fclose(file);
}

// Fonction de service pour calculer la distance entre deux points
double calculer_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Fonction pour chercher les restaurants dans un rayon donné
void cherche_restaurant(double x, double y, double rayon_recherche, Restaurant restaurants[], int n, Restaurant results[], int *n_results) {
    *n_results = 0;
    for (int i = 0; i < n; i++) {
        double distance = calculer_distance(x, y, restaurants[i].position_restaurant.x, restaurants[i].position_restaurant.y);
        if (distance <= rayon_recherche) {
            results[*n_results] = restaurants[i];
            (*n_results)++;
        }
    }
}

// Fonction pour chercher par spécialité et trier par distance
void cherche_par_specialite(double x, double y, char *specialite, Restaurant restaurants[], int n, Restaurant results[], int *n_results) {
    *n_results = 0;
    for (int i = 0; i < n; i++) {
        if (strcasecmp(restaurants[i].specialite, specialite) == 0) {
            results[*n_results] = restaurants[i];
            (*n_results)++;
        }
    }

    // Tri des résultats par distance à la position (x, y)
    for (int i = 0; i < *n_results - 1; i++) {
        for (int j = i + 1; j < *n_results; j++) {
            if (calculer_distance(x, y, results[i].position_restaurant.x, results[i].position_restaurant.y) > calculer_distance(x, y, results[j].position_restaurant.x, results[j].position_restaurant.y)) {
                Restaurant temp = results[i];
                results[i] = results[j];
                results[j] = temp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    Restaurant restaurants[MAX_RESTAURANTS];
    Restaurant results[MAX_RESTAURANTS];
    int n, n_results;
    char specialite[50];
    double x, y, rayon;

    // Charger les restaurants depuis le fichier
    n = lire_restaurant(FILE_NAME, restaurants);

    int choix;
    do {
        printf("\nMenu :\n");
        printf("1. Afficher les restaurants\n");
        printf("2. Insérer un nouveau restaurant\n");
        printf("3. Rechercher des restaurants dans un rayon\n");
        printf("4. Rechercher des restaurants par spécialité\n");
        printf("5. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("\n-----------Affichage des restaurants-----------\n");
                for (int i = 0; i < n; i++) {
                    printf("Restaurant n°%d\n", i+1);
                    printf("Nom: %s \nAdresse: %s \nPosition: (%.2lf, %.2lf) \nSpécialité: %s\n",
                           restaurants[i].nom_restaurant, restaurants[i].adresse_restaurant,
                           restaurants[i].position_restaurant.x, restaurants[i].position_restaurant.y,
                           restaurants[i].specialite);
                    printf("---------------------------------------------------\n\n");
                }
                printf("\nNombre de restaurants lus à partir du fichier : %d.\n", n);
                break;

            case 2: {
                Restaurant r;
                printf("\n-----------Saisie des informations du nouveau restaurant-----------\n");
                printf("Nom : "); scanf("%s", r.nom_restaurant);
                printf("Adresse : "); scanf("%s", r.adresse_restaurant);
                printf("Position (x y) : "); scanf("%lf %lf", &r.position_restaurant.x, &r.position_restaurant.y);
                printf("Spécialité : "); scanf("%s", r.specialite);
                inserer_restaurant(r);
                restaurants[n++] = r;  // Ajouter au tableau local
                printf("Restaurant ajouté !\n");
                break;
            }

            case 3:
                printf("Position actuelle (x y) : "); scanf("%lf %lf", &x, &y);
                printf("Rayon de recherche : "); scanf("%lf", &rayon);
                cherche_restaurant(x, y, rayon, restaurants, n, results, &n_results);
                printf("Restaurants trouvés dans le rayon %.2lf :\n", rayon);
                for (int i = 0; i < n_results; i++) {
                    printf("%s - %s (%.2lf, %.2lf) - %s\n",
                           results[i].nom_restaurant, results[i].adresse_restaurant,
                           results[i].position_restaurant.x, results[i].position_restaurant.y,
                           results[i].specialite);
                }
                break;

            case 4:
                printf("Position actuelle (x y) : "); scanf("%lf %lf", &x, &y);
                printf("Spécialité recherchée : "); scanf("%s", specialite);
                cherche_par_specialite(x, y, specialite, restaurants, n, results, &n_results);
                printf("Restaurants trouvés pour la spécialité \'%s\' :\n", specialite);
                for (int i = 0; i < n_results; i++) {
                    printf("%s - %s (%.2f, %.2f) - %s\n",
                           results[i].nom_restaurant, results[i].adresse_restaurant,
                           results[i].position_restaurant.x, results[i].position_restaurant.y,
                           results[i].specialite);
                }
                break;

            case 5:
                printf("Au revoir...\n");
                exit(0);
                break;

            default:
                printf("Choix invalide. Veuillez saisir une option parmi 1, 2, 3, 4 ou 5.\n");
        }
    } while (choix != 5);

    return 0;
}

