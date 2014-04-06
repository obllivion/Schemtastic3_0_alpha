#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPalette>
#include <QPainter>
#include <QList>
#include <QPaintEvent>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QXmlStreamWriter>
#include <QtXml/QDomComment>
#include <QIODevice>
#include <QDataStream>
#include <QKeyEvent>
#include <QKeySequence>
#include <QBrush>

#include "component.h"
#include "and_component.h"
#include "or_component.h"
#include "nand_component.h"
#include "nor_component.h"
#include "not_component.h"
#include "xor_component.h"
#include "xnor_component.h"
#include "linija.h"
#include "naprednelinije.h"
#include "prekidac.h"
#include "userdefined.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Component *c;
    Linija* l;
    NapredneLinije* ll;
    Component *tren;
    Component* trazi(QPoint p);
    QPoint razlika;
    int tip;
    QString tipp;
    void napraviComponent();
    void saveZaUndo();
    void otvoriUndo();
public slots:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    //void paintEvent();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void crtajSkupa(QPainter &p);


private slots:
    void on_Button_NOT_clicked();

    void on_Button_AND_clicked();

    void on_Button_OR_clicked();

    void on_Button_XOR_clicked();

    void on_Button_NAND_clicked();

    void on_Button_NOR_clicked();

    void on_Button_XNOR_clicked();

    void on_Button_RUKA_clicked();

    void on_Button_LINE_clicked();

    void on_actionClear_All_triggered();

    void on_ButtonPrekidac_clicked();

    void on_actionSave_triggered();

    void on_actionCelu_tabelicu_triggered();

    void on_actionSave_As_triggered();

    void on_actionLoad_triggered();

    void on_actionUndo_triggered();

    void on_pomerajVise_clicked();

    void on_actionOtvori_UDS_triggered();

    void on_actionSave_User_Defined_triggered();

    void on_actionLoad_UDS_triggered();

private:
    Ui::MainWindow *ui;
    QList<Component*> lista;
    QList<Linija*> linije;
    QList<NapredneLinije*> napLin;
    QString savePath;
    QList<QString> undo1path;
    int menjanje;
    QPoint pocKocke;
    QPoint wh;
    QList<Component*> crvene;
    int dodatna;
    QPoint pomRazlika;
};

#endif // MAINWINDOW_H
