#ifndef SAISIE_H
#define SAISIE_H

#include "couleur.h"
#include "document.h"
#include "forme.h"

/**
 * Lit une ligne au clavier, sans le retour à la ligne final.
 * Une ligne plus longue que le tampon est tronquée et le reste vidé.
 *
 * @param invite le texte affiché avant la saisie
 * @param dest   le tampon de destination (au moins taille octets)
 * @param taille la taille du tampon
 * @return       0 si une ligne a été lue, -1 si fin de flux (Ctrl+D)
 */
int lire_ligne(const char *invite, char *dest, int taille);

/**
 * Lit un entier au clavier jusqu'à obtenir une valeur valide.
 * La valeur -1 est réservée : elle signifie l'annulation (ou Ctrl+D)
 * et ne peut donc pas être saisie comme valeur légitime.
 *
 * @param invite le texte affiché avant la saisie
 * @return       l'entier lu, ou -1 si annulation
 */
int lire_entier(const char *invite);

/**
 * Lit une couleur au format "r,g,b" (chaque canal entre 0 et 255),
 * jusqu'à obtenir une valeur valide.
 *
 * @param invite le texte affiché avant la saisie
 * @param c      pointeur de sortie : la couleur lue
 * @return       0 si la couleur a été lue, -1 si annulation (ou Ctrl+D)
 */
int lire_couleur(const char *invite, couleur *c);

/**
 * Réclame un identifiant jusqu'à ce qu'il corresponde à une forme
 * du document, ou jusqu'à annulation (-1).
 *
 * @param doc le document dans lequel chercher
 * @return    la forme correspondant à l'id saisi, ou NULL si annulation
 */
forme *lire_id_valide(document *doc);

#endif