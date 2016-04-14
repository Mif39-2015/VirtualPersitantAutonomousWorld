#ifndef ACTIONSIMPLE_HPP
#define ACTIONSIMPLE_HPP

using namespace std;

#include "Behavior/Action.hpp"
#include "FonctionEnums.hpp"

#include <stack>

class ActionSimple : public Action {
	private :

		FONC_VOID fV = FONC_V_NULL;
		FONC_VOID_ENTITY fVE = FONC_V_E_NULL;

		stack<FONC_ENTITY_ENTITY> sFEE;
		Entity * parametreFinal;

	public :
		void Executer(Sentient_Entity * agent);

		ActionSimple(){};
		ActionSimple(FONC_VOID foncVoid) : fV(foncVoid){}
		ActionSimple(FONC_VOID_ENTITY foncVoidEntity, stack<FONC_ENTITY_ENTITY> stack, Entity * e) : fVE(foncVoidEntity), sFEE(stack), parametreFinal(e){}

		FONC_VOID getFonc_Void(){return fV;}
		FONC_VOID_ENTITY getFonc_Void_Entity(){return fVE;}
		stack<FONC_ENTITY_ENTITY> getStackFonc_Entity_Entity(){return sFEE;}
		Entity * getParametreFinal(){return parametreFinal;}

		void setFonc_Void(FONC_VOID foncVoid){fV = foncVoid;}
		void setFonc_Void_Entity(FONC_VOID_ENTITY foncVoidEntity){fVE = foncVoidEntity;}
		void setStackFonc_Entity_Entity(stack<FONC_ENTITY_ENTITY> stackFoncEntityEntity){sFEE = stackFoncEntityEntity;}
		void setParametreFinal(Entity * e){parametreFinal=e;}

		void ajouterFonc_Entity_Entity(FONC_ENTITY_ENTITY foncEntityEntity){sFEE.push(foncEntityEntity);}
};

#endif
