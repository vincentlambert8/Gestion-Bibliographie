#ifndef JOURNALQT_H
#define JOURNALQT_H

#include <QtGui/QDialog>
#include "ui_journalqt.h"

class JournalQt : public QDialog
{
    Q_OBJECT

public:
    JournalQt(QWidget *parent = 0);
    ~JournalQt();
    std::string reqAuteurs() const;
	std::string reqTitre() const;
	std::string reqNom() const;
	int reqVolume() const;
	int reqNumero() const;
	int reqPage() const;
	int reqAnnee() const;
	std::string reqIdentifiant() const;

    private slots:
    	void validerSaisie();

private:
    Ui::JournalQtClass ui;
};

#endif // JOURNALQT_H
