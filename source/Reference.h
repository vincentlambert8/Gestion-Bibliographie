/**
 *\file Reference.h
 *\brief Header de la classe Reference
 *\author Toma Gagne
 *\version 1
 *\date 22 fevrier 2019
 */

#ifndef REFERENCE_H_
#define REFERENCE_H_

#include <iostream>
#include <string>

namespace biblio
{
	class Reference;
}

/**
 * \class Reference
 * \brief Classe implantant le concept de references bibliographiques
 * 		Attributs: 	int m_annee: annee d'edition de la reference
 * 					string m_auteurs: nom de l'auteur ou des auteurs de la reference
 * 					string m_identifiant: l'identifiant de la reference. Peut etre un code ISSN ou ISBN
 * 					string m_titre: titre de la reference
 */
class biblio::Reference
{
public:
	Reference(const std::string&, const std::string&, int, const std::string&);
	virtual Reference* clone() const =0;
	virtual ~Reference(){};
	int reqAnnee() const;
	const std::string& reqAuteurs() const;
	const std::string& reqIdentifiant() const;
	const std::string& reqTitre() const;
	virtual std::string reqReferenceFormate() const =0;
	void asgAuteurs(const std::string& p_auteurs);
	bool operator==(const Reference& autreReference) const;

private:
	std::string m_auteurs;
	std::string m_titre;
	int m_annee;
	std::string m_identifiant;
	void verifieInvariant() const;
};


#endif /* REFERENCE_H_ */
