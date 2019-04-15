/********************************************************************************
** Form generated from reading UI file 'supprimerreference.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERREFERENCE_H
#define UI_SUPPRIMERREFERENCE_H

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

class Ui_supprimerReferenceClass
{
public:
    QLabel *label;
    QLineEdit *lineEdit_identifiantSupprimer;
    QPushButton *pushButton_supprimer;

    void setupUi(QDialog *supprimerReferenceClass)
    {
        if (supprimerReferenceClass->objectName().isEmpty())
            supprimerReferenceClass->setObjectName(QString::fromUtf8("supprimerReferenceClass"));
        supprimerReferenceClass->resize(394, 152);
        label = new QLabel(supprimerReferenceClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 381, 20));
        lineEdit_identifiantSupprimer = new QLineEdit(supprimerReferenceClass);
        lineEdit_identifiantSupprimer->setObjectName(QString::fromUtf8("lineEdit_identifiantSupprimer"));
        lineEdit_identifiantSupprimer->setGeometry(QRect(60, 70, 271, 27));
        pushButton_supprimer = new QPushButton(supprimerReferenceClass);
        pushButton_supprimer->setObjectName(QString::fromUtf8("pushButton_supprimer"));
        pushButton_supprimer->setGeometry(QRect(150, 110, 80, 28));

        retranslateUi(supprimerReferenceClass);

        QMetaObject::connectSlotsByName(supprimerReferenceClass);
    } // setupUi

    void retranslateUi(QDialog *supprimerReferenceClass)
    {
        supprimerReferenceClass->setWindowTitle(QApplication::translate("supprimerReferenceClass", "supprimerReference", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("supprimerReferenceClass", "Entrez le code ISBN ou ISSN de la r\303\251f\303\251rence \303\240 supprimer", 0, QApplication::UnicodeUTF8));
        pushButton_supprimer->setText(QApplication::translate("supprimerReferenceClass", "Supprimer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class supprimerReferenceClass: public Ui_supprimerReferenceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERREFERENCE_H
