#include <stddef.h>

#include "forme.h"

int centre_forme(forme *f, int *px, int *py)
{
    if (f == NULL || px == NULL || py == NULL)
        return -1;

    switch (f->type)
    {
    case CERCLE:
        *px = f->geo.cercle.cx;
        *py = f->geo.cercle.cy;
        break;

    case ELLIPSE:
        *px = f->geo.ellipse.cx;
        *py = f->geo.ellipse.cy;
        break;

    case RECTANGLE:
        *px = f->geo.rectangle.x + f->geo.rectangle.width / 2;
        *py = f->geo.rectangle.y + f->geo.rectangle.height / 2;
        break;

    case LIGNE:
        *px = (f->geo.ligne.x1 + f->geo.ligne.x2) / 2;
        *py = (f->geo.ligne.y1 + f->geo.ligne.y2) / 2;
        break;

    default:
        return -1;
    }

    return 0;
}