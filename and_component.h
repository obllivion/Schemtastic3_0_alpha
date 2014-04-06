#ifndef AND_COMPONENT_H
#define AND_COMPONENT_H

#include "component.h"
class AND_component : public Component
{
public:
    AND_component();
    void PaintComp(QPainter &p);
    void setTabelicu(int brUlaza);
    void setParent(QWidget *parent);
    void izracunajOpet(int ul, int ko);
    void mojaFja();
};

#endif // AND_COMPONENT_H
