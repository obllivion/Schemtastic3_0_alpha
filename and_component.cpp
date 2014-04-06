#include "and_component.h"

AND_component::AND_component()
{
    tmp=0;
    imekomp="and";
    tip=2;
}

void AND_component::PaintComp(QPainter &p){
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

        p.drawLine(lStart.x(),lStart.y(),lEnd.x(),lEnd.y());
        p.drawArc(lStart.x()-40,lStart.y(),80,80,-90*16, 180*16);

        p.drawLine(ref.x(),ref.y()+30,ref.x()+20,ref.y()+30);
        p.drawLine(ref.x(),ref.y()+50,ref.x()+20,ref.y()+50);
        p.drawLine(ref.x()+60,ref.y()+40,ref.x()+80,ref.y()+40);
    }
}

void AND_component::setTabelicu(int brUlaza)
{
    tabelica->setColumnCount(brUlaza+1);
    int redovi=qPow(2,brUlaza); //4;//2^brUlaza;
   tabelica->setRowCount(redovi);

    QTableWidgetItem* item = new QTableWidgetItem();
   // int br[brUlaza];
    QVector<int> br(brUlaza);
    for(int i=0;i<brUlaza;i++)
        br[i]=0;
    int u=0;
    int dokle=0;
    tabelica->setSortingEnabled(false);

    //pokusavam da upisem iterativno
    for(int i=0;i<redovi;i++)
    {
       // tabelica->insertRow(i);
        for(int j=0;j<brUlaza;j++)
        {
            item=new QTableWidgetItem();
            QString s=QString::number(br[u++]);
            item->setText(s);
            tabelica->setItem(i,j,item);

        }
         dokle++;
        //funkcija za pretvaranje u bin....
        int decimalno=dokle;
        for(int k=brUlaza-1;k>=0;k--){
            br[k]=decimalno%2;
            decimalno=decimalno/2;
        }
        u=0;
    }
    //i sad na kraju, upisujem rezultate!!!
    for(int i=0;i<redovi;i++)
    {
        int proizvodReda=1;
        for(int j=0;j<brUlaza;j++){
            QTableWidgetItem *a=tabelica->item(i,j);
            proizvodReda*=a->text().toInt();
        }
        item=new QTableWidgetItem();
        QString s=QString::number(proizvodReda);
        item->setText(s);
        tabelica->setItem(i,brUlaza,item);
    }
    tabelica->setWindowTitle("AND");

        QTableWidgetItem *header1 = new QTableWidgetItem();
        header1->setText("Out");
        tabelica->setHorizontalHeaderItem(brUlaza,header1);

}

void AND_component::setParent(QWidget *parent)
{
    tabelica=new QTableWidget(parent);
}

void AND_component::izracunajOpet(int ul,int ko)
{
    this->ulazi[ko]=ul;
    this->mojaFja();
}

void AND_component::mojaFja()
{

    int zbir=0;
    for(int i=0;i<ulazi.size();i++){
        zbir+=ulazi[i];
    }
        if(zbir==ulazi.size()) //popravi posle ovo :)
            this->promenioSamSe(1);
        else
            promenioSamSe(0);

}
