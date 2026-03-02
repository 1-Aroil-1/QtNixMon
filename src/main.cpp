#include <QApplication>
#include "ui/mainwindow.h"
#include <print>

import meminfo;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    app.setApplicationName("QtNixMon");
    app.setApplicationVersion("0.1.0");
    app.setOrganizationName("Aroil");

    mainwindow window;
    window.show();

    MemoryStats stats = MemoryInfo::init();

    std::println("{}", stats.total);
    std::println("{}", stats.used);
    std::println("{}", stats.available);

    return app.exec();
}