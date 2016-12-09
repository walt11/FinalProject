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
// QWidget is a class specific to Qt for the NewPatient Window user interface
NewPatientWindow::NewPatientWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewPatientWindow)
{
    ui->setupUi(this); // telling Qt to setup the user interface
}

// NewPatientWindow Constructor for editing the information of a current patient
// QWidget is a class specific to Qt for the NewPatient Window user interface
NewPatientWindow::NewPatientWindow(QWidget *parent, QString device) : QWidget(parent),ui(new Ui::NewPatientWindow)
{
    //cout << edit << endl;
    edit = 1; // keeps track of if a patient is being edited rather than being added
    char file_name[30];
    ui->setupUi(this); // tell Qt to setup user interface
       ui->input_device->setText(device);                                   // set the device field

       if(atoi(device.toStdString().c_str()) < 11){ //is a dog
           cout << "is dog" << endl;
           sprintf(file_name,"Data/Dogs/dog_%d.txt",atoi(device.toStdString().c_str()));
           FILE *f = fopen(file_name,"r");
           if(f != NULL){ // in order to push the edited patient, a file cannot exists
                          // because loadNew_dog handles everything based on if a file for that
                          // is present or not
               remove(file_name);
           }
           fclose(f);
           if(dog_vec[atoi((device).toStdString().c_str())-1] == NULL){
               cout << "Device not found" << endl;
               return;
           }
           Dogs *animal = dog_vec[atoi(device.toStdString().c_str())-1];    // assign the object to location in the vector
           ui->input_dog->setChecked(true);                                 // set whether the patient is a dog or cat
           ui->input_patient->setText(animal->patient.c_str());             // set patient name
           ui->input_owner->setText(animal->owner.c_str());                 // set owner name
                           // device number
           ui->input_medication->appendPlainText(animal->medication.c_str()); // set medications
           ui->input_treatment->appendPlainText(animal->treatment.c_str());   // set treatment
           if(animal->own_food == true){                                      // set food checkbox
               ui->food_checkbox->setChecked(1);
           }else{
               ui->food_checkbox->setChecked(0);
           }
           ui->input_food->setText(animal->food.c_str());                    // set food name
           ui->input_food_amount->setText(animal->food_amount.c_str());      // set food amount
           if(animal->leash == true)                                         // set leash checkbox
               ui->leash_checkbox->setChecked(1);
           else
               ui->leash_checkbox->setChecked(0);
           if(animal->toys == true)                                          // set toys checkbox
               ui->toys_checkbox->setChecked(1);
           else
               ui->toys_checkbox->setChecked(0);
           if(animal->bed_blanket == true)                                   // set bed_blanket checkbox
               ui->bed_blanket_checkbox->setChecked(1);
           else
               ui->bed_blanket_checkbox->setChecked(0);
           if(animal->carrier == true)                                        // set carrier checkbox
               ui->carrier_checkbox->setChecked(1);
           else
               ui->carrier_checkbox->setChecked(0);

           //delete dog_vec[atoi(device.toStdString().c_str())-1];
           //dog_vec[atoi(device.toStdString().c_str())-1] = NULL;
       }
       else{ // *** is a cat - only thing different than above is the vector used ***
           sprintf(file_name,"Data/Dogs/dog_%d.txt",atoi(device.toStdString().c_str()));
           FILE *f = fopen(file_name,"r");
           if(f != NULL){ // in order to push the edited patient, a file cannot exists
                          // because loadNew_cat handles everything based on if a file for that
                          // is present or not
               remove(file_name);
               fclose(f);
           }

           if(cat_vec[atoi((device).toStdString().c_str())-11] == NULL){
               cout << "Device not found" << endl;
               return;
           }
           Cats *animal = cat_vec[atoi(device.toStdString().c_str())-11];
           ui->input_cat->setChecked(true);
           ui->input_patient->setText(animal->patient.c_str());
           ui->input_owner->setText(animal->owner.c_str());
           ui->input_medication->appendPlainText(animal->medication.c_str());
           ui->input_treatment->appendPlainText(animal->treatment.c_str());
           if(animal->own_food == true){
               ui->food_checkbox->setChecked(1);
           }else{
               ui->food_checkbox->setChecked(0);
           }
           ui->input_food->setText(animal->food.c_str());
                              // own food
           ui->input_food_amount->setText(animal->food_amount.c_str());
           if(animal->leash == true)
               ui->leash_checkbox->setChecked(1);
           else
               ui->leash_checkbox->setChecked(0);
           if(animal->toys == true)
               ui->toys_checkbox->setChecked(1);
           else
               ui->toys_checkbox->setChecked(0);
           if(animal->bed_blanket == true)
               ui->bed_blanket_checkbox->setChecked(1);
           else
               ui->bed_blanket_checkbox->setChecked(0);
           if(animal->carrier == true)
               ui->carrier_checkbox->setChecked(1);
           else
               ui->carrier_checkbox->setChecked(0);
           //delete cat_vec[atoi(device.toStdString().c_str())-11];
           //cat_vec[atoi(device.toStdString().c_str())-11] = NULL;
       }
}


