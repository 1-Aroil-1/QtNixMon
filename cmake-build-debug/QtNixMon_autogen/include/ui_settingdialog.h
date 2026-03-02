/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingdialog
{
public:

    void setupUi(QWidget *settingdialog)
    {
        if (settingdialog->objectName().isEmpty())
            settingdialog->setObjectName("settingdialog");
        settingdialog->resize(400, 300);

        retranslateUi(settingdialog);

        QMetaObject::connectSlotsByName(settingdialog);
    } // setupUi

    void retranslateUi(QWidget *settingdialog)
    {
        settingdialog->setWindowTitle(QCoreApplication::translate("settingdialog", "settingdialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class settingdialog: public Ui_settingdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
