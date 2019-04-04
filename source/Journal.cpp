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

const string& Journal::reqNom() const
{
	return m_nom;
}

const int& Journal::reqVolume() const
{
	return m_volume;
}

const int& Journal::reqNumero() const
{
	return m_numero;
}

const int& Journal::reqPage() const
{
	return m_page;
}

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

void Journal::verifieInvariant() const
{
	INVARIANT(!(m_nom.empty()));
	INVARIANT(m_volume >= 0);
	INVARIANT(m_numero >= 0);
	INVARIANT(m_page > 0);
}

}



