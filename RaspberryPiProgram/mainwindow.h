// John Walter and Evan Schulte
// ECE 3220 - Final Project
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QFileSystemWatcher>
#include <QString>
#include <QObject>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();
    void fileChanged(const QString & path);

private:
    Ui::MainWindow *ui;
    string patient;
    string owner;
    string medications;
    string treatment;
    string food;
    string food_amount;
    string belongings;

    string own_food;
    string leash;
    string toys;
    string bed;

    QFileSystemWatcher *file_watch;



};

#endif // MAINWINDOW_H
