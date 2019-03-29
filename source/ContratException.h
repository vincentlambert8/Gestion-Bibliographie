/*
 * ContratException.h
 *
 *  Created on: 2019-03-25
 *      Author: etudiant
 */

#ifndef CONTRATEXCEPTION_H_
#define CONTRATEXCEPTION_H_

#include <string>
#include <stdexcept>

class ContratException : public std::logic_error
{
public:
	ContratException(	std::string p_fichierP, unsigned int p_noLigne,
						std::string p_expressionP, std::string p_typeP);
	~ContratException() throw() {};
	std::string reqTexteException() const;

private:
	std::string m_expression;
	std::string m_fichier;
	unsigned int m_ligne;
};

class PreconditionException : public ContratException
{
public:
	PreconditionException(	std::string p_fichierP,
							unsigned int p_noLigne,
							std::string p_expressionP);
};

class PostconditionException: public ContratException
{
public:
	PostconditionException( std::string p_fichierP,
							unsigned int p_noLigne,
							std::string p_expressionP);
};

class InvariantException: public ContratException
{
public:
	InvariantException(std::string, unsigned int, std::string);
};

#if !defined(NDEBUG)
#	define INVARIANTS() \
		verifieInvariant()

#	define ASSERTION(f) \
		if (!(f)) throw AssertionException(__FILE__, __LINE__, #f);
#	define PRECONDITION(f) \
		if (!(f)) throw PreconditionException(__FILE__, __LINE__, #f);
#	define POSTCONDITION(f) \
		if (!(f)) throw PostconditionException(__FILE__, __LINE__, #f);
# 	define INVARIANT(f) \
		if (!(f)) throw InvariantException(__FILE__, __LINE__, #f);

#else

#define PRECONDITION(f);
#define POSTCONDITION(f);
#define INVARIANTS();
#define INVARIANT(f);
#define ASSERTION(f);


#endif // --- if !defined (NDEBUG)
#endif /* CONTRATEXCEPTION_H_ */
