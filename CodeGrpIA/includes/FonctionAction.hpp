#ifndef FONCTION_ACTION_HPP
#define FONCTION_ACTION_HPP

#include "Sentient_Entity.hpp"
#include "Entity.hpp"

using namespace std;

typedef enum { //Des fonctions d'action ne prennant aucun paramètre spécifique (autre que la Sentient_Entity appelant cette fonction) et ne renvoyant rien du tout
	IDLE,
	DORMIR,
	GOTO_HAUT,
	GOTO_BAS,
	GOTO_GAUCHE,
	GOTO_DROITE
} Fonction_Action_Simple;


typedef enum { //Des fonction d'action prenant un paramètre spécifique(une Entity) et ne renvoyant rien du tout
	GoTo
} Fonction_Action_Parametre;

typedef enum { //Des fonctions prenant un paramètre spécifique et renvoyant une Entity
	GetHallOf,
	GetNearestOf
} Fonction_Action_Parametre_Retour;

class FonctionAction {
	public :
		static map<Fonction_Action_Simple			, void(*)		(Sentient_Entity * a)> mapFonctionsSimple;
		static map<Fonction_Action_Parametre		, void(*)		(Sentient_Entity * a, Entity * e)> mapFonctionsParametre;
		static map<Fonction_Action_Parametre_Retour	, Entity *(*)	(Sentient_Entity * a, Entity * e)> mapFonctionsParametreRetour;
};

//Fonction_Action_Simple
void idle(Sentient_Entity * agent);
void dormir(Sentient_Entity * agent);
void goto_haut(Sentient_Entity * agent);
void goto_bas(Sentient_Entity * agent);
void goto_gauche(Sentient_Entity * agent);
void goto_droite(Sentient_Entity * agent);

//Fonction_Action_Parametre
void go_to(Sentient_Entity * agent, Entity * e);

//Fonction_Action_Parametre_Retour
Entity * getHallOf(Sentient_Entity * agent, Entity * e);
Entity * getNearesOf(Sentient_Entity * agent, Entity * e);
#endif
