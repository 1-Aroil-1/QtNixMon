#include <QApplication>
#include "ui/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    app.setApplicationName("QtNixMon");
    app.setApplicationVersion("0.1.0");
    app.setOrganizationName("Aroil");

    mainwindow window;
    window.show();

    return app.exec();
}