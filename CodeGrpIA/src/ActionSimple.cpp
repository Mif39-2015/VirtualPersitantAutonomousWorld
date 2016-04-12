#include "ActionSimple.hpp"

void ActionSimple::Executer(Sentient_Entity * agent){
	if(fV!=FONC_V_NULL){
		MapEnumPointeur::mapFoncVoid[fV](agent);
	}
	else{
		Entity * e = parametreFinal;
		while(!sFEE.empty()){
			e = MapEnumPointeur::mapFoncEntityEntity[sFEE.top()](agent,e);
			sFEE.pop();
		}
		MapEnumPointeur::mapFoncVoidEntity[fVE](agent,e);
	}
}
