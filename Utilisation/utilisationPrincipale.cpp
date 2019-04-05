/*
 * utilisationPrincipale.cpp
 *
 *  Created on: 2019-03-28
 *      Author: etudiant
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
				cout << "Le(s) nom(s) est(sont) valide(s)" << endl;
			}
		}

		while (identifiantEstValide == false)
		{
			cout << "Entrez le code IBSN de l'ouvrage" << endl;
			getline(cin, identifiantOuvrage);

			if (util::validerCodeIsbn(identifiantOuvrage))
			{
				identifiantEstValide = true;
				cout << "L'identifiant est valide" << endl;
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

			if (anneeOuvrage >= 0)
			{
				anneeEstValide = true;
				cout << "Année valide" << endl;
			}
		}
	cin.ignore();
	Ouvrage ouvrage(nomAuteurOuvrage, titreOuvrage, villeOuvrage, editeurOuvrage, anneeOuvrage, identifiantOuvrage);
	return ouvrage;
}

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
			cout << "Le(s) nom(s) est(sont) valide(s)" << endl;
		}
	}

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

	while (anneeEstValide == false)
	{
		cout << "Entrez l'année de publication du journal" << endl;
		cin >> anneeJournal;

		if (anneeJournal >= 0)
		{
			anneeEstValide = true;
			cout << "Année valide" << endl;
		}
	}

	while (volumeEstValide == false)
	{
		cout << "Entrez le volume de la référence publiée dans le journal" << endl;
		cin >> volumeJournal;
		cin.ignore();

		if (volumeJournal >= 0)
		{
			volumeEstValide = true;
			cout << "Volume valide" << endl;
		}
	}

	while (numeroEstValide == false)
	{
		cout << "Entrez le numero de la référence dans le journal" << endl;
		cin >> numeroJournal;
		cin.ignore();

		if (numeroJournal >= 0)
		{
			numeroEstValide = true;
			cout << "Numero valide" << endl;
		}
	}

	while (pageEstValide == false)
	{
		cout << "Entrez la page où commence la référence publiée dans le journal" << endl;
		cin >> pageJournal;
		cin.ignore();

		if (pageJournal >= 0)
		{
			pageEstValide = true;
			cout << "Page valide" << endl;
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
			cout << "Nom valide" << endl;

		}
	}
	return nomBibliographie;
}



int main()
{
	cout << "Création du premier ouvrage" << endl;
	Ouvrage premierOuvrage = creerOuvrage();
	cout << "Les informations du premier ouvrage sont: " << endl;
	cout << premierOuvrage.reqReferenceFormate() << endl;

	cout << "Création du deuxième ouvrage" << endl;
	Ouvrage deuxiemeOuvrage = creerOuvrage();
	cout << "Les informations du deuxième ouvrage sont: " << endl;
	cout << deuxiemeOuvrage.reqReferenceFormate() << endl;

	cout << "Création du premier journal" << endl;
	Journal premierJournal = creerJournal();
	cout << "Les informations du premier journal sont: " << endl;
	cout << premierJournal.reqReferenceFormate() << endl;

	cout << "Création du deuxième journal" << endl;
	Journal deuxiemeJournal = creerJournal();
	cout << "Les informations du deuxième journal sont: " << endl;
	cout << deuxiemeJournal.reqReferenceFormate() << endl;

	Bibliographie bibliographie(reqNomBibliographie());
	cout << "Création de la bibligraphie ..." << endl;

	cout << "Ajout du premier ouvrage à la bibliographie..." << endl;
	bibliographie.ajouterReference(premierOuvrage);

	cout << "Ajout du deuxième ouvrage à la bibliographie..." << endl;
	bibliographie.ajouterReference(deuxiemeOuvrage);

	cout << "Ajout du premier journal à la bibliographie..." << endl;
	bibliographie.ajouterReference(premierJournal);

	cout << "Ajout deuxieme journal à la bibliographie..." << endl;
	bibliographie.ajouterReference(deuxiemeJournal);

	cout << bibliographie.reqBibliographieFormate() << endl;

	return 0;
}

