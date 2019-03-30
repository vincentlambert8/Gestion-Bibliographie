/*
 * Bibliographie.h
 *
 *  Created on: 2019-03-24
 *      Author: etudiant
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
	void ajouterReference(const Reference& p_nouvelleReference);
	const std::string reqBibliographieFormate() const;
	const std::string& reqNomBibliographie() const;
	const std::vector<Reference*> reqVecteur() const;

private:
	bool ReferenceEstDejaPresente(const std::string& p_identifiant) const;
	std::string m_nomBibliographie;
	std::vector<Reference*> m_vReferences;
	int m_nombreReferences;
};
}

#endif /* BIBLIOGRAPHIE_H_ */
