//
// Created by aroil on 02.03.2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_settingdialog.h" resolved

#include "settingdialog.h"
#include "ui_settingdialog.h"


settingdialog::settingdialog(QWidget *parent) : QWidget(parent), ui(new Ui::settingdialog) {
    ui->setupUi(this);
}

settingdialog::~settingdialog() {
    delete ui;
}