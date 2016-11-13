#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    file = new QFile("../predlozky.txt");
    file->open(QIODevice::ReadOnly);

    parse(file->readAll());

    generate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::parse(QString s)
{
    phrases.clear();
    answers.clear();

    QStringList l = s.split("\n", QString::SkipEmptyParts);
    foreach (QString line, l) {
        QStringList a = line.split("; ", QString::KeepEmptyParts);
        phrases.append(a[0]);
        answers.append(a[1]);
    }

    weights.clear();
    weights.fill(2, l.size());
    sum = 2 * weights.size();
}

void MainWindow::generate()
{
    float r = qrand() * 1.0 / RAND_MAX * sum;

    float fromBeg = 0;
    for(int i = 0; fromBeg<r and i<weights.size(); i++)
    {
        fromBeg += weights[i];
        currentIndex = i;
    }

    ui->lPhrase->setText(phrases[currentIndex]);
}

void MainWindow::on_lEAnswerdit_returnPressed()
{
    if(ui->lEAnswerdit->text() == answers[currentIndex])
    {
        ui->lStatus->setText("Correct!");
        sum -= weights[currentIndex]/2;
        weights[currentIndex] -= weights[currentIndex]/2;
    }
    else
    {
        ui->lStatus->setText("Wrong! The answer is: "+answers[currentIndex]);
        sum += weights[currentIndex];
        weights[currentIndex] += weights[currentIndex];
    }

    ui->lEAnswerdit->setText("");
    generate();

}
