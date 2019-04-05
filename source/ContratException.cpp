/*
 * ContratException.cpp
 *
 *  Created on: 2019-03-25
 *      Author: etudiant
 */

#include "ContratException.h"
#include <sstream>
#include <string>


/**
 * \brief Constructeur de la classe de base ContratException
 * \param[in] p_fichierP est la chaîne de caractères représentant le fichier source dans lequel à eu lieu l'erreur
 * \param[in] p_noLigne est un entier représentant la ligne où a eu lieu l'erreur
 * \param[in] p_expressionP est la chaîne de caractères représentant le message décrivant l'erreur
 * \param[in] p_typeP est la chaîne de caractères représentant le type de l'erreur
 */
ContratException::ContratException(	std::string p_fichierP,
									unsigned int p_noLigne,
									std::string p_expressionP,
									std::string p_typeP)
: std::logic_error(p_typeP), m_expression(p_expressionP), m_fichier(p_fichierP), m_ligne(p_noLigne)
{}

/**
 * \fn std::string ContratException::reqTexteException() const
 * \brief Méthode qui retourne une chaîne de caractères correspondant à l'erreur
 *
 * \return os.str(), la chaîne de caractères correspondant à l'erreur
 */
std::string ContratException::reqTexteException() const
{
	std::ostringstream os;
	os << "Message 	: " << what() << std::endl;
	os << "Fichier 	: " << m_fichier << std::endl;
	os << "Ligne	: " << m_ligne << std::endl;
	os << "Test		: " << m_expression << std::endl;

	return os.str();
}

/**
 * \brief Constructeur de la classe PreconditionException
 * \param[in] p_fichierP est la chaîne de caractères représentant le fichier source dans lequel à eu lieu l'erreur
 * \param[in] p_noLigne est un entier représentant la ligne où a eu lieu l'erreur
 * \param[in] p_expressionP est la chaîne de caractères représentant le message décrivant l'erreur
 */
PreconditionException::PreconditionException(	std::string p_fichierP,
												unsigned int p_noLigne,
												std::string p_expressionP)
: ContratException(p_fichierP, p_noLigne, p_expressionP, "ERREUR DE PRECONDITION")
{}

/**
 * \brief Constructeur de la classe PostconditionException
 * \param[in] p_fichierP est la chaîne de caractères représentant le fichier source dans lequel à eu lieu l'erreur
 * \param[in] p_noLigne est un entier représentant la ligne où a eu lieu l'erreur
 * \param[in] p_expressionP est la chaîne de caractères représentant le message décrivant l'erreur
 */
PostconditionException::PostconditionException( std::string p_fichierP,
												unsigned int p_noLigne,
												std::string p_expressionP)
: ContratException(p_fichierP, p_noLigne, p_expressionP, "ERREUR DE POSTCONDITION")
{}

/**
 * \brief Constructeur de la classe InvariantException
 * \param[in] p_fichierP est la chaîne de caractères représentant le fichier source dans lequel à eu lieu l'erreur
 * \param[in] p_noLigne est un entier représentant la ligne où a eu lieu l'erreur
 * \param[in] p_expressionP est la chaîne de caractères représentant le message décrivant l'erreur
 */
InvariantException::InvariantException(	std::string p_fichierP,
										unsigned int p_noLigne,
										std::string p_expressionP)
: ContratException(p_fichierP, p_noLigne, p_expressionP, "ERREUR INVARIANT")
{}


