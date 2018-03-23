/********************************************************************************
** Form generated from reading UI file 'dialogvolumen.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGVOLUMEN_H
#define UI_DIALOGVOLUMEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogVolumen
{
public:
    QVBoxLayout *verticalLayout;
    QSlider *horizontalSlider_volumen;
    QProgressBar *progressBar_volumen;

    void setupUi(QDialog *DialogVolumen)
    {
        if (DialogVolumen->objectName().isEmpty())
            DialogVolumen->setObjectName(QStringLiteral("DialogVolumen"));
        DialogVolumen->resize(400, 300);
        verticalLayout = new QVBoxLayout(DialogVolumen);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSlider_volumen = new QSlider(DialogVolumen);
        horizontalSlider_volumen->setObjectName(QStringLiteral("horizontalSlider_volumen"));
        horizontalSlider_volumen->setMaximum(100);
        horizontalSlider_volumen->setValue(50);
        horizontalSlider_volumen->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_volumen);

        progressBar_volumen = new QProgressBar(DialogVolumen);
        progressBar_volumen->setObjectName(QStringLiteral("progressBar_volumen"));
        progressBar_volumen->setValue(50);

        verticalLayout->addWidget(progressBar_volumen);


        retranslateUi(DialogVolumen);
        QObject::connect(horizontalSlider_volumen, SIGNAL(valueChanged(int)), progressBar_volumen, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(DialogVolumen);
    } // setupUi

    void retranslateUi(QDialog *DialogVolumen)
    {
        DialogVolumen->setWindowTitle(QApplication::translate("DialogVolumen", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogVolumen: public Ui_DialogVolumen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGVOLUMEN_H
