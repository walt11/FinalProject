/********************************************************************************
** Form generated from reading UI file 'editpatientwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPATIENTWINDOW_H
#define UI_EDITPATIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditPatientWindow
{
public:

    void setupUi(QWidget *EditPatientWindow)
    {
        if (EditPatientWindow->objectName().isEmpty())
            EditPatientWindow->setObjectName(QStringLiteral("EditPatientWindow"));
        EditPatientWindow->resize(1010, 725);

        retranslateUi(EditPatientWindow);

        QMetaObject::connectSlotsByName(EditPatientWindow);
    } // setupUi

    void retranslateUi(QWidget *EditPatientWindow)
    {
        EditPatientWindow->setWindowTitle(QApplication::translate("EditPatientWindow", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class EditPatientWindow: public Ui_EditPatientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPATIENTWINDOW_H
