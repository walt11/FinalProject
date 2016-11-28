// This program uses pscp.exe which we did not create. It can be found at: http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html

#include "mainwindow.h"
#include "newpatientwindow.h"
#include <QApplication>
#include <vector>

vector<Dogs*> dog_vec(10);
vector<Cats*> cat_vec(10);

int main(int argc, char *argv[])
{
    // This is for Qt to setup the application
    QApplication a(argc, argv);
    // Create a mainwindow object
    MainWindow w;
    // display the main window
    w.show();

    return a.exec();
}
