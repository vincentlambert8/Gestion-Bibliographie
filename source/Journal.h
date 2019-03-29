/*
 * Journal.h
 *
 *  Created on: 2019-03-24
 *      Author: etudiant
 */

#ifndef DEBUG_JOURNAL_H_
#define DEBUG_JOURNAL_H_

#include <iostream>
#include "Reference.h"
#include <string>
#include <sstream>

namespace biblio
{

class Journal: public Reference
{
public:
	Journal(const std::string& p_auteurs,
			const std::string& p_titre,
			const std::string& p_nom,
			int p_volume,
			int p_numero,
			int p_page,
			int p_annee,
			const std::string& p_identifiant);
	virtual Reference* clone() const
	{
		return new Journal(*this);
	};
	const std::string& reqNom() const;
	const int& reqVolume() const;
	const int& reqNumero() const;
	const int& reqPage() const;
	std::string reqReferenceFormate() const;

private:
	std::string m_nom;
	int m_volume;
	int m_numero;
	int m_page;
	void verifieInvariant() const;
};

}



#endif /* DEBUG_JOURNAL_H_ */
