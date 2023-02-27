#include "tgt_page.h"
#include "ui_tgt_page.h"
#include<QDebug>
#include <QIntValidator>

tgt_page::tgt_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tgt_page)
{
    ui->setupUi(this);
    ui->tgttype_comboBox->addItem("Cattle");
    ui->tgttype_comboBox->addItem("Man");
    ui->tgttype_comboBox->addItem("Vehicle");

    ui->rad_mov_comboBox->addItem("incoming");
    ui->rad_mov_comboBox->addItem("Outgoing");

    ui->timeoffset_lineEdit->setText("0");

    QValidator *val= new QIntValidator(this);  //To validate values taken are only integers.
    ui->rad_dist_lineEdit->setValidator(val);
    ui->AZ_lineEdit->setValidator(val);
    ui->speed_lineEdit->setValidator(val);
    ui->time_lineEdit->setValidator(val);
}

tgt_page::~tgt_page()
{
    delete ui;
}

void tgt_page::on_save_pushButton_pressed()
{
    QString tgt_typ = ui->tgttype_comboBox->currentText();
    qDebug() <<tgt_typ;

    QString rad_dist = ui->rad_dist_lineEdit->text();
    qDebug() <<rad_dist;

    QString Azimuth = ui->AZ_lineEdit->text();
    qDebug() <<Azimuth;

    QString speed = ui->speed_lineEdit->text();
    qDebug() <<speed;

    QString rad_movement = ui->rad_mov_comboBox->currentText();
    qDebug() <<rad_movement;

    QString time = ui->time_lineEdit ->text();
    qDebug() <<time;

    QString time_offset = ui->timeoffset_lineEdit ->text();
    qDebug() <<time_offset;
}


void tgt_page::on_clear_pushButton_pressed()
{
  ui->tgttype_comboBox->clear();
  ui->rad_dist_lineEdit->clear();
  ui->AZ_lineEdit->clear();
  ui->speed_lineEdit->clear();
  ui->rad_mov_comboBox->clear();
  ui->time_lineEdit->clear();
  ui->timeoffset_lineEdit->clear();
  ui->vehicle_man_comboBox->clear();
}

void tgt_page::on_tgttype_comboBox_currentIndexChanged(int index)
{
    index=ui->tgttype_comboBox->currentIndex();
    ui->vehicle_man_comboBox->show();
    switch (index) {
    case 0:
        ui->vehicle_man_comboBox->hide();
        break;
    case 1:
        ui->vehicle_man_comboBox->clear();
        ui->vehicle_man_comboBox->addItem("Single");
        ui->vehicle_man_comboBox->addItem("group");
        break;
    case 2:
        ui->vehicle_man_comboBox->clear();
        ui->vehicle_man_comboBox->addItem("Truck");
        ui->vehicle_man_comboBox->addItem("Car");
        ui->vehicle_man_comboBox->addItem("Scooter");
        ui->vehicle_man_comboBox->addItem("Bus");

        break;

    default:
        break;
    }
}

