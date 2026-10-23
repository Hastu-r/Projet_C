#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "forme.h"

/**
 * Affiche une forme : identifiant, type, géométrie, couleurs,
 * puis son état de transformation s'il n'est pas neutre.
 *
 * @param f la forme à afficher (rien ne se passe si NULL)
 */
void afficher_forme(forme *f);

#endif