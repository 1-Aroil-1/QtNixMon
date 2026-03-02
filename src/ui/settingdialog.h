#ifndef QTNIXMON_SETTINGDIALOG_H
#define QTNIXMON_SETTINGDIALOG_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class settingdialog;
}

QT_END_NAMESPACE

class settingdialog : public QWidget {
    Q_OBJECT

public:
    explicit settingdialog(QWidget *parent = nullptr);

    ~settingdialog() override;

private:
    Ui::settingdialog *ui;
};


#endif //QTNIXMON_SETTINGDIALOG_H