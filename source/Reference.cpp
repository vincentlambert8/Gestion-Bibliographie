/**
 * \file Reference.cpp
 * \brief Implementation des methodes de la classe Reference
 * \author Toma Gagne
 * \version 1
 * \date 22 fevrier 2019
 */

#include "Reference.h"
#include "validationFormat.h"
#include "ContratException.h"
#include <string>

using namespace std;

namespace biblio
{

Reference::Reference(const string& p_auteurs, const string& p_titre, int p_annee, const string& p_identifiant)
: m_auteurs(p_auteurs), m_titre(p_titre), m_annee(p_annee), m_identifiant(p_identifiant)
{
	PRECONDITION(util::validerFormatNom(p_auteurs));
	PRECONDITION(util::validerFormatNom(p_titre));
	PRECONDITION(p_annee >= 0);

	string code = p_identifiant.substr(0, 4);
	if (code == "ISSN") {
		PRECONDITION(util::validerCodeIssn(p_identifiant));
	}
	else if (code == "ISBN"){
		PRECONDITION(util::validerCodeIsbn(p_identifiant));
	}
}

/**
 * \fn Reference::reqAnnee()
 * \brief Methode d'acces en lecture à l'attribut m_annee
 *
 * \return m_annee
 */
int Reference::reqAnnee() const
{
	return m_annee;
}

/**
 * \fn Reference::reqAuteurs()
 * \brief Methode d'acces en lecture à l'attribut m_auteurs
 *
 * \return m_auteurs
 */
const string& Reference::reqAuteurs() const
{
	return m_auteurs;
}

/**
 * \fn Reference::reqIdentifiant()
 * \brief Methode d'acces en lecture à l'attribut m_identifiant
 *
 * \return m_identifiant
 */
const string& Reference::reqIdentifiant() const
{
	return m_identifiant;
}

/**
 * \fn Reference::reqTitre()
 * \brief Methode d'acces en lecture à l'attribut m_titre
 *
 * \return m_titre
 */
const string& Reference::reqTitre() const
{
	return m_titre;
}

/**
 * \fn Reference::reqReferenceFormate()
 * \brief Methode permettant de formater la reference selon ses attributs
 *
 * \return referenceFormatee, qui est la chaine de caracteres de la reference formatee
 */
string Reference::reqReferenceFormate() const
{
	ostringstream s;
	s << m_auteurs << ". " << m_titre << ".";
	string referenceFormatee = s.str();
	return referenceFormatee;
}

/**
 * \fn Reference::asgAuteurs()
 * \brief Methode permettant de modifier les auteurs d'une reference
 * \param[in] p_auteur est le nom de l'auteur ou des auteurs
 * \pre p_auteurs ne doit pas etre nul et doit avoir un format valide
 * \post l'objet courant a été correctement assigne
 * \return m_auteurs
 */
void Reference::asgAuteurs(const string& p_auteurs)
{
	if (util::validerFormatNom(p_auteurs))
	m_auteurs = p_auteurs;
}

/**
 * \fn Reference::operator==()
 * \brief Surcharge de l'operateur "==" pour comparer deux objets Reference
 * \return un booleen
 */
bool Reference::operator==(const Reference& autreReference) const
{
	bool referenceIdentique = true;
	if (m_auteurs != autreReference.m_auteurs) {referenceIdentique = false;}
	else if (m_identifiant != autreReference.m_identifiant) {referenceIdentique = false;}
	else if (m_annee != autreReference.m_annee) {referenceIdentique = false;}
	else if (m_titre != autreReference.m_titre) {referenceIdentique = false;}
	return referenceIdentique;
}

//void Reference::verifieInvariant() const
//{
//#	INVARIANTS();
//}

}

