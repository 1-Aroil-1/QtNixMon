//
// Created by aroil on 02.03.2026.
//

#ifndef QTNIXMON_MAINWINDOW_H
#define QTNIXMON_MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE

namespace Ui {
    class mainwindow;
}

QT_END_NAMESPACE

class mainwindow : public QMainWindow {
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    Ui::mainwindow *ui;
};


#endif //QTNIXMON_MAINWINDOW_H