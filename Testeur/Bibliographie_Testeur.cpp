/**
 * \file Bibliographie_Testeur.cpp
 * \brief Ensemble des tests des méthodes pour la classe Bibliographie
 * \author Toma Gagne
 * \version 1
 * \date 10 avril 2019
 */

#include "gtest/gtest.h"
#include "Bibliographie.h"
#include "ReferenceException.h"
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
	ASSERT_THROW(Bibliographie bibliographieTest(""), PreconditionException)
			<< "Le nom de la bibliographie inscrit est invalide.";
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
 * 									vérification que l'objet Bibliographie n'est plus vide. Vérification que ce que le vecteur contient
 * 									est bien la référence ajoutée
 * 									Ajout d'une autre référence et vérification de ce qui a été ajouté dans le vecteur est bien la nouvelle référence
 * 			cas invalide:
 * 				ajouterReferenceDejaPresente:	vérification qu'il n'est pas possible d'ajouter une référence
 * 												déjà présente dans la bibliographie.
 */
TEST_F(UneBibliographie, ajouterReference)
{
	Ouvrage t_ouvrage(	"Homayoon Beigi",
						"Fundamentals of Speaker Recognition",
						"New York",
						"Springer",
						2011,
						"ISBN 978-0-387-77591-3");
	EXPECT_TRUE((t_bibliographie.reqVecteur()).empty())
	;
	t_bibliographie.ajouterReference(t_ouvrage);
	EXPECT_FALSE((t_bibliographie.reqVecteur()).empty())
	;
	ASSERT_EQ(t_ouvrage.reqReferenceFormate(), (t_bibliographie.reqVecteur()[0]->reqReferenceFormate()))
	;

	Journal journalTest(	"Hart",
							"A survey of source code management tools for programming courses",
							"Journal of Computing Sciences in Colleges",
							24,
							6,
							113,
							2009,
							"ISSN 1937-4771");
	t_bibliographie.ajouterReference(journalTest);
	ASSERT_EQ(journalTest.reqReferenceFormate(), (t_bibliographie.reqVecteur()[1]->reqReferenceFormate()))
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
TEST_F(UneBibliographie, ajouterReferenceDejaPresente)
{
	Ouvrage t_ouvrage(	"Homayoon Beigi",
						"Fundamentals of Speaker Recognition",
						"New York",
						"Springer",
						2011,
						"ISBN 978-0-387-77591-3");
	ASSERT_TRUE((t_bibliographie.reqVecteur()).empty())
	;
	t_bibliographie.ajouterReference(t_ouvrage);
	ASSERT_FALSE((t_bibliographie.reqVecteur()).empty())
	;
	ASSERT_EQ(1, (t_bibliographie.reqVecteur().size()))
	;
	t_bibliographie.ajouterReference(t_ouvrage);
	ASSERT_EQ(1, (t_bibliographie.reqVecteur().size()))
	;
}


/**
 * \brief	Test de la méthode void supprimerReference(const string& p_identifiant)
 * 			cas valide:
 * 				supprimerReference:	vérification que l'objet Bibliographie est vide au départ, ajout d'une référence,
 * 									vérification que l'objet Bibliographie n'est plus vide. Vérification que ce que le vecteur contient
 * 									est bien la référence ajoutée
 * 									Supression de la référence et vérification que la taille du conteneur est à nouveau vide
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UneBibliographie, supprimerReference)
{
	Ouvrage t_ouvrage(	"Homayoon Beigi",
						"Fundamentals of Speaker Recognition",
						"New York",
						"Springer",
						2011,
						"ISBN 978-0-387-77591-3");
	ASSERT_TRUE((t_bibliographie.reqVecteur()).empty())
	;
	t_bibliographie.ajouterReference(t_ouvrage);
	ASSERT_FALSE((t_bibliographie.reqVecteur()).empty())
	;
	ASSERT_EQ(t_ouvrage.reqReferenceFormate(), (t_bibliographie.reqVecteur()[0]->reqReferenceFormate()))
	;
	t_bibliographie.supprimerReference(t_ouvrage.reqIdentifiant());
	ASSERT_TRUE(t_bibliographie.reqVecteur().empty())
	;
}


/**
 * \brief	Test de la méthode void modifierReference(const string& p_identifiant)
 * 			cas valide:
 * 				modifierReference: 	vérification que l'objet Bibliographie est vide au départ, ajout d'une référence,
 * 									vérification que l'objet Bibliographie n'est plus vide. Vérification que ce que le vecteur contient
 * 									est bien la référence ajoutée
 * 									Modification de la référence et vérification que la référence a bien été modifiée à l'aide d'un accès
 * 									en lecture à m_auteurs
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UneBibliographie, modifierReference)
{
	Ouvrage t_ouvrage(		"Homayoon Beigi",
							"Fundamentals of Speaker Recognition",
							"New York",
							"Springer",
							2011,
							"ISBN 978-0-387-77591-3");
	ASSERT_TRUE((t_bibliographie.reqVecteur()).empty())
	;
	t_bibliographie.ajouterReference(t_ouvrage);
	ASSERT_FALSE((t_bibliographie.reqVecteur()).empty())
	;
	t_bibliographie.modifierReference("ISBN 978-0-387-77591-3", "Hart");
	ASSERT_EQ("Hart", (t_bibliographie.reqVecteur()[0]->reqAuteurs()))
	;

}


/**
 * \brief 	Test de la méthode const std::string reqBibliographieFormate() const
 * 			cas valide:
 * 				requeteReferenceFormate: Vérification du retour selon le format prescrit
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UneBibliographie, requeteReferenceFormate)
{
	ostringstream os;
	Ouvrage t_ouvrage(	"Homayoon Beigi",
						"Fundamentals of Speaker Recognition",
						"New York",
						"Springer",
						2011,
						"ISBN 978-0-387-77591-3");
	t_bibliographie.ajouterReference(t_ouvrage);

	os << "Bibliographie" << endl;
	os << "===============================" << endl;
	os << "[" << 1 << "]" << " " << t_ouvrage.reqReferenceFormate() << endl;
	ASSERT_EQ(os.str(), t_bibliographie.reqBibliographieFormate())
	;
}
