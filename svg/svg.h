#ifndef SVG_H
#define SVG_H

#include "document.h"

/**
 * Écrit le document dans un fichier SVG : une balise par forme,
 * avec ses couleurs et sa transformation éventuelle.
 *
 * @param doc le document à sauvegarder
 * @param nom le chemin du fichier de destination
 * @return    0 en cas de succès, -1 si le fichier n'a pas pu être ouvert
 */
int svg_sauver(document *doc, const char *nom);



#endif