#ifndef COMMANDE_H
#define COMMANDE_H

#include "document.h"

/**
 * Boucle principale du menu d'édition : afficher, ajouter,
 * supprimer, modifier, visualiser ou sauvegarder les formes
 * du document. Rend la main sur "0" ou Ctrl+D.
 *
 * @param doc le document édité
 */
void editer(document *doc);

#endif