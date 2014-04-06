#ifndef NAPREDNELINIJE_H
#define NAPREDNELINIJE_H

#include "component.h"

#include <QPoint>
#include <QPainter>
#include <QString>
#include <QMouseEvent>

class NapredneLinije
{
public:
    NapredneLinije();
    void PaintComp(QPainter &p);
    void setPoc(Component* p);
    void setkraj(Component *k);
    void slikajATM(QPoint p);
    void PONISTI();
    void setRazlika(QPoint p);
    void proslediPromenu(int iz);
    void Save(QDataStream& stream);
   // void Load(QDataStream& stream);

    Component* poc;
    Component* kraj;
    QPoint ulaz,izlaz;
    QPoint razlika;
    int kodKoga;
public slots:
    void prosledi();
};

#endif // NAPREDNELINIJE_H
