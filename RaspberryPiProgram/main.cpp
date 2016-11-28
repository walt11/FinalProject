// John Walter and Evan Schulte
// ECE 3220 - Final Project

// This program is intendted to be ran on a raspberry pi and needs the Qt framework to compile

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	// create application
    QApplication a(argc, argv);
    MainWindow w; // create mainWindow object
    w.setStyleSheet("background-color:black"); // make background color black
    w.showFullScreen(); // show application full screen

    return a.exec();
}
