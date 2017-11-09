#include "mainwindow.h"
#include "tree.h"
#include "book.h"
#include "storybook.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    auto tree = new Tree;
    Book book1("Lermontov", "Demon", "poem", "good", 1842);
    Book book2("Pushkin", "Ruslan","poem", "very good", 1820);
    tree->keyInsert(book1);
    tree->keyInsert(book2);
    QString names = tree->nameGet();
    auto storybook = new Storybook("Sbornik",
                                   2016,
                                   names,
                                   "Normas tak");
    //tree->keyInsert(storybook);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
