#ifndef FAVORI_H
#define FAVORI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour enregistrer une recherche d'un locataire
typedef struct {
    char ville[50];
    float prix_max;
    char description[100];
} Recherche;

// Enregistrer une recherche si aucun logement ne correspond
void enregistrerRecherche(const char *ville, float prix, const char *description);

// Vérifier si un nouveau logement correspond à une ancienne recherche
void verifierRecherches(const char *ville, float prix, const char *description);

#endif
