// John Walter and Evan Schulte
// ECE 3220 - Final Project

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newpatientwindow.h"
#include <QMessageBox>
#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// MainWindow constructor - default by Qt
// creates a main window object UI
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // calls updateDisplay to update the patients displayed on the mainwindow
    updateDisplay();

}

// method to update the display
void MainWindow::updateDisplay(){
    int i;
    char file_name[20];
    char pat[30];
    char ow[30];
    ui->dog_textbrowser->append("Device\t\tPatient\t\tOwner\n");

    // opens each dog's device file and displays the patients name and owner name to the main window
    for(i=1;i<=10;i++){
        // creates the file name to be opened
        sprintf(file_name,"Data/Dogs/dog_%d.txt",i);
        // opens the file and reads in the contents
        ifstream ifile(file_name);
        if (ifile) {
          FILE *fp = fopen(file_name,"r");
          fscanf(fp,"%s",pat);
          fscanf(fp,"%s",ow);
          fclose(fp);
          patient_in = pat;
          owner_in = ow;
          device_in = to_string(i);
          //writes the info the the textbrowser on the main window
          ui->dog_textbrowser->append(("("+device_in+")\t\t"+patient_in+"\t\t"+owner_in).c_str());
        }

    }
    ui->cat_textbrowser->append("Device\t\tPatient\t\tOwner\n");
    // opens each cat's device file and displays the patients name and owner name to the main window
    for(i=11;i<=20;i++){
        // creates the file name to be opened
        sprintf(file_name,"Data/Cats/cat_%d.txt",i);
        // opens the file and reads in the contents
        ifstream ifile(file_name);
        if (ifile) {
          FILE *fp = fopen(file_name,"r");
          fscanf(fp,"%s",pat);
          fscanf(fp,"%s",ow);
          fclose(fp);
          patient_in = pat;
          owner_in = ow;
          device_in = to_string(i);
          //writes the info the the textbrowser on the main window
          ui->cat_textbrowser->append(("("+device_in+")\t\t"+patient_in+"\t\t"+owner_in).c_str());
        }

    }

}

// main window destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// method called when the pushButton is clicked
void MainWindow::on_pushButton_clicked()
{
    // creates a NewPatientWindow object and shows that objects window
    NewPatientWindow *newPatient = new NewPatientWindow();
    newPatient->show();
}

// method called when the update button is clicked
void MainWindow::on_update_clicked()
{
    // clears the textbrowsers on the mainwindow
    ui->dog_textbrowser->clear();
    ui->cat_textbrowser->clear();
    // updates the display
    updateDisplay();
}

// method called when the edit patient button is clicked
void MainWindow::on_edit_patient_clicked()
{
    // creates a new object the the newpatientwindow and will insert the current information into that window when completed
    NewPatientWindow *editPatient = new NewPatientWindow(0,ui->lineEdit->text());
    // shows the newpatientwindow
    editPatient->show();
}