#ifndef BOOK_H
#define BOOK_H


#include<QString>
#include<QDebug>
#include<QRegExp>
#include <QJsonObject>
#include "base.h"

class Book: public Base
{
public:
    Book();
    Book(const QString &author, const QString &name, const QString &genre, const QString &descr, const int &year);
    Book(Book &otherBooks);
    Book(const QString &name, const int &year, const QString &descr);
    ~Book();
    void setAuthor(const QString &author);
    void setGenre(const QString &genre);
    QString getAuthor();
    QString getGenre();

    void toJsonObject(QJsonObject& json) const;

private:
    QString author, name, genre, descr;
    int year;
};

#endif // BOOK_H
