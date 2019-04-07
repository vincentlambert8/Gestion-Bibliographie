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

/**
 * \brief	Test du Constructeur Journal(	const string& p_auteurs,
											const string& p_titre,
											const string& p_nom,
											int p_volume,
											int p_numero,
											int p_page,
											int p_annee,
											const string& p_identifiant)
			cas valide:
				ConstructeurAvecParametres: Création d'un objet Journal avec tous les paramètres nécessaires.
											Chaque attribut doit correspondre à son paramètre respectif.
			cas invalide:
				ConstructeurNomInvalide: Le paramètre p_nom ne doit pas être vide
				ConstructeurVolumeInvalide: Le paramètre p_volume ne doit pas être négatif
				ConstructeurNumeroInvalide: Le paramètre p_numero ne doit pas être négatif
				ConstructeurPageInvalide: Le paramètre p_page doit être plus grand que 0
 */
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

/**
 * \class UnJournal
 * \brief Fixture UnJournal pour la création d'un objet Journal pour les tests
 */
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

/**
 * \brief	Test de la méthode const int& reqVolume() const
 * 			cas valide:
 * 				requeteVolume: vérification du retour
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnJournal, requeteVolume)
{
	EXPECT_EQ(24, t_journal.reqVolume());
}

/**
 * \brief	Test de la méthode const int& reqNumero() const
 * 			cas valide:
 * 				requeteNumero: vérification du retour
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnJournal, requeteNumero)
{
	EXPECT_EQ(6, t_journal.reqNumero());
}

/**
 * \brief	Test de la méthode const int& reqPage() const
 * 			cas valide:
 * 				requetePage: vérification du retour
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnJournal, requetePage)
{
	EXPECT_EQ(113, t_journal.reqPage());
}

/**
 * \brief	Test de la méthode std::string reqReferenceFormate() const
 * 			cas valide:
 * 				AfficherReferenceFormate:	La méthode doit retourner une string avec l'information relative à l'objet
 * 											dans le format prescrit
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnJournal, AfficherReferenceFormate)
{
	EXPECT_EQ("Hart. A survey of source code management tools for programming courses. Journal of Computing Sciences in Colleges, vol. 24, no. 6, pp. 113, 2009. ISSN 1937-4771.",
				t_journal.reqReferenceFormate());
}

/**
 * \brief	Test de la méthode virtual Reference* clone() const
 * 			cas valide:
 * 				MethodeClone: 	création d'un référence clone à partir d'un journal de base et utilisation de la
 * 								méthode reqReferenceFormate pour vérification de la concordance entre les deux objets
 */
TEST_F(UnJournal, MethodeClone)
{
	Reference* clone = t_journal.clone();
	ASSERT_EQ(t_journal.reqReferenceFormate(), clone->reqReferenceFormate())
	;
}
