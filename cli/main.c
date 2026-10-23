#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "document.h"
#include "saisie.h"
#include "affichage.h"
#include "commande.h"


int main(void)
{
    document *doc = initialiser_document(800, 800);
    if (doc == NULL)
    {
        printf("Erreur : impossible de créer le document\n");
        return -1;
    }
    
    system("clear");
    char ligne[256];
    int continuer = 1;

    while (continuer)
    {
        printf("===COMMANDES===\n");
        printf("1. Ouvrir\n");
        printf("2. Nouveau\n");
        printf("0. Quitter\n");

        if (lire_ligne("> ", ligne, sizeof ligne) == -1)
            continuer = 0;

        if (strcmp(ligne, "1") == 0)
        {
            system("clear");
            printf("Pas pris en charge pour le moment\n");
        }

        else if (strcmp(ligne, "2") == 0)
        {
            system("clear");
            char nom[256];
            if (lire_ligne("Nom du fichier SVG (ex: dessin.svg) : ", nom, sizeof nom) == 0 && nom[0] != '\0')
            {
                definir_nom_fichier(doc, nom);
                editer(doc);
            }
        }

        else if (strcmp(ligne, "0") == 0)
        {
            system("clear");
            continuer = 0;
        }

        else
            printf("Commande inconnue : %s\n", ligne);
    }
    liberer_document(doc);
    return 0;
}