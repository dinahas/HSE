#ifndef BASA_H
#define BASA_H

#include<QString>
#include<QDebug>
#include<QRegExp>

class Base
{
public:
    //Base();
    void setName(const QString &name);
    void setDescr(const QString &descr);
    void setYear(const int &year);
    QString getName();
    QString getDescr();
    int getYear();

private:
    QString name, descr;
    int year;
};

#endif // BASA_H
