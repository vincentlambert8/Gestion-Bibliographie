/*
 * Journal_Testeur.cpp
 *
 *  Created on: 2019-03-28
 *      Author: etudiant
 */


#include "gtest/gtest.h"
#include "Journal.h"
using namespace std;
using namespace biblio;

class JournalDeTest: public Journal
{
public:
	JournalDeTest(	const std::string& p_auteurs,
					const std::string& p_titre,
					const std::string& p_nom,
					int p_volume,
					int p_numero,
					int p_page,
					int p_annee,
					const std::string& p_identifiant):
		Journal(p_auteurs, p_titre, p_nom, p_volume, p_numero, p_page, p_annee, p_identifiant)
		{};
	virtual Reference* clone() const
	{
		return new JournalDeTest(*this);
	};
	virtual std::string reqReferenceFormate() const
	{
		return Reference::reqReferenceFormate();
	};
};

/*
class UneReference: public ::testing::Test
{
public:
	UneReference():
		t_reference("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3")
		{};
	ReferenceDeTest t_reference;
};
*/


TEST(Journal, ConstructeurAvecParametres)
{
	JournalDeTest journalTest(	"Hart",
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

