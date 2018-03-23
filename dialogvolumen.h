#ifndef DIALOGVOLUMEN_H
#define DIALOGVOLUMEN_H

#include <QDialog>

namespace Ui {
class DialogVolumen;
}

class DialogVolumen : public QDialog
{
    Q_OBJECT

public:
    explicit DialogVolumen(QWidget *parent = 0);
    ~DialogVolumen();

private:
    Ui::DialogVolumen *ui;
};

#endif // DIALOGVOLUMEN_H
