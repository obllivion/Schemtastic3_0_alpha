#ifndef NOR_COMPONENT_H
#define NOR_COMPONENT_H

#include "component.h"

class NOR_component : public Component
{
public:
    NOR_component();
    void PaintComp(QPainter &p);
    void setTabelicu(int brUlaza);
    void setParent(QWidget *parent);
    void mojaFja();
};

#endif // NOR_COMPONENT_H
