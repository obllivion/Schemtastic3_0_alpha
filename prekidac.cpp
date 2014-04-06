#include "prekidac.h"

Prekidac::Prekidac()
{
    boja=Qt::red;
    imekomp="prekidac";
    nn=NULL;
    tip=9;
    brojac=0;
}

void Prekidac::PaintComp(QPainter &p){
    //p.drawRect();
    p.fillRect(ref.x(),ref.y(),80,80,boja);
}

void Prekidac::promeniStanje()
{
    if(boja==Qt::red)
        boja=Qt::green;
    else
        boja=Qt::red;
}

void Prekidac::setTabelicu(int brUlaza){

    if(boja==Qt::red)
        boja=Qt::green;
    else
        boja=Qt::red;

    if(boja==Qt::green)
        this->promenioSamSe(1);
    else
        this->promenioSamSe(0);
}

void Prekidac::setParent(QWidget *parent){
     tabelica=new QTableWidget(parent);
}

void Prekidac::izracunajOpet(int ul, int ko){
   if(ul==0)
       boja=Qt::red;
   else
       boja=Qt::green;
}

//void Prekidac::promenioSamSe(int iz){

//    if(boja==Qt::red)
//        boja=Qt::green;
//    else
//        boja=Qt::red;
//}
void Prekidac::Sracunajfja(int br){

    if(br==1)
        boja=Qt::green;
    else
        boja=Qt::red;

    if(br==1)
        this->promenioSamSe(1);
    else
        this->promenioSamSe(0);
}
