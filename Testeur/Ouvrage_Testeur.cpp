/*
 * Ouvrage_Testeur.cpp
 *
 *  Created on: 2019-03-28
 *      Author: etudiant
 */

#include "gtest/gtest.h"
#include "Ouvrage.h"
#include "ContratException.h"
using namespace std;
using namespace biblio;


TEST(Ouvrage, ConstructeurAvecParametres)
{
	Ouvrage ouvrageTest(	"Homayoon Beigi",
							"Fundamentals of Speaker Recognition",
							"New York",
							"Springer",
							2011,
							"ISBN 978-0-387-77591-3");

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

TEST(Ouvrage, ConstructeurVilleInvalide)
{
	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition", "New-York", "Springer", 2011, "ISBN 978-0-387-77591-3"),
			PreconditionException);
	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition", " ", "Springer", 2011, "ISBN 978-0-387-77591-3"),
				PreconditionException);
	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition", "New York 2", "Springer", 2011, "ISBN 978-0-387-77591-3"),
				PreconditionException);
}

TEST(Ouvrage, ConstructeurEditeurInvalide)
{
	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition", "New York", " ", 2011, "ISBN 978-0-387-77591-3"),
				PreconditionException);
	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition", "New York", "Sprin-ger", 2011, "ISBN 978-0-387-77591-3"),
				PreconditionException);
	ASSERT_THROW(Ouvrage ouvrageTest("Homayoon Beigi", "Fundamentals of Speaker Recognition", "New York", "Springer2", 2011, "ISBN 978-0-387-77591-3"),
				PreconditionException);
}

/**
 * \class UnOuvrage
 * \brief Fixture pour les tests avec un objet ouvrage
 */
class UnOuvrage: public ::testing::Test
{
public:
	UnOuvrage():
		t_ouvrage(	"Homayoon Beigi",
					"Fundamentals of Speaker Recognition",
					"New York",
					"Springer",
					2011,
					"ISBN 978-0-387-77591-3")
		{};
	Ouvrage t_ouvrage;
};

TEST_F(UnOuvrage, requeteVille)
{
	EXPECT_EQ("New York", t_ouvrage.reqVille());
}

TEST_F(UnOuvrage, requeteEditeur)
{
	EXPECT_EQ("Springer", t_ouvrage.reqEditeur());
}

TEST_F(UnOuvrage, AfficherReferenceFormate)
{
	EXPECT_EQ("Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer, 2011. ISBN 978-0-387-77591-3.",
			t_ouvrage.reqReferenceFormate());
}

TEST_F(UnOuvrage, MethodeClone)
{
	Reference* clone = t_ouvrage.clone();
	ASSERT_EQ(t_ouvrage.reqReferenceFormate(), clone->reqReferenceFormate())
	;
}


