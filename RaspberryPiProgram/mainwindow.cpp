// John Walter and Evan Schulte
// ECE 3220 - Final Project

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <QFileSystemWatcher>
#include <QObject>

using namespace std;

// Main window constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this); // setup the window
    ui->pushButton->setStyleSheet("QPushButton {color : white}");
    string ip = "";
      FILE *fp;
      char file_type[40];

      fp = popen("ifconfig", "r");
      if (fp == NULL) {
          printf("Failed to run command\n" );
      }else{

      while (fgets(file_type, sizeof(file_type), fp) != NULL) {

          ip = ip + string(file_type);
      }
      }



    ui->textBrowser->setStyleSheet("QTextBrowser {color : white}");
    ui->textBrowser->setText(ip.c_str());

    // These hide all of the objects on the main window so only the Activate button is shown
    ui->patient_label->setVisible(false);
    ui->owner_label->setVisible(false);
    ui->medications_text->setVisible(false);
    ui->treatment_label->setVisible(false);
    ui->food_label->setVisible(false);
    ui->belongings_label->setVisible(false);

    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);

    // these set the text color to blue for the labels
    ui->label->setStyleSheet("QLabel {color : blue}");
    ui->label_2->setStyleSheet("QLabel {color : blue}");
    ui->label_3->setStyleSheet("QLabel {color : blue}");
    ui->label_4->setStyleSheet("QLabel {color : blue}");
    ui->label_5->setStyleSheet("QLabel {color : blue}");
    ui->label_6->setStyleSheet("QLabel {color : blue}");

    // these set the text color to white for the patients information
    ui->patient_label->setStyleSheet("QLabel {color: white}");
    ui->owner_label->setStyleSheet("QLabel {color: white}");
    ui->medications_text->setStyleSheet("QTextBrowser {color: white}");
    ui->treatment_label->setStyleSheet("QTextBrowser {color: white}");
    ui->food_label->setStyleSheet("QLabel {color: white}");
    ui->belongings_label->setStyleSheet("QLabel {color: white}");
}

// mainwindow deconsructor
MainWindow::~MainWindow()
{
    delete ui;
}

// method that is called if a file change is detected
void MainWindow::fileChanged(const QString &)
{
  belongings = ""; // clear belongings
  //cout << "Inside fileChanged" << endl;
  ifstream file("/home/pi/to_push.txt");

  // open the file that was pushed
  if (file){
   	// read in all of the patient information
      getline(file,patient);
      getline(file,owner);
      getline(file,medications);
      getline(file,treatment);
      getline(file,food);
      getline(file,own_food);
      getline(file,food_amount);
      getline(file,leash);
      getline(file,toys);
      getline(file,bed);
      getline(file,carrier);

      if(atoi(own_food.c_str()) == 1){
          belongings = belongings+"Food, ";
      }
      if(atoi(leash.c_str()) == 1){
          belongings = belongings+"Leash, ";
      }
      if(atoi(toys.c_str()) == 1){
          belongings = belongings+"Toys, ";
      }
      if(atoi(bed.c_str()) == 1){
          belongings = belongings+"Bed/Blanket, ";
      }
      if(atoi(carrier.c_str()) == 1){
          belongings = belongings+"Carrier, ";
      }
      belongings.erase(belongings.end()-2);

      // Sets the labels on the screen to display the patient information
      ui->patient_label->setText(patient.c_str());
      ui->owner_label->setText(owner.c_str());
      ui->medications_text->setText(medications.c_str());
      ui->treatment_label->setText(treatment.c_str());
      ui->food_label->setText((food+": "+food_amount).c_str());
      ui->belongings_label->setText(belongings.c_str());
  }

}

// this method is ran when the activate button is pushed, at the start of the program
void MainWindow::on_pushButton_clicked()
{
    belongings = ""; // clear belongings

    // show all of the objects on the window
    ui->patient_label->setVisible(true);
    ui->owner_label->setVisible(true);
    ui->medications_text->setVisible(true);
    ui->treatment_label->setVisible(true);
    ui->food_label->setVisible(true);
    ui->belongings_label->setVisible(true);

    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->label_4->setVisible(true);
    ui->label_5->setVisible(true);
    ui->label_6->setVisible(true);

    ui->pushButton->setVisible(false); // hide the activate button
    ui->textBrowser->setVisible(false);

    // read in the file that was pushed
    ifstream file("/home/pi/to_push.txt");
    if (file){
        getline(file,patient);
        getline(file,owner);
        getline(file,medications);
        getline(file,treatment);
        getline(file,food);
        getline(file,own_food);
        getline(file,food_amount);
        getline(file,leash);
        getline(file,toys);
        getline(file,bed);
        getline(file,carrier);

        if(atoi(own_food.c_str()) == 1){
            belongings = belongings+"Food, ";
        }
        if(atoi(leash.c_str()) == 1){
            belongings = belongings+"Leash, ";
        }
        if(atoi(toys.c_str()) == 1){
            belongings = belongings+"Toys, ";
        }
        if(atoi(bed.c_str()) == 1){
            belongings = belongings+"Bed/Blanket, ";
        }
        if(atoi(carrier.c_str()) == 1){
            belongings = belongings+"Carrier, ";
        }
        belongings.erase(belongings.end()-2);
    //cout << "File read in" << endl;
    //cout << "Popped" << endl;

    // display the patient information on the screen
        ui->patient_label->setText(patient.c_str());
        ui->owner_label->setText(owner.c_str());
        ui->medications_text->setText(medications.c_str());
        ui->treatment_label->setText(treatment.c_str());
        ui->food_label->setText((food+": "+food_amount).c_str());
        ui->belongings_label->setText(belongings.c_str());
    }

    // this establishes a watcher (a Qt function) that watches the given file for changes
    // when a change is detected, it calls the fileChanged() method
    file_watch = new QFileSystemWatcher(this);
    connect(file_watch,SIGNAL(fileChanged(const QString &)), this, SLOT(fileChanged(const QString &)));
    file_watch->addPath("/home/pi/to_push.txt");
}
