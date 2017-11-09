#include "book.h"


Book::Book(){
    name = "";
    author = "";
    genre = "";
    descr = "";
    year = 0;
}

Book::Book(const QString &author, const QString &name, const QString &genre, const QString &descr, const int &year){
    this->setAuthor(author);
    this->setName(name);
    this->setGenre(genre);
    this->setDescr(descr);
    this->setYear(year);
    //qDebug() << "Debug:  The initialization (int, QString)constructor is called";
}

Book::Book(Book &otherBooks){
    author = otherBooks.author;
    name = otherBooks.name;
    genre = otherBooks.genre;
    descr = otherBooks.descr;
    year = otherBooks.year;
    //qDebug() << "Debug: The copy constructor is called";
}

Book::~Book(){
    //qDebug()<< "Debug: The destructor is called";
}

void Book::setAuthor(const QString &author){
    QRegExp regAuthor("^[a-z]+$");
    if (regAuthor.exactMatch(author.toLower())){
        //author =
        this->author = author;
    }
    else{
        this->author = "Unknown author";
        //qDebug() << "Incorrect author";
    }
    //qDebug() << "Debug: setAuthor is called";
}

void Book::setGenre(const QString &genre){
    QRegExp RegGenre("\\b(poem|prose)\\b");
    if (RegGenre.exactMatch(genre)){
        this->genre = genre;
    }
    else{
        //qDebug() << "Incorrect genre";
        this->genre = "Unknown genre";
    }
    //qDebug() << "Debug: setGenre is called";
}

QString Book::getAuthor(){
    //qDebug() << "Debug: getAuthor is called";
    return this->author;
}

QString Book::getGenre(){
    //qDebug() << "Debug: getGenre is called";
    return this->genre;
}

void Book::toJsonObject(QJsonObject& json) const {
    json.insert("name", name);
    json.insert("author", author);
    json.insert("genre", genre);
    json.insert("descr", descr);
    QString str =  QString::number(year);
    json.insert("year", str);
}

