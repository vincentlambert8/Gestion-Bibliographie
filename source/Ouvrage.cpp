

#include "Ouvrage.h"
#include "validationFormat.h"
#include "ContratException.h"

using namespace std;

namespace biblio
{

/**
 * \fn Ouvrage::Ouvrage
 * \brief Constructeur de la classe Ouvrage avec paramètres.
 * On construit un objet Ouvrage à partir des données passées en paramètres.
 * \param[in] p_auteurs est le nom de ou des auteurs
 * \param[in] p_titre est le nom de l'ouvrage
 * \param[in] p_ville est le nom de la ville d'édition de l'ouvrage
 * \param[in] p_editeur est le nom de l'éditeur de l'ouvrage
 * \param[in] p_annee est l'annee de publication de la reference
 * \param[in] p_identifiant est le code ISBN de la reference
 * \pre p_auteurs, non vide et contient que des lettres
 * \pre p_titre, non vide et contient que des lettres
 * \pre p_ville, non vide et contient que des lettres
 * \pre p_editeur, non vide et contient que des lettres
 * \pre p_annee, est plus grand ou égal à 0
 * \pre p_identifiant, respecte le format d'un code ISBN/ISSN
 */
Ouvrage::Ouvrage(	const string& p_auteurs,
					const string& p_titre,
					const string& p_ville,
					const string& p_editeur,
					int p_annee,
					const string& p_identifiant)
: Reference(p_auteurs, p_titre, p_annee, p_identifiant), m_ville(p_ville), m_editeur(p_editeur)
{
	PRECONDITION(util::validerFormatNom(p_ville));
	PRECONDITION(util::validerFormatNom(p_editeur));
	PRECONDITION(util::validerCodeIsbn(p_identifiant));

	POSTCONDITION(m_ville == p_ville);
	POSTCONDITION(m_editeur == p_editeur);

	INVARIANTS();
}

/**
 * \fn Ouvrage::reqEditeur()
 * \brief Methode d'acces en lecture à l'attribut m_editeur
 *
 * \return m_editeur
 */
const string& Ouvrage::reqEditeur() const
{
	return m_editeur;
}

/**
 * \fn Ouvrage::reqVille()
 * \brief Methode d'acces en lecture à l'attribut m_ville
 *
 * \return m_ville
 */
const string& Ouvrage::reqVille() const
{
	return m_ville;
}

/**
 * \fn Ouvrage::reqReferenceFormate
 * \brief Methode permettant de formater l'objet Ouvrage courant selon ses attributs
 *
 * \return chaineFormatee, qui est la chaîne de caracteres de l'ouvrage formatée
 */
string Ouvrage::reqReferenceFormate() const
{
	ostringstream chaine;
	chaine << 	Reference::reqReferenceFormate() <<
				" " <<
				m_ville <<
				" : " <<
				m_editeur <<
				", " <<
				Reference::reqAnnee() <<
				". " <<
				Reference::reqIdentifiant() <<
				".";
	string chaineFormatee = chaine.str();
	return chaineFormatee;
}

/*
 * \fn Ouvrage::verifieInvariant() const
 * \brief Vérification des invariants de la classe Ouvrage
 * L'invariant de cette classe s'assure que l'Ouvrage est valide
 */
void Ouvrage::verifieInvariant() const
{
	INVARIANT(util::validerFormatNom(m_ville));
	INVARIANT(util::validerFormatNom(m_editeur));
}

}



