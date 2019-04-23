/********************************************************************************
** Form generated from reading UI file 'interfacebibliographie.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACEBIBLIOGRAPHIE_H
#define UI_INTERFACEBIBLIOGRAPHIE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceBibliographieClass
{
public:
    QAction *actionOuvrage;
    QAction *actionJournal;
    QAction *actionSupprimer;
    QAction *actionModifier;
    QWidget *centralwidget;
    QPushButton *Quitter;
    QTextEdit *textEdit;
    QPushButton *pushButton_afficherBiblio;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuAjouter_une_r_f_rence;
    QMenu *menuSupprimerReference;
    QMenu *menuModifier_une_r_f_rence;

    void setupUi(QMainWindow *InterfaceBibliographieClass)
    {
        if (InterfaceBibliographieClass->objectName().isEmpty())
            InterfaceBibliographieClass->setObjectName(QString::fromUtf8("InterfaceBibliographieClass"));
        InterfaceBibliographieClass->resize(761, 421);
        actionOuvrage = new QAction(InterfaceBibliographieClass);
        actionOuvrage->setObjectName(QString::fromUtf8("actionOuvrage"));
        actionJournal = new QAction(InterfaceBibliographieClass);
        actionJournal->setObjectName(QString::fromUtf8("actionJournal"));
        actionSupprimer = new QAction(InterfaceBibliographieClass);
        actionSupprimer->setObjectName(QString::fromUtf8("actionSupprimer"));
        actionModifier = new QAction(InterfaceBibliographieClass);
        actionModifier->setObjectName(QString::fromUtf8("actionModifier"));
        centralwidget = new QWidget(InterfaceBibliographieClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Quitter = new QPushButton(centralwidget);
        Quitter->setObjectName(QString::fromUtf8("Quitter"));
        Quitter->setGeometry(QRect(650, 330, 80, 28));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 50, 721, 261));
        pushButton_afficherBiblio = new QPushButton(centralwidget);
        pushButton_afficherBiblio->setObjectName(QString::fromUtf8("pushButton_afficherBiblio"));
        pushButton_afficherBiblio->setGeometry(QRect(290, 10, 171, 28));
        InterfaceBibliographieClass->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(InterfaceBibliographieClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        InterfaceBibliographieClass->setStatusBar(statusbar);
        menubar = new QMenuBar(InterfaceBibliographieClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 761, 25));
        menuAjouter_une_r_f_rence = new QMenu(menubar);
        menuAjouter_une_r_f_rence->setObjectName(QString::fromUtf8("menuAjouter_une_r_f_rence"));
        menuSupprimerReference = new QMenu(menubar);
        menuSupprimerReference->setObjectName(QString::fromUtf8("menuSupprimerReference"));
        menuModifier_une_r_f_rence = new QMenu(menubar);
        menuModifier_une_r_f_rence->setObjectName(QString::fromUtf8("menuModifier_une_r_f_rence"));
        InterfaceBibliographieClass->setMenuBar(menubar);

        menubar->addAction(menuAjouter_une_r_f_rence->menuAction());
        menubar->addAction(menuSupprimerReference->menuAction());
        menubar->addAction(menuModifier_une_r_f_rence->menuAction());
        menuAjouter_une_r_f_rence->addAction(actionOuvrage);
        menuAjouter_une_r_f_rence->addAction(actionJournal);
        menuSupprimerReference->addAction(actionSupprimer);
        menuModifier_une_r_f_rence->addAction(actionModifier);

        retranslateUi(InterfaceBibliographieClass);
        QObject::connect(Quitter, SIGNAL(clicked()), InterfaceBibliographieClass, SLOT(close()));

        QMetaObject::connectSlotsByName(InterfaceBibliographieClass);
    } // setupUi

    void retranslateUi(QMainWindow *InterfaceBibliographieClass)
    {
        InterfaceBibliographieClass->setWindowTitle(QApplication::translate("InterfaceBibliographieClass", "Interface TP4", 0, QApplication::UnicodeUTF8));
        actionOuvrage->setText(QApplication::translate("InterfaceBibliographieClass", "Ajouter un ouvrage", 0, QApplication::UnicodeUTF8));
        actionJournal->setText(QApplication::translate("InterfaceBibliographieClass", "Ajouter un journal", 0, QApplication::UnicodeUTF8));
        actionSupprimer->setText(QApplication::translate("InterfaceBibliographieClass", "Supprimer", 0, QApplication::UnicodeUTF8));
        actionModifier->setText(QApplication::translate("InterfaceBibliographieClass", "Modifier", 0, QApplication::UnicodeUTF8));
        Quitter->setText(QApplication::translate("InterfaceBibliographieClass", "Quitter", 0, QApplication::UnicodeUTF8));
        pushButton_afficherBiblio->setText(QApplication::translate("InterfaceBibliographieClass", "Afficher la bibliographie", 0, QApplication::UnicodeUTF8));
        menuAjouter_une_r_f_rence->setTitle(QApplication::translate("InterfaceBibliographieClass", "Ajouter une r\303\251f\303\251rence", 0, QApplication::UnicodeUTF8));
        menuSupprimerReference->setTitle(QApplication::translate("InterfaceBibliographieClass", "Supprimer une r\303\251f\303\251rence", 0, QApplication::UnicodeUTF8));
        menuModifier_une_r_f_rence->setTitle(QApplication::translate("InterfaceBibliographieClass", "Modifier une r\303\251f\303\251rence", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InterfaceBibliographieClass: public Ui_InterfaceBibliographieClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACEBIBLIOGRAPHIE_H
