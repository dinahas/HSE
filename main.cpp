#include "mainwindow.h"
#include "tree.h"
#include "book.h"
#include "storybook.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
