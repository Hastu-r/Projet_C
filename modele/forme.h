#ifndef FORME_H
#define FORME_H

#include "couleur.h"
#include "transform.h"
#include "cercle.h"
#include "ellipse.h"
#include "rectangle.h"
#include "ligne.h"

/**
 * Les types de formes du modèle.
 */
typedef enum type_forme type_forme;
enum type_forme
{
    CERCLE,
    ELLIPSE,
    RECTANGLE,
    LIGNE,
};

/**
 * La géométrie propre au type de la forme.
 * Une seule de ces structures est valide à la fois, celle qui
 * correspond au champ type de la forme utilisée.
 */
typedef union geometrie geometrie;
union geometrie
{
    cercle cercle;
    ellipse ellipse;
    rectangle rectangle;
    ligne ligne;
};

/**
 * Une forme du document.
 *
 * Champs communs à toutes les formes : identifiant, type, couleurs,
 * transformation. La géométrie spécifique vit dans geo, selon le type.
 */
typedef struct forme forme;
struct forme
{
    int id;                    /* identifiant unique, affiché à l'utilisateur */
    type_forme type;           /* quelle union membre est valide dans geo     */
    forme *suivant;            /* la forme suivante dans le document          */
    geometrie geo;             /* les coordonnées propres à la forme          */
    couleur couleur_fond;      /* couleur de remplissage                      */
    couleur couleur_trait;     /* couleur du contour                          */
    transform transformation;  /* état de rotation/inversion, élément neutre = {0,0,0} */
};

/**
 * Rend dans *px et *py le centre géométrique de la forme f.
 *
 * Le centre sert de pivot à la rotation et de point d'ancrage à
 * l'inversion lors de la sauvegarde SVG.
 *
 * @param f  la forme dont on cherche le centre
 * @param px pointeur de sortie : abscisse du centre
 * @param py pointeur de sortie : ordonnée du centre
 * @return   0 si le centre a été calculé, -1 si un argument est NULL
 *           ou si le type de la forme est inconnu
 */
int centre_forme(forme *f, int *px, int *py);

#endif