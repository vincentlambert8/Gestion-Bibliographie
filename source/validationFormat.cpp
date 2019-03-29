/**
 * \file validationFormat.cpp
 * \brief Implementation des fonctions du namespace 'util'
 * \author Toma Gagne
 * \version 1
 * \date 27 fevrier 2019
 */

#include "validationFormat.h"

using namespace std;

namespace util {

/**
 * \fn bool validerFormatNom(const string& p_nom)
 * \brief Fonction qui valide le format du nom entrée par l'utilisateur
 *
 * \param[in] L'entrée p_nom est la chaine entrée par l'utilisateur
 * \post p_nom n'est pas composé que d'espace
 * \post p_nom ne comporte pas de chiffre
 * \post p_nom ne possède pas de caractères spéciaux
 * \return un booléen, vrai si p_nom possède un format valide
 */
bool validerFormatNom(const string& p_nom)
{
	int longueurNom = p_nom.length();
	bool validationNom = true;
	{
		for (int i = 0; i < longueurNom; i++)
		{

			if (p_nom.at(0) == ' ')
			{
				validationNom = false;
				break;
			}

			else if (p_nom.at(i) == ' ')
			{
				continue;
			}
			else if (!(isalpha(p_nom.at(i))))
			{
				validationNom = false;
				break;
			}
		}
	}
	return validationNom;
}

/**
 * \fn bool validerCodeIssn(const string& p_issn)
 * \brief Fonction qui valide si le code ISSN entré par l'utilisateur est un code valide
 * \param[in] L'entrée p_issn est la chaîne représentant le code ISSN entré par l'utilisateur
 * \post L'entrée p_issn est un code ISSN valide
 * \return Un booléen, vrai si p_issn est un code ISSN valide
 */
bool validerCodeIssn(const string& p_issn)
{
	bool validationCode = true;

	istringstream is_chaine (p_issn);


	string acronyme;
	is_chaine >> acronyme;
	if (acronyme != "ISSN")
	{
		validationCode = false;
	}

	string groupeChiffre;
	is_chaine >> groupeChiffre;
	int longueurCode = groupeChiffre.length();

	if (longueurCode != 9)
	{
		validationCode = false;
	}

	string codeSansTiret = "";
	if (validationCode)
	{
		for (int i = 0; i < longueurCode; i++)
		{
			if (groupeChiffre.at(i) == '-')
			{
				if (i != 4)
				{
					validationCode = false;
					break;
				}
			}

			else if (0x30 > groupeChiffre.at(i) || groupeChiffre.at(i) > 0x39)
			{
				validationCode = false;
				break;
			}
			else
			{
				codeSansTiret += groupeChiffre.at(i);
			}
		}
	}

	if (validationCode)
	{
		if (!(util::verifierCleIssn(codeSansTiret)))
		{
			validationCode = false;
		}
	}
	return validationCode;
}


/**
 * \fn bool validerCodeIsbn(const string& p_ibsn)
 * \brief Fonction qui valide si le code ISBN entré par l'utilisateur est un code valide
 * \param[in] L'entrée p_isbn est la chaîne représentant le code ISBN entré par l'utilisateur
 * \post L'entrée p_isbn est un code ISBN valide
 * \return Un booléen, vrai si p_issn est un code ISBN valide
 */
bool validerCodeIsbn(const string& p_isbn)
{
	bool validation = true;
	istringstream is_chaine(p_isbn);

	string acronyme;
	is_chaine >> acronyme;
	if (acronyme != "ISBN")
	{
		return false;
	}

	string groupeChiffre;
	is_chaine >> groupeChiffre;
	int longueurCode = groupeChiffre.length();

	if (longueurCode == 13)
	{
		if (!(util::validerFormatIsbn10(groupeChiffre, longueurCode)))
		{
			validation = false;
		}
	}

	else if (longueurCode == 17)
	{
		if (!(util::validerFormatIsbn13(groupeChiffre, longueurCode)))
		{
			validation = false;
		}
	}

	else
	{
		validation = false;
	}

	return validation;
}

/**
 * \fn bool validerFormatIsbn10(const string& p_isbn10, int p_longueurCode)
 * \brief Fonction qui valide si le format du code ISBN 10 entré par l'utilisateur est valide
 * \param[in] L'entrée p_isbn10 est la chaîne représentant le code ISSN entré par l'utilisateur
 * \param[in] L'entrée p_longueurCode est le nombre de caractère de la chaîne p_isbn10
 * \post L'entrée p_isbn10 possède le bon format d'un code isbn 10 standard
 * \return Un booléen, vrai si p_isbn10 est un code ISBN10 valide
 */
bool validerFormatIsbn10(const string& p_isbn10, int p_longueurCode)
{
	bool validation = true;
	int nombreTiret = 0;
	string codeSansTiret = "";

	for (int i = 0; i < p_longueurCode; i++)
	{
		if (p_isbn10.at(i) == '-')
		{
			nombreTiret++;
		}

		else if ((0x30 > p_isbn10.at(i) || p_isbn10.at(i) > 0x39) && p_isbn10.at(i) != 'X')
		{
			validation = false;
			break;
		}
		else
		{
			codeSansTiret += p_isbn10.at(i);
		}
	}

	if (nombreTiret != 3)
	{
		validation = false;
	}

	if (validation)
	{
		if (!(util::verifierCleIsbn10(codeSansTiret)))
		{
			validation = false;
		}
	}
	return validation;
}

/**
 * \fn bool validerFormatIsbn13(const string& p_isbn13, int p_longueurCode)
 * \brief Fonction qui valide si le format du code ISBN 13 entré par l'utilisateur est valide
 * \param[in] L'entrée p_isbn13 est la chaîne représentant le code ISSN entré par l'utilisateur
 * \param[in] L'entrée p_longueurCode est le nombre de caractère de la chaîne p_isbn13
 * \post L'entrée p_isbn13 possède le bon format d'un code isbn 13 standard
 * \return Un booléen, vrai si p_isbn13 est un code ISBN10 valide
 */
bool validerFormatIsbn13(const string& p_isbn13, int p_longueurCode)
{
	bool validation = true;
	int nombreTiret = 0;
	string codeSansTiret = "";

	for (int i = 0; i < p_longueurCode; i++)
	{
		if (p_isbn13.at(i) == '-')
		{
			nombreTiret++;
		}

		else if (0x30 > p_isbn13.at(i) || p_isbn13.at(i) > 0x39)
		{
			validation = false;
			break;
		}

		else
		{
			codeSansTiret += p_isbn13.at(i);
		}
	}

	if (nombreTiret != 4)
	{
		validation = false;
	}

	if (validation)
	{
		if (!(util::verifierCleIsbn13(codeSansTiret)))
		{
			validation = false;
		}
	}
	return validation;
}


/**
 * \fn bool verifierCleIssn(const string& chiffreSansTiret)
 * \brief Fonction qui valide si la clé du code ISSN entrée par l'utilisateur est valide
 * \param[in] L'entrée chiffreSansTiret est la chaîne représentant le code ISSN entré par l'utilisateur, sans tiret
 * \post La clé du code ISSN entrée par l'utilisateur est valide
 * \return Un booléen, vrai si la clé du code ISSN est valide
 */
bool verifierCleIssn(const string& chiffreSansTiret)
{
	bool validationCle = true;
	int somme = 0;

	for (int j = 8; j >= 2; j--)
	{
		somme += (chiffreSansTiret.at(8-j)- '0') * j;
	}

	int dernierChiffre = chiffreSansTiret.at(7) - '0';
	int resultatCle = 11 - (somme % 11);
	if (dernierChiffre != resultatCle)
	{
		validationCle = false;
	}
	return validationCle;
}

/**
 * \fn bool verifierCleIsbn10(const string& p_isbn10)
 * \brief Fonction qui valide si la clé du code ISBN 10 entrée par l'utilisateur est valide
 * \param[in] L'entrée p_isbn10 est la chaîne représentant le code ISBN 10 entrée par l'utilisateur, sans tiret
 * \post La clé du code ISBN 10 entrée par l'utilisateur est valide
 * \return Un booléen, vrai si la clé du code ISBN 10 est valide
 */
bool verifierCleIsbn10(const string& p_isbn10)
{
	bool validationCle = true;
	char dernierChiffre = p_isbn10.at(9);
	int somme = 0;

	if ((dernierChiffre < '0' || dernierChiffre > '9') && (dernierChiffre != 'X'))
	{
		validationCle = false;
	}

	if (validationCle)
	{
		for (int i = 10; i >= 2; i--)
		{
			somme += ((p_isbn10.at(10 - i) - '0') * i);
		}

		int resultat = somme % 11;

		if (dernierChiffre == 'X')
		{
			if ((resultat + 10) % 11 !=0)
			{
				validationCle = false;
			}

		}

		else
		{
			if ((resultat + (dernierChiffre - '0')) % 11 != 0)
			{
				validationCle = false;
			}
		}
	}

	return validationCle;
}

/**
 * \fn bool verifierCleIsbn13(const string& p_isbn13)
 * \brief Fonction qui valide si la clé du code ISBN 13 entrée par l'utilisateur est valide
 * \param[in] L'entrée p_isbn13 est la chaîne représentant le code ISBN 13 entrée par l'utilisateur, sans tiret
 * \post La clé du code ISBN 13 entrée par l'utilisateur est valide
 * \return Un booléen, vrai si la clé du code ISBN 13 est valide
 */
bool verifierCleIsbn13(const string& p_isbn13)
{
	bool validationCle = true;
	char dernierChiffre = p_isbn13.at(12);
	int somme = 0;

	if ((dernierChiffre < '0' || dernierChiffre > '9'))
	{
		validationCle = false;
	}

	if (validationCle)
	{
		for (int i = 0; i < 12; i++)
		{
			if (i % 2 == 0)
			{
				somme += p_isbn13.at(i) - '0';
			}
			else
			{
				somme += (p_isbn13.at(i) - '0') * 3;
			}
		}

		int resultat = somme % 10;
		int cleRes = 10 - resultat;
		int cle = dernierChiffre - '0';

		if (resultat == 0)
		{
			if (cle != 0)
			{
				validationCle = false;
			}
		}

		else if (resultat != 0)
		{
			if (cle != cleRes)
			{
				validationCle = false;
			}
		}
	}
	return validationCle;
}

}
