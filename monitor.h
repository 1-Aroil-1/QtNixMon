//
// Created by aroil on 28.02.2026.
//

#ifndef QTNIXMON_MONITOR_H
#define QTNIXMON_MONITOR_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class Monitor;
}

QT_END_NAMESPACE

class Monitor : public QWidget {
    Q_OBJECT

public:
    explicit Monitor(QWidget *parent = nullptr);

    ~Monitor() override;

private:
    Ui::Monitor *ui;
};


#endif //QTNIXMON_MONITOR_H