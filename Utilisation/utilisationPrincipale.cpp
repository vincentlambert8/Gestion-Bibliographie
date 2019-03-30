/*
 * utilisationPrincipale.cpp
 *
 *  Created on: 2019-03-28
 *      Author: etudiant
 */

#include "Reference.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "Bibliographie.h"
#include <iostream>

using namespace std;
using namespace biblio;

int main()
{
	Bibliographie uneBiblio("biblio");
	Ouvrage ouvrageAjoute(	"Homayoon Beigi",
								"Fundamentals of Speaker Recognition",
								"New York",
								"Springer",
								2011,
								"ISBN 978-0-387-77591-3");
	Journal journalAjoute(	"Hart",
								"A survey of source code management tools for programming courses",
								"Journal of Computing Sciences in Colleges",
								24,
								6,
								113,
								2009,
								"ISSN 1937-4771");
	uneBiblio.ajouterReference(ouvrageAjoute);
	uneBiblio.ajouterReference(journalAjoute);
	cout << uneBiblio.reqBibliographieFormate() << endl;
	return 0;
}

