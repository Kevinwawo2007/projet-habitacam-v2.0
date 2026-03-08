#include "Favori.h"

// Enregistre la recherche dans un fichier "recherches.txt"
void enregistrerRecherche(const char *ville, float prix, const char *description)
{
    FILE *f = fopen("recherches.txt", "a"); // ouvrir en mode ajout
    if (f == NULL)
    {
        printf("Erreur: impossible d'ouvrir le fichier des recherches.\n");
        return;
    }

    fprintf(f, "%s %.2f %s\n", ville, prix, description);
    fclose(f);
}

// Vérifie si un nouveau logement correspond à une recherche précédente
void verifierRecherches(const char *ville, float prix, const char *description)
{
    FILE *f = fopen("recherches.txt", "r"); // lire le fichier
    if (f == NULL)
        return; // si fichier inexistant, rien à faire

    char ville_r[50];
    float prix_r;
    char description_r[100];

    while (fscanf(f, "%s %f %s", ville_r, &prix_r, description_r) != EOF)
    {
        if (strcmp(ville_r, ville) == 0 &&
            prix <= prix_r &&
            strcmp(description_r, description) == 0)
        {
            printf("\n--- Notification ---\n");
            printf("Une maison correspondant à une recherche précédente est maintenant disponible !\n");
            printf("Ville : %s\nPrix : %.2f\nDescription : %s\n", ville, prix, description);
        }
    }

    fclose(f);
}
