/**
*\file Bibliographie.h
*\brief Header de la classe Bibliographie
*\author Toma Gagne
*\version 1
*\date 10 avril 2019
*/

#ifndef BIBLIOGRAPHIE_H_
#define BIBLIOGRAPHIE_H_

#include "Reference.h"
#include <vector>

namespace biblio
{
class Bibliographie
{
public:
	Bibliographie(const std::string& p_nomBibliographie);
	~Bibliographie();
	void ajouterReference(const Reference& p_nouvelleReference);
	void supprimerReference(const std::string& p_identifiant);
	const std::string reqBibliographieFormate() const;
	const std::string& reqNomBibliographie() const;
	const std::vector<Reference*> reqVecteur() const;

private:
	Bibliographie(const Bibliographie& p_bibliographie);
	const Bibliographie& operator= (const Bibliographie& p_bibliographie);
	bool ReferenceEstDejaPresente(const std::string& p_identifiant) const;
	std::string m_nomBibliographie;
	std::vector<Reference*> m_vReferences;
	void verifieInvariant() const;
};
}

#endif /* BIBLIOGRAPHIE_H_ */
