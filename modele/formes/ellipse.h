#ifndef ELLIPSE_H
#define ELLIPSE_H

typedef struct document document;
typedef struct couleur couleur;

/**
 * La géométrie propre à une ellipse.
 * Les noms cx, cy rx et ry reprennent les attributs SVG correspondants.
 */
typedef struct ellipse ellipse;
struct ellipse
{
    int cx;    /* abscisse du centre  */
    int cy;    /* ordonnée du centre  */
    int rx;    /* rayon d'abscisse    */
    int ry;    /* rayon d'ordonnée    */
};

/**
 * Insère une ellipse dans le document à la position demandée.
 *
 * @param doc      le document cible
 * @param position la position d'insertion (0 = début, dépassement = fin)
 * @param cx       abscisse du centre de l'ellipse
 * @param cy       ordonnée du centre de l'ellipse
 * @param rx       rayon en abscisse de l'ellipse
 * @param ry       rayon en ordonnée de l'ellipse
 * @param fond     couleur de remplissage
 * @param trait    couleur du contour
 * @return         l'identifiant attribué à l'ellipse, ou -1 si l'insertion a échoué
 */
int inserer_ellipse(document *doc, int position, int cx, int cy, int rx, int ry, couleur fond, couleur trait);


#endif