#ifndef COMPONENT_H
#define COMPONENT_H

#include <QPainter>
#include <QMouseEvent>
#include <QTableWidget>
#include <QtMath>
#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QDebug>
//#include "naprednelinije.h"
class NapredneLinije;

class Component
{
public:
    Component();
    virtual void PaintComp(QPainter &p);
    virtual void setTabelicu(int brUlaza);
    virtual void setParent(QWidget* parent=0);
    void setPosition(QMouseEvent *ev);

    void setLiniju(NapredneLinije *nap);
    void promenioSamSe(int iz);
    virtual void izracunajOpet(int ul,int ko);
    virtual void mojaFja();
    virtual void Save(QDataStream& stream);
    virtual void Load(QDataStream& stream);
    void setRef(QPoint p);

    QString imekomp;
    int vratiUlaz();

    QTableWidget* tabelica;
    QPoint ref;
    int tip,tmp;

    int izlaz;
    QList<int> ulazi;
    NapredneLinije* nn;
    bool selektovan=false;
    QPoint pomRazlika;
signals:
    void promenihSe(int i);
};

#endif // COMPONENT_H
