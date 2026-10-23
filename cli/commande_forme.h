#ifndef COMMANDE_FORME_H
#define COMMANDE_FORME_H

#include "document.h"
#include "forme.h"

/**
 * Demande les paramètres d'un cercle à l'utilisateur puis
 * l'insère dans le document, et annonce son identifiant.
 * Une annulation à n'importe quelle question interrompt l'ajout.
 *
 * @param doc      le document cible
 * @param position la position d'insertion dans la liste
 */
void ajouter_cercle(document *doc, int position);

/**
 * Boucle du menu de modification d'une forme : géométrie,
 * couleurs, pivot et inversion. Rend la main sur "0" ou Ctrl+D.
 *
 * @param f la forme à modifier
 */
void modif_cercle(forme *f);

/**
 * Demande les paramètres d'une ellipse à l'utilisateur puis
 * l'insère dans le document, et annonce son identifiant.
 * Une annulation à n'importe quelle question interrompt l'ajout.
 *
 * @param doc      le document cible
 * @param position la position d'insertion dans la liste
 */
void ajouter_ellipse(document *doc, int position);

/**
 * Boucle du menu de modification d'une forme : géométrie,
 * couleurs, pivot et inversion. Rend la main sur "0" ou Ctrl+D.
 *
 * @param f la forme à modifier
 */
void modif_ellipse(forme *f);

/**
 * Demande les paramètres d'un rectangle à l'utilisateur puis
 * l'insère dans le document, et annonce son identifiant.
 * Une annulation à n'importe quelle question interrompt l'ajout.
 *
 * @param doc      le document cible
 * @param position la position d'insertion dans la liste
 */
void ajouter_rectangle(document *doc, int position);

/**
 * Boucle du menu de modification d'une forme : géométrie,
 * couleurs, pivot et inversion. Rend la main sur "0" ou Ctrl+D.
 *
 * @param f la forme à modifier
 */
void modif_rectangle(forme *f);

/**
 * Demande les paramètres d'un carre à l'utilisateur puis
 * l'insère dans le document, et annonce son identifiant.
 * Une annulation à n'importe quelle question interrompt l'ajout.
 *
 * @param doc      le document cible
 * @param position la position d'insertion dans la liste
 */
void ajouter_carre(document *doc, int position);

/**
 * Demande les paramètres d'une ligne à l'utilisateur puis
 * l'insère dans le document, et annonce son identifiant.
 * Une annulation à n'importe quelle question interrompt l'ajout.
 *
 * @param doc      le document cible
 * @param position la position d'insertion dans la liste
 */
void ajouter_ligne(document *doc, int position);

/**
 * Boucle du menu de modification d'une forme : géométrie,
 * couleurs, pivot et inversion. Rend la main sur "0" ou Ctrl+D.
 *
 * @param f la forme à modifier
 */
void modif_ligne(forme *f);

#endif