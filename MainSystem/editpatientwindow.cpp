// This have to been implemented yet
#include "editpatientwindow.h"
#include "ui_editpatientwindow.h"

EditPatientWindow::EditPatientWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditPatientWindow)
{
    ui->setupUi(this);
}

EditPatientWindow::~EditPatientWindow()
{
    delete ui;
}
