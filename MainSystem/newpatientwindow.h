// John Walter and Evan Schulte
// ECE 3220 - Final Project

#ifndef NEWPATIENTWINDOW_H
#define NEWPATIENTWINDOW_H

#include <QWidget>
#include <string>
#include <vector>

using namespace std;

namespace Ui {
class NewPatientWindow;
}

class NewPatientWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NewPatientWindow(QWidget *parent = 0); // constructor for a new patient
    explicit NewPatientWindow(QWidget *parent, QString device); // constructor for a current patient to be edited

    int pushInfo(string,char *); // method that pushes to the device
    ~NewPatientWindow();         // destructor
    int loadNew_dog();           // method that loads dog object into vector
    int loadNew_cat();           // method that loads cat object into vector
    void writeDogToFile(char*);  // method that writes dog to file
    void writeCatToFile(char*);  // method that writes cat to file

private slots: // generated by Qt

    void on_push_clicked(); // called when the Push button is clicked

private:
    int edit = 0;
    Ui::NewPatientWindow *ui; // used by Qt for interface
};

#endif // NEWPATIENTWINDOW_H
