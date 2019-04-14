#ifndef OUVRAGEQT_H
#define OUVRAGEQT_H

#include <QtGui/QDialog>
#include "ui_ouvrageqt.h"
#include <string>

class OuvrageQt : public QDialog
{
    Q_OBJECT

public:
    OuvrageQt(QWidget *parent = 0);
    ~OuvrageQt();
    std::string reqAuteurs() const;
    std::string reqTitre() const;
    std::string reqVille() const;
    std::string reqEditeur() const;
    int reqAnnee() const;
    std::string reqIdentifiant() const;

private slots:
	void validerSaisie();

private:
    Ui::OuvrageQtClass ui;
};

#endif // OUVRAGEQT_H
