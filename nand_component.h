#ifndef NAND_COMPONENT_H
#define NAND_COMPONENT_H

#include "component.h"

class NAND_component : public Component
{
public:
    NAND_component();
    void PaintComp(QPainter &p);
    void setTabelicu(int brUlaza);
    void setParent(QWidget *parent);
    void izracunajOpet(int ul, int ko);
    void mojaFja();
};

#endif // NAND_COMPONENT_H
