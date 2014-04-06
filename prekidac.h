#ifndef PREKIDAC_H
#define PREKIDAC_H

#include "component.h"


class Prekidac : public Component
{
public:
    Prekidac();
    void PaintComp(QPainter &p);
    void promeniStanje();
    void setTabelicu(int brUlaza);
    void setParent(QWidget *parent);
    void izracunajOpet(int ul,int ko);
    void Sracunajfja(int br);

    QBrush boja;
    int brojac;
    int pon;
};

#endif // PREKIDAC_H
