/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextBrowser *cat_textbrowser;
    QTextBrowser *dog_textbrowser;
    QPushButton *edit_patient;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_3;
    QPushButton *update;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1216, 560);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        cat_textbrowser = new QTextBrowser(centralWidget);
        cat_textbrowser->setObjectName(QStringLiteral("cat_textbrowser"));
        cat_textbrowser->setMinimumSize(QSize(600, 400));
        cat_textbrowser->setMaximumSize(QSize(600, 400));

        gridLayout->addWidget(cat_textbrowser, 4, 3, 1, 2);

        dog_textbrowser = new QTextBrowser(centralWidget);
        dog_textbrowser->setObjectName(QStringLiteral("dog_textbrowser"));
        dog_textbrowser->setMinimumSize(QSize(600, 400));
        dog_textbrowser->setMaximumSize(QSize(600, 400));

        gridLayout->addWidget(dog_textbrowser, 4, 0, 1, 3);

        edit_patient = new QPushButton(centralWidget);
        edit_patient->setObjectName(QStringLiteral("edit_patient"));

        gridLayout->addWidget(edit_patient, 5, 4, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);

        gridLayout->addWidget(label, 5, 0, 1, 1, Qt::AlignLeft);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 5, 3, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 25));
        label_3->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(label_3, 3, 3, 1, 1);

        update = new QPushButton(centralWidget);
        update->setObjectName(QStringLiteral("update"));

        gridLayout->addWidget(update, 3, 4, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 50));
        label_4->setMaximumSize(QSize(16777215, 50));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 25));
        label_2->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(50, 16777215));
        QFont font2;
        font2.setPointSize(14);
        lineEdit->setFont(font2);

        gridLayout->addWidget(lineEdit, 5, 1, 1, 1, Qt::AlignLeft);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PetView", 0));
        edit_patient->setText(QApplication::translate("MainWindow", "Edit Patient", 0));
        label->setText(QApplication::translate("MainWindow", "Select:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "New Patient", 0));
        label_3->setText(QApplication::translate("MainWindow", "Cats:", 0));
        update->setText(QApplication::translate("MainWindow", "Update", 0));
        label_4->setText(QApplication::translate("MainWindow", "PetView", 0));
        label_2->setText(QApplication::translate("MainWindow", "Dogs:", 0));
        lineEdit->setText(QApplication::translate("MainWindow", "1", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
