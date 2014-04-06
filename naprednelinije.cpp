#include "naprednelinije.h"



NapredneLinije::NapredneLinije()
{
 //   zauzeto=false;
    kraj=NULL;
}


void NapredneLinije::setPoc(Component *p){
    poc=p;
    //poc->setLiniju(this);
}

void NapredneLinije::setkraj(Component* k){
    kraj=k;
    kodKoga=kraj->vratiUlaz();
    kraj->ulazi.append(0); //prvo je radilo na 0 ako se ista pokvari....
   // poc->mojaFja();
   // kraj->mojaFja();
}

void NapredneLinije::PaintComp(QPainter &p){

    if (izlaz.x()!=99990 && ulaz.x()!=99990){
    izlaz.setX(poc->ref.x()+80);
    izlaz.setY(poc->ref.y()+40);

    if(kraj!=NULL){
    ulaz.setX(kraj->ref.x()+10);
    //proximity.... for now :P
    if(razlika.y()-36<=kraj->ref.y())
        ulaz.setY(kraj->ref.y()+30);
    else
        ulaz.setY(kraj->ref.y()+50);
    }

    if(izlaz.y() != ulaz.y())
    p.drawLine(izlaz.x(),izlaz.y(),izlaz.x(),ulaz.y());

    if(izlaz.x()!=ulaz.x())
        p.drawLine(izlaz.x(),ulaz.y(),ulaz.x(),ulaz.y());
    }
}

void NapredneLinije::slikajATM(QPoint p){
    ulaz=p;
}

void NapredneLinije::PONISTI(){
    izlaz.setX(99990);
    ulaz.setX(99990);
    izlaz.setY(0);
    ulaz.setY(0);
    poc=NULL;
}

void NapredneLinije::setRazlika(QPoint p){
    razlika=p;
}

void NapredneLinije::proslediPromenu(int iz){
    kraj->izracunajOpet(iz,kodKoga);
}
void NapredneLinije::prosledi()
{kraj->setTabelicu(0);}

void NapredneLinije::Save(QDataStream &stream)
{
    stream << this->poc->ref; //cuvam pocetan point
    stream << this->kraj->ref; //cuvam i krajnji point
}
