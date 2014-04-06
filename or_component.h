#ifndef OR_COMPONENT_H
#define OR_COMPONENT_H

#include "component.h"
class OR_component : public Component
{
public:
    OR_component();
    void PaintComp(QPainter &p);
    void setParent(QWidget *parent);
    void setTabelicu(int brUlaza);
    void izracunajOpet(int ul, int ko);
    void mojaFja();
};

#endif // OR_COMPONENT_H
