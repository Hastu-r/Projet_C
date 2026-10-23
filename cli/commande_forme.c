#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commande_forme.h"
#include "saisie.h"

static void modifier_entier(const char *etiquette, int *cible)
{
    printf("Nouvelle valeur de %s (actuelle : %d) : ", etiquette, *cible);

    int v = lire_entier("");
    if (v == -1)          
        return;

    *cible = v;           
}

static void modifier_couleur(const char *etiquette, couleur *cible)
{
    couleur nouvelle;
    printf("%s actuelle : (%d, %d, %d)\n", etiquette, cible->r, cible->g, cible->b);

    if (lire_couleur("Nouvelle couleur (r,g,b) : ", &nouvelle) == 0)
        *cible = nouvelle;         
}

static void pivoter_forme(forme *f)
{
    printf("Angle actuel : %d\n", f->transformation.angle);
    int angle = lire_entier("Nouvel angle : ");
    if (angle != -1)
        f->transformation.angle = angle;
}

static void inverser_forme(forme *f)
{
    char axe[8];
    if (lire_ligne("Axe (X/Y) : ", axe, sizeof axe) == -1)
        return;
    if (strcmp(axe, "X") == 0 || strcmp(axe, "x") == 0)
        f->transformation.inverse_x = !f->transformation.inverse_x;
    else if (strcmp(axe, "Y") == 0 || strcmp(axe, "y") == 0)
        f->transformation.inverse_y = !f->transformation.inverse_y;
    else
        printf("Axe inconnu : %s\n", axe);
}

void ajouter_cercle(document *doc, int position)
{
    int cx = lire_entier("Valeur de cx : ");
    int cy = lire_entier("Valeur de cy : ");
    int r  = lire_entier("Valeur de r : ");
    if (cx == -1 || cy == -1 || r == -1)
    {
        system("clear");
        printf("Saisie annulée, aucune forme ajoutée\n");
        return;
    }                                 

    couleur fond, trait;
    // la vérif de -1 fonctionne même pas car lire_couleur empêche -1, à vérifier                               
    if (lire_couleur("Couleur de fond (r,g,b) : ",  &fond)  == -1)
    {
        system("clear");
        printf("Saisie annulée, aucune forme ajoutée\n");
        return;
    }
    if (lire_couleur("Couleur de trait (r,g,b) : ", &trait) == -1)
    {
        system("clear");
        printf("Saisie annulée, aucune forme ajoutée\n");
        return;
    }

    system("clear");
    int id = inserer_cercle(doc, position, cx, cy, r, fond, trait);
    if (id < 0)
        printf("Erreur, ajout impossible\n");
    else
        printf("Cercle ajouté sous l'ID %d\n", id);     
}

void modif_cercle(forme *f)
{
    system("clear");
    char saisie_modif[256];
    int continuer_modif = 1;

    while (continuer_modif)
    {
        printf("^^^Modification -- cercle^^^\n");
        printf("1. Valeur de cx\n");
        printf("2. Valeur de cy\n");
        printf("3. Valeur de r\n");
        printf("4. Couleur de fond\n");
        printf("5. Couleur de trait\n");
        printf("6. Pivoter\n");
        printf("7. Inverser\n");
        printf("0. Retour au menu d'édition\n");

        if (lire_ligne("> ", saisie_modif, sizeof saisie_modif) == -1)
            return;

        if (strcmp(saisie_modif, "1") == 0)
        {
            system("clear");
            modifier_entier("cx", &f->geo.cercle.cx);
        }

        else if (strcmp(saisie_modif, "2") == 0)
        {
            system("clear");
            modifier_entier("cy", &f->geo.cercle.cy);
        }

        else if (strcmp(saisie_modif, "3") == 0)
        {
            system("clear");
            modifier_entier("r", &f->geo.cercle.r);
        }

        else if (strcmp(saisie_modif, "4") == 0)
        {
            system("clear");
            modifier_couleur("Couleur fond", &f->couleur_fond);
        }

        else if (strcmp(saisie_modif, "5") == 0)
        {
            system("clear");
            modifier_couleur("Couleur trait", &f->couleur_trait);
        }

        else if (strcmp(saisie_modif, "6") == 0)
        {
            system("clear");
            pivoter_forme(f);
        }

        else if (strcmp(saisie_modif, "7") == 0)
        {
            system("clear");
            inverser_forme(f);
        }

        else if (strcmp(saisie_modif, "0") == 0)
        {
            system("clear");
            continuer_modif = 0;
        }

        else
            printf("Commande inconnue : %s\n", saisie_modif);
    }
}


