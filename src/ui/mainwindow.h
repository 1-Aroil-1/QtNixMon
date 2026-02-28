//
// Created by aroil on 28.02.2026.
//

#ifndef QTNIXMON_MAINWINDOW_H
#define QTNIXMON_MAINWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class mainwindow;
}

QT_END_NAMESPACE

class mainwindow : public QWidget {
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    Ui::mainwindow *ui;
};


#endif //QTNIXMON_MAINWINDOW_H