#ifndef COULEUR_H
#define COULEUR_H

/**
 * Une couleur en notation rgb.
 *
 * Chaque valeur est un entier de 0 (éteint) à 255 (intensité maximale),
 * on utilise unsigned char car 0-255 tient exactement dans 1 octet.
 */
typedef struct couleur couleur;
struct couleur
{
    unsigned char r;    /* intensité du canal rouge  */
    unsigned char g;    /* intensité du canal vert   */
    unsigned char b;    /* intensité du canal bleu   */
};

#endif