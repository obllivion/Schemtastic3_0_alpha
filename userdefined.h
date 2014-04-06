#ifndef USERDEFINED_H
#define USERDEFINED_H

#include "component.h"
#include "prekidac.h"

class UserDefined : public Component
{
public:
    UserDefined();
    void PaintComp(QPainter &p);
    void mojaFja();

    QList<Prekidac*> mojiUlazi;
    QList<int> kolkoUlaza;
    int brulaza;
};

#endif // USERDEFINED_H