void ajouter_ellipse(document *doc, int position)
{
    int cx = lire_entier("Valeur de cx : ");
    int cy = lire_entier("Valeur de cy : ");
    int rx = lire_entier("Valeur de rx : ");
    int ry = lire_entier("Valeur de ry : ");
    if (cx == -1 || cy == -1 || rx == -1 || ry == -1)
    {
        system("clear");
        printf("Saisie annulée, aucune forme ajoutée\n");
        return;
    }                                 

    couleur fond, trait;                              
    if (lire_couleur("Couleur de fond (r,g,b) : ",  &fond)  == -1) 
    {
        system("clear");
        printf("Saisie annulée, aucune forme ajoutée\n");
        return;
    }
    if (lire_couleur("Couleur de trait (r,g,b) : ", &trait) == -1)
    {
        system("clear");
        printf("Saisie annulée, aucune forme ajoutée\n");
        return;
    }

    system("clear");
    int id = inserer_ellipse(doc, position, cx, cy, rx, ry, fond, trait);
    if (id < 0)
        printf("Erreur, ajout impossible\n");
    else
        printf("Ellipse ajoutée sous l'ID %d\n", id);     
}

void modif_ellipse(forme *f)
{
    system("clear");
    char saisie_modif[256];
    int continuer_modif = 1;

    while (continuer_modif)
    {
        printf("^^^Modification -- ellipse^^^\n");
        printf("1. Valeur de cx\n");
        printf("2. Valeur de cy\n");
        printf("3. Valeur de rx\n");
        printf("4. Valeur de ry\n");
        printf("5. Couleur de fond\n");
        printf("6. Couleur de trait\n");
        printf("7. Pivoter\n");
        printf("8. Inverser\n");
        printf("0. Retour au menu d'édition\n");

        if (lire_ligne("> ", saisie_modif, sizeof saisie_modif) == -1)
            return;

        if (strcmp(saisie_modif, "1") == 0)
        {
            system("clear");
            modifier_entier("cx", &f->geo.ellipse.cx);
        }

        else if (strcmp(saisie_modif, "2") == 0)
        {
            system("clear");
            modifier_entier("cy", &f->geo.ellipse.cy);
        }
        
        else if (strcmp(saisie_modif, "3") == 0)
        {
            system("clear");
            modifier_entier("rx", &f->geo.ellipse.rx);
        }

        else if (strcmp(saisie_modif, "4") == 0)
        {
            system("clear");
            modifier_entier("ry", &f->geo.ellipse.ry);
        }

        else if (strcmp(saisie_modif, "5") == 0)
        {
            system("clear");
            modifier_couleur("Couleur fond", &f->couleur_fond);
        }

        else if (strcmp(saisie_modif, "6") == 0)
        {
            system("clear");
            modifier_couleur("Couleur trait", &f->couleur_trait);
        }

        else if (strcmp(saisie_modif, "7") == 0)
        {
            system("clear");
            pivoter_forme(f);
        }

        else if (strcmp(saisie_modif, "8") == 0)
        {
            system("clear");
            inverser_forme(f);
        }

        else if (strcmp(saisie_modif, "0") == 0)
        {
            system("clear");
            continuer_modif = 0;
        }

        else
            printf("Commande inconnue : %s\n", saisie_modif);
    }
}


void ajouter_rectangle(document *doc, int position)
{
    int x = lire_entier("Valeur de x : ");
    int y = lire_entier("Valeur de y : ");
    int width = lire_entier("Valeur de width : ");
    int height = lire_entier("Valeur de height : ");
    if (x == -1 || y == -1 || width == -1 || height == -1)
    {
        system("clear");
        printf("Saisie annulée, aucune forme ajoutée\n");
        return;
    }                         

    couleur fond, trait;                              
    if (lire_couleur("Couleur de fond (r,g,b) : ",  &fond)  == -1)
    {
        system("clear");
        printf("Saisie annulée, aucune forme ajoutée\n");
        return;
    }
    if (lire_couleur("Couleur de trait (r,g,b) : ", &trait) == -1)
    {
        system("clear");
        printf("Saisie annulée, aucune forme ajoutée\n");
        return;
    }

    system("clear");
    int id = inserer_rectangle(doc, position, x, y, width, height, fond, trait);
    if (id < 0)
        printf("Erreur, ajout impossible\n");
    else
        printf("Rectangle ajouté sous l'ID %d\n", id);     
}

void modif_rectangle(forme *f)
{
    system("clear");
    char saisie_modif[256];
    int continuer_modif = 1;

    while (continuer_modif)
    {
        printf("^^^Modification -- rectangle^^^\n");
        printf("1. Valeur de x\n");
        printf("2. Valeur de y\n");
        printf("3. Valeur de width\n");
        printf("4. Valeur de height\n");
        printf("5. Couleur de fond\n");
        printf("6. Couleur de trait\n");
        printf("7. Pivoter\n");
        printf("8. Inverser\n");
        printf("0. Retour au menu d'édition\n");

        if (lire_ligne("> ", saisie_modif, sizeof saisie_modif) == -1)
            return;

        if (strcmp(saisie_modif, "1") == 0)
        {
            system("clear");
            modifier_entier("x", &f->geo.rectangle.x);
        }

        else if (strcmp(saisie_modif, "2") == 0)
        {
            system("clear");
            modifier_entier("y", &f->geo.rectangle.y);
        }

        else if (strcmp(saisie_modif, "3") == 0)
        {
            system("clear");
            modifier_entier("width", &f->geo.rectangle.width);
        }

        else if (strcmp(saisie_modif, "4") == 0)
        {
            system("clear");
            modifier_entier("height", &f->geo.rectangle.height);
        }

        else if (strcmp(saisie_modif, "5") == 0)
        {
            system("clear");
            modifier_couleur("Couleur fond", &f->couleur_fond);
        }

        else if (strcmp(saisie_modif, "6") == 0)
        {
            system("clear");
            modifier_couleur("Couleur trait", &f->couleur_trait);
        }

        else if (strcmp(saisie_modif, "7") == 0)
        {
            system("clear");
            pivoter_forme(f);
        }

        else if (strcmp(saisie_modif, "8") == 0)
        {
            system("clear");
            inverser_forme(f);
        }

        else if (strcmp(saisie_modif, "0") == 0)
        {
            system("clear");
            continuer_modif = 0;
        }

        else
            printf("Commande inconnue : %s\n", saisie_modif);
    }
}


