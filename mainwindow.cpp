#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showFullScreen();

    QPalette pal(palette());
    pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    tip=0;

    //dugmici nevidljivi
    ui->Button_AND->setFlat(true);
    ui->Button_NAND->setFlat(true);
    ui->Button_NOR->setFlat(true);
    ui->Button_NOT->setFlat(true);
    ui->Button_OR->setFlat(true);
    ui->Button_XNOR->setFlat(true);
    ui->Button_XOR->setFlat(true);

   // this->connect(c,SIGNAL(promenihSe(int)),ll,SLOT(prosledi()));
    undo1path.append("D:/undo.sch");
    undo1path.append("D:/undo2.sch");
    menjanje=0;

    pocKocke.setX(-1);
    pocKocke.setY(-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    if(pocKocke.x()!=-1 && tip==666)
    {
        QPen olovka;
        olovka.setColor(Qt::red);
        olovka.setStyle(Qt::DashDotLine);
        p.setPen(olovka);
       // wh=ev->pos();

        p.drawRect(pocKocke.x(),pocKocke.y(),wh.x()-pocKocke.x(),wh.y()-pocKocke.y());
        p.setPen(Qt::NoPen);

    }
    else
    {
        pocKocke.setX(-1);
    }

    for(int i=0;i<lista.size();i++)
        lista[i]->PaintComp(p);

    for(int i=0;i<napLin.size();i++)
        napLin[i]->PaintComp(p);
}
void MainWindow::mousePressEvent(QMouseEvent *ev){

    for(int i=0;i<lista.size();i++)
        lista[i]->selektovan=false;

    if(tip>0 && tip<10){
        this->napraviComponent();
        c->setPosition(ev);
        lista.append(c);
        this->repaint();
    }
    else if(tip==101)
    {
        this->napraviComponent();
        c->setPosition(ev);
        lista.append(c);
        this->repaint();
    }
    else if(tip==10)
    {
        if(ll->izlaz.x()==99990)
            ll=new NapredneLinije();
        if(ll->kraj!=NULL)
            ll=new NapredneLinije();

        napLin.append(ll);
        tren=trazi(ev->pos());
        if(tren!= NULL){
            ll->setPoc(tren);
            tren->setLiniju(ll);
        }
        this->repaint();
        tren=NULL;

    }
    else //samo ukoliko je ruka selektovana
    {

        this->repaint();
        tren=trazi(ev->pos());
        if(tren!=NULL)
        {
            tren->selektovan=true;
            this->repaint();
        }
        else
        {
           if(dodatna==404)
           {
               for(int i=0;i<crvene.size();i++)
                    crvene[i]->pomRazlika=crvene[i]->ref-ev->pos();
           }
            this->pocKocke=ev->pos();
            tip=666;
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    if(tip==10)
    {
        tren=trazi(ev->pos());
         if(tren!= NULL){
            ll->setkraj(tren);
         }
         else
             ll->PONISTI();
         ll->setRazlika(ev->pos());
         repaint();
         tren=NULL;
    }
    else if(tip==666)
    {
        for(int i=0;i<lista.size();i++)
            if(lista[i]->ref.x()<=wh.x() && lista[i]->ref.y()<=wh.y())
                if(lista[i]->ref.x()>=pocKocke.x() && lista[i]->ref.y()>=pocKocke.y())
                {
                    crvene.append(lista[i]); //dodam sve one koje su u kocki
                    lista[i]->selektovan=true; //sve sada postaju crvene! :D yeeeeeaaah
                    //dodatna=667;
                   // pomRazlika=lista[i]->ref-pocKocke;
                }
       // dodatna=0;
        this->repaint();
    }
    this->saveZaUndo();
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *ev){
    tren=trazi(ev->pos());
    if(tren!=NULL){
        tren->setParent();

        tren->setTabelicu(2);
        if(tren->tabelica->columnCount()==0){
            //tren->promenioSamSe(1);
            tren->tabelica->close();
            repaint();
        }
        else{
        tren->tabelica->show();
        tren->tabelica->resize(400,300);
        tren->tabelica->move(300,300);
        }
    }
}

void MainWindow::napraviComponent(){
    //sacekaj da implementiras ostale klase!!!
    crvene.clear();
    switch (tip) {
    case 2:
        c= new AND_component();
        break;
    case 3:
        c= new OR_component();
        break;
    case 5:
        c= new NAND_component();
        break;
    case 6:
        c=new NOR_component();
        break;
    case 1:
        c=new NOT_component();
        break;
    case 4:
        c=new XOR_component();
        break;
    case 7:
        c=new XNOR_component();
        break;
    case 9:
        c=new Prekidac();
        break;
    case 101:
        c=new UserDefined();
        break;
    default:
        break;
    }
}

Component* MainWindow::trazi(QPoint p){

    for(int i=0;i<lista.size();i++)
    {
        if(p.x()>= lista[i]->ref.x() && p.x() < lista[i]->ref.x()+100 && p.y()>= lista[i]->ref.y() && p.y() < lista[i]->ref.y()+100)
        {
            razlika=p-lista[i]->ref;
            return lista[i];
        }
    }
    return NULL;
}

void MainWindow::on_Button_NOT_clicked()
{
    tip=1;
    tren=NULL;
}

void MainWindow::on_Button_AND_clicked()
{
    tip=2;
    tren=NULL;
}

void MainWindow::on_Button_OR_clicked()
{
    tip=3;
    tren=NULL;
}

void MainWindow::on_Button_XOR_clicked()
{
    tip=4;
    tren=NULL;
}

void MainWindow::on_Button_NAND_clicked()
{
    tip=5;
    tren=NULL;
}

void MainWindow::on_Button_NOR_clicked()
{
    tip=6;
    tren=NULL;
}

void MainWindow::on_Button_XNOR_clicked()
{
    tip=7;
    tren=NULL;
}

void MainWindow::on_Button_RUKA_clicked()
{
    c=NULL;
    tip=0;
    dodatna=0;
    crvene.clear();
}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    if(tren!=NULL)
    {
    tren->ref=ev->pos()-razlika;
    repaint();
    }
    if(tip==10)
    {
        //l->setATM(ev);
        ll->slikajATM(ev->pos());
        repaint();
    }
    else //znaci tren je null, nisam selektovao komponentu, ali je ruka selektovana...
    {
        if(dodatna!=667 && dodatna!=404){
            wh=ev->pos();
            this->repaint();
        }
        else //multi move je sada...
        {
            pocKocke.setX(-1);//ne treba mi vise kocka...
            for(int i=0;i<crvene.size();i++)
            {
                crvene[i]->ref=ev->pos()+crvene[i]->pomRazlika; //praise to jesus!
                repaint();
            }
        }
    }
}

void MainWindow::on_Button_LINE_clicked()
{
    tren=NULL;
    c=NULL;
    tip=10;
    ll=new NapredneLinije();
}

void MainWindow::on_actionClear_All_triggered()
{
    lista.clear();
    napLin.clear();
    crvene.clear();
    repaint();
}

void MainWindow::on_ButtonPrekidac_clicked()
{
    tip=9;
    tren=NULL;
}

void MainWindow::on_actionSave_triggered()
{
   if(this->savePath.isEmpty())
       on_actionSave_As_triggered();
   else
   {
       QFile f(savePath);
       if(!f.open(QFile::WriteOnly)){}
       else{
       QDataStream stream(&f);

       quint16 code = 0xCCDD;
       stream << code;
        //dotle klasika :)
       quint16 size = (quint16)lista.size();
       stream << size; //upisao sam koliko imam komponenti :P
       //upisujem svaku komponentu....
       for(int i=0; i<size; i++)
       {
          lista[i]->Save(stream);
       }
       //sad cu linije da sacuvam
       size=(quint16) napLin.size();
       stream<<size;
       for(int i=0;i<size;i++)
       {
           napLin[i]->Save(stream);
       }
       f.close();
   }
   }

}

void MainWindow::on_actionCelu_tabelicu_triggered()
{
    QList<Prekidac*> prek;
    QList<Prekidac*> kompi; //kompi=izlaz
    for(int i=0;i<lista.size();i++)
    {
        if(lista[i]->imekomp=="prekidac")
        {

            if(lista[i]->nn!=NULL)
            {
                Prekidac* pp=(Prekidac*) lista[i];
                prek.append(pp);
            }
            else
            {
                Prekidac* pp=(Prekidac*) lista[i];
                kompi.append(pp);
            }
        }

    }
    QTableWidget* tabelica;
    tabelica=new QTableWidget();
    tabelica->setColumnCount(prek.size()+kompi.size());
    int redovi=qPow(2,prek.size()); //4;//2^brUlaza
    tabelica->setRowCount(redovi);
    tabelica->move(400,300);
    tabelica->setGeometry(400,300,500,300);
    QTableWidgetItem* item = new QTableWidgetItem();

//    QTableWidgetItem *header1 = new QTableWidgetItem();
//    header1->setText("Out");
//    tabelica->setHorizontalHeaderItem(prek.size(),header1);
    int dokle=0;
    int k=0;
    for(int l=0;l<prek.size();l++)
    {
        prek[l]->brojac=0; //prvo resetujem sve :)
        prek[l]->pon=0;
    }
    for(int i=0; i<redovi;i++) //prolazim kroz redove, a nakon pregledanja menjam state-ove
    {
        for(int j=0; j<prek.size();j++) //samo citam/upisujem :)
        {
            //jebena logika za racunanje cele tabele
            int nesto=qPow(2,j); //ovo je koliko ponavljanja moze da ima
            prek[j]->Sracunajfja(prek[j]->brojac);
            prek[j]->pon++;
            if(prek[j]->pon==nesto)
            {
                if(prek[j]->brojac==0)
                    prek[j]->brojac=1;
                else
                    prek[j]->brojac=0;
                prek[j]->pon=0;
            }
            //tolko!

            item=new QTableWidgetItem();
            QString s;
            if(prek[j]->boja==Qt::red)
                s="0";
            else
                s="1";
            item->setText(s);
            tabelica->setItem(i,j,item);
        }
        for(int k=0;k<kompi.size();k++) //ispisujem izlaze?
        {
            item=new QTableWidgetItem();
            QString s;
            if(kompi[k]->boja==Qt::red)
                s="0";
            else
                s="1";
            item->setText(s);
            tabelica->setItem(i,prek.size()+k,item);

                QTableWidgetItem *header1 = new QTableWidgetItem();
                header1->setText("Izlaz");
                tabelica->setHorizontalHeaderItem(prek.size()+k,header1);
        }
    }
    tabelica->show();
}

void MainWindow::on_actionSave_As_triggered()
{
    savePath = QFileDialog::getSaveFileName(this, QString(), QString(), "Schemtastic Doc (*.sch);;All Files (*.*)");
    if(!savePath.isEmpty())
    on_actionSave_triggered();
}

void MainWindow::on_actionLoad_triggered()
{
    savePath = QFileDialog::getOpenFileName(this, QString(), QString(), "Schemtastic Doc (*.sch);;All Files (*.*)");
    if(!savePath.isEmpty())
    {
        on_actionClear_All_triggered();

        QFile f(savePath);
        if(!f.open(QFile::ReadOnly)) {}
        else{

            QDataStream stream(&f);

            quint16 code = 0;
            stream >> code;
            if(code != 0xCCDD) {}
            else{
                quint16 size = 0;
                stream >> size;
                for(quint16 i=0; i<size; i++)
                {
                    stream >> tip;
                    this->napraviComponent();
                   // c->Load(stream);
                    QPoint dummy;
                    stream >> dummy;
                    c->setRef(dummy);
                    lista.append(c);
                //    repaint();
                }
                //zavrsio sam sa komponentama, sada ucitavam i linije
                stream >> size;
                for(quint16 i=0; i<size;i++)
                {
                    this->ll=new NapredneLinije();
                    QPoint dummy;
                    stream >> dummy;
                    tren=trazi(dummy);
                    if(tren!= NULL){
                        ll->setPoc(tren);
                        tren->setLiniju(ll);
                    }
                    stream >> dummy;
                    tren=trazi(dummy);
                    if(tren!= NULL){
                        ll->setkraj(tren);
                    }
                    napLin.append(ll);
                }
                this->repaint();
                f.close();
        }

       }
    }
}

void MainWindow::saveZaUndo(){

        int kl=menjanje%2;
        menjanje++;
        QFile f(undo1path[kl]);
        if(!f.open(QFile::WriteOnly)){}
        else{
        QDataStream stream(&f);

        quint16 code = 0xCCDD;
        stream << code;
         //dotle klasika :)
        quint16 size = (quint16)lista.size();
        stream << size; //upisao sam koliko imam komponenti :P
        //upisujem svaku komponentu....
        for(int i=0; i<size; i++)
        {
           lista[i]->Save(stream);
        }
        //sad cu linije da sacuvam
        size=(quint16) napLin.size();
        stream<<size;
        for(int i=0;i<size;i++)
        {
            napLin[i]->Save(stream);
        }
        f.close();
    }
}

void MainWindow::otvoriUndo(){
    on_actionClear_All_triggered();

    int kl=menjanje%2;
    menjanje--;
    QFile f(undo1path[kl]);
    if(!f.open(QFile::ReadOnly)) {}
    else{

        QDataStream stream(&f);

        quint16 code = 0;
        stream >> code;
        if(code != 0xCCDD) {}
        else{
            quint16 size = 0;
            stream >> size;
            for(quint16 i=0; i<size; i++)
            {
                stream >> tip;
                this->napraviComponent();
                QPoint dummy;
                stream >> dummy;
                c->setRef(dummy);
                lista.append(c);
            }
            //zavrsio sam sa komponentama, sada ucitavam i linije
            stream >> size;
            for(quint16 i=0; i<size;i++)
            {
                this->ll=new NapredneLinije();
                QPoint dummy;
                stream >> dummy;
                tren=trazi(dummy);
                if(tren!= NULL){
                    ll->setPoc(tren);
                    tren->setLiniju(ll);
                }
                stream >> dummy;
                tren=trazi(dummy);
                if(tren!= NULL){
                    ll->setkraj(tren);
                }
                napLin.append(ll);
            }
            this->repaint();
            f.close();
}
    }
}


void MainWindow::on_actionUndo_triggered()
{
    this->otvoriUndo();
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    if(k->key()==Qt::Key_Delete)
        for(int i=0;i<lista.size();i++)
            if(lista[i]->selektovan==true)
            {
                lista.removeAt(i);
                repaint();
            }

        if( k->modifiers() == Qt::ControlModifier )
        if(k->key()==Qt::Key_Z)
            this->otvoriUndo();

    this->repaint();
}

void MainWindow::on_pomerajVise_clicked()
{
    dodatna=404;
}

void MainWindow::crtajSkupa(QPainter &p)
{

}

void MainWindow::on_actionOtvori_UDS_triggered()
{
    tip=101;
    tren=NULL;
}

void MainWindow::on_actionSave_User_Defined_triggered()
{
    QFile f("D:\obli.uds");
    Prekidac* prek;
    if(!f.open(QFile::WriteOnly)){}
    else{
    QDataStream stream(&f);

    quint16 code = 0xCCDD;
    stream << code;
    QList<Prekidac*> sviPrekidaci;
        for(int i=0;i<lista.size();i++)
            if(lista[i]->imekomp=="prekidac")
            {
                if(lista[i]->nn!=NULL)
                {
                    Prekidac* p = (Prekidac*) lista[i];
                    sviPrekidaci.append(p);
                }
                else
                {
                    prek=(Prekidac*) lista[i];
                }
            }
        //izbrojao sam koliko imam PREKIDACA, sada upisujem im broj, i njihove izlaze!
        int tmp=qPow(2,sviPrekidaci.size());
        quint16 size;
        size=(quint16) tmp;
        stream<<size; //upisao sam koliko imam vrsta, sada treba da citam vrednosti???
        quint16 brl;
        brl=(quint16) sviPrekidaci.size();
        stream<<brl;
        //cuvaj se i pomozi boze!!!!
        QTableWidget* tabelica;
        tabelica=new QTableWidget();
        tabelica->setColumnCount(sviPrekidaci.size()+1);
        int redovi=qPow(2,sviPrekidaci.size()); //4;//2^brUlaza
        tabelica->setRowCount(redovi);
        tabelica->move(400,300);
        tabelica->setGeometry(400,300,500,300);
        QTableWidgetItem* item = new QTableWidgetItem();
        for(int i=0; i<tmp;i++) //prolazim kroz redove, a nakon pregledanja menjam state-ove
        {
            for(int j=0; j<sviPrekidaci.size();j++) //samo citam/upisujem :)
            {
                //jebena logika za racunanje cele tabele
                int nesto=qPow(2,j); //ovo je koliko ponavljanja moze da ima
                sviPrekidaci[j]->Sracunajfja(sviPrekidaci[j]->brojac);
                sviPrekidaci[j]->pon++;
                if(sviPrekidaci[j]->pon==nesto)
                {
                    if(sviPrekidaci[j]->brojac==0)
                        sviPrekidaci[j]->brojac=1;
                    else
                        sviPrekidaci[j]->brojac=0;
                    sviPrekidaci[j]->pon=0;
                }
                //tolko!

                item=new QTableWidgetItem();
                QString s;
                if(sviPrekidaci[j]->boja==Qt::red)
                    s="0";
                else
                    s="1";
                item->setText(s);
                tabelica->setItem(i,j,item);
            }
            //sada u citam iz tren-a
            quint16 nestoTamo;
            if(prek->boja==Qt::green)
                nestoTamo=(quint16) 1;
            else
                nestoTamo=(quint16) 0;

                stream<<nestoTamo;
        }
        //do ovde se cuvas!!!!
        f.close();
    }
}

void MainWindow::on_actionLoad_UDS_triggered()
{
    QString putanjica=QFileDialog::getOpenFileName(this, QString(), QString(), "User Defined Doc (*.uds);;All Files (*.*)");
    if(!putanjica.isEmpty())
    {
        on_actionClear_All_triggered();

        QFile f(putanjica);
        if(!f.open(QFile::ReadOnly)) {}
        else{
            QDataStream stream(&f);

            quint16 code = 0;
            stream >> code;
            if(code != 0xCCDD) {}
            else{
                quint16 size = 0;
                quint16 tmm;
                stream >> size; //procitao sam koliko komponenti imam....
                quint16 brl;
                stream >> brl;
               UserDefined* ud=new UserDefined();
               ud->brulaza=brl;
               for(quint16 i=0; i<size;i++)
               {
                   stream>>tmm;
                   int mtt=(int) tmm;
                   ud->kolkoUlaza.append(mtt);
               }
               f.close();
               c=ud;
               lista.append(c);
               repaint();
            }
        }
    }
}
