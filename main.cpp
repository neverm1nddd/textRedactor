#include "redactormainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    redactorMainWindow w;
    w.show();
    return a.exec();
}