void ajouter_carre(document *doc, int position)
{
    int x = lire_entier("Valeur de x : ");
    int y = lire_entier("Valeur de y : ");
    int cote = lire_entier("Valeur d'un côté : ");
    if (x == -1 || y == -1 || cote == -1)
    {
        system("clear");
        printf("Saisie annulée, aucune forme ajoutée\n");
        return;
    }                      

    couleur fond, trait;                              
    if (lire_couleur("Couleur de fond (r,g,b) : ",  &fond)  == -1)
    {
        system("clear");
        printf("Saisie annulée, aucune forme ajoutée\n");
        return;
    }
    if (lire_couleur("Couleur de trait (r,g,b) : ", &trait) == -1)
    {
        system("clear");
        printf("Saisie annulée, aucune forme ajoutée\n");
        return;
    }

    system("clear");
    int id = inserer_rectangle(doc, position, x, y, cote, cote, fond, trait);
    if (id < 0)
        printf("Erreur, ajout impossible\n");
    else
        printf("Carré ajouté sous l'ID %d\n", id);     
}


void ajouter_ligne(document *doc, int position)
{
    int x1 = lire_entier("Valeur de x1 : ");
    int y1 = lire_entier("Valeur de y1 : ");
    int x2 = lire_entier("Valeur de x2 : ");
    int y2 = lire_entier("Valeur de y2 : ");
    if (x1 == -1 || y1 == -1 || x2 == -1 || y2 == -1)
    {
        system("clear");
        printf("Saisie annulée, aucune forme ajoutée\n");
        return;
    }                              

    couleur trait;                              
    if (lire_couleur("Couleur de trait (r,g,b) : ", &trait) == -1)
    {
        system("clear");
        printf("Saisie annulée, aucune forme ajoutée\n");
        return;
    }
    couleur fond = {0, 0, 0};

    system("clear");
    int id = inserer_ligne(doc, position, x1, y1, x2, y2, fond, trait);
    if (id < 0)
        printf("Erreur, ajout impossible\n");
    else
        printf("Ligne ajoutée sous l'ID %d\n", id);     
}

void modif_ligne(forme *f)
{
    system("clear");
    char saisie_modif[256];
    int continuer_modif = 1;

    while (continuer_modif)
    {
        printf("^^^Modification -- ligne^^^\n");
        printf("1. Valeur de x1\n");
        printf("2. Valeur de y1\n");
        printf("3. Valeur de x2\n");
        printf("4. Valeur de y2\n");
        printf("5. Couleur de trait\n");
        printf("6. Pivoter\n");
        printf("7. Inverser\n");
        printf("0. Retour au menu d'édition\n");

        if (lire_ligne("> ", saisie_modif, sizeof saisie_modif) == -1)
            return;

        if (strcmp(saisie_modif, "1") == 0)
        {
            system("clear");
            modifier_entier("x1", &f->geo.ligne.x1);
        }

        else if (strcmp(saisie_modif, "2") == 0)
        {
            system("clear");
            modifier_entier("y1", &f->geo.ligne.y1);
        }

        else if (strcmp(saisie_modif, "3") == 0)
        {
            system("clear");
            modifier_entier("x2", &f->geo.ligne.x2);
        }

        else if (strcmp(saisie_modif, "4") == 0)
        {
            system("clear");
            modifier_entier("y2", &f->geo.ligne.y2);
        }

        else if (strcmp(saisie_modif, "5") == 0)
        {
            system("clear");
            modifier_couleur("Couleur trait", &f->couleur_trait);
        }

        else if (strcmp(saisie_modif, "6") == 0)
        {
            system("clear");
            pivoter_forme(f);
        }
        
        else if (strcmp(saisie_modif, "7") == 0)
        {
            system("clear");
            inverser_forme(f);
        }

        else if (strcmp(saisie_modif, "0") == 0)
        {
            system("clear");
            continuer_modif = 0;
        }

        else
            printf("Commande inconnue : %s\n", saisie_modif);
    }
}