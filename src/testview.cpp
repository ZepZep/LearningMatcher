#include "testview.h"
#include "ui_testview.h"

TestView::TestView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestView)
{
    ui->setupUi(this);
    test = new TestHandler;
    answered = false;

    on_pBLoad_clicked();
}

TestView::~TestView()
{
    delete ui;
}

void TestView::showNewQuestion()
{
    currentQuestion = test->getQuestion();

    ui->lQuestion->setText(currentQuestion.text);
    ui->lStatus->setText("");
    answered = false;
}

void TestView::on_pBSubmit_clicked()
{
    if(answered)
    {
        ui->lEAnswer->setText("");
        ui->lStatus->setStyleSheet("");
        showNewQuestion();
    }
    else
    {
        answered = true;
        if(ui->lEAnswer->text().toLower() == currentQuestion.answer.toLower())
        {
            ui->lStatus->setText("Correct!\n The answer is: " + currentQuestion.answer+".");
            ui->lStatus->setStyleSheet("QLabel { color : green; }");
            test->putAnswer(currentQuestion.id, true);
        }
        else
        {
            ui->lStatus->setText("Wrong!\n The answer is: " + currentQuestion.answer+".");
            ui->lStatus->setStyleSheet("QLabel { color : red; }");
            test->putAnswer(currentQuestion.id, false);
        }
    }
}

void TestView::on_lEAnswer_returnPressed()
{
    ui->pBSubmit->click();
}

void TestView::on_pBLoad_clicked()
{
    test->loadQuestionFile(ui->lEPath->text());
    showNewQuestion();
}

void TestView::on_pBReset_clicked()
{
    test->resetTest();
}

void TestView::on_pBPath_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select test file", ".");
    if(fileName != "") ui->lEPath->setText(fileName);
}

void TestView::on_pBDebug_clicked()
{
    test->displayProbsbilities();
}
