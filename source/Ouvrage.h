/*
 * Ouvrage.h
 *
 *  Created on: 2019-03-25
 *      Author: etudiant
 */

#ifndef OUVRAGE_H_
#define OUVRAGE_H_

#include <iostream>
#include "Reference.h"
#include <string>
#include <sstream>

namespace biblio
{

class Ouvrage: public Reference
{
public:
	Ouvrage(const std::string& p_auteurs,
			const std::string& p_titre,
			const std::string& p_ville,
			const std::string& p_editeur,
			int p_annee,
			const std::string& p_identifiant);
	virtual Reference* clone() const
		{
			return new Ouvrage(*this);
		};
	const std::string& reqEditeur() const;
	const std::string& reqVille() const;
	std::string reqReferenceFormate() const;

private:
	std::string m_ville;
	std::string m_editeur;
	void verifieInvariant() const;
};

}


#endif /* OUVRAGE_H_ */
