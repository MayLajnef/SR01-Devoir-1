# Variables
CC = gcc
CFLAGS = -Wall
TARGETS = ex2 ex3
HEADERS = ex3.h  # Les fichiers d'en-tête

# Cible principale : compile tous les exercices
all: $(TARGETS)

# Compilation de l'exercice 2
ex2: ex2.c
	$(CC) $(CFLAGS) -o ex2 ex2.c

# Compilation de l'exercice 3
ex3: ex3.c $(HEADERS)
	$(CC) $(CFLAGS) -o ex3 ex3.c -lm

# Exécution de l'exercice 2
run2: ex2
	./ex2

# Exécution de l'exercice 3
run3: ex3
	./ex3

# Nettoyage des fichiers générés
clean:
	rm -f $(TARGETS) *.o

# Commandes utilisables dans le terminal
# Compiler tous les exercices : make
# Exécuter l'exercice 2 : make run2
# Exécuter l'exercice 3 : make run3
# Nettoyer les fichiers générés : make clean
