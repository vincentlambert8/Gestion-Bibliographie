/*
 * Bibliographie_Testeur.cpp
 *
 *  Created on: 2019-03-28
 *      Author: etudiant
 */

#include "gtest/gtest.h"
#include "Bibliographie.h"
using namespace std;
using namespace biblio;


class BibliographieDeTest: public Bibliographie
{
public:
	BibliographieDeTest(const string& p_nomBibliographie)
	: Bibliographie(p_nomBibliographie)
	{};

};
/*
class UneBibliographie: public ::testing::Test
{
public:
	UneBibliographie()
		: t_bibliographie("Bibliographie")
		{};
	BibliographieDeTest t_bibliographie;

};
*/

TEST(Bibliographie, ConstructeurAvecNom)
{
	BibliographieDeTest bibliographieTest("Biblio");
	EXPECT_EQ("Biblio", bibliographieTest.reqNomBibliographie())
	;
}
