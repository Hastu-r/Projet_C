#ifndef RECTANGLE_H
#define RECTANGLE_H

typedef struct document document;
typedef struct couleur couleur;

/**
 * La géométrie propre à un rectangle.
 * Les noms x, y, width, height reprennent les attributs SVG correspondants.
 */
typedef struct rectangle rectangle;
struct rectangle
{
    int x;         /* la position en abscisse du coin haut-gauche du rectangle  */
    int y;         /* la position en ordonnée du coin haut-gauche du rectangle  */
    int width;     /* la largeur du rectangle                                   */
    int height;    /* la hauteur du rectangle                                   */
};

/**
 * Insère un rectangle dans le document à la position demandée.
 *
 * @param doc      le document cible
 * @param position la position d'insertion (0 = début, dépassement = fin)
 * @param x        position en abscisse du coin haut-gauche du rectangle
 * @param y        position en ordonnée du coin haut-gauche du rectangle
 * @param width    largeur du rectangle
 * @param height   hauteur du rectangle
 * @param fond     couleur de remplissage
 * @param trait    couleur du contour
 * @return         l'identifiant attribué au rectangle, ou -1 si l'insertion a échoué
 */
int inserer_rectangle(document *doc, int position, int x, int y, int width, int height, couleur fond, couleur trait);

#endif