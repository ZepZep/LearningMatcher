#ifndef TESTVIEW_H
#define TESTVIEW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QString>

#include "testhandler.h"
#include "question.h"

namespace Ui {
class TestView;
}

class TestView : public QWidget
{
    Q_OBJECT

public:
    explicit TestView(QWidget *parent = 0);
    ~TestView();

    void showNewQuestion();

private slots:
    void on_pBSubmit_clicked();
    void on_lEAnswer_returnPressed();
    void on_pBLoad_clicked();
    void on_pBReset_clicked();
    void on_pBPath_clicked();

    void on_pBDebug_clicked();

private:
    Ui::TestView *ui;

    TestHandler *test;
    Question currentQuestion;
    bool answered;
};

#endif // TESTVIEW_H
