#include "component.h"
#include "naprednelinije.h"

Component::Component()
{
    tip=0;
}

void Component::setPosition(QMouseEvent *ev)
{
    ref=ev->pos();
}
void Component::PaintComp(QPainter &p)
{

}

void Component::setTabelicu(int brUlaza){

}

void Component::setParent(QWidget *parent)
{}

void Component::setLiniju(NapredneLinije *nap){
    nn=nap;

}

void Component::promenioSamSe(int iz){
    this->izlaz=iz;
    if(nn!=NULL)
        nn->proslediPromenu(iz);
}

void Component::izracunajOpet(int ul, int ko){
    this->ulazi[ko]=ul;
    this->mojaFja();

}
int Component::vratiUlaz(){
    return this->ulazi.size();
}
void Component::mojaFja(){} //ne diraj je

void Component::Save(QDataStream &stream){
    stream << tip;
    stream << ref;
}
void Component::Load(QDataStream &stream)
{
  //  stream >> ref;
  //  this->setRef(ref);
}

void Component::setRef(QPoint p)
{
    ref=p;
}
