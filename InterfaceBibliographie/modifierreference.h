#ifndef MODIFIERREFERENCE_H
#define MODIFIERREFERENCE_H

#include <QtGui/QDialog>
#include "ui_modifierreference.h"
#include <string>

class modifierReference : public QDialog
{
    Q_OBJECT

public:
    modifierReference(QWidget *parent = 0);
    ~modifierReference();
    std::string reqIdentifiant() const;
    std::string asgAuteurs();

private slots:
	void validerModifier();

private:
    Ui::modifierReferenceClass ui;
};

#endif // MODIFIERREFERENCE_H
