#include <stddef.h>

#include "rectangle.h"
#include "document.h"
#include "forme.h"
#include "couleur.h"


int inserer_rectangle(document *doc, int position, int x, int y, int width, int height, couleur fond, couleur trait)
{
    forme *nouveau = inserer_forme(doc, position);
    if (nouveau == NULL)
        return -1;

    nouveau->type = RECTANGLE;
    nouveau->geo.rectangle.x = x;
    nouveau->geo.rectangle.y = y;
    nouveau->geo.rectangle.width = width;
    nouveau->geo.rectangle.height = height;

    nouveau->couleur_fond = fond;
    nouveau->couleur_trait = trait;
    
    return nouveau->id;
}

