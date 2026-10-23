#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commande.h"
#include "saisie.h"
#include "affichage.h"
#include "commande_forme.h"
#include "svg.h"

static void ajouter_element(document *doc)
{
    char saisie_ajouter[256];
    int position;
    int continuer_ajouter = 1;

    while (continuer_ajouter)
    {
        printf("---FORMES---\n");
        printf("1. Cercle\n");
        printf("2. Ellipse\n");
        printf("3. Rectangle\n");
        printf("4. Ligne\n");
        printf("5. Carré\n");
        printf("0. Retour au menu d'édition\n");

        if (lire_ligne("> ", saisie_ajouter, sizeof saisie_ajouter) == -1)
            return;

        if (strcmp(saisie_ajouter, "1") == 0)
        {
            position = lire_entier("Quelle position dans la liste : ");
            ajouter_cercle(doc, position);
        }
        
        else if (strcmp(saisie_ajouter, "2") == 0)
        {
            position = lire_entier("Quelle position dans la liste : ");
            ajouter_ellipse(doc, position);   
        }

        else if (strcmp(saisie_ajouter, "3") == 0)
        {
            position = lire_entier("Quelle position dans la liste : ");
            ajouter_rectangle(doc, position);
        }

        else if (strcmp(saisie_ajouter, "4") == 0)
        {
            position = lire_entier("Quelle position dans la liste : ");
            ajouter_ligne(doc, position);
        }

        else if (strcmp(saisie_ajouter, "5") == 0)
        {
            position = lire_entier("Quelle position dans la liste : ");
            ajouter_carre(doc, position);
        }

        else if (strcmp(saisie_ajouter, "0") == 0)
            continuer_ajouter = 0;

        else
            printf("Commande inconnue : %s\n", saisie_ajouter);      
    }
}

static void modifier_forme(forme *f)
{
    switch (f->type)
    {
        case CERCLE: modif_cercle(f); break;
        case ELLIPSE: modif_ellipse(f); break;
        case RECTANGLE: modif_rectangle(f); break;
        case LIGNE: modif_ligne(f); break;
        default: printf("Forme inconnue\n");
    }
}

static void afficher_document(document *doc)
{
    if (doc == NULL)
        return;

    forme *actuel = doc->premier;

    printf("Liste complète : ");
    while (actuel != NULL)
    {
        afficher_forme(actuel);
        actuel = actuel->suivant;
        printf("->");
    }
    printf("NULL\n");
    printf("Taille de la liste : %d\n", doc->taille_liste);
    return;
}

static void modif(document *doc)
{
    if (doc == NULL)
        return;

    afficher_document(doc);

    forme *element = lire_id_valide(doc);
    if (element == NULL)
    {
        printf("Aucun element avec cet id.\n");
        return ;
    }

    modifier_forme(element);

    return;
}


static void supprimer_element(document *doc)
{
    forme *element = lire_id_valide(doc);
    if (element == NULL)
    {
        printf("Aucun element avec cet id.\n");
        return;
    }

    int id = element->id;
    if (supprimer_forme(doc, id) == 0)
        printf("Forme %d supprimée.\n", id);
    else
        printf("Échec de la suppression.\n");
}

static void afficher_element(document *doc)
{
    if (doc == NULL)
        return;

    forme *element = lire_id_valide(doc);
    if (element == NULL)
    {
        printf("Aucun element avec cet id.\n");
        return;
    }

    afficher_forme(element);

    return;
}


void editer(document *doc)
{
    char saisie_editer[256];
    int continuer_editer = 1;

    while (continuer_editer)
    {
        printf("~~~Édition~~~\n");
        printf("1. Afficher le contenu de la liste\n");
        printf("2. Afficher un élément de la liste\n");
        printf("3. Ajouter une forme\n");
        printf("4. Supprimer une forme\n");
        printf("5. Modifier une forme\n");
        printf("6. Visualiser le document\n");
        printf("7. Sauvegarder le docuement\n");
        printf("0. Retour au menu principal\n");

        if (lire_ligne("> ", saisie_editer, sizeof saisie_editer) == -1)
            return;

        if (strcmp(saisie_editer, "1") == 0)
            afficher_document(doc);

        else if (strcmp(saisie_editer, "2") == 0)
            afficher_element(doc);

        else if (strcmp(saisie_editer, "3") == 0)
            ajouter_element(doc);

        else if (strcmp(saisie_editer, "4") == 0)
            supprimer_element(doc);

        else if (strcmp(saisie_editer, "5") == 0)
            modif(doc);

        else if (strcmp(saisie_editer, "6") == 0)
        {
            FILE *present = fopen(doc->nom_fichier, "r");
            if (present == NULL)
            {
                printf("Pas encore de fichier %s sur le disque : sauvegardez d'abord (option 7).\n", doc->nom_fichier);
            }
            else
            {
                fclose(present);
                char commande[320];
                snprintf(commande, sizeof commande, "xdg-open %s &", doc->nom_fichier);
                system(commande);
            }
        }

        else if (strcmp(saisie_editer, "7") == 0)
        {
            if (svg_sauver(doc, doc->nom_fichier) == 0)
                printf("Document sauvegardé dans %s\n", doc->nom_fichier);
            else
                printf("Échec de la sauvegarde.\n");
        }

        else if (strcmp(saisie_editer, "0") == 0)
            continuer_editer = 0;

        else
            printf("Commande inconnue : %s\n", saisie_editer);           
    }
}