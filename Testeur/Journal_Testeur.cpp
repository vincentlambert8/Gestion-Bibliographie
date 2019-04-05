/*
 * Journal_Testeur.cpp
 *
 *  Created on: 2019-03-28
 *      Author: etudiant
 */


#include "gtest/gtest.h"
#include "Journal.h"
#include "ContratException.h"
using namespace std;
using namespace biblio;

TEST(Journal, ConstructeurAvecParametres)
{
	Journal journalTest(	"Hart",
							"A survey of source code management tools for programming courses",
							"Journal of Computing Sciences in Colleges",
							24,
							6,
							113,
							2009,
							"ISSN 1937-4771");

	EXPECT_EQ("Hart", journalTest.reqAuteurs())
	;
	EXPECT_EQ("A survey of source code management tools for programming courses", journalTest.reqTitre())
	;
	EXPECT_EQ("Journal of Computing Sciences in Colleges", journalTest.reqNom())
	;
	ASSERT_EQ(24, journalTest.reqVolume())
	;
	ASSERT_EQ(6, journalTest.reqNumero())
	;
	ASSERT_EQ(113, journalTest.reqPage())
	;
	ASSERT_EQ(2009, journalTest.reqAnnee())
	;
	EXPECT_EQ("ISSN 1937-4771", journalTest.reqIdentifiant())
	;
}

TEST(Journal, ConstructeurNomInvalide)
{
	ASSERT_THROW(Journal journalDeTest("Hart", "A survey of source code management tools for programming courses",
					"", 24, 6, 113, 2009, "ISSN 1937-4771"),
					PreconditionException) << "Le nom du journal ne doit pas être vide";
}

TEST(Journal, ConstructeurVolumeInvalide)
{
	ASSERT_THROW(Journal journalDeTest("Hart", "A survey of source code management tools for programming courses",
						"Journal of Computing Sciences in Colleges", -1, 6, 113, 2009, "ISSN 1937-4771"),
						PreconditionException);
}

TEST(Journal, ConstructeurNumeroInvalide)
{
	ASSERT_THROW(Journal journalDeTest("Hart", "A survey of source code management tools for programming courses",
						"Journal of Computing Sciences in Colleges", 24, -1, 113, 2009, "ISSN 1937-4771"),
						PreconditionException);
}

TEST(Journal, ConstructeurPageInvalide)
{
	ASSERT_THROW(Journal journalDeTest("Hart", "A survey of source code management tools for programming courses",
						"Journal of Computing Sciences in Colleges", -1, 6, 0, 2009, "ISSN 1937-4771"),
						PreconditionException);
	ASSERT_THROW(Journal journalDeTest("Hart", "A survey of source code management tools for programming courses",
						"Journal of Computing Sciences in Colleges", -1, 6, -1, 2009, "ISSN 1937-4771"),
						PreconditionException);
}

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

TEST_F(UnJournal, requeteVolume)
{
	EXPECT_EQ(24, t_journal.reqVolume());
}

TEST_F(UnJournal, requeteNumero)
{
	EXPECT_EQ(6, t_journal.reqNumero());
}

TEST_F(UnJournal, requetePage)
{
	EXPECT_EQ(113, t_journal.reqPage());
}

TEST_F(UnJournal, AfficherReferenceFormate)
{
	EXPECT_EQ("Hart. A survey of source code management tools for programming courses. Journal of Computing Sciences in Colleges, vol. 24, no. 6, pp. 113, 2009. ISSN 1937-4771.",
				t_journal.reqReferenceFormate());
}

TEST_F(UnJournal, MethodeClone)
{
	Reference* clone = t_journal.clone();
	ASSERT_EQ(t_journal.reqReferenceFormate(), clone->reqReferenceFormate())
	;
}
