#ifndef BASA_H
#define BASA_H

#include<QString>
#include<QDebug>
#include<QRegExp>

class Base
{
public:
    //Base();
    virtual void setName(const QString &name);
    virtual void setDescr(const QString &descr);
    virtual void setYear(const int &year);
    virtual QString getName() const;
    virtual QString getDescr() const;
    virtual int getYear() const;
    //virtual void toJsonObject();
    virtual bool isBook() = 0;

protected:
    QString name, descr;
    int year;
};

#endif // BASA_H
