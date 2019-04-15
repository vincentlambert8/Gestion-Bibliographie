/**
 * \file Bibliographie.cpp
 * \brief Implémentation des méthodes de la classe Bibliographie
 * \author Toma Gagne
 * \version 1
 * \date 10 avril 2019
 */


#include <iostream>
#include "Bibliographie.h"
#include "ContratException.h"
#include <string>
#include <sstream>
#include "ReferenceException.h"

using namespace std;
namespace biblio
{

/**
 * \brief Constructeur de la classe Bibliographie
 * \param[in] p_nomBibliographie est le nom de la bibliographie
 * \pre p_nomBibliographie, non vide
 * \post L'attribut m_nomBibliographie équivaut à p_nomBibliographie passé en paramètre
 */
Bibliographie::Bibliographie(const string& p_nomBibliographie)
: m_nomBibliographie(p_nomBibliographie)
	{
		PRECONDITION(!(p_nomBibliographie.empty()));

		POSTCONDITION(m_nomBibliographie == p_nomBibliographie);

		INVARIANTS();
	}

/**
 * \brief Destructeur de la classe Bibliographie
 */
Bibliographie::~Bibliographie()
{
	for (vector<Reference*>::iterator i = m_vReferences.begin(); i != m_vReferences.end(); ++i)
	{
 		delete *i;
	}
}

/**
 * \fn Bibliographie::ajouterReference(const Reference& p_nouvelleReference)
 * \brief Méthode permettant d'ajouter une référence à la bibliographie courante
 * \param[in] p_nouvelleReference est l'objet à ajouter à la bibliographie
 * \pre[in] p_nouvelleReference, ne doit pas être déjà présente dans la bibliographie
 */
void Bibliographie::ajouterReference(const Reference& p_nouvelleReference)
{
	try{
		if (Bibliographie::ReferenceEstDejaPresente(p_nouvelleReference.reqIdentifiant()))
			{
				throw ReferenceDejaPresenteException(p_nouvelleReference.reqReferenceFormate());
			}
		else
		{
			m_vReferences.push_back(p_nouvelleReference.clone());
		}
	}catch(const ReferenceDejaPresenteException& p_e){
		cout << p_e.what() << endl;
	}
}

void Bibliographie::supprimerReference(const string& p_identifiant)
{
	try{
		if (ReferenceAbsente(p_identifiant))
		{
			throw ReferenceAbsenteException("La référence est absente de la bibliographie");
		}
		else
		{
			for (vector<Reference*>::iterator it = m_vReferences.begin(); it < m_vReferences.end(); it++)
			{
				if ((*it)->reqIdentifiant() == p_identifiant)
				{
					delete *it;
					m_vReferences.erase(it); // ca fonctionne
				}
			}
		}
	}catch (const ReferenceAbsenteException& p_e)
	{
		cout << p_e.what() << endl;
	}
}

/**
 * \fn const vector<Reference*> Bibliographie::reqVecteur() const
 * \brief Méthode d'accès en lecture à l'attribut m_vReferences
 *
 * \return m_vReferences
 */
const vector<Reference*> Bibliographie::reqVecteur() const
	{
		return m_vReferences;
	}

/**
 * \fn const string Bibliographie::reqBibliographieFormate() const
 * \brief Methode permettant de formater l'objet Bibliographie courant selon ses attributs
 *
 * \return os.str(), qui est la chaîne de caractères de la bibliographie formatée
 */
const string Bibliographie::reqBibliographieFormate() const
{
	ostringstream os;
	os << this->reqNomBibliographie() << endl;
	os << "===============================" << endl;
	for (float i = 0; i < m_vReferences.size(); i++)
	{
		os << "[" << i + 1 << "]" << " " << (*m_vReferences[i]).reqReferenceFormate();
		os << endl;
	}
	return os.str();
}

/**
 * \fn const string& Bibliographie::reqNomBibliographie() const
 * \brief Méthode d'accès en lecture de l'attribut m_nomBibliographie
 *
 * \return m_nomBibliographie
 */
const string& Bibliographie::reqNomBibliographie() const
{
	return m_nomBibliographie;
}

/**
 * \fn bool Bibliographie::ReferenceEstDejaPresente(const std::string& p_identifiant) const
 * \brief Méthode permettant de vérifier si une référence est déjà présente dans la bibliographie courante
 * \param[in] p_identifiant est l'identifiant de la référence dont on vérifie la présence dans la biliographie
 *
 * \return un booléen, vrai si la référence testée est déjà présente dans la bibliographie courante
 */
bool Bibliographie::ReferenceEstDejaPresente(const std::string& p_identifiant) const
{
	bool estDejaPresente = false;
	for (float i = 0; i < m_vReferences.size(); i++)
	{
		if (m_vReferences[i]->reqIdentifiant() == p_identifiant)
		{
			estDejaPresente = true;
		}
	}
	return estDejaPresente;
}

bool Bibliographie::ReferenceAbsente(const std::string & p_identifiant) const
{
	bool estAbsente = true;
	for (size_t i = 0; i < m_vReferences.size(); i++)
	{
		if (m_vReferences[i]->reqIdentifiant() == p_identifiant)
		{
			estAbsente = false;
		}
	}
	return estAbsente;
}

void Bibliographie::verifieInvariant() const
{
	INVARIANT(!(m_nomBibliographie.empty()));
}

}

