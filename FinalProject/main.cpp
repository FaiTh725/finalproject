#include "mainwindow.h"

#include <QDebug>
#include <QApplication>
#include "Student.h"
#include "Vector.h"
#include "mergesort.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow m;
    m;

    return a.exec();
}
