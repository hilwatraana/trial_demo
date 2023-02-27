#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ok_pushbutton_pressed()
{
     int num_tgt=ui->numtgt_spinBox->value();
     if(num_tgt>0)
     {
         tabwidget = new QTabWidget ();
         for(int i=1; i<=num_tgt; i++)
         {
             t1 = new tgt_page();
             tabwidget->addTab(t1, QString("Target_%0").arg(tabwidget->count() + 1));
             ui->verticalLayout->addWidget(tabwidget,0);
             QVBoxLayout * size = new QVBoxLayout;
             size->geometry();
             tabwidget->show();
         }

     }
}

