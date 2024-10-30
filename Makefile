
# Variables
CC = gcc
CFLAGS = -Wall
TARGETS = ex2 ex3

# Cible principale : compile tous les exercices
all: $(TARGETS)


# Compilation de l'exercice 2
ex2: ex2.c
	$(CC) $(CFLAGS) -o ex2 ex2.c

# Compilation de l'exercice 3
ex3: ex3.c
	$(CC) $(CFLAGS) -o ex3 ex3.c

# Exécution de l'exercice 2
run2: ex2
	./ex2

# Exécution de l'exercice 3
run3: ex3
	./ex3

# Nettoyage des fichiers générés
clean:
	rm -f $(TARGETS) *.o
