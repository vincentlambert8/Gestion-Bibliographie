/**
 * \file gestionBibliographie.cpp
 * \brief fichier principal pour gérer 2 ouvrages et 2 journaux dans une bibliographie
 * \author Toma Gagne
 * \version 1
 * \date 10 avril 2019
 */

#include "Reference.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "Bibliographie.h"
#include "validationFormat.h"
#include <iostream>
#include <string>

using namespace std;
using namespace biblio;


/**
 * \fn Ouvrage creerOuvrage()
 * \brief Fonction permettant de construire un objet Ouvrage
 *
 * \return Un objet ouvrage si les données entrées par l'utilisateur sont valides
 */
Ouvrage creerOuvrage()
{
	string nomAuteurOuvrage;
	string titreOuvrage;
	string villeOuvrage;
	string editeurOuvrage;
	int anneeOuvrage;
	string identifiantOuvrage;

	bool nomEstValide = false;
	bool identifiantEstValide = false;
	bool titreEstValide = false;
	bool anneeEstValide = false;
	bool villeEstValide = false;
	bool editeurEstValide = false;

	while (nomEstValide == false)
	{
		cout << "Entrez le nom du ou des auteurs" << endl;
		getline(cin, nomAuteurOuvrage);

		if (util::validerFormatNom(nomAuteurOuvrage))
		{
			nomEstValide = true;
			cout << "Nom(s) valide(s)" << endl;
		}
	}

	while (titreEstValide == false)
	{
		cout << "Entrez le nom de l'ouvrage" << endl;
		getline(cin, titreOuvrage);

		if (util::validerFormatNom(titreOuvrage))
		{
			titreEstValide = true;
			cout << "Titre valide" << endl;
		}
	}

	while (villeEstValide == false)
	{
		cout << "Entrez le nom de la ville d'édition" << endl;
		getline(cin, villeOuvrage);

		if (util::validerFormatNom(villeOuvrage))
		{
			villeEstValide = true;
			cout << "Ville valide" << endl;
		}
	}

	while (editeurEstValide == false)
	{
		cout << "Entrez le nom de l'éditeur" << endl;
		getline(cin, editeurOuvrage);

		if (util::validerFormatNom(editeurOuvrage))
		{
			editeurEstValide = true;
			cout << "Editeur valide" << endl;
		}
	}

	while (anneeEstValide == false)
	{
		cout << "Entrez l'année d'édition de l'ouvrage" << endl;
		cin >> anneeOuvrage;

		if (cin.fail() || anneeOuvrage <= 0)
		{
			cout << "Année valide" << endl;
			cin.clear();
			cin.ignore();
			continue;
		}
		else
		{
			cout << "Année invalide" << endl;
			anneeEstValide = true;
		}
	}
	cin.ignore();

	while (identifiantEstValide == false)
	{
		cout << "Entrez le code ISBN de l'ouvrage" << endl;
		getline(cin, identifiantOuvrage);

		if (util::validerCodeIsbn(identifiantOuvrage))
		{
			identifiantEstValide = true;
			cout << "L'identifiant est valide" << endl;
		}
	}

	Ouvrage ouvrage(nomAuteurOuvrage, titreOuvrage, villeOuvrage, editeurOuvrage, anneeOuvrage, identifiantOuvrage);
	return ouvrage;
}

/**
 * \fn Journal creerJournal()
 * \brief Fonction permettant de construire un objet Journal
 *
 * \return Un objet journal si les données entrées par l'utilisateur sont valides
 */
