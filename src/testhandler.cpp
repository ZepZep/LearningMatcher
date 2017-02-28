#include "testhandler.h"


#include <QDebug>

TestHandler::TestHandler()
{
    clearTest();
}

void TestHandler::loadQuestionFile(QString path)
{
    clearTest();

    QFile *file = new QFile(path);
    file->open(QIODevice::ReadOnly);

    QString s = file->readAll();
    QStringList l = s.split("\n", QString::SkipEmptyParts);

    foreach (QString line, l) {
        if(line.left(2) != "//")
        {
            QStringList a = line.split("; ", QString::KeepEmptyParts);
            Question q(a[0], a[1]);
            addQuestion(q);
        }
    }
}

void TestHandler::addQuestion(Question q)
{
    q.id = questions.size();
    questions.append(q);
    probabilities.append(1);
    counts.append(0);
    probMax += 1;

    qsrand(std::time(NULL));
}

Question TestHandler::getQuestion()
{
    if(questions.size() == 0) return Question();
    float fIndex = qrand();
    fIndex /= RAND_MAX;
    fIndex *= probMax;
    double dindex = fIndex;

    double cur = probabilities[0];
    int index = 0;
    while(cur < dindex)
    {
        cur += probabilities[++index];
    }

    return questions[index];
}

void TestHandler::putAnswer(int id, bool correct)
{
    double prob = probabilities[id];
    probMax -= prob;
    if(correct)
        prob /= 1.5;
    else
        prob *= 1.5;

    probMax += prob;
    probabilities[id] = prob;
}

void TestHandler::displayProbsbilities()
{
    qDebug() <<probabilities;
}

void TestHandler::displayCounts()
{
    return;
}

void TestHandler::resetTest()
{
    probabilities.fill(1);
    counts.fill(0);
    probMax = 0;
}

void TestHandler::clearTest()
{
    questions.clear();
    probabilities.clear();
    counts.clear();
    probMax = 0;
}
