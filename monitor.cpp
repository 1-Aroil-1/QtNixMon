//
// Created by aroil on 28.02.2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Monitor.h" resolved

#include "monitor.h"
#include "ui_monitor.h"


Monitor::Monitor(QWidget *parent) : QWidget(parent), ui(new Ui::Monitor) {
    ui->setupUi(this);
}

Monitor::~Monitor() {
    delete ui;
}

int main() {
    Monitor app;
    app.show();
}