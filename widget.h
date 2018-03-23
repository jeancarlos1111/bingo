#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMediaPlayer>

namespace Ui {
class Widget;
}

class QMediaPlayer;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_iniciar_clicked();

    void on_pushButton_lanzar_clicked();

    void on_pushButton_clicked();


private:
    Ui::Widget *ui;
    int contador= 0;
    int num;
    QSqlDatabase bingodb;
    QMediaPlayer *mMediaplayer;

};

#endif // WIDGET_H
