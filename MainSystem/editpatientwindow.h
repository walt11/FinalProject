// This has not been implemented yet
#ifndef EDITPATIENTWINDOW_H
#define EDITPATIENTWINDOW_H

#include <QWidget>

namespace Ui {
class EditPatientWindow;
}

class EditPatientWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditPatientWindow(QWidget *parent = 0);
    ~EditPatientWindow();

private:
    Ui::EditPatientWindow *ui;
};

#endif // EDITPATIENTWINDOW_H
