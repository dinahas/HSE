#ifndef STORYBOOK_H
#define STORYBOOK_H

#include<QString>
#include<QDebug>
#include<QRegExp>
#include "book.h"
#include "base.h"

class Storybook: public Base
{
public:
    Storybook();
    Storybook(
            const QString& name,
            const int& year,
            const QString& descr,
            const QString& names);
    Storybook(const Storybook &otherStorybook);
    ~Storybook();
    void setNames(const QString& names);
    QString getNames() const;
    virtual bool isBook();
    /*virtual*/ void toJsonObject(QJsonObject& json);

private:
    QString names;
};

#endif // STORYBOOK_H
