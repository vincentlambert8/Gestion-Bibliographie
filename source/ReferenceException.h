/*
 * BibliographieException.h
 *
 *  Created on: 2019-04-11
 *      Author: etudiant
 */

#ifndef REFERENCEEXCEPTION_H_
#define REFERENCEEXCEPTION_H_


class ReferenceException: public std::runtime_error
{
public:
	ReferenceException (const std::string& p_raison): std::runtime_error(p_raison){}
};

class ReferenceDejaPresenteException: public ReferenceException
{
public:
	ReferenceDejaPresenteException(const std::string& p_raison): ReferenceException(p_raison){}
};

class ReferenceAbsenteException: public ReferenceException
{
public:
	ReferenceAbsenteException(const std::string& p_raison): ReferenceException(p_raison){}
};


#endif /* REFERENCEEXCEPTION_H_ */
