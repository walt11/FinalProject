// John Walter and Evan Schulte
// ECE 3220 - Final Project

#include "newpatientwindow.h"
#include "ui_newpatientwindow.h"
#include "mainwindow.h"
#include "mainwindow.cpp"
#include <iostream>
#include <QMessageBox>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "main.cpp"

using namespace std;

// NewPatientWindow Constructor for creating new patient
NewPatientWindow::NewPatientWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewPatientWindow)
{
    ui->setupUi(this);
}

// NewPatientWindow Constructor for editing the information of a current patient (NOT COMPLETE)
NewPatientWindow::NewPatientWindow(QWidget *parent, QString device) : QWidget(parent),ui(new Ui::NewPatientWindow)
{
    ui->setupUi(this);
    cout << "New patient window clicked" << endl;
    ui->input_device->setText(device);
}


//NewPatientWindow Destructor
NewPatientWindow::~NewPatientWindow()
{
    //cout << "Goodbye newpatientwindow" << endl;
    delete ui;
}

// This function pushes the patients file to the device given
int NewPatientWindow::pushInfo(string d){
    cout << d << endl;
    cout << "Getting IP Address..." << endl;
    char *ip_address;
    // opens the file containing the ip addresses
    FILE *fp = fopen("Data/device_ips.txt","r");

    // loops through to find the correct ip address associated to the device given
    if ( fp != NULL )
    {
        int lineNumber = atoi(d.c_str())*2;
        int count = 1;
        char line[20];
        while (fgets(line, sizeof line, fp) != NULL){
            if (count == lineNumber){
                ip_address = line;
                break;
            }else{
                //cout << count << endl;
                count++;
            }
        }
    }
    fclose(fp);



    //cout << ip_address;
    string ip = string(ip_address);
    // removes the newline character read in from the file in the ip address string
    ip.erase(remove(ip.begin(), ip.end(), '\n'), ip.end());
    //cout << ip << endl;

    // below forms the command that pushes the file to the device
    char pushcommand[50];
    if(atoi(d.c_str()) >= 11){
        sprintf(pushcommand,"pscp.exe to_push.txt pi@%s:/home/pi/",ip.c_str());
    }else{
        sprintf(pushcommand,"pscp.exe to_push.txt pi@%s:/home/pi/",ip.c_str());
    }

    //cout << pushcommand << endl;
    cout << "Pushing to device..." << endl;
    cout << pushcommand;
    if(system(pushcommand) != 0){ // if the command fails
        return -1;
    }else{ // if the command is successful
        return 0;
    }
}