//NewPatientWindow Destructor
NewPatientWindow::~NewPatientWindow()
{
    delete ui;
}

// This function pushes the patients file to the device given
int NewPatientWindow::pushInfo(string d,char *file_name){

    // make a copy of the patients file
    std::ifstream infile (file_name,std::ifstream::binary); // open patient file
    std::ofstream outfile ("to_push.txt",std::ofstream::binary); // open the file that is pushed to the device

    // get the length of the patient file
    infile.seekg (0,infile.end);
    long size = infile.tellg();
    infile.seekg (0);

    char* data = new char[size]; // stores file content
    infile.read (data,size);    // reads in the patient file
    outfile.write (data,size);  // writes to the file to be pushed
    delete[] data; // deletes the data variable
    outfile.close(); // close files
    infile.close();
    cout << "file copied" << endl;
    char *ip_address;
    // opens the file containing the ip addresses
    FILE *fp = fopen("Data/device_ips.txt","r");

    // loops through to find the correct ip address associated to the device given
    if ( fp != NULL )
    {
        int lineNumber = atoi(d.c_str())*2; // skip over each cage number to every ip address in the file
        int count = 1;
        char line[20];
        // loop to the correct cage
        while (fgets(line, sizeof(line), fp) != NULL){
            if (count == lineNumber){
                ip_address = line;
                break;
            }else{
                //cout << count << endl;
                count++;
            }
        }
        // make sure that the default ip address is not there
        if(strcmp(ip_address, "0.0.0.0\n") == 0){
            QMessageBox::information(this,"ERROR","No IP Address Found");
            return -1;
        }
        //cout << ip_address << endl;

    }else{ // otherwise the "device_ips.txt" file could not be found
        QMessageBox::information(this,"ERROR","Ip Address File not Found");
        return -1;
    }
    fclose(fp);

    string ip = string(ip_address); //  convert the ip address to a string
    // removes the newline character read in from the file in the ip address string
    ip.erase(remove(ip.begin(), ip.end(), '\n'), ip.end());

    // below forms the command that pushes the file to the device
    char pushcommand[50];
    if(atoi(d.c_str()) >= 11){
        sprintf(pushcommand,"pscp.exe to_push.txt pi@%s:/home/pi/",ip.c_str());
    }else{
        sprintf(pushcommand,"pscp.exe to_push.txt pi@%s:/home/pi/",ip.c_str());
    }

    // try to run the command
    if(system(pushcommand) != 0){ // if the command fails
        return -1;
    }else{ // if the command is successful
        return 0;
    }
}

// method that runs when the Push button is clicked
void NewPatientWindow::on_push_clicked()
{
     cout << "in push clicked" << endl;
    // checks to make sure the main fields are filled out
    try{
         cout << "input empty" << endl;
        if(ui->input_patient->text().toStdString().empty()){
            throw(-1);
        }
        cout << "owner empty" << endl;
        if(ui->input_owner->text().toStdString().empty()){
            throw(-1);
        }
        cout << "treatment empty" << endl;
        if(ui->input_treatment->toPlainText().toStdString().empty()){
            throw(-1);
        }
    }
    catch(int){
        QMessageBox::information(this,"ERROR","Patient,Owner, Treatment, and Device\nFields Required");
        return;
    }

    // check to make sure that when a dog is selected, a correct device number is entered (1 to 10), or if a cat is selected (11 to 20)
    char file_name[20];
    try{
       if(ui->input_dog->isChecked()){ // if dog
            int devicenum = atoi(ui->input_device->text().toStdString().c_str());//convert string to int to get device num
            if(devicenum > 10 || devicenum < 1) // invalid device num for dogs
                throw(devicenum); // throw error
            if(loadNew_dog() == -1){ // load the dog into vector
                return;
            }
            sprintf(file_name,"Data/Dogs/dog_%d.txt",atoi(ui->input_device->text().toStdString().c_str()));
            writeDogToFile(file_name); // write dog to file
            cout << "wrote dog to file" << endl;

        }else{ // if cat

           int devicenum = atoi(ui->input_device->text().toStdString().c_str());
           if(devicenum > 20 || devicenum < 11)
                throw(devicenum); // throw error

         sprintf(file_name,"Data/Cats/cat_%d.txt",atoi(ui->input_device->text().toStdString().c_str()));
         cout << " load cat" << endl;
         if(loadNew_cat() == -1){ //  load cat into vector
             //cout << "cat loaded" << endl;
             return;
         }
         cout << "write cat" << endl;
         writeCatToFile(file_name); // write cat to file
         cout << "wrote cat" << endl;
         cout << "Wrote cat to file" << endl;
        }
    }
    catch(int){
        QMessageBox::information(this,"ERROR","Dogs must go from 1 to 10\nCats must go from 11 to 20");
            return;
    }

    cout << "Trying to push" << endl;
    // tries to push the file to the device
    if(pushInfo(ui->input_device->text().toStdString(),file_name) == -1){
        QMessageBox::information(this,"ERROR","Error pushing to device.");
        NewPatientWindow::close();
    }else{
        QMessageBox::information(this,"Complete","Info Pushed Successfully");
        NewPatientWindow::close();
    }
}

