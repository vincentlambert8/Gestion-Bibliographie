/*
 * Journal.cpp
 *
 *  Created on: 2019-03-24
 *      Author: etudiant
 */

#include "Journal.h"
#include "validationFormat.h"
#include "ContratException.h"

using namespace std;

namespace biblio
{
/**
 * \brief Constructeur de la classe Journal avec paramètres.
 * On construit un objet Journal à partir des données passées en paramètres.
 * \param[in] p_auteurs est le nom de ou des auteurs
 * \param[in] p_titre est le nom de l'ouvrage
 * \param[in] p_nom est le nom du journal dans laquelle a été publiée la référence
 * \param[in] p_volume est le volume de la référence dans le journal
 * \param[in] p_numero est le numero de la référence dans le journal
 * \param[in] p_page est la page où commence la référence dans le journal
 * \param[in] p_annee est l'annee de publication de la reference
 * \param[in] p_identifiant est le code ISSN de la reference
 * \pre p_auteurs, non vide et contient que des lettres
 * \pre p_titre, non vide et contient que des lettres
 * \pre p_volume, est plus grand ou égal à 0
 * \pre p_numero, est plus grand ou égal à 0
 * \pre p_page, est plus grand que 0
 * \pre p_annee, est plus grand ou égal à 0
 * \pre p_identifiant, respecte le format d'un code ISSN
 */
Journal::Journal(	const string& p_auteurs,
					const string& p_titre,
					const string& p_nom,
					int p_volume,
					int p_numero,
					int p_page,
					int p_annee,
					const string& p_identifiant)
: Reference(p_auteurs, p_titre, p_annee, p_identifiant),
  m_nom(p_nom),
  m_volume(p_volume),
  m_numero(p_numero),
  m_page(p_page)
{
	PRECONDITION(!(m_nom.empty()));
	PRECONDITION(p_volume >= 0);
	PRECONDITION(p_numero >= 0);
	PRECONDITION(p_page > 0);
	PRECONDITION(util::validerCodeIssn(p_identifiant));

	POSTCONDITION(m_nom == p_nom);
	POSTCONDITION(m_volume == p_volume);
	POSTCONDITION(m_numero == p_numero);
	POSTCONDITION(m_page == p_page);

	INVARIANTS();

}

/**
 * \fn Journal::reqNom()
 * \brief Methode d'acces en lecture à l'attribut m_nom
 *
 * \return m_nom
 */
const string& Journal::reqNom() const
{
	return m_nom;
}

/**
 * \fn Journal::reqVolume()
 * \brief Methode d'acces en lecture à l'attribut m_volume
 *
 * \return m_volume
 */
const int& Journal::reqVolume() const
{
	return m_volume;
}

/**
 * \fn Journal::reqNumero()
 * \brief Methode d'acces en lecture à l'attribut m_numero
 *
 * \return m_numero
 */
const int& Journal::reqNumero() const
{
	return m_numero;
}

/**
 * \fn Journal::reqPage()
 * \brief Methode d'acces en lecture à l'attribut m_page
 *
 * \return m_page
 */
const int& Journal::reqPage() const
{
	return m_page;
}

/**
 * \fn Journal::reqReferenceFormate
 * \brief Methode permettant de formater l'objet Journal courant selon ses attributs
 *
 * \return chaineFormatee, qui est la chaîne de caracteres de la référencee dans le journal formatée
 */
string Journal::reqReferenceFormate() const
{
	ostringstream chaine;
	chaine << 	Reference::reqReferenceFormate() << " " <<
				m_nom << ", " <<
				"vol. " << reqVolume() << ", " <<
				"no. " << reqNumero() << ", " <<
				"pp. " << reqPage() << ", " <<
				Reference::reqAnnee() << ". " <<
				Reference::reqIdentifiant() << ".";
	string chaineFormatee = chaine.str();
	return chaineFormatee;
}

/*
 * \fn Journal::verifieInvariant() const
 * \brief Vérification des invariants de la classe Journal
 * L'invariant de cette classe s'assure que le Journal est valide
 */
void Journal::verifieInvariant() const
{
	INVARIANT(!(m_nom.empty()));
	INVARIANT(m_volume >= 0);
	INVARIANT(m_numero >= 0);
	INVARIANT(m_page > 0);
}

}