// method that runs when the Push button is clicked
void NewPatientWindow::on_push_clicked()
{
    // checks to make sure the main fields are filled out
    if(ui->input_patient->text().toStdString().empty()){
        QMessageBox::information(this,"ERROR","Patient Required"); // error message window
        return;
    }
    if(ui->input_owner->text().toStdString().empty()){
        QMessageBox::information(this,"ERROR","Owner Required"); // error message window
        return;
    }
    if(ui->input_treatment->toPlainText().toStdString().empty()){
        QMessageBox::information(this,"ERROR","Treatment Required"); // error message window
        return;
    }

    // if the dog radio button is selected (for dogs)
    int dog;
    if(ui->input_dog->isChecked()){
        // grab all the information from the user and store it is the correct object of the vector
        Dogs *animal = new Dogs; // create a new Dog object
        dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1] = animal; // assign the object to location in the vector
        animal->patient = ui->input_patient->text().toStdString();              // patient name
        animal->owner = ui->input_owner->text().toStdString();                  // owner name
        animal->device = ui->input_device->text().toStdString();                // device number
        animal->medication = ui->input_medication->toPlainText().toStdString(); // medications
        animal->treatment = ui->input_treatment->toPlainText().toStdString();   // treatment
        animal->food = ui->input_food->text().toStdString();                    // food name
        animal->own_food = ui->food_checkbox->isChecked();                      // own food
        animal->food_amount = ui->input_food_amount->text().toStdString();      // food amount
        animal->leash = ui->leash_checkbox->isChecked();                        // leash
        animal->toys = ui->toys_checkbox->isChecked();                          // toys
        animal->bed_blanket = ui->bed_blanket_checkbox->isChecked();            // bed/blanket
        animal->carrier = ui->carrier_checkbox->isChecked();                    // carrier
        dog = 1;
    }else{ // (for cats)
        // grab all the information from the user and store it is the correct object of the vector
        Cats *animal = new Cats; // create a new Cat object
        //cout << "cat created" << endl;
        //cout << atoi(ui->input_device->text().toStdString().c_str())-11 << endl;
        cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11] = animal; // assign the object to location in the vector
        //cout << "Success" << endl;
        animal->patient = ui->input_patient->text().toStdString();              // patient name
        animal->owner = ui->input_owner->text().toStdString();                  // owner name
        animal->device = ui->input_device->text().toStdString();                // device number
        animal->medication = ui->input_medication->toPlainText().toStdString(); // medications
        animal->treatment = ui->input_treatment->toPlainText().toStdString();   // treatment
        animal->food = ui->input_food->text().toStdString();                    // food name
        animal->own_food = ui->food_checkbox->isChecked();                      // own food
        animal->food_amount = ui->input_food_amount->text().toStdString();      // food amount
        animal->leash = ui->leash_checkbox->isChecked();                        // leash
        animal->toys = ui->toys_checkbox->isChecked();                          // toys
        animal->bed_blanket = ui->bed_blanket_checkbox->isChecked();            // bed/blanket
        animal->carrier = ui->carrier_checkbox->isChecked();                    // carrier
        dog = 0;
    }

    // the dogs devices go from 1 to 10 and the cats go from 11 to 20, so this checks to make sue the device inputted is correct based on animal type
    char file_name[20];
    if(dog == 1){
        if(((atoi(ui->input_device->text().toStdString().c_str()))>10) | (atoi(ui->input_device->text().toStdString().c_str())<0)){
            QMessageBox::information(this,"ERROR","For Dogs: Device must be from 1 to 10");
            return;
        }
        sprintf(file_name,"Data/Dogs/dog_%d.txt",atoi(ui->input_device->text().toStdString().c_str()));
    }else{
        if((atoi(ui->input_device->text().toStdString().c_str())>20) | (atoi(ui->input_device->text().toStdString().c_str())<11)){
            QMessageBox::information(this,"ERROR","For Cats: Device must be from 11 to 20");
            return;
        }
        sprintf(file_name,"Data/Cats/cat_%d.txt",atoi(ui->input_device->text().toStdString().c_str()));
    }


    // open the patients file and write all the inputted information to it
    FILE *file = fopen(file_name,"w");
    if(file == NULL){
        QMessageBox::information(this,"ERROR","Error opening file to write too");
    }
    // for a dog
    if(dog == 1){
        fprintf(file,"%s\n",dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->patient.c_str());
        fprintf(file,"%s\n",dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->owner.c_str());
        fprintf(file,"%s\n",dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->medication.c_str());
        fprintf(file,"%s\n",dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->treatment.c_str());
        fprintf(file,"%s\n",dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->food.c_str());
        if(dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->own_food){
            fprintf(file,"1\n");
        }else{
            fprintf(file,"0\n");
        }
        fprintf(file,"%s\n",dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->food_amount.c_str());
        if(dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->leash){
            fprintf(file,"1\n");
        }else{
            fprintf(file,"0\n");
        }
        if(dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->toys){
            fprintf(file,"1\n");
        }else{
            fprintf(file,"0\n");
        }
        if(dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->bed_blanket){
            fprintf(file,"1\n");
        }else{
            fprintf(file,"0\n");
        }
        if(dog_vec[atoi(ui->input_device->text().toStdString().c_str()-1)]->carrier){
            fprintf(file,"1\n");
        }else{
            fprintf(file,"0\n");
        }
        // for a cat
    }else{
        fprintf(file,"%s\n",cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11]->patient.c_str());
        fprintf(file,"%s\n",cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11]->owner.c_str());
        fprintf(file,"%s\n",cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11]->medication.c_str());
        fprintf(file,"%s\n",cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11]->treatment.c_str());
        fprintf(file,"%s\n",cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11]->food.c_str());
        if(cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11]->own_food){
            fprintf(file,"1\n");
        }else{
            fprintf(file,"0\n");
        }
        fprintf(file,"%s\n",cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11]->food_amount.c_str());
        if(cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11]->leash){
            fprintf(file,"1\n");
        }else{
            fprintf(file,"0\n");
        }
        if(cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11]->toys){
            fprintf(file,"1\n");
        }else{
            fprintf(file,"0\n");
        }
        if(cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11]->bed_blanket){
            fprintf(file,"1\n");
        }else{
            fprintf(file,"0\n");
        }
        if(dog_vec[atoi(ui->input_device->text().toStdString().c_str()-11)]->carrier){
            fprintf(file,"1\n");
        }else{
            fprintf(file,"0\n");
        }
    }
    fclose(file);


    // below copies the file to a different name in order to be pushed to the device

    std::ifstream infile (file_name,std::ifstream::binary);
    std::ofstream outfile ("to_push.txt",std::ofstream::binary);

     // get size of file current file
     infile.seekg (0,infile.end);
     long size = infile.tellg();
     infile.seekg (0);

     char* buffer = new char[size];
     infile.read (buffer,size); // read line
     outfile.write (buffer,size); // write line
     delete[] buffer; //free buffer
     outfile.close();
     infile.close();



    // tries to push the file to the device
    if(pushInfo(ui->input_device->text().toStdString()) == -1){
        QMessageBox::information(this,"ERROR","Error pushing to device.");
    }else{
        QMessageBox::information(this,"Complete","Info Pushed Successfully");
        NewPatientWindow::close();
    }
}

