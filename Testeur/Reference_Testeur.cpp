/*
 * Reference_Testeur.cpp
 *
 *  Created on: 2019-03-28
 *      Author: etudiant
 */

#include "gtest/gtest.h"
#include "Reference.h"
#include <string>
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


class UneReference: public ::testing::Test
{
public:
	UneReference():
		t_reference("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3"),
		t_reference2("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3"),
		t_reference3("Hart", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3"),
		t_reference4("Homayoon Beigi", "Hello world", 2011, "ISBN 978-0-387-77591-3"),
		t_reference5("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2010, "ISBN 978-0-387-77591-3"),
		t_reference6("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISSN 1937-4771")
		{};
	ReferenceDeTest t_reference;
	ReferenceDeTest t_reference2;
	ReferenceDeTest t_reference3;
	ReferenceDeTest t_reference4;
	ReferenceDeTest t_reference5;
	ReferenceDeTest t_reference6;
};



TEST(Reference, ConstructeurAvecParametres)
{
	ReferenceDeTest referenceTest(	"Homayoon Beigi",
									"Fundamentals of Speaker Recognition",
									2011,
									"ISBN 978-0-387-77591-3");

	EXPECT_EQ("Homayoon Beigi", referenceTest.reqAuteurs())
	;
	EXPECT_EQ("Fundamentals of Speaker Recognition", referenceTest.reqTitre())
	;
	ASSERT_EQ(2011, referenceTest.reqAnnee())
	;
	EXPECT_EQ("ISBN 978-0-387-77591-3", referenceTest.reqIdentifiant())
	;
}

TEST_F(UneReference, MutateurAuteurs)
{
	EXPECT_EQ("Homayoon Beigi", t_reference.reqAuteurs())
	;
	t_reference.asgAuteurs("Hart");
	EXPECT_EQ("Hart", t_reference.reqAuteurs())
	;
	t_reference.asgAuteurs("Homayoon Beigi");
	EXPECT_EQ("Homayoon Beigi", t_reference.reqAuteurs())
	;
}

TEST_F(UneReference, AfficherReferenceFormate)
{
	string ReferenceChaineFormate = "Homayoon Beigi. Fundamentals of Speaker Recognition.";
	EXPECT_EQ(ReferenceChaineFormate, t_reference.reqReferenceFormate());
}

TEST_F(UneReference, RequeteAuteurs)
{
	EXPECT_EQ("Homayoon Beigi", t_reference.reqAuteurs())
	;
}

TEST_F(UneReference, RequeteTitre)
{
	EXPECT_EQ("Fundamentals of Speaker Recognition", t_reference.reqTitre())
	;
}

TEST_F(UneReference, RequeteAnnee)
{
	ASSERT_EQ(2011, t_reference.reqAnnee())
	;
}

TEST_F(UneReference, requeteIdentifiant)
{
	EXPECT_EQ("ISBN 978-0-387-77591-3", t_reference.reqIdentifiant())
	;
}

TEST_F(UneReference, OperateurEgalite)
{
	ASSERT_TRUE(t_reference == t_reference2);
	ASSERT_FALSE(t_reference == t_reference3);
	ASSERT_FALSE(t_reference == t_reference4);
	ASSERT_FALSE(t_reference == t_reference5);
	ASSERT_FALSE(t_reference == t_reference6);
}




