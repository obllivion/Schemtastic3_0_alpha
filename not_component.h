#ifndef NOT_COMPONENT_H
#define NOT_COMPONENT_H

#include "component.h"

class NOT_component : public Component
{
public:
    NOT_component();
    void PaintComp(QPainter &p);
    void setParent(QWidget *parent);
    void setTabelicu(int brUlaza);
    void mojaFja();
};

#endif // NOT_COMPONENT_H
