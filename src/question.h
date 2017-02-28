#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QStringList>

class Question
{
public:
    Question();
    Question(QString q, QString a);

    void setChoosable(bool ch, QStringList l);


    int id;
    QString text;
    QString answer;

    bool isChoosable;
    QStringList choices;

};

#endif // QUESTION_H
