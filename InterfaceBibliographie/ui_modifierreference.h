/********************************************************************************
** Form generated from reading UI file 'modifierreference.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFIERREFERENCE_H
#define UI_MODIFIERREFERENCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_modifierReferenceClass
{
public:
    QLineEdit *lineEdit_identifiantModifier;
    QLabel *label;
    QLineEdit *lineEdit_auteursModifier;
    QLabel *label_2;
    QPushButton *pushButton_modifier;

    void setupUi(QDialog *modifierReferenceClass)
    {
        if (modifierReferenceClass->objectName().isEmpty())
            modifierReferenceClass->setObjectName(QString::fromUtf8("modifierReferenceClass"));
        modifierReferenceClass->resize(400, 248);
        lineEdit_identifiantModifier = new QLineEdit(modifierReferenceClass);
        lineEdit_identifiantModifier->setObjectName(QString::fromUtf8("lineEdit_identifiantModifier"));
        lineEdit_identifiantModifier->setGeometry(QRect(60, 70, 271, 27));
        label = new QLabel(modifierReferenceClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 311, 20));
        lineEdit_auteursModifier = new QLineEdit(modifierReferenceClass);
        lineEdit_auteursModifier->setObjectName(QString::fromUtf8("lineEdit_auteursModifier"));
        lineEdit_auteursModifier->setGeometry(QRect(60, 160, 271, 27));
        label_2 = new QLabel(modifierReferenceClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 130, 291, 20));
        pushButton_modifier = new QPushButton(modifierReferenceClass);
        pushButton_modifier->setObjectName(QString::fromUtf8("pushButton_modifier"));
        pushButton_modifier->setGeometry(QRect(160, 200, 80, 28));

        retranslateUi(modifierReferenceClass);

        QMetaObject::connectSlotsByName(modifierReferenceClass);
    } // setupUi

    void retranslateUi(QDialog *modifierReferenceClass)
    {
        modifierReferenceClass->setWindowTitle(QApplication::translate("modifierReferenceClass", "modifierReference", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("modifierReferenceClass", "Entrez le code  ISSN ou ISBN de la r\303\251f\303\251rence \303\240 modifier", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("modifierReferenceClass", "Saisissez le(s) nouveau(x) nom(s) de(s) l'auteur(s)", 0, QApplication::UnicodeUTF8));
        pushButton_modifier->setText(QApplication::translate("modifierReferenceClass", "Modifier", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class modifierReferenceClass: public Ui_modifierReferenceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFIERREFERENCE_H