Journal creerJournal()
{
	string nomAuteurJournal;
	string titreJournal;
	string nomJournal;
	int volumeJournal;
	int numeroJournal;
	int pageJournal;
	int anneeJournal;
	string identifiantJournal;

	bool auteurEstValide = false;
	bool identifiantEstValide = false;
	bool titreEstValide = false;
	bool nomEstValide = false;
	bool anneeEstValide = false;
	bool volumeEstValide = false;
	bool numeroEstValide = false;
	bool pageEstValide = false;

	while (auteurEstValide == false)
	{
		cout << "Entrez le nom du ou des auteurs" << endl;
		getline(cin, nomAuteurJournal);

		if (util::validerFormatNom(nomAuteurJournal))
		{
			auteurEstValide = true;
			cout << "Nom(s) valide(s)" << endl;
		}
	}

	while (titreEstValide == false)
	{
		cout << "Entrez le titre de la référence dans le journal" << endl;
		getline(cin, titreJournal);

		if (util::validerFormatNom(titreJournal))
		{
			titreEstValide = true;
			cout << "Titre valide" << endl;
		}
	}

	while (nomEstValide == false)
	{
		cout << "Entrez le nom du journal" << endl;
		getline(cin, nomJournal);

		if (util::validerFormatNom(nomJournal))
		{
			nomEstValide = true;
			cout << "Nom valide" << endl;
		}
	}

	while (volumeEstValide == false)
	{
		cout << "Entrez le volume de la référence publiée dans le journal" << endl;
		cin >> volumeJournal;

		if (cin.fail() || volumeJournal < 0)
		{
			cout << "Volume invalide" << endl;
			cin.clear();
			cin.ignore();
			continue;
		}
		else
		{
			cout << "Volume valide" << endl;
			volumeEstValide = true;
		}
	}

	while (numeroEstValide == false)
	{
		cout << "Entrez le numero de la référence dans le journal" << endl;
		cin >> numeroJournal;
		if (cin.fail() || numeroJournal < 0)
		{
			cout << "Numéro invalide" << endl;
			cin.clear();
			cin.ignore();
			continue;
		}
		else
		{
			cout << "Numéro valide" << endl;
			numeroEstValide = true;
		}
	}

	while (pageEstValide == false)
	{
		cout << "Entrez la page où commence la référence publiée dans le journal" << endl;
		cin >> pageJournal;
		if (cin.fail() || pageJournal <= 0)
		{
			cout << "Page invalide" << endl;
			cin.clear();
			cin.ignore();
			continue;
		}
		else
		{
			cout << "Page valide" << endl;
			pageEstValide = true;
		}
	}
	cin.ignore();

	while (anneeEstValide == false)
	{
		cout << "Entrez l'année de publication du journal" << endl;
		cin >> anneeJournal;

		if (cin.fail() || anneeJournal <= 0)
		{
			cout << "Année invalide" << endl;
			cin.clear();
			cin.ignore();
			continue;
		}
		else
		{
			cout << "Année valide" << endl;
			anneeEstValide = true;
		}
	}
	cin.ignore();

	while (identifiantEstValide == false)
	{
		cout << "Entrez le code ISSN du journal" << endl;
		getline(cin, identifiantJournal);

		if (util::validerCodeIssn(identifiantJournal))
		{
			identifiantEstValide = true;
			cout << "L'identifiant est valide" << endl;
		}
	}

	Journal journal(nomAuteurJournal,
					titreJournal,
					nomJournal,
					volumeJournal,
					numeroJournal,
					pageJournal,
					anneeJournal,
					identifiantJournal);
	return journal;
}

/**
 * \fn string reqNomBibliographie()
 * \brief 	Fonction permettant de demander à l'utilisateur le nom de la bibliographie
 * 			qu'il souhaite créer
 *
 * 	\return nomBibliographie, le nom entré par l'utilisateur qui est dans un format valide
 */
string reqNomBibliographie()
{
	string nomBibliographie;
	bool nomEstValide = false;

	while (nomEstValide == false)
	{
		cout << "Entrez le nom de la bibliographie" << endl;
		getline(cin, nomBibliographie);

		if (util::validerFormatNom(nomBibliographie))
		{
			nomEstValide = true;
			cout << "Nom bibliographie valide" << endl;

		}
	}
	return nomBibliographie;
}


/**
 * \fn int main()
 * \brief Entrée du programme
 *
 * \return 0 - Arrêt normal du programme
 */
int main()
{
	Bibliographie bibliographie(reqNomBibliographie());
	cout << "Création de la bibliographie ..." << endl;

	cout << endl << "Ajoutez un premier ouvrage" << endl;
	Ouvrage premierOuvrage = creerOuvrage();
	cout << "Les informations du premier ouvrage sont: " << endl;
	cout << premierOuvrage.reqReferenceFormate() << endl;

	cout << "Ajout du premier ouvrage à la bibliographie..." << endl;
	bibliographie.ajouterReference(premierOuvrage);

	cout << endl << "Ajoutez un deuxième ouvrage" << endl;
	Ouvrage deuxiemeOuvrage = creerOuvrage();
	cout << "Les informations du deuxième ouvrage sont: " << endl;
	cout << deuxiemeOuvrage.reqReferenceFormate() << endl;

	cout << "Ajout du deuxième ouvrage à la bibliographie..." << endl;
	bibliographie.ajouterReference(deuxiemeOuvrage);

	cout << endl << "Ajoutez un premier journal" << endl;
	Journal premierJournal = creerJournal();
	cout << "Les informations du premier journal sont: " << endl;
	cout << premierJournal.reqReferenceFormate() << endl;

	cout << "Ajout du premier journal à la bibliographie..." << endl;
	bibliographie.ajouterReference(premierJournal);

	cout << endl << "Ajoutez un deuxième journal" << endl;
	Journal deuxiemeJournal = creerJournal();
	cout << "Les informations du deuxième journal sont: " << endl;
	cout << deuxiemeJournal.reqReferenceFormate() << endl;

	cout << "Ajout du deuxième journal à la bibliographie..." << endl;
	bibliographie.ajouterReference(deuxiemeJournal);

	cout << endl << "Références bibliographiques enregistrées :" << endl;
	cout << endl << bibliographie.reqBibliographieFormate() << endl;

	cout << "Fin de la bibliographie" << endl;
	cout << "Fin du programme..." << endl;
	return 0;
}
