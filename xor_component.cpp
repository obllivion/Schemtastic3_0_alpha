#include "xor_component.h"

XOR_component::XOR_component()
{
    imekomp="xor";
    tip=4;
}

void XOR_component::PaintComp(QPainter &p){
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

        //prvi unutrasnji krug
        p.drawArc(lStart.x()-20,lStart.y(),40,80,-90*16, 180*16);

        //drugi unutrasnji krug
        p.drawArc(lStart.x()-10,lStart.y(),40,80,-90*16,180*16);

        //spajalice
        p.drawLine(lStart.x()+10,lStart.y(),lStart.x()+30,lStart.y());
        p.drawLine(lStart.x()+10,lStart.y()+80,lStart.x()+28,lStart.y()+80);

        //spoljasnji krug
        p.drawArc(lStart.x(),lStart.y(),50,80,-90*16, 180*16);

        //pinovi
        p.drawLine(ref.x(),ref.y()+30,ref.x()+38,ref.y()+30);
        p.drawLine(ref.x(),ref.y()+50,ref.x()+38,ref.y()+50);
        p.drawLine(ref.x()+70,ref.y()+40,ref.x()+90,ref.y()+40);
    }
}

void XOR_component::setParent(QWidget *parent){
    tabelica=new QTableWidget(parent);
}

void XOR_component::setTabelicu(int brUlaza){
    tabelica->setColumnCount(brUlaza+1);
    int redovi=qPow(2,brUlaza);
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
        int zbirReda=0;
        for(int j=0;j<brUlaza;j++){
            QTableWidgetItem *a=tabelica->item(i,j);
            zbirReda+=a->text().toInt();
        }
        //provera da li ima 1
       if(zbirReda%2==0)
           zbirReda=0;
       else
           zbirReda=1;

        item=new QTableWidgetItem();
        QString s=QString::number(zbirReda);
        item->setText(s);
        tabelica->setItem(i,brUlaza,item);
    }
    tabelica->setWindowTitle("XOR");
}

void XOR_component::mojaFja()
{
    int zbir=0;
    for(int i=0;i<ulazi.size();i++)
        zbir+=ulazi[i];
    if(zbir%2==0)
        this->promenioSamSe(0);
    else
        this->promenioSamSe(1);
}
