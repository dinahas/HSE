#include "storybook.h"
#include "book.h"
#include "tree.h"
#include<QRegExp>

Storybook::Storybook()
{

}

Storybook::Storybook(const QString &name_, const int &year_, const QString &descr_, const QString &names)
{
    this->setName(name_);
    this->setYear(year_);
    this->setNames(names);
    this->setDescr(descr_);
}

Storybook::Storybook(const Storybook &otherStorybook)
{
    name = otherStorybook.name;
    year = otherStorybook.year;
    names= otherStorybook.names;
    descr = otherStorybook.descr;
}

Storybook::~Storybook()
{

}

void Storybook::setNames(const QString &names)
{
    QRegExp regNames("^\\S+$");
    if (regNames.exactMatch(names.toLower())){
        this->names = names;
    }
    else{
        this->names = "Unknown author";
    }
}

QString Storybook::getNames() const
{
    return this->names;
}

bool Storybook::isBook()
{
    return false;
}

void Storybook::toJsonObject(QJsonObject& json)
{
    json.insert("name", name);
    json.insert("names", names);
    json.insert("descr", descr);
    QString str =  QString::number(year);
    json.insert("year", str);
}
