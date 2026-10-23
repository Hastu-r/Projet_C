#include <stdio.h>
#include <stdlib.h>

#include "document.h"
#include "forme.h"
#include "transform.h"

document *initialiser_document(int width, int height)
{
    document *doc = malloc(sizeof(*doc));
    if (doc == NULL)
        return NULL;
    doc->width = width;
    doc->height = height;
    doc->nom_fichier[0] = '\0';
    doc->taille_liste = 0;
    doc->compteur_id = 1;
    doc->premier = NULL;
    return doc;
}

int definir_nom_fichier(document *doc, const char *nom)
{
    if (doc == NULL || nom == NULL)
        return -1;

    snprintf(doc->nom_fichier, sizeof doc->nom_fichier, "%s/%s", DOSSIER_DESSINS, nom);
    return 0;
}

forme * inserer_forme(document *doc, int position)
{
    if (doc == NULL || position < 0)
        return NULL;

    forme *nouveau = malloc(sizeof(*nouveau));
    if (nouveau == NULL)
        return NULL;

    if (position == 0 || doc->premier == NULL)
    {
        nouveau->suivant = doc->premier;
        doc->premier = nouveau;
    }

    else
    {
        forme *precedent = doc->premier;
        while(precedent->suivant != NULL && position > 1)
        {
            precedent = precedent->suivant;
            position--;
        }
    nouveau->suivant = precedent->suivant;
    precedent->suivant = nouveau;
    }

    nouveau->id = doc->compteur_id;
    nouveau->transformation = (transform){0};
    doc->taille_liste += 1;
    doc->compteur_id += 1;
    return nouveau;
}

int supprimer_forme(document *doc, int id)
{
    if (doc == NULL)
        return -1;

    forme *actuel = doc->premier;
    forme *precedent = NULL;

    while (actuel != NULL && actuel->id != id)
    {
        precedent = actuel;
        actuel = actuel->suivant;
    }

    if (actuel == NULL)
        return -1;

    /* Si precedent est NULL, la cible est la tête : c'est doc->premier
       qu'il faut réécrire, pas precedent->suivant. */
    if (precedent == NULL)
        doc->premier = actuel->suivant;
    else
        precedent->suivant = actuel->suivant;

    doc->taille_liste -= 1;

    free(actuel);
    return 0;
}


forme * rechercher_forme(document *doc, int id) 
{
    if (doc == NULL)
        return NULL;

    forme *actuel = doc->premier;

    while(actuel != NULL && id != actuel->id)
    {
        actuel = actuel->suivant;
    }
    return actuel;
}

int liberer_document(document *doc)
{
    if (doc == NULL)
        return -1;

    forme *actuel = doc->premier;

    while (actuel != NULL)
    {
        forme *prochaine_forme = actuel->suivant;
        free(actuel);
        actuel = prochaine_forme;
    }
    free(doc);
    return 0;
}