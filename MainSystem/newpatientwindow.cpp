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
    //cout << "New patient window clicked" << endl;
       ui->input_device->setText(device);
       if(atoi(device.toStdString().c_str()) < 11){//is a dog
           cout << atoi((device).toStdString().c_str()) << endl;
           if(dog_vec[atoi((device).toStdString().c_str())-1] == NULL){
               cout << "Device not found" << endl;
               return;
           }
           Dogs *animal = dog_vec[atoi(device.toStdString().c_str())-1];    // assign the object to location in the vector
           ui->input_dog->setChecked(true);
           ui->input_patient->setText(animal->patient.c_str());                     // patient name
           ui->input_owner->setText(animal->owner.c_str());                  // owner name
                           // device number
           ui->input_medication->appendPlainText(animal->medication.c_str()); // medications
           ui->input_treatment->appendPlainText(animal->treatment.c_str());   // treatment
           if(animal->own_food == true){
               ui->food_checkbox->setChecked(1);
           }else{
               ui->food_checkbox->setChecked(0);
           }
           ui->input_food->setText(animal->food.c_str());                    // food name
                              // own food
           ui->input_food_amount->setText(animal->food_amount.c_str());      // food amount
           if(animal->leash == true)                                        // leash
               ui->leash_checkbox->setChecked(1);
           else
               ui->leash_checkbox->setChecked(0);
           if(animal->toys == true)                                        // toys
               ui->toys_checkbox->setChecked(1);
           else
               ui->toys_checkbox->setChecked(0);
           if(animal->bed_blanket == true)                                        // bed_blanket
               ui->bed_blanket_checkbox->setChecked(1);
           else
               ui->bed_blanket_checkbox->setChecked(0);
           if(animal->carrier == true)                                        // carrier
               ui->carrier_checkbox->setChecked(1);
           else
               ui->carrier_checkbox->setChecked(0);
       }
       else{
           if(cat_vec[atoi((device).toStdString().c_str())-11] == NULL){
               cout << "Device not found" << endl;
               return;
           }
           Cats *animal = cat_vec[atoi(device.toStdString().c_str())-11];    // assign the object to location in the vector
           ui->input_cat->setChecked(true);
           ui->input_patient->setText(animal->patient.c_str());                     // patient name
           ui->input_owner->setText(animal->owner.c_str());                  // owner name
                           // device number
           ui->input_medication->appendPlainText(animal->medication.c_str()); // medications
           ui->input_treatment->appendPlainText(animal->treatment.c_str());   // treatment
           if(animal->own_food == true){
               ui->food_checkbox->setChecked(1);
           }else{
               ui->food_checkbox->setChecked(0);
           }
           ui->input_food->setText(animal->food.c_str());                    // food name
                              // own food
           ui->input_food_amount->setText(animal->food_amount.c_str());      // food amount
           if(animal->leash == true)                                        // leash
               ui->leash_checkbox->setChecked(1);
           else
               ui->leash_checkbox->setChecked(0);
           if(animal->toys == true)                                        // toys
               ui->toys_checkbox->setChecked(1);
           else
               ui->toys_checkbox->setChecked(0);
           if(animal->bed_blanket == true)                                        // bed_blanket
               ui->bed_blanket_checkbox->setChecked(1);
           else
               ui->bed_blanket_checkbox->setChecked(0);
           if(animal->carrier == true)                                        // carrier
               ui->carrier_checkbox->setChecked(1);
           else
               ui->carrier_checkbox->setChecked(0);
       }



}


//NewPatientWindow Destructor
NewPatientWindow::~NewPatientWindow()
{
    //cout << "Goodbye newpatientwindow" << endl;
    delete ui;
}

