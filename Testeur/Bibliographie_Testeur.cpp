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
 * \brief	Test de la méthode void ajouterReference(const Reference& p_nouvelleReference)
 * 			cas valide:
 * 				ajouterReference: 	vérification que l'objet Bibliographie est vide au départ, ajout d'une référence,
 * 									vérification que l'objet Bibliographie n'est plus vide
 * 			cas invalide:
 * 				Aucun identifié
 */

/**
TEST(UneBibliographie, ajouterReference)
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
	cout << "Avant appel de la méthode ajouterReference" << endl;
	bibliographieTest.ajouterReference(t_ouvrage);
	cout << "Après appel de la méthode ajouterReference" << endl;
	EXPECT_FALSE((bibliographieTest.reqVecteur()).empty())
	;
	cout << "Après essai vérification si le vecteur est vide" << endl;
}
*/
