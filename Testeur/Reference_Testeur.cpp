/*
 * Reference_Testeur.cpp
 *
 *  Created on: 2019-03-28
 *      Author: etudiant
 */

#include "gtest/gtest.h"
#include "Reference.h"
using namespace std;
using namespace biblio;

class ReferenceDeTest: public Reference
{
public:
	ReferenceDeTest(const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant):
		Reference(p_auteurs, p_titre, p_annee, p_identifiant)
		{};
	virtual Reference* clone() const
	{
		return new ReferenceDeTest(*this);
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


TEST(Reference, ConstructeurAvecParametres)
{
	ReferenceDeTest referenceTest(	"Homayoon Beigi",
									"Fundamentals of Speaker Recognition",
									2011, "ISBN 978-0-387-77591-3");

	EXPECT_EQ("Homayoon Beigi", referenceTest.reqAuteurs())
	;
	EXPECT_EQ("Fundamentals of Speaker Recognition", referenceTest.reqTitre())
	;
	ASSERT_EQ(2011, referenceTest.reqAnnee())
	;
	EXPECT_EQ("ISBN 978-0-387-77591-3", referenceTest.reqIdentifiant())
	;
}


