#include "ouvrageqt.h"
#include "validationFormat.h"
#include <qmessagebox.h>

OuvrageQt::OuvrageQt(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton_ajouterOuvrage, SIGNAL(clicked()), this, SLOT(validerSaisie()));
}

OuvrageQt::~OuvrageQt()
{

}

std::string OuvrageQt::reqAuteurs() const
{
	return ui.lineEdit_auteurOuvrage->text().toStdString();
}
std::string OuvrageQt::reqTitre() const
{
	return ui.lineEdit_titreOuvrage->text().toStdString();
}
std::string OuvrageQt::reqVille() const
{
	return ui.lineEdit_villeOuvrage->text().toStdString();
}
std::string OuvrageQt::reqEditeur() const
{
	return ui.lineEdit_editeurOuvrage->text().toStdString();
}
int OuvrageQt::reqAnnee() const
{
	return ui.spinBox_anneeOuvrage->value();
}
std::string OuvrageQt::reqIdentifiant() const
{
	return ui.lineEdit_identifiantOuvrage->text().toStdString();
}

void OuvrageQt::validerSaisie()
{
	if (ui.lineEdit_auteurOuvrage->text().isEmpty())
	{
		QString message = "Le nom du ou des auteurs ne doit pas être vide";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	if (!(util::validerFormatNom(this->reqAuteurs())))
	{
		QString message = "Le nom du ou des auteurs doit être dans un format valide";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	if (ui.lineEdit_titreOuvrage->text().isEmpty())
	{
		QString message = "Le titre ne doit pas être vide";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	if (!(util::validerFormatNom(this->reqVille())))
	{
		QString message = "Le nom de la ville doit être dans un format valide";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	if (!(util::validerFormatNom(this->reqEditeur())))
	{
		QString message = "Le nom de l'éditeur doit être dans un format valide";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	if (this->reqAnnee() < 0)
	{
		QString message = "L'année doit être plus grande ou égale à 0";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	if (!(util::validerCodeIsbn(this->reqIdentifiant())))
	{
		QString message = "Le code ISBN de l'identifiant n'est pas valide";
		QMessageBox::information(this, "Message d'erreur", message);
	}

	else{
		accept();
	}
}
