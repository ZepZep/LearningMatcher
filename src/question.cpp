#include "question.h"


Question::Question()
{
    Question("Blank?", "false");
}

Question::Question(QString q, QString a)
{
    text = q;
    answer = a;

    isChoosable = false;
    choices = QStringList();
}

void Question::setChoosable(bool ch, QStringList l)
{
    isChoosable = ch;
    choices = l;
}
