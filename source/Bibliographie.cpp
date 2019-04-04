/*
 * Bibliographie.cpp
 *
 *  Created on: 2019-03-24
 *      Author: etudiant
 */

#include <iostream>
#include "Bibliographie.h"
#include <string>
#include <sstream>

using namespace std;

namespace biblio
{
Bibliographie::Bibliographie(const string& p_nomBibliographie)
: m_nomBibliographie(p_nomBibliographie), m_nombreReferences(0)
{}

Bibliographie::~Bibliographie()
{
	for (int i = 0; i < m_nombreReferences; i++)
	{
		delete [] m_vReferences[0];
	}
}

void Bibliographie::ajouterReference(const Reference& p_nouvelleReference)
{
	if (!Bibliographie::ReferenceEstDejaPresente(p_nouvelleReference.reqIdentifiant()))
	{
		m_nombreReferences += 1;
		m_vReferences.push_back(p_nouvelleReference.clone());
	}
	else
	{
		cout << "La référence est déjà présente dans la bibliographie" << endl;
	}
}

const std::vector<Reference*> Bibliographie::reqVecteur() const
	{
		return m_vReferences;
	}


const string Bibliographie::reqBibliographieFormate() const
{
	ostringstream os;
	os << "Bibliographie" << endl;
	os << "===============================" << endl;
	for (int i = 0; i < m_nombreReferences; i++)
	{
		os << "[" << i + 1 << "]" << " " << (*m_vReferences[i]).reqReferenceFormate();
		os << endl;
	}
	return os.str();
}

const string& Bibliographie::reqNomBibliographie() const
{
	return m_nomBibliographie;
}

bool Bibliographie::ReferenceEstDejaPresente(const std::string& p_identifiant) const
{
	bool estDejaPresente = false;
	for (int i = 0; i < m_nombreReferences; i++)
	{
		if (m_vReferences[i]->reqIdentifiant() == p_identifiant)
		{
			estDejaPresente = true;
		}
	}
	return estDejaPresente;
}

}

