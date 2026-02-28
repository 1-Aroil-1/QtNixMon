#ifndef QTNIXMON_SETTINGSDIALOG_H
#define QTNIXMON_SETTINGSDIALOG_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class settingsdialog;
}

QT_END_NAMESPACE

class settingsdialog : public QWidget {
    Q_OBJECT

public:
    explicit settingsdialog(QWidget *parent = nullptr);

    ~settingsdialog() override;

private:
    Ui::settingsdialog *ui;
};


#endif //QTNIXMON_SETTINGSDIALOG_H