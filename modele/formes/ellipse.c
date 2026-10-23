#include <stddef.h>

#include "ellipse.h"
#include "document.h"
#include "forme.h"
#include "couleur.h"


int inserer_ellipse(document *doc, int position, int cx, int cy, int rx, int ry, couleur fond, couleur trait)
{
    forme *nouveau = inserer_forme(doc, position);
    if (nouveau == NULL)
        return -1;

    nouveau->type = ELLIPSE;
    nouveau->geo.ellipse.cx = cx;
    nouveau->geo.ellipse.cy = cy;
    nouveau->geo.ellipse.rx = rx;
    nouveau->geo.ellipse.ry = ry;

    nouveau->couleur_fond = fond;
    nouveau->couleur_trait = trait;
    
    return nouveau->id;
}
