#include <stdio.h>

#include "affichage.h"

static void afficher_couleur(forme *f)
{
    printf("couleur de fond rgb(%d,%d,%d) ", f->couleur_fond.r, f->couleur_fond.g, f->couleur_fond.b);
    printf("couleur de trait rgb(%d,%d,%d)\n", f->couleur_trait.r, f->couleur_trait.g, f->couleur_trait.b);
}

static void afficher_cercle(forme *f)
{
    printf("ID = %d, type = cercle, cx = %d, cy = %d, r = %d ", f->id, f->geo.cercle.cx, f->geo.cercle.cy, f->geo.cercle.r);
    afficher_couleur(f);
}

static void afficher_ellipse(forme *f)
{
    printf("ID = %d, type = ellipse, cx = %d, cy = %d, rx = %d, ry = %d ", f->id, f->geo.ellipse.cx, f->geo.ellipse.cy, f->geo.ellipse.rx, f->geo.ellipse.ry);
    afficher_couleur(f);
}

static void afficher_rectangle(forme *f)
{
    printf("ID = %d, type = rectangle, x = %d, y = %d, width = %d, height = %d ", f->id, f->geo.rectangle.x, f->geo.rectangle.y, f->geo.rectangle.width, f->geo.rectangle.height);
    afficher_couleur(f);
}

static void afficher_ligne(forme *f)
{
    printf("ID = %d, type = ligne, x1 = %d, y1 = %d, x2 = %d, y2 = %d ", f->id, f->geo.ligne.x1, f->geo.ligne.y1, f->geo.ligne.x2, f->geo.ligne.y2);
    printf("couleur de trait rgb(%d,%d,%d)\n", f->couleur_trait.r, f->couleur_trait.g, f->couleur_trait.b);
}


void afficher_forme(forme *f)
{
    if (f == NULL)                
        return;

    switch (f->type)
    {
    case CERCLE: afficher_cercle(f); break;
    case ELLIPSE: afficher_ellipse(f); break;
    case RECTANGLE: afficher_rectangle(f); break;
    case LIGNE: afficher_ligne(f); break;
    default: printf("Forme inconnue\n");
    }

    /* État de transformation : visible seulement s'il n'est pas neutre,
       pour que pivoter et inverser se voient à l'affichage. */
    if (f->transformation.angle != 0 || f->transformation.inverse_x || f->transformation.inverse_y)
    {
        printf("    transformation : angle = %d", f->transformation.angle);
        if (f->transformation.inverse_x)
            printf(", inversée selon X");
        if (f->transformation.inverse_y)
            printf(", inversée selon Y");
        printf("\n");
    }
}