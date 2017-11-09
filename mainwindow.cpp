#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tree.h"
#include "book.h"
#include "QString"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(800, 600);
    ui->pushButton->setFixedSize(150, 30);
    ui->pushButton_2->setFixedSize(150, 30);
    ui->pushButton_3->setFixedSize(150, 30);
    ui->textBrowser->setFixedHeight(130);
    ui->textEdit->setFixedHeight(130);
    ui->textBrowser_2->setFixedHeight(100);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->textBrowser_2->setVisible(false);

    QGridLayout *grid = new QGridLayout;

    grid->addWidget(ui->label, 1, 0);
    grid->addWidget(ui->label_2, 2, 0);
    grid->addWidget(ui->label_3, 3, 0);
    grid->addWidget(ui->label_4, 4, 0);
    grid->addWidget(ui->label_5, 5, 0);
    grid->addWidget(ui->lineEdit, 1, 1);
    grid->addWidget(ui->lineEdit_2, 2, 1);
    grid->addWidget(ui->lineEdit_3, 3, 1);
    grid->addWidget(ui->lineEdit_4, 4, 1);
    grid->addWidget(ui->textEdit, 5, 1);
    grid->addWidget(ui->pushButton, 6, 0);
    grid->addWidget(ui->pushButton_2, 7, 0);
    grid->addWidget(ui->pushButton_3, 8, 0);
    grid->addWidget(ui->textBrowser_2, 9, 0);
    grid->addWidget(ui->textBrowser, 0, 0);

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
    QString name, author, genre, descr;
    int year;

    name = ui->lineEdit->text();
    author = ui->lineEdit_2->text();
    year = ui->lineEdit_3->text().toInt();
    genre = ui->lineEdit_4->text();
    descr = ui->textEdit->toPlainText();

    Book book(author, name, genre, descr, year);
    tree.keyInsert(book);
    ui->pushButton_2->setVisible(true);
    ui->pushButton_3->setVisible(true);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString name = ui->lineEdit->text();
    if (!tree.isEmpty())
    {
        tree.keyDelete(name);
    }
    if (tree.size() == 0){
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(false);
    }
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString name = ui->lineEdit->text();
    ui->textBrowser_2->setVisible(true);
    if (tree.find(name).getYear() != 0){
        ui->textBrowser_2->setPlainText(tree.find(name).getName()
                                        + " "
                                        + tree.find(name).getAuthor()
                                        +  " "
                                        + QString::number(tree.find(name).getYear())
                                        + " "
                                        + tree.find(name).getGenre()
                                        + " "
                                        + tree.find(name).getDescr());
    }
    else
        ui->textBrowser_2->setPlainText("No such book:(");

    ui->lineEdit->clear();
}
