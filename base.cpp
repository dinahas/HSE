#include "base.h"

//Base::Base()
//{

//}

void Base::setName(const QString &name){
    QRegExp regName("^\\S+$");
    if (regName.exactMatch(name)){
        this->name = name;
    }
    else{
        //qDebug() << "Incorrect name";
        this->name = "Unknown name";
    }
    //qDebug() << "Debug: setName is called";
}

void Base::setDescr(const QString &descr){
    this->descr = descr;
    //qDebug() << "Debug: setDescr is called";
}

void Base::setYear(const int &year){
    if (year >= 1 && year <= 2017){
        this->year = year;
    }
    else{
        qDebug() << "Incorrect year";
        this->year = 0;
    }
    //qDebug() << "Debug: setYear is called";
}

QString Base::getName() const{
    //qDebug() << "Debug: getName is called";
    return this->name;
}

QString Base::getDescr() const{
    //qDebug() << "Debug: getDescr is called";
    return this->descr;
}

int Base::getYear() const{
    //qDebug() << "Debug: getYear is called";
    return this->year;
}

