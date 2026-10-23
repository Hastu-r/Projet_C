#ifndef CERCLE_H
#define CERCLE_H

typedef struct document document;
typedef struct couleur couleur;

/**
 * La géométrie propre à un cercle.
 * Les noms cx, cy et r reprennent les attributs SVG correspondants.
 */
typedef struct cercle cercle;
struct cercle
{
    int cx;    /* abscisse du centre  */
    int cy;    /* ordonnée du centre  */
    int r;     /* rayon               */
};

/**
 * Insère un cercle dans le document à la position demandée.
 *
 * @param doc      le document cible
 * @param position la position d'insertion (0 = début, dépassement = fin)
 * @param cx       abscisse du centre du cercle
 * @param cy       ordonnée du centre du cercle
 * @param r        rayon du cercle
 * @param fond     couleur de remplissage
 * @param trait    couleur du contour
 * @return         l'identifiant attribué au cercle, ou -1 si l'insertion a échoué
 */
int inserer_cercle(document *doc, int position, int cx, int cy, int r, couleur fond, couleur trait);

#endif