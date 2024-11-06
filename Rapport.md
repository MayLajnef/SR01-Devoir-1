D'accord, voici le rapport entièrement en **Markdown**, formaté pour GitHub avec des sections, sous-sections, des blocs de code en C, des signatures de fonctions en gras, et des explications détaillées :

---

# Rapport - Devoir 1 SR01

**Auteurs :** LAJNEF May et DULAC–BELESGAA Sofia

## Exercice 1

### Programme 1
Ce programme génère une erreur de compilation car il tente d’appliquer une incrémentation `++` à une expression temporaire (`++!B`). En C, l’incrémentation nécessite une l-value (une variable modifiable), donc appliquer `++` directement sur une expression temporaire n’est pas permis.

```c
#include <stdio.h>

int main() {
    int A = 10;
    int B = 0;
    int C = ++!B; // Erreur : tentative d'incrémentation d'une expression temporaire
    printf("C = %d\n", C);
    return 0;
}
```

### Programme 2
Le premier `printf` affiche `1` car l’expression conditionnelle est évaluée comme vraie. L'expression `(A && B) || (!0 && (++C && !++D))` est vraie dans ce contexte car `A` et `B` sont différents de `0`.

```c
#include <stdio.h>

int main() {
    int A = 20;
    int B = 5;
    int C = 0, D = 0;
    
    printf("%d\n", (A && B) || (!0 && (++C && !++D))); // Affiche 1
    return 0;
}
```

### Programme 3
Ce programme illustre la priorité opératoire en C, qui est évaluée de gauche à droite. L'opérateur `++q` est une **pré-incrémentation** tandis que `q++` est une **post-incrémentation**.

```c
#include <stdio.h>

int main() {
    int p[4] = {1, -2, 3, 4};
    int *q = p;
    
    printf("c=%d\n", *++q * *q++); // Affiche c=4
    printf("c=%d\n", *q);           // Affiche c=3
    return 0;
}
```

1. `*++q` incrémente le pointeur `q` de 1, il pointe donc sur `-2`.
2. Ensuite, `*q++` utilise la valeur pointée avant l'incrémentation, donc `-2`.
3. Résultat : `-2 * -2 = 4`.

### Programme 4
Ce programme effectue des opérations bit à bit et montre l’incrémentation postfixe du pointeur `q`.

```c
#include <stdio.h>

int main() {
    int p[4] = {1, -2, 3, 4};
    int *q = p;
    int d = *q & *q++ | *q++;
    
    printf("d=%d\n", d); // Affiche d=-1
    printf("q=%d\n", *q); // Affiche q=3
    return 0;
}
```

### Programme 5
Dans ce programme, la priorité des opérateurs conditionnels affecte l’affichage final des variables `a`, `b`, et `c`.

```c
#include <stdio.h>

int main() {
    int a = -8, b = 3;
    int c = ++a && --b ? b-- : a++;
    
    printf("a=%d b=%d c=%d\n", a, b, c); // Affiche a=-7 b=1 c=2
    return 0;
}
```

### Programme 6
Ce programme effectue une opération de décalage binaire combinée avec un OU exclusif (`^`).

```c
#include <stdio.h>

int main() {
    int a = -8, b = 3;
    a >>= 2 ^ b;
    
    printf("a=%d\n", a); // Affiche a=-4
    return 0;
}
```

## Exercice 2

### Description
Cet exercice utilise un tableau d'entiers `POINTS` pour stocker les notes d'étudiants, avec des fonctions pour calculer la **valeur maximale**, **valeur minimale** et **moyenne** des notes.

```c
int points[N]; // Tableau des notes
```

### Histogramme et Nuage de Points
L'histogramme et le nuage de points sont générés à partir du tableau `NOTES`, avec un axe des ordonnées et abscisses pour visualiser les scores.

## Exercice 3

### Structure `Restaurant`
La structure `Restaurant` contient les champs `nom_restaurant`, `adresse_restaurant`, `position_restaurant` et `specialité`.

```c
typedef struct {
    char nom_restaurant[50];
    char adresse_restaurant[100];
    double position_restaurant[2];
    char specialite[30];
} Restaurant;
```

### **Fonction `lire_restaurant`**
La fonction **`int lire_restaurant(char* chemin, Restaurant restaurants[])`** lit les données de restaurant depuis un fichier.

```c
int lire_restaurant(char* chemin, Restaurant restaurants[]) {
    // Initialisation du descripteur de fichier
    int fd = open(chemin, O_RDONLY);
    if (fd == -1) return -1;

    // Lecture et parsing
    char buffer[1024];
    int nb_restaurants = 0;
    while (read(fd, buffer, sizeof(buffer)) > 0) {
        // Parsing et stockage des données dans le tableau restaurants
        sscanf(buffer, "%[^;];%[^;];%lf;%lf;%[^\n]",
               restaurants[nb_restaurants].nom_restaurant,
               restaurants[nb_restaurants].adresse_restaurant,
               &restaurants[nb_restaurants].position_restaurant[0],
               &restaurants[nb_restaurants].position_restaurant[1],
               restaurants[nb_restaurants].specialite);
        nb_restaurants++;
    }
    close(fd);
    return nb_restaurants;
}
```

### **Fonction `inserer_restaurant`**
La fonction **`void inserer_restaurant(Restaurant restaurant)`** insère un restaurant à la fin du fichier.

```c
void inserer_restaurant(Restaurant restaurant) {
    int fd = open("restau.txt", O_WRONLY | O_APPEND);
    if (fd == -1) return;

    dprintf(fd, "%s;%s;%.2f;%.2f;%s\n",
            restaurant.nom_restaurant,
            restaurant.adresse_restaurant,
            restaurant.position_restaurant[0],
            restaurant.position_restaurant[1],
            restaurant.specialite);
    close(fd);
}
```

### Conclusion
Ce rapport couvre les explications détaillées pour chaque programme de l’exercice 1, ainsi que l’implémentation des fonctions du fichier restaurant pour l’exercice 3.