/********************************************************************************
** Form generated from reading UI file 'ouvrageqt.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUVRAGEQT_H
#define UI_OUVRAGEQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_OuvrageQtClass
{
public:
    QLineEdit *lineEdit_auteurOuvrage;
    QLineEdit *lineEdit_titreOuvrage;
    QLineEdit *lineEdit_villeOuvrage;
    QLineEdit *lineEdit_editeurOuvrage;
    QLineEdit *lineEdit_identifiantOuvrage;
    QSpinBox *spinBox_anneeOuvrage;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_ajouterOuvrage;

    void setupUi(QDialog *OuvrageQtClass)
    {
        if (OuvrageQtClass->objectName().isEmpty())
            OuvrageQtClass->setObjectName(QString::fromUtf8("OuvrageQtClass"));
        OuvrageQtClass->resize(400, 348);
        lineEdit_auteurOuvrage = new QLineEdit(OuvrageQtClass);
        lineEdit_auteurOuvrage->setObjectName(QString::fromUtf8("lineEdit_auteurOuvrage"));
        lineEdit_auteurOuvrage->setGeometry(QRect(200, 40, 181, 27));
        lineEdit_titreOuvrage = new QLineEdit(OuvrageQtClass);
        lineEdit_titreOuvrage->setObjectName(QString::fromUtf8("lineEdit_titreOuvrage"));
        lineEdit_titreOuvrage->setGeometry(QRect(200, 80, 181, 27));
        lineEdit_villeOuvrage = new QLineEdit(OuvrageQtClass);
        lineEdit_villeOuvrage->setObjectName(QString::fromUtf8("lineEdit_villeOuvrage"));
        lineEdit_villeOuvrage->setGeometry(QRect(200, 120, 181, 27));
        lineEdit_editeurOuvrage = new QLineEdit(OuvrageQtClass);
        lineEdit_editeurOuvrage->setObjectName(QString::fromUtf8("lineEdit_editeurOuvrage"));
        lineEdit_editeurOuvrage->setGeometry(QRect(200, 160, 181, 27));
        lineEdit_identifiantOuvrage = new QLineEdit(OuvrageQtClass);
        lineEdit_identifiantOuvrage->setObjectName(QString::fromUtf8("lineEdit_identifiantOuvrage"));
        lineEdit_identifiantOuvrage->setGeometry(QRect(200, 240, 181, 27));
        spinBox_anneeOuvrage = new QSpinBox(OuvrageQtClass);
        spinBox_anneeOuvrage->setObjectName(QString::fromUtf8("spinBox_anneeOuvrage"));
        spinBox_anneeOuvrage->setGeometry(QRect(200, 200, 181, 27));
        spinBox_anneeOuvrage->setMaximum(3000);
        spinBox_anneeOuvrage->setValue(2019);
        label = new QLabel(OuvrageQtClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 50, 151, 20));
        label_2 = new QLabel(OuvrageQtClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 90, 121, 20));
        label_3 = new QLabel(OuvrageQtClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 130, 131, 20));
        label_4 = new QLabel(OuvrageQtClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 170, 121, 20));
        label_5 = new QLabel(OuvrageQtClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 210, 121, 20));
        label_6 = new QLabel(OuvrageQtClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 250, 121, 20));
        label_7 = new QLabel(OuvrageQtClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 0, 391, 31));
        pushButton_ajouterOuvrage = new QPushButton(OuvrageQtClass);
        pushButton_ajouterOuvrage->setObjectName(QString::fromUtf8("pushButton_ajouterOuvrage"));
        pushButton_ajouterOuvrage->setGeometry(QRect(130, 300, 141, 28));

        retranslateUi(OuvrageQtClass);

        QMetaObject::connectSlotsByName(OuvrageQtClass);
    } // setupUi

    void retranslateUi(QDialog *OuvrageQtClass)
    {
        OuvrageQtClass->setWindowTitle(QApplication::translate("OuvrageQtClass", "OuvrageQt", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OuvrageQtClass", "Nom du ou des auteurs", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("OuvrageQtClass", "Titre de l'ouvrage", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("OuvrageQtClass", "Ville d'\303\251dition", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("OuvrageQtClass", "Nom de l'\303\251diteur", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("OuvrageQtClass", "Ann\303\251e de publication", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("OuvrageQtClass", "Identifiant ISBN", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("OuvrageQtClass", "Ajouter les informations de l'ouvrage \303\240 ajouter \303\240 la bibliographie", 0, QApplication::UnicodeUTF8));
        pushButton_ajouterOuvrage->setText(QApplication::translate("OuvrageQtClass", "Ajouter l'ouvrage", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OuvrageQtClass: public Ui_OuvrageQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUVRAGEQT_H
