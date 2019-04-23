#ifndef SUPPRIMERREFERENCE_H
#define SUPPRIMERREFERENCE_H

#include <QtGui/QDialog>
#include <string>
#include "ui_supprimerreference.h"

class supprimerReference : public QDialog
{
    Q_OBJECT

public:
    supprimerReference(QWidget *parent = 0);
    ~supprimerReference();
    std::string reqIdentifiant() const;

    private slots:
		void validerSupprimer();

private:
    Ui::supprimerReferenceClass ui;
};

#endif // SUPPRIMERREFERENCE_H
