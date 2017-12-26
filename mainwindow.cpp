#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tree.h"
#include "node.h"
#include "book.h"
#include "QStringList"
#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    //ui->pushButton_5->setVisible(false);
    ui->textBrowser_2->setVisible(false);
    ui->treeWidget->clear();

    QGridLayout *grid = new QGridLayout;

    grid->addWidget(ui->centralWidget);

    QWidget *as = new QWidget;
    as->setLayout(grid);

    setCentralWidget(as);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->treeWidget->clear();

    QString name, author, genre, descr;
    int year;

    if (ui->lineEdit->text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Message");
        msgBox.setText("Plese, write name of the book!");
        msgBox.exec();
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->textEdit->clear();
        ui->textEdit_3->clear();
        return;
    }
    else
        name = ui->lineEdit->text();
    static QString let = "1234567890`~!@#$%^&*()_-+=;:'?/><.,{}|№";
    foreach(const QChar & ch, let) {
        if(ui->lineEdit_2->text().contains(ch) || ui->lineEdit_2->text().isEmpty())
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Message");
            msgBox.setText("Plese, write author of the book!");
            msgBox.exec();
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->textEdit->clear();
            ui->textEdit_3->clear();
           return;
        }
        else
            author = ui->lineEdit_2->text();
    }
    foreach(const QChar & ch, let) {
        if(ui->lineEdit_4->text().contains(ch) || ui->lineEdit_4->text().isEmpty())
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Message");
            msgBox.setText("Plese, write genre of the book!");
            msgBox.exec();
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->textEdit->clear();
            ui->textEdit_3->clear();
            return;
        }
        else
            genre = ui->lineEdit_4->text();
    }
    let = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm "
          "`~!@#$%^&*()_-+=;:'?/><.,{}|№";
        foreach(const QChar & ch, let) {
            if(ui->lineEdit_3->text().contains(ch) || ui->lineEdit_3->text().isEmpty())
            {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Message");
                msgBox.setText("Plese, write year of publication!");
                msgBox.exec();
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
                ui->lineEdit_3->clear();
                ui->lineEdit_4->clear();
                ui->textEdit->clear();
                ui->textEdit_3->clear();
               return;
            }
            else
                year = ui->lineEdit_3->text().toInt();
        }
    descr = ui->textEdit->toPlainText();
    tree.keyInsert(Book(author, name, genre, descr, year));
    ui->pushButton_2->setVisible(true);
    ui->pushButton_3->setVisible(true);
    //ui->pushButton_5->setVisible(true);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->textEdit->clear();
    ui->textEdit_3->clear();

    ui->treeWidget->clear();
    Base *base = tree.getRoot()->data;
    QStringList list = (QStringList() << "'" + base->getName() + "'" + " "
                        + QString::number(base->getYear()) +
                        " " + "'" + base->getDescr() + "'"
         << QString::number(base->getYear())
         << base->getDescr());
    QTreeWidgetItem *topItem = new QTreeWidgetItem(list);
    ui->treeWidget->addTopLevelItem(topItem);
    //base = tree.getNext(tree.getRoot())->data;
    if (tree.size() > 1)
    {
        Node* curr = tree.getNext(tree.getRoot());
        while(curr)
        {
            base = curr->data;
            QStringList child = (QStringList() << base->getName()
                 << QString::number(base->getYear())
                 << base->getDescr());
            QTreeWidgetItem *childItem = new QTreeWidgetItem(child);
            topItem->addChild(childItem);
            if (tree.size() > 2)
                curr = tree.getNext(curr);
            else curr = NULL;
            topItem = childItem;
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->treeWidget->clear();
    QString name = ui->lineEdit->text();
    if (!tree.isEmpty())
    {
        tree.keyDelete(name);
    }
    if (tree.size() == 0){
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(false);
        //ui->pushButton_5->setVisible(false);
    }
    ui->lineEdit->clear();
    ui->treeWidget->clear();
    Base *base = tree.getRoot()->data;
    QStringList list = (QStringList() << "'" + base->getName() + "'" + " "
                        + QString::number(base->getYear()) +
                        " " + "'" + base->getDescr() + "'"
         << QString::number(base->getYear())
         << base->getDescr());
    QTreeWidgetItem *topItem = new QTreeWidgetItem(list);
    ui->treeWidget->addTopLevelItem(topItem);
    //base = tree.getNext(tree.getRoot())->data;
    if (tree.size() > 1)
    {
        Node* curr = tree.getNext(tree.getRoot());
        while(curr)
        {
            base = curr->data;
            QStringList child = (QStringList() << base->getName()
                 << QString::number(base->getYear())
                 << base->getDescr());
            QTreeWidgetItem *childItem = new QTreeWidgetItem(child);
            topItem->addChild(childItem);
            if (tree.size() > 2)
                curr = tree.getNext(curr);
            else curr = NULL;
            topItem = childItem;
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString name = ui->lineEdit->text();
    ui->textBrowser_2->setVisible(true);

    if(tree.find(name)->isBook())
    {
        Book* book = static_cast<Book*>(tree.find(name));
        if (book->getAuthor() != NULL){
            ui->textBrowser_2->setPlainText(book->getName()
                                            + "\n"
                                            + book->getAuthor()
                                            + "\n"
                                            + QString::number(book->getYear())
                                            + "\n"
                                            + book->getGenre()
                                            + "\n"
                                            + book->getDescr());
        }
        else
            ui->textBrowser_2->setPlainText("No such book:(");
    }
    else
    {
        Storybook* storybook = static_cast<Storybook*>(tree.find(name));
        if (storybook->getName() != NULL){
            ui->textBrowser_2->setPlainText(storybook->getName()
                                            + "\n"
                                            + QString::number(storybook->getYear())
                                            + "\n"
                                            + storybook->getDescr()
                                            + "\n"
                                            + storybook->getNames());
        }
        else
            ui->textBrowser_2->setPlainText("No such book:(");
    }

    ui->lineEdit->clear();
    ui->treeWidget->clear();
}

void MainWindow::on_pushButton_4_clicked()
{
    {
        ui->treeWidget->clear();

        QString name, names, descr;
        int year;

        if (ui->lineEdit->text().isEmpty())
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Message");
            msgBox.setText("Plese, write name of the storybook!");
            msgBox.exec();
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->textEdit->clear();
            ui->textEdit_3->clear();
            return;
        }
        else
            name = ui->lineEdit->text();
        static QString let = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm "
              "`~!@#$%^&*()_-+=;:'?/><.,{}|№";
            foreach(const QChar & ch, let) {
                if(ui->lineEdit_3->text().contains(ch) || ui->lineEdit_3->text().isEmpty())
                {
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Message");
                    msgBox.setText("Plese, write year of publication!");
                    msgBox.exec();
                    ui->lineEdit->clear();
                    ui->lineEdit_2->clear();
                    ui->lineEdit_3->clear();
                    ui->lineEdit_4->clear();
                    ui->textEdit->clear();
                    ui->textEdit_3->clear();
                   return;
                }
                else
                    year = ui->lineEdit_3->text().toInt();
            }
        if (ui->lineEdit->text().isEmpty())
        {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Message");
            msgBox.setText("Plese, write names of books!");
            msgBox.exec();
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->textEdit->clear();
            ui->textEdit_3->clear();
            return;
        }
        else
            names = ui->textEdit_3->toPlainText();
        descr = ui->textEdit->toPlainText();

        Storybook storybook(name, year, descr, names);
        tree.keyInsert(storybook);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        //ui->pushButton_5->setVisible(true);

        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->textEdit_3->clear();
        ui->textEdit->clear();
    }
    ui->treeWidget->clear();
    Base *base = tree.getRoot()->data;
    QString data = base->getName() + base->getDescr() + QString::number(base->getYear());
    QStringList list = (QStringList() << "'" + base->getName() + "'" + " "
                        + QString::number(base->getYear()) +
                        " " + "'" + base->getDescr() + "'"
         << QString::number(base->getYear())
         << base->getDescr());
    //qDebug() << list;
    QTreeWidgetItem *topItem = new QTreeWidgetItem(list);
    ui->treeWidget->addTopLevelItem(topItem);
    //base = tree.getNext(tree.getRoot())->data;
    if (tree.size() > 1)
    {
        Node* curr = tree.getNext(tree.getRoot());
        while(curr)
        {
            base = curr->data;
            QStringList child = (QStringList() << base->getName()
                 << QString::number(base->getYear())
                 << base->getDescr());
            QTreeWidgetItem *childItem = new QTreeWidgetItem(child);
            topItem->addChild(childItem);
            if (tree.size() > 2)
                curr = tree.getNext(curr);
            else curr = NULL;
            topItem = childItem;
        }
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if (tree.size() == 0)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Message");
        msgBox.setText("No elements!");
        msgBox.exec();
    }
    else
    {
        QString str = ui->lineEdit_5->text();
        tree.save(str+".json");
        QMessageBox msgBox;
        msgBox.setWindowTitle("Message");
        msgBox.setText("Done!");
        msgBox.exec();
    }
    ui->lineEdit_5->clear();
    ui->treeWidget->clear();
}

void MainWindow::on_pushButton_7_clicked()
{
    QString str = ui->lineEdit_5->text();
    QFile file(str + ".json");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Message");
        msgBox.setText("No file with such name!");
        msgBox.exec();
    }
    else
    {
        tree.load(str + ".json");
    }
    ui->lineEdit_5->clear();
    ui->pushButton_2->setVisible(true);
    ui->pushButton_3->setVisible(true);
    //ui->pushButton_5->setVisible(true);

    ui->treeWidget->clear();
    Base *base = tree.getRoot()->data;
    QStringList list = (QStringList() << "'" + base->getName() + "'" + " "
                        + QString::number(base->getYear()) +
                        " " + "'" + base->getDescr() + "'"
         << QString::number(base->getYear())
         << base->getDescr());
    QTreeWidgetItem *topItem = new QTreeWidgetItem(list);
    ui->treeWidget->addTopLevelItem(topItem);
    //base = tree.getNext(tree.getRoot())->data;
    if (tree.size() > 1)
    {
        Node* curr = tree.getNext(tree.getRoot());
        while(curr)
        {
            base = curr->data;
            QStringList child = (QStringList() << base->getName()
                 << QString::number(base->getYear())
                 << base->getDescr());
            QTreeWidgetItem *childItem = new QTreeWidgetItem(child);
            topItem->addChild(childItem);
            if (tree.size() > 2)
                curr = tree.getNext(curr);
            else curr = NULL;
            topItem = childItem;
        }
    }
}
