#include "settingdialog.h"
#include "ui_settingdialog.h"


settingdialog::settingdialog(QWidget *parent) : QWidget(parent), ui(new Ui::settingdialog) {
    ui->setupUi(this);
}

settingdialog::~settingdialog() {
    delete ui;
}