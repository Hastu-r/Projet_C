#ifndef TRANSFORM_H
#define TRANSFORM_H

/**
 * Représente l'état de transformation d'une forme.
 *
 * La transformation est représentée, jamais calculée : le modèle
 * stocke l'état, et c'est la sauvegarde SVG qui le traduit en
 * attribut transform="...".
 *
 * L'état {0, 0, 0} est l'élément neutre : aucune transformation,
 * aucun attribut écrit à la sauvegarde.
 */
typedef struct transform transform;
struct transform
{
    int angle;      /* rotation en degrés, angle absolu (0 = pas de rotation) */
    int inverse_x;  /* inversion selon l'axe X : 0 = normale, 1 = inversée     */
    int inverse_y;  /* inversion selon l'axe Y : 0 = normale, 1 = inversée     */
};

#endif