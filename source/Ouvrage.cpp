

#include "Ouvrage.h"

using namespace std;

namespace biblio
{

Ouvrage::Ouvrage(	const string& p_auteurs,
					const string& p_titre,
					const string& p_ville,
					const string& p_editeur,
					int p_annee,
					const string& p_identifiant)
: Reference(p_auteurs, p_titre, p_annee, p_identifiant), m_ville(p_ville), m_editeur(p_editeur)
{}

const string& Ouvrage::reqEditeur() const
{
	return m_editeur;
}

const string& Ouvrage::reqVille() const
{
	return m_ville;
}

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

}



