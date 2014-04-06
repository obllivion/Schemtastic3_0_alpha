#include "not_component.h"

NOT_component::NOT_component()
{
    imekomp="not";
    tip=1;
}

void NOT_component::PaintComp(QPainter &p)
{
    if(!ref.isNull())
    {
        if(selektovan==true){
              p.setPen(Qt::red);
        }
        else
        {
           p.setPen(Qt::black);
        }
        QPoint lStart(ref.x()+20,ref.y());
        QPoint lEnd(ref.x()+20,ref.y()+80);
        QPoint centar(ref.x()+65,ref.y()+40);

        //pinovi
        p.drawLine(ref.x(),ref.y()+40,lStart.x(),lStart.y()+40);
      //  p.drawLine(ref.x(),ref.y()+50,lStart.x(),lStart.y()+50);
        p.drawLine(ref.x()+70,ref.y()+40,ref.x()+90,ref.y()+40);

        //komponenta
        p.drawLine(lStart.x(),lStart.y(),lEnd.x(),lEnd.y());
        p.drawLine(lStart.x(),lStart.y(),lStart.x()+40,lStart.y()+40);
        p.drawLine(lEnd.x(),lEnd.y(),lEnd.x()+40,lEnd.y()-40);
        p.drawEllipse(centar,5,5);
    }
}

void NOT_component::setParent(QWidget *parent){
    tabelica=new QTableWidget(parent);
}

void NOT_component::setTabelicu(int brUlaza){

    tabelica->setRowCount(2);
    tabelica->setColumnCount(2);
    QTableWidgetItem *item;
    item=new QTableWidgetItem();
    QString s="0";
    item->setText(s);
    tabelica->setItem(0,0,item);

    item=new QTableWidgetItem();
    item->setText(s);
    tabelica->setItem(1,1,item);

    item=new QTableWidgetItem();
    s="1";
    item->setText(s);
    tabelica->setItem(0,1,item);

    item=new QTableWidgetItem();
    item->setText(s);
    tabelica->setItem(1,0,item);
    tabelica->setWindowTitle("NOT");
}

void NOT_component::mojaFja()
{
    if(ulazi[0]==0)
        this->promenioSamSe(1);
    else
        this->promenioSamSe(0);
}
