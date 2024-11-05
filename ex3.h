#ifndef EX3_H_
#define EX3_H_

// Constantes symboliques
#define MAX_RESTAURANTS 100
#define FILE_NAME "restau.txt"

// Structure pour représenter une position
typedef struct Position
{
    double x;
    double y;
}Position;


// Structure pour représenter un restaurant
typedef struct Restaurant {
    char nom_restaurant[50];
    char adresse_restaurant[100];
    Position position_restaurant; // Position du restaurant
    char specialite[50];   // Spécialité du restaurant
} Restaurant;

// Signatures des fonctions
int lire_restaurant(char *chemin, Restaurant restaurants[]);
void inserer_restaurant(Restaurant restaurant);
double calculer_distance(double x1, double y1, double x2, double y2);
void cherche_restaurant(double x, double y, double rayon_recherche, Restaurant restaurants[], int n, Restaurant results[], int *n_results);
void cherche_par_specialite(double x, double y, char *specialite, Restaurant restaurants[], int n, Restaurant results[], int *n_results);


#endif /*EX3_H_*/