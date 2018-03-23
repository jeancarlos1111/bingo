#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <time.h>
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QMediaPlayerControl>
#include <QMediaService>
#include <QMediaPlayer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    srand(time(NULL));
    mMediaplayer = new QMediaPlayer(this);
    bingodb = QSqlDatabase::addDatabase("QSQLITE");
    bingodb.setDatabaseName(QDir::currentPath()+"/bingo.sqlite");
    if(!bingodb.open())
    {

        QMessageBox::critical(this, tr("Error a abrir base de datos: "),bingodb.lastError().text());
    }else{
        QSqlQuery vaciar;
        vaciar.prepare("DELETE FROM resultados");
        if(!vaciar.exec())
            QMessageBox::critical(this, tr("Error a vaciar base de datos: "),vaciar.lastError().text());


    }



}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_iniciar_clicked()
{
    contador=0;
    ui->label_numero->setText("<html><head/><body><p><span style=' font-size:72pt; font-style:italic; color:#ffffff;'>A Jugar!!!</span></p></body></html>");
    ui->label_1->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_2->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_3->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_4->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_5->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_6->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_7->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_8->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_9->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_10->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_11->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_12->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_13->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_14->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_15->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_16->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_17->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_18->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_19->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_20->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_21->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_22->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_23->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_24->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_25->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_26->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_27->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_28->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_29->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_30->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_31->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_32->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_33->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_34->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_35->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_36->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_37->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_38->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_39->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_40->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_41->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_42->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_43->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_44->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_45->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_46->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_47->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_48->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_49->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_50->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_51->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_52->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_53->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_54->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_55->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_56->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_57->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_58->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_59->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_60->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_61->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_62->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_63->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_64->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_65->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_66->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_67->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_68->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_69->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_70->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_71->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_72->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_73->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_74->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    ui->label_75->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.352826, cy:0.784, radius:0.5, fx:0.074, fy:1, stop:0 rgba(180, 152, 39, 255), stop:1 rgba(203, 145, 0, 252));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: rgba(203, 145, 0, 252);border-radius: 15px;");
    QSqlQuery vaciar;
    if(!bingodb.open())
    {
        QMessageBox::critical(this, tr("Error"),bingodb.lastError().text());
    }else
    {
        vaciar.prepare("DELETE FROM resultados");
        if(!vaciar.exec())
            QMessageBox::critical(this, tr("Error a vaciar base de datos: "),vaciar.lastError().text());
        bingodb.close();
    }
    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/a jugar.mp3"));
    mMediaplayer->setVolume(100);
    mMediaplayer->play();
}

