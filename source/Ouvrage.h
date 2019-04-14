/**
*\file Ouvrage.h
*\brief Header de la classe Ouvrage
*\author Toma Gagne
*\version 1
*\date 27 10 avril 2019
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
	~Ouvrage(){};
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
