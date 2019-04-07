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

/**
 * \brief 	Test du constructeur Ouvrage(	const std::string& p_auteurs,
										const std::string& p_titre,
										const std::string& p_ville,
										const std::string& p_editeur,
										int p_annee,
										const std::string& p_identifiant)
			cas valide:
				ConstructeurAvecParamètres: Création d'un objet Ouvrage avec tous les paramètres nécessaires.
											Chaque attribut doit correspondre à son paramètre respectif.
			cas invalide:
				ConstructeurVilleInvalide: Le format du paramètre p_ville n'est pas valide
				ConstructeurEditeurInvalide: Le format du paramètre p_editeur n'est pas valide
 */
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
 * \brief Fixture UnOuvrage pour la création d'un objet Ouvrage pour les tests
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

/**
 * \brief 	Test de la méthode const std::string& reqVille() const
 * 			cas valide:
 * 				requeteVille: vérification du retour
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnOuvrage, requeteVille)
{
	ASSERT_EQ("New York", t_ouvrage.reqVille());
}

/**
 * \brief	Test de la méthode const std::string& reqEditeur() const
 * 			cas valide:
 * 				requeteEditeur: vérification du retour
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnOuvrage, requeteEditeur)
{
	ASSERT_EQ("Springer", t_ouvrage.reqEditeur());
}

/**
 * \brief 	Test de la méthode std::string reqReferenceFormate() const
 * 			cas valide:
 * 				AfficherReferenceFormate: vérification du retour
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnOuvrage, AfficherReferenceFormate)
{
	EXPECT_EQ("Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer, 2011. ISBN 978-0-387-77591-3.",
			t_ouvrage.reqReferenceFormate());
}

/**
 * \brief	Test de la méthode virtual Reference* clone() const
 * 			cas valide:
 * 				MethodeClone: 	création d'une référence clone à partir d'un ouvrage de base et utilisation de la
 * 								méthode reqReferenceFormate pour vérification de la concordance entre les deux objets
 */
TEST_F(UnOuvrage, MethodeClone)
{
	Reference* clone = t_ouvrage.clone();
	ASSERT_EQ(t_ouvrage.reqReferenceFormate(), clone->reqReferenceFormate())
	;
}