void Widget::on_pushButton_lanzar_clicked()
{
    QSqlQuery consulta;
    QString cnumero;//convertir el numero a string
    if(!bingodb.open())
    {
        QMessageBox::critical(this, tr("Error 1"),bingodb.lastError().text());
    }
    num = 1 + rand() %(76 -1);//selecionamos un numero aleatorio
    consulta.prepare("SELECT resultado FROM resultados WHERE resultado = :numero");//verificamos que el
    consulta.bindValue(":numero", num);//numero no a sido seleccionado
    if(consulta.exec())
    {
        int incremento = 0;//definimos la variable de incremento en cero
        while (consulta.next()) {
            incremento++;//aumentamos si encontramos un registro coincidente
        }
        if(incremento >= 1)//si es mayor a 1 ejecuta este bloque
        {
            if(contador < 75)//el contador lleva la cantidad de lanzamientos tiene que ser menor a 75
            {
                on_pushButton_lanzar_clicked();//invocamos de nuevo a la funcion para obtener otro numero aleatorio
            }else{
                QMessageBox::warning(this, tr("Advertencia"),tr("Ya alcanzo el limite de lanzamientos"));
            }

        }else
        {
            consulta.prepare("INSERT INTO resultados (resultado) VALUES(:numero)");
            consulta.bindValue(":numero",num);
            if(!consulta.exec())
             {
                QMessageBox::critical(this, tr("Error"),consulta.lastError().text());
            }else
            {
                contador++;
                bingodb.close();
                //ui->lcdNumber_resultado->display(num);
                //ui->lcdNumber_resultado->display(cnumero.setNum(num));
                //ui->label_1->setText(cnumero.setNum(num));
                if(num >= 1 && num <= 15){
                    ui->label_numero->setText("<html><head/><body><p><span style=' font-size:72pt; font-style:italic;'>B"+cnumero.setNum(num)+"</span></p></body></html>");
                }else if(num >= 16 && num <= 30){
                    ui->label_numero->setText("<html><head/><body><p><span style=' font-size:72pt; font-style:italic; '>I"+cnumero.setNum(num)+"</span></p></body></html>");
                }else if(num >= 31 && num <= 45)
                {
                    ui->label_numero->setText("<html><head/><body><p><span style=' font-size:72pt; font-style:italic; '>N"+cnumero.setNum(num)+"</span></p></body></html>");
                }else if(num >= 46 && num <= 60)
                {
                    ui->label_numero->setText("<html><head/><body><p><span style=' font-size:72pt; font-style:italic; '>G"+cnumero.setNum(num)+"</span></p></body></html>");
                }else if(num >= 61 && num <= 75)
                {
                    ui->label_numero->setText("<html><head/><body><p><span style=' font-size:72pt; font-style:italic;'>O"+cnumero.setNum(num)+"</span></p></body></html>");
                }
                switch (num) {
                case 1:
                    ui->label_1->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/B1.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 2:
                    ui->label_6->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/B2.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 3:
                    ui->label_11->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/B3.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 4:
                    ui->label_16->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/B4.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 5:
                    ui->label_21->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/B5.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 6:
                    ui->label_26->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/B6.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 7:
                    ui->label_31->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/B7.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 8:
                    ui->label_36->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/B8.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 9:
                    ui->label_41->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/B9.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 10:
                    ui->label_46->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/B10.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 11:
                    ui->label_51->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/B11.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 12:
                    ui->label_56->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/B12.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 13:
                    ui->label_61->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/B13.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 14:
                    ui->label_66->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/B14.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 15:
                    ui->label_71->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/B15.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 16:
                    ui->label_2->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/I16.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 17:
                    ui->label_7->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/I17.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 18:
                    ui->label_12->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/I18.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 19:
                    ui->label_17->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/I19.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 20:
                    ui->label_22->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/I20.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 21:
                    ui->label_27->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/I21.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 22:
                    ui->label_32->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/I22.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 23:
                    ui->label_37->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/I23.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 24:
                    ui->label_42->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/I24.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 25:
                    ui->label_47->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/I25.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 26:
                    ui->label_52->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/I26.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 27:
                    ui->label_57->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/I27.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 28:
                    ui->label_62->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/I28.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 29:
                    ui->label_67->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/I29.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 30:
                    ui->label_72->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/I30.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 31:
                    ui->label_3->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/N31.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 32:
                    ui->label_8->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/N32.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 33:
                    ui->label_13->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/N33.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 34:
                    ui->label_18->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/N34.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 35:
                    ui->label_23->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/N35.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 36:
                    ui->label_28->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/N36.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 37:
                    ui->label_33->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/N37.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 38:
                    ui->label_38->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/N38.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 39:
                    ui->label_43->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/N39.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 40:
                    ui->label_48->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/N40.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 41:
                    ui->label_53->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/N41.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 42:
                    ui->label_58->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/N42.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 43:
                    ui->label_63->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/N43.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 44:
                    ui->label_68->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/N44.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 45:
                    ui->label_73->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/N45.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 46:
                    ui->label_4->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/G46.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 47:
                    ui->label_9->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/G47.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 48:
                    ui->label_14->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/G48.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 49:
                    ui->label_19->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/G49.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 50:
                    ui->label_24->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/G50.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 51:
                    ui->label_29->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/G51.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 52:
                    ui->label_34->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/G52.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 53:
                    ui->label_39->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/G53.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 54:
                    ui->label_44->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/G54.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 55:
                    ui->label_49->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/G55.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 56:
                    ui->label_54->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/G56.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 57:
                    ui->label_59->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/G57.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 58:
                    ui->label_64->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/G58.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 59:
                    ui->label_69->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/G59.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 60:
                    ui->label_74->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/G60.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 61:
                    ui->label_5->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/O61.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 62:
                    ui->label_10->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/O62.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 63:
                    ui->label_15->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/O63.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 64:
                    ui->label_20->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/O64.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 65:
                    ui->label_25->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/O65.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 66:
                    ui->label_30->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/O66.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 67:
                    ui->label_35->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/O67.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 68:
                    ui->label_40->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/O68.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 69:
                    ui->label_45->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/O69.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 70:
                    ui->label_50->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/O70.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 71:
                    ui->label_55->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/O71.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 72:
                    ui->label_60->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/O72.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 73:
                    ui->label_65->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/O73.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 74:
                    ui->label_70->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/O74.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                case 75:
                    ui->label_75->setStyleSheet("background-color:qradialgradient(spread:pad, cx:0.483, cy:0.125, radius:0.5, fx:0.476955, fy:0.125, stop:0 rgba(255, 255, 255, 219), stop:1 rgba(255, 182, 0, 255));color:rgb(0, 0, 0);border-width: 1px;border-style: solid;border-color: #ffb600;border-radius: 15px;");
                    mMediaplayer->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/audios/O75.mp3"));
                    mMediaplayer->setVolume(100);
                    mMediaplayer->play();
                    break;
                default:
                    break;
                }

            }
        }
    }else
    {
        QMessageBox::critical(this, tr("Error 2"),consulta.lastError().text());
    }

}



void Widget::on_pushButton_clicked()
{
    QMessageBox::about(this, tr("Acerca"), tr("<h3>Desarrollado por: Jean Zamora</h3>\n<h3>Versión: 1.0.0</h3>\n<h3>Licencia: GPL v3</h3>\n<h3>Correo: jeancarloscuatro1@gmail.com</h3>\n<h3>Artistas: Iliana Doble, Francheska Romero</h3>\n<h3>Audio: Francheska Romero</h3>"));
}

