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
#include <sstream>
using namespace std;
using namespace biblio;

/**
 *\brief 	Test du Constructeur Bibliographie(const std::string& p_nomBibliographie)
 *			cas valide:
 *				ConstructeurAvecNom: Le nom donné n'est pas vide vide
 *			cas invalide:
 *				ConstructeurAvecNomInvalide: Le nom de la bibliographie ne doit pas être vide
 *
 */
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


/**
 * \class UneBibliographie
 * \brief Fixture UneBibliographie pour la création d'un objet Bibliographie pour les tests
 */
class UneBibliographie: public ::testing::Test
{
public:
	UneBibliographie()
		: t_bibliographie("Bibliographie")
		{};
	Bibliographie t_bibliographie;

};

/**
 * \brief	Test de la méthode void ajouterReference(const Reference& p_nouvelleReference)
 * 			cas valide:
 * 				ajouterReference: 	vérification que l'objet Bibliographie est vide au départ, ajout d'une référence,
 * 									vérification que l'objet Bibliographie n'est plus vide. Vérification que ce que contient le vecteur contient
 * 									est bien la référence ajoutée
 * 									Ajout d'une autre référence et vérification de ce qui a été ajouté dans le vecteur est bien la nouvelle référence
 * 			cas invalide:
 * 				ajouterReferenceDejaPresente:	vérification qu'il n'est pas possible d'ajouter une référence
 * 												déjà présente dans la bibliographie.
 */
TEST(Bibliographie, ajouterReference)
{
	Bibliographie bibliographieTest("Biblio");
	Ouvrage t_ouvrage(	"Homayoon Beigi",
						"Fundamentals of Speaker Recognition",
						"New York",
						"Springer",
						2011,
						"ISBN 978-0-387-77591-3");
	EXPECT_TRUE((bibliographieTest.reqVecteur()).empty())
	;
	bibliographieTest.ajouterReference(t_ouvrage);
	EXPECT_FALSE((bibliographieTest.reqVecteur()).empty())
	;
	ASSERT_EQ(t_ouvrage.reqReferenceFormate(), (bibliographieTest.reqVecteur())[0]->reqReferenceFormate())
	;

	Journal journalTest(	"Hart",
							"A survey of source code management tools for programming courses",
							"Journal of Computing Sciences in Colleges",
							24,
							6,
							113,
							2009,
							"ISSN 1937-4771");
	bibliographieTest.ajouterReference(journalTest);
	ASSERT_EQ(journalTest.reqReferenceFormate(), (bibliographieTest.reqVecteur())[1]->reqReferenceFormate())
	;
}

/**
 * \brief	Test de la méthode void ajouterReference(const Reference& p_nouvelleReference)
 * 			cas invalide:
 * 				ajouterReferenceDejaPresente:	vérification qu'il n'est pas possible d'ajouter une référence
 * 												déjà présente dans la bibliographie. En ajoutant 2 fois la même
 * 												référence, la longueur du vecteur reste la même car la référence
 * 												n'est pas ajouté deux fois
 */
TEST(Bibliographie, ajouterReferenceDejaPresente)
{
	Bibliographie bibliographieTest("Biblio");
	Ouvrage t_ouvrage(	"Homayoon Beigi",
						"Fundamentals of Speaker Recognition",
						"New York",
						"Springer",
						2011,
						"ISBN 978-0-387-77591-3");
	ASSERT_TRUE((bibliographieTest.reqVecteur()).empty())
	;
	bibliographieTest.ajouterReference(t_ouvrage);
	ASSERT_FALSE((bibliographieTest.reqVecteur()).empty())
	;
	ASSERT_EQ(1, (bibliographieTest.reqVecteur()).size())
	;
	bibliographieTest.ajouterReference(t_ouvrage);
	ASSERT_EQ(1, (bibliographieTest.reqVecteur()).size())
	;
}


/**
 * \brief 	Test de la méthode const std::string reqBibliographieFormate() const
 * 			cas valide:
 * 				requeteReferenceFormate: Vérification du retour selon le format prescrit
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST(Bibliographie, requeteReferenceFormate)
{
	ostringstream os;
	Bibliographie bibliographieTest("Biblio");
	Ouvrage t_ouvrage(	"Homayoon Beigi",
						"Fundamentals of Speaker Recognition",
						"New York",
						"Springer",
						2011,
						"ISBN 978-0-387-77591-3");
	bibliographieTest.ajouterReference(t_ouvrage);

	os << "Bibliographie" << endl;
	os << "===============================" << endl;
	os << "[" << 1 << "]" << " " << t_ouvrage.reqReferenceFormate() << endl;
	ASSERT_EQ(os.str(), bibliographieTest.reqBibliographieFormate())
	;
}
