/*
 * Bibliographie_Testeur.cpp
 *
 *  Created on: 2019-03-28
 *      Author: etudiant
 */

#include "gtest/gtest.h"
#include "Bibliographie.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "ContratException.h"
using namespace std;
using namespace biblio;

TEST(Bibliographie, ConstructeurAvecNom)
{
	Bibliographie bibliographieTest("Biblio");
	EXPECT_EQ("Biblio", bibliographieTest.reqNomBibliographie())
	;
}

TEST(Bibliographie, ConstructeurAvecNomInvalide)
{
	ASSERT_THROW(Bibliographie bibliographieTest(""), PreconditionException);
}

class UneBibliographie: public ::testing::Test
{
public:
	UneBibliographie()
		: t_bibliographie("Bibliographie")
		{};
	Bibliographie t_bibliographie;

};

class UnJournal: public ::testing::Test
{
public:
	UnJournal():
		t_journal(	"Hart",
					"A survey of source code management tools for programming courses",
					"Journal of Computing Sciences in Colleges",
					24,
					6,
					113,
					2009,
					"ISSN 1937-4771")
		{};
	Journal t_journal;
};

TEST_F(UneBibliographie, ajouterReference)
{
	ASSERT_TRUE((t_bibliographie.reqVecteur()).empty())
	;
}
