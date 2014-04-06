#ifndef LINIJA_H
#define LINIJA_H

#include <QPoint>
#include <QPainter>
#include <QMouseEvent>

class Linija
{
public:
    Linija();
    void PaintComp(QPainter &p);
    void setPosition(QMouseEvent *ev);
    void setATM(QMouseEvent *ev);
    void setKRAJ(QPoint& p);
    void promeni();
    bool diraj;

    QPoint pocetak;
    QPoint atm;
    QList<QPoint> prekidi;
};

#endif // LINIJA_H