// This function pushes the patients file to the device given
int NewPatientWindow::pushInfo(string d,char *file_name){
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



    //cout << d << endl;
    //cout << "Getting IP Address..." << endl;
    char *ip_address;
    // opens the file containing the ip addresses
    FILE *fp = fopen("Data/device_ips.txt","r");

    // loops through to find the correct ip address associated to the device given
    if ( fp != NULL )
    {
        int lineNumber = atoi(d.c_str())*2;
        int count = 1;
        char line[20];
        while (fgets(line, sizeof(line), fp) != NULL){
            if (count == lineNumber){
                ip_address = line;
                break;
            }else{
                //cout << count << endl;
                count++;
            }
        }
        if(strcmp(ip_address, "0.0.0.0\n") == 0){
            QMessageBox::information(this,"ERROR","No IP Address Found");
            return -1;
        }
        //cout << ip_address << endl;
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
    //cout << "Pushing to device..." << endl;
    //cout << pushcommand;
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
    try{
    if(ui->input_patient->text().toStdString().empty()){
        throw(-1);
    }
    if(ui->input_owner->text().toStdString().empty()){
        throw(-1);
    }
    if(ui->input_treatment->toPlainText().toStdString().empty()){
       throw(-1);
    }
    }
    catch(int){
        QMessageBox::information(this,"ERROR","Patient,Owner, Treatment, and Device\nFields Required");
        return;
    }

    char file_name[20];
    try{
       if(ui->input_dog->isChecked()){
            int devicenum = atoi(ui->input_device->text().toStdString().c_str());//convert string to int to get device num
            if(devicenum > 10 || devicenum < 1)//invalid device num for dogs
                throw(devicenum);//throw in
            if(loadNew_dog() == -1){
                return;
            }
            sprintf(file_name,"Data/Dogs/dog_%d.txt",atoi(ui->input_device->text().toStdString().c_str()));
            writeDogToFile(file_name);

        }else{

           int devicenum = atoi(ui->input_device->text().toStdString().c_str());
           if(devicenum > 20 || devicenum < 11)
                throw(devicenum);

         sprintf(file_name,"Data/Cats/cat_%d.txt",atoi(ui->input_device->text().toStdString().c_str()));
         if(loadNew_cat() == -1){
             return;
         }
         writeCatToFile(file_name);
        }
    }
    catch(int){
        QMessageBox::information(this,"ERROR","Dogs must go from 1 to 10\nCats must go from 11 to 20");
            return;
    }

    // tries to push the file to the device
    if(pushInfo(ui->input_device->text().toStdString(),file_name) == -1){
        QMessageBox::information(this,"ERROR","Error pushing to device.");
    }else{
        QMessageBox::information(this,"Complete","Info Pushed Successfully");
        NewPatientWindow::close();
    }
}

int NewPatientWindow::loadNew_dog(){
    Dogs *animal = NULL;
    // If there is no Object in the index in the vector, create a new object
    if(dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1] == NULL){
        //cout << "creating new dog" << endl;
        animal = new Dogs; // create a new Dog object
        dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1] = animal; // assign the object to location in the vector
    }else{
        // There is already a patient associated to that device
        QMessageBox::information(this,"ERROR","There is a patient in that kennel\nPlease choose another");
        return -1;
        //animal = dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1];
    }
    //dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1] = animal; // assign the object to location in the vector
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
    return 0;
}
int NewPatientWindow::loadNew_cat(){
    //cout << "in cats" << endl;
    Cats *animal = NULL;
    // If there is no Object in the index in the vector, create a new object
    if(cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11] == NULL){
        //cout << " *******creating new cat*********" << endl;
        animal = new Cats; // create a new cat object
        cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11] = animal; // assign the object to location in the vector
    }else{
        QMessageBox::information(this,"ERROR","There is a patient in that kennel\nPlease choose another");
        return -1;
        //cout << "******** cat in that location exists ********" << endl;
        //animal = cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11];
    }

    // grab all the information from the user and store it is the correct object of the vector

    //cout << "cat created" << endl;
    //cout << atoi(ui->input_device->text().toStdString().c_str())-11 << endl;
    //cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11] = animal; // assign the object to location in the vector
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
    return 0;
}

void NewPatientWindow::writeDogToFile(char *file_name){

    FILE *file = fopen(file_name,"w");
    if(file == NULL){
        QMessageBox::information(this,"ERROR","Error opening file to write too");
        return;
    }

    //cout << "writing dog to file" << endl;
    fprintf(file,"%s\n",dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->patient.c_str());
    //cout << "owner" << endl;
    fprintf(file,"%s\n",dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->owner.c_str());
    //cout << "meds" << endl;
    fprintf(file,"%s\n",dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->medication.c_str());
    //cout << "treatment" << endl;
    fprintf(file,"%s\n",dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->treatment.c_str());
    //cout << "food" << endl;
    fprintf(file,"%s\n",dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->food.c_str());

    if(dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->own_food){
        fprintf(file,"1\n");
    }else{
        fprintf(file,"0\n");
    }
    //cout << "food amount" << endl;
    fprintf(file,"%s\n",dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->food_amount.c_str());
    //cout << "leash" << endl;
    if(dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->leash){
        fprintf(file,"1\n");
    }else{
        fprintf(file,"0\n");
    }
    //cout << "toys" << endl;
    if(dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->toys){
        fprintf(file,"1\n");
    }else{
        fprintf(file,"0\n");
    }
    //cout << "bed" << endl;
    if(dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->bed_blanket){
        fprintf(file,"1\n");
    }else{
        fprintf(file,"0\n");
    }
    //cout << "carrier" << endl;
    if(dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->carrier){
        fprintf(file,"1\n");
    }else{
        fprintf(file,"0\n");
    }
    //cout << "dog done" << endl;
    fclose(file);
}

void NewPatientWindow::writeCatToFile(char *file_name){

    FILE *file = fopen(file_name,"w");
    if(file == NULL){
        QMessageBox::information(this,"ERROR","Error opening file to write too");
        return;
    }

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
    if(dog_vec[atoi(ui->input_device->text().toStdString().c_str())-11]->carrier){
        fprintf(file,"1\n");
    }else{
        fprintf(file,"0\n");
    }
    fclose(file);
}



