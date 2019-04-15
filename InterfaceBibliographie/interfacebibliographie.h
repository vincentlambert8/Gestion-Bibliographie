#ifndef INTERFACEBIBLIOGRAPHIE_H
#define INTERFACEBIBLIOGRAPHIE_H

#include <QtGui/QMainWindow>
#include "ui_interfacebibliographie.h"
#include "Reference.h"
#include "ReferenceException.h"
#include "Bibliographie.h"

class InterfaceBibliographie : public QMainWindow
{
    Q_OBJECT

public:
    InterfaceBibliographie(QWidget *parent = 0, std::string p_nomBibliographie = "Bibliographie");
    ~InterfaceBibliographie();

private slots:
	void ajouterOuvrage();
	void enregistrerOuvrage(const std::string& p_auteurs,
							const std::string& p_titre,
							const std::string& p_ville,
							const std::string& p_editeur,
							int p_annee,
							const std::string& p_identifiant);
	bool verifierReferenceDejaPresente(const std::string& p_identifiant);
	void ajouterJournal();
	void enregistrerJournal(const std::string& p_auteurs,
							const std::string& p_titre,
							const std::string& p_nom,
							int p_volume,
							int p_numero,
							int p_page,
							int p_annee,
							const std::string& p_identifiant);
	void afficherBibliographie();
	void supprimerUneReference();
	void enregistrerSuppressionReference(const std::string& p_identifiant);
	bool verifierReferenceAbsente(const std::string& p_identifiant);

private:
    Ui::InterfaceBibliographieClass ui;
    biblio::Bibliographie m_bibliographie;
};

#endif // INTERFACEBIBLIOGRAPHIE_H
