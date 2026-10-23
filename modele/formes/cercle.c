#include <stddef.h>

#include "cercle.h"
#include "document.h"
#include "forme.h"
#include "couleur.h"


int inserer_cercle(document *doc, int position, int cx, int cy, int r, couleur fond, couleur trait)
{
    forme *nouveau = inserer_forme(doc, position);
    if (nouveau == NULL)
        return -1;

    nouveau->type = CERCLE;
    nouveau->geo.cercle.cx = cx;
    nouveau->geo.cercle.cy = cy;
    nouveau->geo.cercle.r = r;

    nouveau->couleur_fond = fond;
    nouveau->couleur_trait = trait;
    
    return nouveau->id;
}

