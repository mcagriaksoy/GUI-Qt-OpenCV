#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileInfo>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //DOSYA GÖSTERME LİST VİEW

    ui->setupUi(this);
    QString sPath = "/home/organic/Masaüstü/GUI-master/";
    dirmodel = new QFileSystemModel (this);
    dirmodel -> setRootPath(sPath);
    dirmodel -> setFilter(QDir::NoDotAndDotDot | QDir::Files);
 ui->listView->setModel(dirmodel);
 ui->listView->setRootIndex(dirmodel->setRootPath(sPath));

 ui->listView_2->setModel(dirmodel);
 ui->listView_2->setRootIndex(dirmodel->setRootPath(sPath));




//RESİM BOYOUT

    QPixmap pix("/home/organic/Masaüstü/GUI-Master/1.jpg");

    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    //000000000000000000000000000000000000

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}




void MainWindow::on_listView_clicked(const QModelIndex &index)
{


    QPixmap pix(dirmodel ->fileInfo(index).absoluteFilePath());

    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

}
void MainWindow::on_listView_2_clicked(const QModelIndex &index)
{

    QPixmap pix(dirmodel ->fileInfo(index).absoluteFilePath());

    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_9->setText("value");

}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_dateTimeEdit_editingFinished()
{

}
