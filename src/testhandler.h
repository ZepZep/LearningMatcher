#ifndef TESTHANDLER_H
#define TESTHANDLER_H

#include "question.h"
#include <QString>
#include <QStringList>
#include <QVector>
#include <QFile>

#include <cstdlib>
#include <ctime>

class TestHandler
{
public:
    TestHandler();

    void loadQuestionFile(QString path);
    void addQuestion(Question q);

    Question getQuestion();
    void putAnswer(int id, bool correct);

    void displayProbsbilities();
    void displayCounts();

    void resetTest();
    void clearTest();

    QVector<Question> questions;
    QVector<double> probabilities;
    QVector<int> counts;

private:

    double probMax;

};

#endif // TESTHANDLER_H