// method to load dog object into vector
int NewPatientWindow::loadNew_dog(){
    char file_name[30];
    Dogs *animal = NULL;
    // If there is no Object in the index in the vector, create a new object
    if(dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1] == NULL){
        //cout << "creating new dog" << endl;
        animal = new Dogs; // create a new Dog object
        dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1] = animal; // assign the object to location in the vector
    }else{
        sprintf(file_name,"Data/Dogs/dog_%d.txt",atoi(ui->input_device->text().toStdString().c_str()));
        ifstream ifile(file_name);

        // when a patient is deleted in mainwindow, it only deletes the file and not the object in the vector - below checks to see if the patients file
        // has been deleted or not
        // if it has, then animal just set to point to the current object that already exists to change the values in it
        // if it hasn't, then an error is displayed because that device is still assigned a patient
        if (!ifile) {
            ifile.close();
            cout << "file not found but patient associated to device" << endl;
            animal = dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1];
        }else if(edit == 1){ // if the user is editing the patient, we still want to be able to push the edited patient without the error below being triggered
            animal = dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1];
            edit = 0;
        }else{
            // There is already a patient associated to that device
            QMessageBox::information(this,"ERROR","There is a patient in that kennel\nPlease choose another");
            return -1;
        }
    }
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

// method to load cat object into vector
int NewPatientWindow::loadNew_cat(){
    char file_name[30];
    Cats *animal = NULL;
    // If there is no Object in the index in the vector, create a new object
    if(cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11] == NULL){
        animal = new Cats; // create a new cat object
        cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11] = animal; // assign the object to location in the vector
    }else{ // if there is already a patient object in that index
        sprintf(file_name,"Data/Cats/cat_%d.txt",atoi(ui->input_device->text().toStdString().c_str()));

        // when a patient is deleted in mainwindow, it only deletes the file and not the object in the vector - below checks to see if the patients file
        // has been deleted or not
        // if it has, then animal just set to point to the current object that already exists to change the values in it
        // if it hasn't, then an error is displayed because that device is still assigned a patient
        ifstream ifile(file_name);
        if (!ifile) {
            ifile.close();
            cout << "file not found but patient associated to device" << endl;
            animal = cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11];
        }else if(edit == 1){ // if the user is editing the patient, we still want to be able to push the edited patient without the error below being triggered
            animal = cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11];
            edit = 0;
        }else{
            QMessageBox::information(this,"ERROR","There is a patient in that kennel\nPlease choose another");
            return -1;
        }
    }

    // grab all the information from the user and store it is the correct object of the vector
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

// This is used to delete the objects in the vectors when the program exits
// It is in this file and not the mainwindow file because of scope issues between
// MainWindow and the two vectors.
void NewPatientWindow::deleteVecs(){
    for(int i=0;i<10;i++){
        if(dog_vec[i] != NULL)
            delete dog_vec[i];
        if(cat_vec[i] != NULL)
            delete cat_vec[i];
    }
}

// method to write dog to file
void NewPatientWindow::writeDogToFile(char *file_name){
    // open file
    FILE *file = fopen(file_name,"w");
    if(file == NULL){
        QMessageBox::information(this,"ERROR","Error opening file to write too");
        return;
    }
    // write patient information to the file
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
    if(dog_vec[atoi(ui->input_device->text().toStdString().c_str())-1]->carrier){
        fprintf(file,"1\n");
    }else{
        fprintf(file,"0\n");
    }
    fclose(file);
}

// write cat to file
void NewPatientWindow::writeCatToFile(char *file_name){
    // open file
    FILE *file = fopen(file_name,"w");
    if(file == NULL){
        QMessageBox::information(this,"ERROR","Error opening file to write too");
        return;
    }
    // write patient information to the file
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
    if(cat_vec[atoi(ui->input_device->text().toStdString().c_str())-11]->carrier){
        fprintf(file,"1\n");
    }else{
        fprintf(file,"0\n");
    }
    fclose(file);
}



