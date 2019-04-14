/********************************************************************************
** Form generated from reading UI file 'journalqt.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNALQT_H
#define UI_JOURNALQT_H

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

class Ui_JournalQtClass
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_auteurJournal;
    QLineEdit *lineEdit_titreJournal;
    QLineEdit *lineEdit_nomJournal;
    QLineEdit *lineEdit_identifiantJournal;
    QSpinBox *spinBox_anneeJournal;
    QSpinBox *spinBox_pageJournal;
    QSpinBox *spinBox_numeroJournal;
    QSpinBox *spinBox_volumeJournal;
    QPushButton *pushButton_ajouterJournal;

    void setupUi(QDialog *JournalQtClass)
    {
        if (JournalQtClass->objectName().isEmpty())
            JournalQtClass->setObjectName(QString::fromUtf8("JournalQtClass"));
        JournalQtClass->resize(400, 429);
        label = new QLabel(JournalQtClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 70, 141, 16));
        label_2 = new QLabel(JournalQtClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 110, 141, 17));
        label_3 = new QLabel(JournalQtClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 150, 131, 17));
        label_4 = new QLabel(JournalQtClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 190, 55, 17));
        label_5 = new QLabel(JournalQtClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 230, 55, 17));
        label_6 = new QLabel(JournalQtClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 270, 55, 21));
        label_7 = new QLabel(JournalQtClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 310, 55, 17));
        label_8 = new QLabel(JournalQtClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 350, 141, 17));
        label_9 = new QLabel(JournalQtClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 20, 371, 20));
        lineEdit_auteurJournal = new QLineEdit(JournalQtClass);
        lineEdit_auteurJournal->setObjectName(QString::fromUtf8("lineEdit_auteurJournal"));
        lineEdit_auteurJournal->setGeometry(QRect(190, 60, 181, 27));
        lineEdit_titreJournal = new QLineEdit(JournalQtClass);
        lineEdit_titreJournal->setObjectName(QString::fromUtf8("lineEdit_titreJournal"));
        lineEdit_titreJournal->setGeometry(QRect(190, 100, 181, 27));
        lineEdit_nomJournal = new QLineEdit(JournalQtClass);
        lineEdit_nomJournal->setObjectName(QString::fromUtf8("lineEdit_nomJournal"));
        lineEdit_nomJournal->setGeometry(QRect(190, 140, 181, 27));
        lineEdit_identifiantJournal = new QLineEdit(JournalQtClass);
        lineEdit_identifiantJournal->setObjectName(QString::fromUtf8("lineEdit_identifiantJournal"));
        lineEdit_identifiantJournal->setGeometry(QRect(190, 340, 181, 27));
        spinBox_anneeJournal = new QSpinBox(JournalQtClass);
        spinBox_anneeJournal->setObjectName(QString::fromUtf8("spinBox_anneeJournal"));
        spinBox_anneeJournal->setGeometry(QRect(190, 300, 181, 27));
        spinBox_anneeJournal->setMaximum(3000);
        spinBox_anneeJournal->setValue(2019);
        spinBox_pageJournal = new QSpinBox(JournalQtClass);
        spinBox_pageJournal->setObjectName(QString::fromUtf8("spinBox_pageJournal"));
        spinBox_pageJournal->setGeometry(QRect(190, 260, 181, 27));
        spinBox_pageJournal->setMaximum(1000000000);
        spinBox_pageJournal->setValue(1);
        spinBox_numeroJournal = new QSpinBox(JournalQtClass);
        spinBox_numeroJournal->setObjectName(QString::fromUtf8("spinBox_numeroJournal"));
        spinBox_numeroJournal->setGeometry(QRect(190, 220, 181, 27));
        spinBox_numeroJournal->setMaximum(3000);
        spinBox_numeroJournal->setValue(0);
        spinBox_volumeJournal = new QSpinBox(JournalQtClass);
        spinBox_volumeJournal->setObjectName(QString::fromUtf8("spinBox_volumeJournal"));
        spinBox_volumeJournal->setGeometry(QRect(190, 180, 181, 27));
        spinBox_volumeJournal->setMaximum(3000);
        spinBox_volumeJournal->setValue(0);
        pushButton_ajouterJournal = new QPushButton(JournalQtClass);
        pushButton_ajouterJournal->setObjectName(QString::fromUtf8("pushButton_ajouterJournal"));
        pushButton_ajouterJournal->setGeometry(QRect(150, 380, 80, 28));

        retranslateUi(JournalQtClass);

        QMetaObject::connectSlotsByName(JournalQtClass);
    } // setupUi

    void retranslateUi(QDialog *JournalQtClass)
    {
        JournalQtClass->setWindowTitle(QApplication::translate("JournalQtClass", "JournalQt", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("JournalQtClass", "Nom du ou des auteurs", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("JournalQtClass", "Titre de la r\303\251f\303\251rence", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("JournalQtClass", "Nom du journal", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("JournalQtClass", "Volume ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("JournalQtClass", "Num\303\251ro", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("JournalQtClass", "Pages", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("JournalQtClass", "Ann\303\251e", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("JournalQtClass", "Identifiant ISSN", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("JournalQtClass", "Entrez les informations de la r\303\251f\303\251rence apparue dans le journal", 0, QApplication::UnicodeUTF8));
        pushButton_ajouterJournal->setText(QApplication::translate("JournalQtClass", "Ajouter ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class JournalQtClass: public Ui_JournalQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNALQT_H
