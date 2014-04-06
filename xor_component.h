#ifndef XOR_COMPONENT_H
#define XOR_COMPONENT_H

#include "component.h"

class XOR_component : public Component
{
public:
    XOR_component();
    void PaintComp(QPainter &p);
    void setParent(QWidget *parent);
    void setTabelicu(int brUlaza);
    void mojaFja();
};

#endif // XOR_COMPONENT_H
