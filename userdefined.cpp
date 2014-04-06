#include "userdefined.h"

UserDefined::UserDefined()
{
}

void UserDefined::PaintComp(QPainter &p){

    if(selektovan==true){
          p.setPen(Qt::red);
    }
    else
    {
       p.setPen(Qt::black);
    }
    p.drawRect(this->ref.x()+20,this->ref.y(),40,80);

    p.drawLine(ref.x(),ref.y()+30,ref.x()+20,ref.y()+30);
    p.drawLine(ref.x(),ref.y()+50,ref.x()+20,ref.y()+50);
    p.drawLine(ref.x()+60,ref.y()+40,ref.x()+80,ref.y()+40);
}

void UserDefined::mojaFja(){
//   for(int i=0;i<kolkoUlaza.size();i++)
//   {
//        for(int j=0;j<ulazi.size();j++)
//        {
//            if(ulazi[0]==0 && ulazi[1]==0)
//                this->promenioSamSe(kolkoUlaza[0]);
//            else
//                this->promenioSamSe(kolkoUlaza[1]);
//        }
//   }

        int zbir=0;
        for(int i=0;i<ulazi.size();i++)
        {
            int stepen=qPow(2,i);
            zbir+=ulazi[i]*stepen; //ulazi[i] su mi ustvari 1 ili 0 u nizu....
        }
        this->promenioSamSe(kolkoUlaza[zbir]);


}
