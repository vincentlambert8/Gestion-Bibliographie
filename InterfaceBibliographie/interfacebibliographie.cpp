#include "interfacebibliographie.h"
#include "ouvrageqt.h"
#include "Ouvrage.h"
#include "journalqt.h"
#include "Journal.h"
#include "supprimerreference.h"
#include "Bibliographie.h"
#include <qmessagebox.h>


using namespace biblio;
using namespace std;

InterfaceBibliographie::InterfaceBibliographie(QWidget *parent, string p_nomBibliographie)
    : QMainWindow(parent), m_bibliographie(p_nomBibliographie)
{
	ui.setupUi(this);
	QObject::connect(ui.actionOuvrage, SIGNAL(triggered()), this, SLOT(ajouterOuvrage()));
	QObject::connect(ui.actionJournal, SIGNAL(triggered()), this, SLOT(ajouterJournal()));
	QObject::connect(ui.pushButton_afficherBiblio, SIGNAL(clicked()), this, SLOT(afficherBibliographie()));
	QObject::connect(ui.actionSupprimer, SIGNAL(triggered()), this, SLOT(supprimerUneReference()));
}

InterfaceBibliographie::~InterfaceBibliographie()
{

}

void InterfaceBibliographie::ajouterOuvrage(){
	OuvrageQt ouvrageQt;
	if(ouvrageQt.exec())
		{
			enregistrerOuvrage(	ouvrageQt.reqAuteurs(), ouvrageQt.reqTitre(),
								ouvrageQt.reqVille(), ouvrageQt.reqEditeur(),
								ouvrageQt.reqAnnee(), ouvrageQt.reqIdentifiant());
		}
}

void InterfaceBibliographie::enregistrerOuvrage(const std::string& p_auteurs,
												const std::string& p_titre,
												const std::string& p_ville,
												const std::string& p_editeur,
												int p_annee,
												const std::string& p_identifiant)
{
	try{
		Ouvrage ouvrage(p_auteurs, p_titre, p_ville, p_editeur, p_annee, p_identifiant);
		if (verifierReferenceDejaPresente(ouvrage.reqIdentifiant()))
		{
			throw ReferenceDejaPresenteException("La référence est déjà présente dans la bibliographie");
		}
		else
		{
			m_bibliographie.ajouterReference(ouvrage);
		}
	}catch(const ReferenceDejaPresenteException& p_e){
		QString message(p_e.what());
		QMessageBox::information(this, "Message d'erreur", message);
	}
}

void InterfaceBibliographie::ajouterJournal(){
	JournalQt journalQt;
	if (journalQt.exec())
		{
			enregistrerJournal(	journalQt.reqAuteurs(), journalQt.reqTitre(), journalQt.reqNom(), journalQt.reqVolume(),
								journalQt.reqNumero(), journalQt.reqPage(), journalQt.reqAnnee(),
								journalQt.reqIdentifiant());
		}
}

void InterfaceBibliographie::enregistrerJournal(const std::string& p_auteurs,
												const std::string& p_titre,
												const std::string& p_nom,
												int p_volume,
												int p_numero,
												int p_page,
												int p_annee,
												const std::string& p_identifiant)
{
	try{
		Journal journal(p_auteurs, p_titre, p_nom, p_volume, p_numero, p_page, p_annee, p_identifiant);
		if (verifierReferenceDejaPresente(journal.reqIdentifiant()))
		{
			throw ReferenceDejaPresenteException("La référence est déjà présente dans la bibliographie");
		}
		else
		{
			m_bibliographie.ajouterReference(journal);
		}
	}catch(const ReferenceDejaPresenteException& p_e){
		QString message(p_e.what());
		QMessageBox::information(this, "Message d'erreur", message);
	}
}

bool InterfaceBibliographie::verifierReferenceDejaPresente(const std::string& p_identifiant)
{
	bool estDejaPresente = false;
	for (size_t i = 0; i < (m_bibliographie.reqVecteur()).size(); i++)
	{
		if ((m_bibliographie.reqVecteur())[i]->reqIdentifiant() == p_identifiant)
		{
			estDejaPresente = true;
		}
	}
	return estDejaPresente;
}

void InterfaceBibliographie::afficherBibliographie()
{
	QString q(QString::fromStdString(m_bibliographie.reqBibliographieFormate()));
	ui.textEdit->setText(q);
}

void InterfaceBibliographie::supprimerUneReference()
{
	supprimerReference supprimerQt;
	if (supprimerQt.exec())
	{
		enregistrerSuppressionReference(supprimerQt.reqIdentifiant());
	}

}

void InterfaceBibliographie::enregistrerSuppressionReference(const string& p_identifiant)
{
	try{
		if (verifierReferenceAbsente(p_identifiant))
		{
			throw ReferenceAbsenteException("La référence est absente de la bibliographie");
		}
		else
		{
			m_bibliographie.supprimerReference(p_identifiant);
		}
	}catch(const ReferenceAbsenteException& p_e){
		QString message(p_e.what());
		QMessageBox::information(this, "Message d'erreur", message);
	}
}

bool InterfaceBibliographie::verifierReferenceAbsente(const string& p_identifiant)
{
	bool estAbsente = true;
	for (size_t i = 0; i < (m_bibliographie.reqVecteur()).size(); i++)
	{
		if ((m_bibliographie.reqVecteur())[i]->reqIdentifiant() == p_identifiant)
		{
			estAbsente = false;
		}
	}
	return estAbsente;

}
