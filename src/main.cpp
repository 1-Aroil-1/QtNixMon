#include <QApplication>
#include "ui/mainwindow.h"

int main() {
    QApplication::setApplicationName("QtNixMon");
    QApplication::setApplicationVersion("0.1.0");
    QApplication::setOrganizationName("Aroil");

    mainwindow window;
    window.show();

    return QApplication::exec();
}