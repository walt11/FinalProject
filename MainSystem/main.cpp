// This program uses pscp.exe which we did not create. It can be found at: http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html

#include "mainwindow.h"
#include "newpatientwindow.h"
#include <QApplication>
#include <vector>
#include <windows.h>

vector<Dogs*> dog_vec(10);
vector<Cats*> cat_vec(10);

//MainWindow w;

bool dirExists(const std::string& dirName_in)
{
  DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
  if (ftyp == INVALID_FILE_ATTRIBUTES)
    return false;  //something is wrong with your path!

  if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
    return true;   // this is a directory!

  return false;    // this is not a directory!
}

int main(int argc, char *argv[])
{
    // This is for Qt to setup the application
    QApplication a(argc, argv);
    // Create a mainwindow object
    MainWindow w;

    // builds the database if not found
    if(!dirExists("Data")){
        cout << "Making directory" << endl;
        system("mkdir Data");
        system("mkdir Data\\Dogs");
        system("mkdir Data\\Cats");
    }else{
        cout << "Creating Dogs directory" << endl;
        if(!dirExists("Data\\Dogs")){
           system("mkdir Data\\Dogs");
        }
        cout << "Creating Dats directory" << endl;
        if(!dirExists("Data\\Cats")){
            system("mkdir Data\\Cats");
        }
    }

    // load all of the dogs into memory
    string x;
    char *file_name;
    for(int i = 0;i<10;i++){
        sprintf(file_name,"Data/Dogs/dog_%d.txt",i+1);
        Dogs *animal = new Dogs;
        dog_vec[i] = animal;
        ifstream file(file_name);
        if (!file){
            //cout << file_name << " not found" << endl;
            dog_vec[i] = NULL;
         }else{
          // read in all of the patient information
            //cout << file_name << " found" << endl;
            getline(file,animal->patient);
            //cout << animal->patient << endl;
            //cout << dog_vec[i]->patient << endl;
            //cout << "Patient read in" << endl;
            getline(file,animal->owner);
            getline(file,animal->medication);
            getline(file,animal->treatment);
            getline(file,animal->food);
            getline(file,x);
            if(atoi(x.c_str()) == 1){
                animal->own_food = true;
            }
            getline(file,animal->food_amount);
            getline(file,x);
            if(atoi(x.c_str()) == 1){
                animal->leash = true;
            }
            getline(file,x);
            if(atoi(x.c_str()) == 1){
                animal->toys = true;
            }
            getline(file,x);
            if(atoi(x.c_str()) == 1){
                animal->bed_blanket = true;
            }
        }
    }

    // load all of the cats into memory
    for(int i = 0;i<10;i++){
        sprintf(file_name,"Data/Cats/cat_%d.txt",i+11);
        Cats *animal = new Cats;
        cat_vec[i] = animal;
        ifstream file(file_name);
        if (!file){
            //cout << file_name << " not found" << endl;
            cat_vec[i] = NULL;
         }else{
          // read in all of the patient information
            //cout << file_name << " found" << endl;
            getline(file,animal->patient);
            //cout << animal->patient << endl;
            //cout << cat_vec[i]->patient << endl;
            //cout << "Patient read in" << endl;
            getline(file,animal->owner);
            getline(file,animal->medication);
            getline(file,animal->treatment);
            getline(file,animal->food);
            getline(file,x);
            if(atoi(x.c_str()) == 1){
                animal->own_food = true;
            }
            getline(file,animal->food_amount);
            getline(file,x);
            if(atoi(x.c_str()) == 1){
                animal->leash = true;
            }
            getline(file,x);
            if(atoi(x.c_str()) == 1){
                animal->toys = true;
            }
            getline(file,x);
            if(atoi(x.c_str()) == 1){
                animal->bed_blanket = true;
            }
        }
    }


    w.show();
    return a.exec();
}
