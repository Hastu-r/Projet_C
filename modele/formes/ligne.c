#include <stddef.h>

#include "ligne.h"
#include "document.h"
#include "forme.h"
#include "couleur.h"


int inserer_ligne(document *doc, int position, int x1, int y1, int x2, int y2, couleur fond, couleur trait)
{
    forme *nouveau = inserer_forme(doc, position);
    if (nouveau == NULL)
        return -1;

    nouveau->type = LIGNE;
    nouveau->geo.ligne.x1 = x1;
    nouveau->geo.ligne.y1 = y1;
    nouveau->geo.ligne.x2 = x2;
    nouveau->geo.ligne.y2 = y2;

    nouveau->couleur_fond = fond;
    nouveau->couleur_trait = trait;
    
    return nouveau->id;
}

