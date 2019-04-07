/*
 * Reference_Testeur.cpp
 *
 *  Created on: 2019-03-28
 *      Author: etudiant
 */

#include "gtest/gtest.h"
#include "Reference.h"
#include "ContratException.h"
#include <string>
using namespace std;
using namespace biblio;


/**
 * \class ReferenceDeTest: public cReference
 * \brief Classe permettant de tester les méthodes de la classe abstraite Reference
 */
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

/**
 * \class UneReference
 * \brief Fixture UneReferencee pour la création d'un objet Reference pour les tests
 */
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


/**
 * \brief 	Test du Constructeur Reference(const string p_auteurs, const string p_titre, int p_annee, const string p_identifiant)
 * 			cas valide:
 * 			ConstructeurAvecParamètres: Référence complète avec les 4 paramètres.
 * 										Chaque attribut doit être pareil à son paramètre respectif
 * 			cas invalides:
 * 			ConstructeurNomVide: Le paramètre p_auteurs ne doit pas être vide
 * 			ConstructeurNomInvalide:	Le paramètre p_auteurs doit être dans le format valide. Il ne doit contenir
 * 										que des lettres
 * 			ConstructeurTitreInvalide:	p_titre doit être dans un format valide. Il doit être non vide et ne
 * 										contenir que des lettres
 * 			ConstructeurAnneeInvalide:	p_annee doit être supérieur ou égal à 0
 * 			ConstructeurIdentifiantInvalide:	L'identifiant doit être dans un format valide
 */
TEST(Reference, ConstructeurAvecParametres)
{
	ReferenceDeTest referenceTest(	"Homayoon Beigi",
									"Fundamentals of Speaker Recognition",
									2011,
									"ISBN 978-0-387-77591-3");

	ASSERT_EQ("Homayoon Beigi", referenceTest.reqAuteurs())
	;
	ASSERT_EQ("Fundamentals of Speaker Recognition", referenceTest.reqTitre())
	;
	ASSERT_EQ(2011, referenceTest.reqAnnee())
	;
	ASSERT_EQ("ISBN 978-0-387-77591-3", referenceTest.reqIdentifiant())
	;
}

TEST(Reference, ConstructeurNomVide)
{
	ASSERT_THROW(ReferenceDeTest referenceTest(	" ", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3"),
			PreconditionException) << "Le nom du ou des auteurs ne peut pas être vide";
}

TEST(Reference, ConstructeurNomInvalide)
{
	ASSERT_THROW(ReferenceDeTest referenceTest(	"Toma 2", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3"),
			PreconditionException);
	ASSERT_THROW(ReferenceDeTest referenceTest(	" Toma", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3"),
				PreconditionException);
	ASSERT_THROW(ReferenceDeTest referenceTest(	"Homayoon-Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3"),
				PreconditionException);
	ASSERT_THROW(ReferenceDeTest referenceTest(	"1 Homayoon", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3"),
				PreconditionException);
}

TEST(Reference, ConstructeurTitreInvalide)
{
	ASSERT_THROW(ReferenceDeTest referenceTest(	"Homayoon Beigi", "", 2011, "ISBN 978-0-387-77591-3"),
			PreconditionException) << "Le titre doit être non vide";
}

TEST(Reference, ConstructeurAnneeInvalide)
{
	ASSERT_THROW(ReferenceDeTest referenceTest(	"Homayoon Beigi", "Fundamentals of Speaker Recognition", -1, "ISBN 978-0-387-77591-3"),
			PreconditionException) << "L'année ne peut pas être négative";
}

TEST(Reference, ConstructeurIdentifiantInvalide)
{
	ASSERT_THROW(ReferenceDeTest referenceTest(	"Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "978-0-387-77591-3"),
				PreconditionException);
	ASSERT_THROW(ReferenceDeTest referenceTest(	"Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISSN 978-0-387-77591-3"),
					PreconditionException);
	ASSERT_THROW(ReferenceDeTest referenceTest(	"Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-2"),
					PreconditionException);
	ASSERT_THROW(ReferenceDeTest referenceTest(	"Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-775913"),
						PreconditionException);
	ASSERT_THROW(ReferenceDeTest referenceTest(	"Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 9780387775913"),
						PreconditionException);
	ASSERT_THROW(ReferenceDeTest referenceTest(	"Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 98-0-387-77591-2"),
						PreconditionException);
}

/**
 * \brief 	Test de la méthode void asgAuteurs(const string p_auteurs)
 *			cas valide:
 *				MutateurAuteurs: Remplacement des auteurs et vérification dee mise à jour
 *			cas invalide:
 *				Aucun identifié
 */
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

/**
 * \brief 	Test de la méthode string reqReferenceFormate() const
 * 			cas valide:
 * 				AfficherReferenceFormate: La méthode retourne une string dans le format prescrit
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UneReference, AfficherReferenceFormate)
{
	string ReferenceChaineFormate = "Homayoon Beigi. Fundamentals of Speaker Recognition.";
	EXPECT_EQ(ReferenceChaineFormate, t_reference.reqReferenceFormate());
}

/**
 * \brief 	Test de la méthode const string reqAuteurs() const
 * 			cas valide:
 * 				RequeteAuteurs: Vérification du retour
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UneReference, RequeteAuteurs)
{
	EXPECT_EQ("Homayoon Beigi", t_reference.reqAuteurs())
	;
}

/**
 * \brief	Test de la méthode const string reqTitre() const
 * 			cas valide:
 * 				RequeteTitre: Vérification du retour
 * 			cas invalide:
 * 				Aucun identifié
 */

TEST_F(UneReference, RequeteTitre)
{
	EXPECT_EQ("Fundamentals of Speaker Recognition", t_reference.reqTitre())
	;
}

/**
 * \brief	Test de la méthode const int reqAnnee() const
 * 			cas valide:
 * 				RequeteAnnee: vérification du retour
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UneReference, RequeteAnnee)
{
	ASSERT_EQ(2011, t_reference.reqAnnee())
	;
}

/**
 * \brief 	Test de la méthode const string reqIdentifiant() const
 * 			cas valide:
 * 				requeteIdentifiant: vérification du retour
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UneReference, requeteIdentifiant)
{
	EXPECT_EQ("ISBN 978-0-387-77591-3", t_reference.reqIdentifiant())
	;
}

/**
 * \brief 	Test de la méthode bool Reference::operator==(const Reference& autreReference) const
 * 			cas valide:
 * 				OperateurEgalite: 	Vérifie l'égalité entre une référence de base avec une autre référence valide et
 * 									5 autres références invalides
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UneReference, OperateurEgalite)
{
	ASSERT_TRUE(t_reference == t_reference2);
	ASSERT_FALSE(t_reference == t_reference3);
	ASSERT_FALSE(t_reference == t_reference4);
	ASSERT_FALSE(t_reference == t_reference5);
	ASSERT_FALSE(t_reference == t_reference6);
}

/**
 * \brief 	Test de la méthode virtual Reference* clone() const
 * 			cas valide:
 * 				MethodeClone: 	création d'une référence clone à partir d'une référence de base et utilisation de la
 * 								méthode reqReferenceFormate pour vérification de la concordance entre les deux objets
 */
TEST_F(UneReference, MethodeClone)
{
	Reference *clone = t_reference.clone();
	ASSERT_EQ(t_reference.reqReferenceFormate(), clone->reqReferenceFormate())
	;
}




