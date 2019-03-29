/*
 * ContratException.cpp
 *
 *  Created on: 2019-03-25
 *      Author: etudiant
 */

#include "ContratException.h"
#include <sstream>
#include <string>

ContratException::ContratException(	std::string p_fichierP,
									unsigned int p_noLigne,
									std::string p_expressionP,
									std::string p_typeP)
: std::logic_error(p_typeP), m_expression(p_expressionP), m_fichier(p_fichierP), m_ligne(p_noLigne)
{}

std::string ContratException::reqTexteException() const
{
	std::ostringstream os;
	os << "Message 	: " << what() << std::endl;
	os << "Fichier 	: " << m_fichier << std::endl;
	os << "Ligne	: " << m_ligne << std::endl;
	os << "Test		: " << m_expression << std::endl;

	return os.str();
}

PreconditionException::PreconditionException(	std::string p_fichierP,
												unsigned int p_noLigne,
												std::string p_expressionP)
: ContratException(p_fichierP, p_noLigne, p_expressionP, "ERREUR DE PRECONDITION")
{}

PostconditionException::PostconditionException( std::string p_fichierP,
												unsigned int p_noLigne,
												std::string p_expressionP)
: ContratException(p_fichierP, p_noLigne, p_expressionP, "ERREUR DE POSTCONDITION")
{}

InvariantException::InvariantException(	std::string p_fichierP,
										unsigned int p_noLigne,
										std::string p_expressionP)
: ContratException(p_fichierP, p_noLigne, p_expressionP, "ERREUR INVARIANT")
{}


