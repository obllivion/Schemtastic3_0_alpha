#ifndef XNOR_COMPONENT_H
#define XNOR_COMPONENT_H

#include "component.h"

class XNOR_component : public Component
{
public:
    XNOR_component();
    void PaintComp(QPainter &p);
    void setParent(QWidget *parent);
    void setTabelicu(int brUlaza);
    void mojaFja();
};

#endif // XNOR_COMPONENT_H
