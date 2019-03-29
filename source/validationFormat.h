/**
 *\file validationFormat.h
 *\brief Header du namespace util, contenant les fonctions pour valider le format des entrées
 *\author Toma Gagne
 *\version 1
 *\date 27 fevrier 2019
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include "ctype.h"
#include <iostream>
#include <sstream>
#include <string>

namespace util
{
bool validerFormatNom(const std::string& p_nom);
bool validerCodeIssn(const std::string& p_issn);
bool validerCodeIsbn(const std::string& p_isbn);
bool validerFormatIsbn10(const std::string& p_isbn10, int p_longueur);
bool validerFormatIsbn13(const std::string& p_isbn13, int p_longueur);
bool verifierCleIssn(const std::string& p_issn);
bool verifierCleIsbn10(const std::string& p_isbn10);
bool verifierCleIsbn13(const std::string& p_isbn13);
}

#endif /* VALIDATIONFORMAT_H_ */
