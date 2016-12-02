/********************************************************************************
** Form generated from reading UI file 'newpatientwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPATIENTWINDOW_H
#define UI_NEWPATIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewPatientWindow
{
public:
    QGridLayout *gridLayout;
    QRadioButton *input_dog;
    QCheckBox *food_checkbox;
    QPushButton *push;
    QLabel *label;
    QPlainTextEdit *input_treatment;
    QPlainTextEdit *input_medication;
    QCheckBox *leash_checkbox;
    QLineEdit *input_device;
    QLabel *label_4;
    QLabel *label_3;
    QCheckBox *toys_checkbox;
    QCheckBox *bed_blanket_checkbox;
    QLabel *label_5;
    QLineEdit *input_patient;
    QRadioButton *input_cat;
    QLineEdit *input_owner;
    QLabel *label_2;
    QLabel *label_6;
    QLineEdit *input_food;
    QLineEdit *input_food_amount;
    QCheckBox *carrier_checkbox;

    void setupUi(QWidget *NewPatientWindow)
    {
        if (NewPatientWindow->objectName().isEmpty())
            NewPatientWindow->setObjectName(QStringLiteral("NewPatientWindow"));
        NewPatientWindow->resize(673, 479);
        gridLayout = new QGridLayout(NewPatientWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        input_dog = new QRadioButton(NewPatientWindow);
        input_dog->setObjectName(QStringLiteral("input_dog"));
        QFont font;
        font.setPointSize(20);
        input_dog->setFont(font);
        input_dog->setChecked(true);

        gridLayout->addWidget(input_dog, 0, 6, 1, 1);

        food_checkbox = new QCheckBox(NewPatientWindow);
        food_checkbox->setObjectName(QStringLiteral("food_checkbox"));
        food_checkbox->setFont(font);

        gridLayout->addWidget(food_checkbox, 5, 0, 1, 1);

        push = new QPushButton(NewPatientWindow);
        push->setObjectName(QStringLiteral("push"));
        QFont font1;
        font1.setPointSize(16);
        push->setFont(font1);

        gridLayout->addWidget(push, 9, 8, 1, 1);

        label = new QLabel(NewPatientWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        input_treatment = new QPlainTextEdit(NewPatientWindow);
        input_treatment->setObjectName(QStringLiteral("input_treatment"));

        gridLayout->addWidget(input_treatment, 3, 2, 1, 7);

        input_medication = new QPlainTextEdit(NewPatientWindow);
        input_medication->setObjectName(QStringLiteral("input_medication"));

        gridLayout->addWidget(input_medication, 4, 2, 1, 7);

        leash_checkbox = new QCheckBox(NewPatientWindow);
        leash_checkbox->setObjectName(QStringLiteral("leash_checkbox"));
        leash_checkbox->setFont(font);

        gridLayout->addWidget(leash_checkbox, 7, 0, 1, 3);

        input_device = new QLineEdit(NewPatientWindow);
        input_device->setObjectName(QStringLiteral("input_device"));
        input_device->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(input_device, 9, 7, 1, 1);

        label_4 = new QLabel(NewPatientWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 4, 0, 1, 2, Qt::AlignTop);

        label_3 = new QLabel(NewPatientWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 0, 1, 2, Qt::AlignTop);

        toys_checkbox = new QCheckBox(NewPatientWindow);
        toys_checkbox->setObjectName(QStringLiteral("toys_checkbox"));
        toys_checkbox->setFont(font);

        gridLayout->addWidget(toys_checkbox, 8, 0, 1, 1);

        bed_blanket_checkbox = new QCheckBox(NewPatientWindow);
        bed_blanket_checkbox->setObjectName(QStringLiteral("bed_blanket_checkbox"));
        bed_blanket_checkbox->setFont(font);

        gridLayout->addWidget(bed_blanket_checkbox, 9, 0, 1, 4);

        label_5 = new QLabel(NewPatientWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font2;
        font2.setPointSize(18);
        label_5->setFont(font2);

        gridLayout->addWidget(label_5, 9, 5, 1, 2, Qt::AlignRight);

        input_patient = new QLineEdit(NewPatientWindow);
        input_patient->setObjectName(QStringLiteral("input_patient"));
        input_patient->setMinimumSize(QSize(250, 0));
        input_patient->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(input_patient, 0, 2, 1, 4);

        input_cat = new QRadioButton(NewPatientWindow);
        input_cat->setObjectName(QStringLiteral("input_cat"));
        input_cat->setFont(font);

        gridLayout->addWidget(input_cat, 0, 7, 1, 1);

        input_owner = new QLineEdit(NewPatientWindow);
        input_owner->setObjectName(QStringLiteral("input_owner"));

        gridLayout->addWidget(input_owner, 2, 2, 1, 4);

        label_2 = new QLabel(NewPatientWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_6 = new QLabel(NewPatientWindow);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 5, 4, 1, 1);

        input_food = new QLineEdit(NewPatientWindow);
        input_food->setObjectName(QStringLiteral("input_food"));

        gridLayout->addWidget(input_food, 5, 1, 1, 3);

        input_food_amount = new QLineEdit(NewPatientWindow);
        input_food_amount->setObjectName(QStringLiteral("input_food_amount"));

        gridLayout->addWidget(input_food_amount, 5, 5, 1, 2);

        carrier_checkbox = new QCheckBox(NewPatientWindow);
        carrier_checkbox->setObjectName(QStringLiteral("carrier_checkbox"));
        carrier_checkbox->setFont(font);

        gridLayout->addWidget(carrier_checkbox, 6, 0, 1, 1);


        retranslateUi(NewPatientWindow);

        QMetaObject::connectSlotsByName(NewPatientWindow);
    } // setupUi

    void retranslateUi(QWidget *NewPatientWindow)
    {
        NewPatientWindow->setWindowTitle(QApplication::translate("NewPatientWindow", "Add New Patient", 0));
        input_dog->setText(QApplication::translate("NewPatientWindow", "Dog", 0));
        food_checkbox->setText(QApplication::translate("NewPatientWindow", "Food:", 0));
        push->setText(QApplication::translate("NewPatientWindow", "Push", 0));
        label->setText(QApplication::translate("NewPatientWindow", "Patient:", 0));
        leash_checkbox->setText(QApplication::translate("NewPatientWindow", "Leash", 0));
        label_4->setText(QApplication::translate("NewPatientWindow", "Medication:", 0));
        label_3->setText(QApplication::translate("NewPatientWindow", "Treatment:", 0));
        toys_checkbox->setText(QApplication::translate("NewPatientWindow", "Toys", 0));
        bed_blanket_checkbox->setText(QApplication::translate("NewPatientWindow", "Bed/Blanket", 0));
        label_5->setText(QApplication::translate("NewPatientWindow", "Device:", 0));
        input_cat->setText(QApplication::translate("NewPatientWindow", "Cat", 0));
        label_2->setText(QApplication::translate("NewPatientWindow", "Owner:", 0));
        label_6->setText(QApplication::translate("NewPatientWindow", "Amount:", 0));
        carrier_checkbox->setText(QApplication::translate("NewPatientWindow", "Carrier", 0));
    } // retranslateUi

};

namespace Ui {
    class NewPatientWindow: public Ui_NewPatientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPATIENTWINDOW_H
