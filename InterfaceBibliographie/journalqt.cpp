#include "journalqt.h"
#include "validationFormat.h"
#include <qmessagebox.h>

JournalQt::JournalQt(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton_ajouterJournal, SIGNAL(clicked()), this, SLOT(validerSaisie()));
}

JournalQt::~JournalQt()
{

}

std::string JournalQt::reqAuteurs() const
{
	return ui.lineEdit_auteurJournal->text().toStdString();
}

std::string JournalQt::reqTitre() const
{
	return ui.lineEdit_titreJournal->text().toStdString();
}

std::string JournalQt::reqNom() const
{
	return ui.lineEdit_nomJournal->text().toStdString();
}

int JournalQt::reqVolume() const
{
	return ui.spinBox_volumeJournal->value();
}

int JournalQt::reqNumero() const
{
	return ui.spinBox_numeroJournal->value();
}

int JournalQt::reqPage() const
{
	return ui.spinBox_pageJournal->value();
}

int JournalQt::reqAnnee() const
{
	return ui.spinBox_anneeJournal->value();
}

std::string JournalQt::reqIdentifiant() const
{
	return ui.lineEdit_identifiantJournal->text().toStdString();
}

void JournalQt::validerSaisie()
{
	if (ui.lineEdit_auteurJournal->text().isEmpty())
	{
		QString message = "Le nom du ou des auteurs ne doit pas être vide";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	if (!(util::validerFormatNom(this->reqAuteurs())))
	{
		QString message = "Le nom du ou des auteurs doit être dans un format valide";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	if (ui.lineEdit_titreJournal->text().isEmpty())
	{
		QString message = "Le titre ne doit pas être vide";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	if (ui.lineEdit_nomJournal->text().isEmpty())
	{
		QString message = "Le nom du journal ne doit pas être vide ";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	if (this->reqVolume() < 0)
	{
		QString message = "Le numéro de volume doit être plus grand ou égal à 0";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	if (this->reqNumero() < 0)
	{
		QString message = "Le numéro du journal doit être plus grand ou égal à 0";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	if (this->reqPage() <= 0)
	{
		QString message = "Le numéro de la page doit être plus grand que 0";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	if (this->reqAnnee() < 0)
	{
		QString message = "L'année doit être plus grande ou égale à 0";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	if (!(util::validerCodeIssn(this->reqIdentifiant())))
	{
		QString message = "Le code ISSN de l'identifiant n'est pas valide";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	else{
		accept();
	}
}
