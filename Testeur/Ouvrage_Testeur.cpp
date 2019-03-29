/*
 * Ouvrage_Testeur.cpp
 *
 *  Created on: 2019-03-28
 *      Author: etudiant
 */

#include "gtest/gtest.h"
#include "Ouvrage.h"
using namespace std;
using namespace biblio;

class OuvrageDeTest: public Ouvrage
{
public:
	OuvrageDeTest(	const std::string& p_auteurs,
					const std::string& p_titre,
					const std::string& p_ville,
					const std::string& p_editeur,
					int p_annee,
					const std::string& p_identifiant):
		Ouvrage(p_auteurs, p_titre, p_ville, p_editeur, p_annee, p_identifiant)
		{};
	virtual Reference* clone() const
	{
		return new OuvrageDeTest(*this);
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


TEST(Ouvrage, ConstructeurAvecParametres)
{
	OuvrageDeTest ouvrageTest(	"Homayoon Beigi",
								"Fundamentals of Speaker Recognition",
								"New York",
								"Springer",
								2011, "ISBN 978-0-387-77591-3");

	EXPECT_EQ("Homayoon Beigi", ouvrageTest.reqAuteurs())
	;
	EXPECT_EQ("Fundamentals of Speaker Recognition", ouvrageTest.reqTitre())
	;
	EXPECT_EQ("New York", ouvrageTest.reqVille())
	;
	EXPECT_EQ("Springer", ouvrageTest.reqEditeur())
	;
	ASSERT_EQ(2011, ouvrageTest.reqAnnee())
	;
	EXPECT_EQ("ISBN 978-0-387-77591-3", ouvrageTest.reqIdentifiant())
	;
}




