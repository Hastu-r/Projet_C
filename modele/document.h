#ifndef DOCUMENT_H
#define DOCUMENT_H

/* Le dossier où vivent les fichiers SVG du projet. */
#define DOSSIER_DESSINS "dessins"

typedef struct forme forme;

/**
 * Le document : un plan de dimensions fixes et la liste des
 * formes qu'il contient.
 */
typedef struct document document;
struct document
{
    int width;             /* la largeur du plan, en pixels       */
    int height;            /* la hauteur du plan, en pixels       */
    int taille_liste;      /* le nombre de formes présentes       */
    int compteur_id;       /* le prochain identifiant à attribuer */
    forme *premier;        /* la tête de la liste des formes      */
    char nom_fichier[256]; /* le fichier SVG associé au document  */
};

/**
 * Crée un document vide aux dimensions données.
 *
 * @param width   la largeur du plan
 * @param height  la hauteur du plan
 * @return        le document créé, ou NULL si l'allocation a échoué
 */
document *initialiser_document(int width, int height);

/**
 * Associe un fichier SVG au document : c'est dans ce fichier
 * que la sauvegarde l'écrira, c'est lui que "Visualiser" ouvre.
 *
 * @param doc le document cible
 * @param nom le chemin du fichier (ex: "dessin.svg")
 * @return    0 en cas de succès, -1 si un argument est NULL
 */
int definir_nom_fichier(document *doc, const char *nom);

/**
 * Alloue une forme et l'insère dans le document à la position demandée.
 *
 * La forme commence à l'état neutre : transformation {0,0,0}, identifiant
 * unique attribué automatiquement (à partir de 1 — le 0 n'est jamais
 * un id valide, il sert de valeur d'annulation côté menu). Ses
 * couleurs et sa géométrie restent à définir par l'appelant.
 *
 * Si la position dépasse la taille de la liste, la forme est
 * ajoutée à la fin (pas d'erreur).
 *
 * @param doc      le document cible
 * @param position la position d'insertion (0 = début)
 * @return         la forme insérée, ou NULL si arguments invalides ou allocation échouée
 */
forme * inserer_forme(document *doc, int position);

/**
 * Supprime la forme portant cet identifiant et libère sa mémoire.
 *
 * @param doc le document cible
 * @param id  l'identifiant de la forme à supprimer
 * @return 0 si supprimée, -1 si le document est NULL ou l'id introuvable
 */
int supprimer_forme(document *doc, int id);

/**
 * Recherche la forme portant cet identifiant.
 *
 * @param doc le document cible
 * @param id  l'identifiant recherché
 * @return    la forme trouvée, ou NULL si introuvable ou document NULL
 */
forme * rechercher_forme(document *doc, int id);

/**
 * Libère toutes les formes du document, puis le document lui-même.
 * Le pointeur devient invalide après l'appel.
 *
 * @param doc le document à libérer
 * @return 0 en cas de succès, -1 si le document est NULL
 */
int liberer_document(document *doc);


#endif