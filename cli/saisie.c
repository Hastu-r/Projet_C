#include <stdio.h>
#include <string.h>

#include "saisie.h"


int lire_ligne(const char *invite, char *dest, int taille)
{
    printf("%s", invite);

    if (fgets(dest, taille, stdin) == NULL)
        return -1;

    dest[strcspn(dest, "\n")] = '\0';

    /* Ligne plus longue que le tampon : le reste traîne dans stdin,
       on le vide pour ne pas polluer la prochaine lecture. 
       size_t un type pour les tailles et longeurs, comme strlen renvoie un size_t on l'utilise pour
       convertir taille-1 en size_t
       strlen compte les caractère avant le \0, donc ici la vérif est : mon tampon est plein ? */
    if (strlen(dest) == (size_t)(taille - 1))
    {
        /* Ici getchar() lis ce qu'il reste dans le stdin (ce qui dépasse potentiellement du tampon)
         Elle lis caractère par caractère et le retire, si fin de fichier renvoie la const EOF
         c int car EOF int */
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }

    return 0;
}

int lire_entier(const char *invite)
{
    char saisie[256];

    while (1)
    {
        if (lire_ligne(invite, saisie, sizeof saisie) == -1)
            return -1;

        /* ajout récent de char reste avec %c dans les cas ou l'utilisateur donne 12abc par exemple,
        c'est normalement non valide mais avant ça passait, maintenant %c attrape ce qui colle
        au int et si y'a effectivement quelque chose sscanf renvoie 2 donc ça échoue*/
        int valeur;
        char reste;
        if (sscanf(saisie, "%d %c", &valeur, &reste) == 1)
            return valeur;

        printf("Veuillez entrer un nombre entier.\n");
    }
}

int lire_couleur(const char *invite, couleur *c)
{
    char saisie[256];

    while(1)
    {
        if (lire_ligne(invite, saisie, sizeof saisie) == -1)
            return -1;

        unsigned int vr, vg, vb;
        if (sscanf(saisie, "%u,%u,%u", &vr, &vg, &vb) == 3 && vr <= 255 && vg <= 255 && vb <= 255)
            {
                c->r = vr;
                c->g = vg;
                c->b = vb;
                return 0;
            }

        printf("Veuillez entrer une valeur au format rrr,ggg,bbb.\n");
    }
}

forme *lire_id_valide(document *doc)
{
    if (doc == NULL)
        return NULL;

    while(1)
    {
        int id = lire_entier("Valeur de l'id de la forme recherchée (-1 pour annuler): ");
        if (id == -1)
            return NULL;

        forme *element = rechercher_forme(doc, id);
        if (element != NULL)
            return element;

        printf("ID invalide.\n");
    }
}