#ifndef LIGNE_H
#define LIGNE_H

typedef struct document document;
typedef struct couleur couleur;

/**
 * La géométrie propre à une ligne.
 * Les noms x1, y1, x2, y2 reprennent les attributs SVG correspondants.
 */
typedef struct ligne ligne;
struct ligne
{
    int x1;    /* la position en abscisse du 1er point   */
    int y1;    /* la position en ordonnée du 1er point   */
    int x2;    /* la position en abscisse du 2nd point   */
    int y2;    /* la position en ordonnée du 2nd point   */
};

/**
 * Insère une ligne dans le document à la position demandée.
 *
 * @param doc      le document cible
 * @param position la position d'insertion (0 = début, dépassement = fin)
 * @param x1       abscisse du 1er pointde la ligne
 * @param y1       ordonnée du 1er point de la ligne
 * @param x2       abscisse du 2nd point de la ligne
 * @param y2       ordonnée du 2nd point de la ligne
 * @param fond     couleur de remplissage
 * @param trait    couleur du contour
 * @return         l'identifiant attribué à la ligne, ou -1 si l'insertion a échoué
 */
int inserer_ligne(document *doc, int position, int x1, int y1, int x2, int y2, couleur fond, couleur trait);

#endif