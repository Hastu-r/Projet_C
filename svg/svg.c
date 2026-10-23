#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> 

#include "svg.h"
#include "forme.h"

/* Ecrit la transformation ssi elle est transformée car de base == 0
   avec centre forme on récupere le centre de la forme en centre_x (cx) ..y */
static void svg_transform(forme *f, FILE *fichier)
{
    if (f->transformation.angle == 0 && !f->transformation.inverse_x && !f->transformation.inverse_y)
        return;                      

    int cx, cy;
    centre_forme(f, &cx, &cy);

    fprintf(fichier, "transform=\"");
    if (f->transformation.angle != 0)
        fprintf(fichier, "rotate(%d %d %d) ", f->transformation.angle, cx, cy);
    if (f->transformation.inverse_x)
        fprintf(fichier, "translate(%d 0) scale(-1 1) ", 2 * cx);
    if (f->transformation.inverse_y)
        fprintf(fichier, "translate(0 %d) scale(1 -1) ", 2 * cy);
    fprintf(fichier, "\" ");
}


static void svg_cercle(forme *f, FILE *fichier)
{
    fprintf(fichier, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" ", f->geo.cercle.cx, f->geo.cercle.cy, f->geo.cercle.r);
    fprintf(fichier, "fill=\"rgb(%d,%d,%d)\" ", f->couleur_fond.r, f->couleur_fond.g, f->couleur_fond.b);
    fprintf(fichier, "stroke=\"rgb(%d,%d,%d)\" ", f->couleur_trait.r, f->couleur_trait.g, f->couleur_trait.b);
    svg_transform(f, fichier);
    fprintf(fichier, "/>\n");
}

static void svg_ellipse(forme *f, FILE *fichier)
{
    fprintf(fichier, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" ", f->geo.ellipse.cx, f->geo.ellipse.cy, f->geo.ellipse.rx, f->geo.ellipse.ry);
    fprintf(fichier, "fill=\"rgb(%d,%d,%d)\" ", f->couleur_fond.r, f->couleur_fond.g, f->couleur_fond.b);
    fprintf(fichier, "stroke=\"rgb(%d,%d,%d)\" ", f->couleur_trait.r, f->couleur_trait.g, f->couleur_trait.b);
    svg_transform(f, fichier);
    fprintf(fichier, "/>\n");
}

static void svg_rectangle(forme *f, FILE *fichier)
{
    fprintf(fichier, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" ", f->geo.rectangle.x, f->geo.rectangle.y, f->geo.rectangle.width, f->geo.rectangle.height);
    fprintf(fichier, "fill=\"rgb(%d,%d,%d)\" ", f->couleur_fond.r, f->couleur_fond.g, f->couleur_fond.b);
    fprintf(fichier, "stroke=\"rgb(%d,%d,%d)\" ", f->couleur_trait.r, f->couleur_trait.g, f->couleur_trait.b);
    svg_transform(f, fichier);
    fprintf(fichier, "/>\n");
}

static void svg_ligne(forme *f, FILE *fichier)
{
    fprintf(fichier, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" ", f->geo.ligne.x1, f->geo.ligne.y1, f->geo.ligne.x2, f->geo.ligne.y2);
    fprintf(fichier, "stroke=\"rgb(%d,%d,%d)\" ", f->couleur_trait.r, f->couleur_trait.g, f->couleur_trait.b);
    svg_transform(f, fichier);
    fprintf(fichier, "/>\n");
}

static void svg_forme(forme *f, FILE *fichier)
{
    switch (f->type)
    {
    case CERCLE: svg_cercle(f, fichier); break;
    case ELLIPSE: svg_ellipse(f, fichier); break;
    case RECTANGLE: svg_rectangle(f, fichier); break;
    case LIGNE: svg_ligne(f, fichier); break;
    default: printf("Type inconnu\n");
    }
}


int svg_sauver(document *doc, const char *nom)
{
    mkdir(DOSSIER_DESSINS, 0755);    /* crée le dossier s'il manque ; s'il existe déjà, échec ignoré */

    FILE *fichier = fopen(nom, "w");
    if (fichier == NULL)
        return -1;

    fprintf(fichier, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\">\n", doc->width, doc->height);

    forme *actuel = doc->premier;
    while (actuel != NULL)
    {
        svg_forme(actuel, fichier);     
        actuel = actuel->suivant;
    }

    fprintf(fichier, "</svg>\n");
    fclose(fichier);
    return 0;
}