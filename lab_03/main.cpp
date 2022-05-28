#include <QApplication>

#include <QScreen>
#include <QStyle>

#include "gui/qt/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    a.setStyle("Fusion");
    w.setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, w.size(),
                                      QGuiApplication::primaryScreen()->availableGeometry()));
    w.show();
    return QApplication::exec();
}