#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void parse(QString s);
    void generate();

private slots:
    void on_lEAnswerdit_returnPressed();

private:
    Ui::MainWindow *ui;

    QFile *file;
    QStringList phrases, answers;
    QVector<float> weights;

    int currentIndex;
    float sum;
};

#endif // MAINWINDOW_H
