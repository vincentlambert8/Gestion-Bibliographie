#include "modifierreference.h"
#include "validationFormat.h"
#include <qmessagebox.h>

using namespace std;

modifierReference::modifierReference(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton_modifier, SIGNAL(clicked()), this, SLOT(validerModifier()));
}

modifierReference::~modifierReference()
{

}

string modifierReference::reqIdentifiant() const
{
	return ui.lineEdit_identifiantModifier->text().toStdString();
}

string modifierReference::asgAuteurs()
{
	return ui.lineEdit_auteursModifier->text().toStdString();
}

void modifierReference::validerModifier()
{
	if (ui.lineEdit_identifiantModifier->text().isEmpty())
	{
		QString message = "L'identifiant ne doit pas être vide";
		QMessageBox::information(this, "Message d'erreur", message);
		return;
	}
	else if (ui.lineEdit_auteursModifier->text().isEmpty())
	{
		QString message = "L'identifiant ne doit pas être vide";
		QMessageBox::information(this, "Message d'erreur", message);
		return;
	}
	else if (!(util::validerFormatNom(ui.lineEdit_auteursModifier->text().toStdString())))
	{
		QString message = "Le(s) nom(s) de(s) auteur(s) est invalide";
		QMessageBox::information(this, "Message d'erreur", message);
		return;
	}

	std::string code = (ui.lineEdit_identifiantModifier->text().toStdString()).substr(0, 4);

	if (code == "ISBN")
	{
		if (!(util::validerCodeIsbn(this->reqIdentifiant())))
		{
			QString message = "L'identifiant ISBN entré n'est pas dans un format valide";
			QMessageBox::information(this, "Message d'erreur", message);
			return;
		}
		else{
			accept();
		}
	}

	if (code == "ISSN")
	{
		if (!(util::validerCodeIssn(this->reqIdentifiant())))
		{
			QString message = "L'identifiant ISSN entré n'est pas dans un format valide";
			QMessageBox::information(this, "Message d'erreur", message);
			return;
		}
		else{
			accept();
		}
	}
	else{
		accept();
	}
}
