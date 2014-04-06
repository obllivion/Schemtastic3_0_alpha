#include "linija.h"

Linija::Linija()
{
    diraj=true;

}

void Linija::PaintComp(QPainter &p){
    if(!pocetak.isNull())
    {
        //samo da bude parno!!!!
        for(int i=0;i<prekidi.size();i=i+2)
        {

//                if(prekidi[i].x()!=prekidi[i+1].x())
//                    p.drawLine(prekidi[i].x(),prekidi[i].y(),prekidi[i+1].x(),prekidi[i].y());
//                if(prekidi[i].y()!=prekidi[i+1].y())
//                    p.drawLine(prekidi[i+1].x(),prekidi[i].y(),prekidi[i+1].x(),prekidi[i+1].y());


                if(prekidi[i].y()!=prekidi[i+1].y())
                    p.drawLine(prekidi[i].x(),prekidi[i].y(),prekidi[i].x(),prekidi[i+1].y());
                if(prekidi[i].x()!=prekidi[i+1].x())
                    p.drawLine(prekidi[i].x(),prekidi[i+1].y(),prekidi[i+1].x(),prekidi[i+1].y());

        }

      //  p.drawLine(pocetak,atm);
        //e sad, proba da se crta po liniji :D

//            if(pocetak.x()!=atm.x())
//                p.drawLine(pocetak.x(),pocetak.y(),atm.x(),pocetak.y());
//            if(pocetak.y()!=atm.y())
//                p.drawLine(atm.x(),pocetak.y(),atm.x(),atm.y());


            if(pocetak.y()!=atm.y())
                p.drawLine(pocetak.x(),pocetak.y(),pocetak.x(),atm.y());
            if(pocetak.x()!=atm.x())
                p.drawLine(pocetak.x(),atm.y(),atm.x(),atm.y());

    }
}

void Linija::setPosition(QMouseEvent *ev){
    pocetak=ev->pos();
}

void Linija::setATM(QMouseEvent *ev){
    atm=ev->pos();
}

void Linija::promeni(){
    QPoint start=pocetak;
    QPoint kraj=atm;
    prekidi.append(start);
    prekidi.append(kraj);
    pocetak=atm;
    //ovaj deo ne moram :)
  //  pocetak=NULL;
    //atm=NULL;
}

void Linija::setKRAJ(QPoint &p){
    atm=p;
}
