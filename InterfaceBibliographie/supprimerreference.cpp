#include <iostream>
#include "supprimerreference.h"
#include "validationFormat.h"
#include <qmessagebox.h>

using namespace std;

supprimerReference::supprimerReference(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton_supprimer, SIGNAL(clicked()), this, SLOT(validerSupprimer()));
}

supprimerReference::~supprimerReference()
{

}

string supprimerReference::reqIdentifiant() const
{
	return ui.lineEdit_identifiantSupprimer->text().toStdString();
}

void supprimerReference::validerSupprimer()
{
	if (ui.lineEdit_identifiantSupprimer->text().isEmpty())
	{
		QString message = "L'identifiant ne doit pas être vide";
		QMessageBox::information(this, "Message d'erreur", message);
		return;
	}

	std::string code = (ui.lineEdit_identifiantSupprimer->text().toStdString()).substr(0, 4);

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

