#include "storybook.h"
#include "book.h"
#include "tree.h"

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

Storybook::Storybook(Storybook &otherStorybook)
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
    //QRegExp regNames("^\\w+$");
    if (names != NULL){
        this->names = names;
    }
    else{
        //qDebug() << "Incorrect name";
        this->names = "No books in this Storybook:(";
    }
}

QString Storybook::getNames()
{
    return this->names;
}
