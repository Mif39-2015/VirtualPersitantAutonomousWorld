#include "Behavior/Arete.hpp"

bool Arete::isTrue(Sentient_Entity * a){
	for(auto it=condition_simple.begin(); it!=condition_simple.end(); ++it){
		if(!MapEnumPointeur::mapFoncBool[*it](a)) return false;
	}
	for(auto it=condition_Complexe.begin(); it!=condition_Complexe.end(); ++it){
		Entity * e = it->e1;
		while(!it->fEE1.empty()) {
			e = MapEnumPointeur::mapFoncEntityEntity[it->fEE1.top()](a,e);
			it->fEE1.pop();
		}

		int val1 = MapEnumPointeur::mapFoncIntEntity[it->fIE1](a,e);

		int val2;
		if(it->fIE2!=FONC_I_E_NULL){
			e = it->e2;
			while(!it->fEE2.empty()) {
				e = MapEnumPointeur::mapFoncEntityEntity[it->fEE2.top()](a,e);
				it->fEE2.pop();
			}
			val2 = MapEnumPointeur::mapFoncIntEntity[it->fIE2](a,e);
		}
		else {
			val2 = it->comp;
		}

		switch (it->op){
			case Inf :
				if(!(val1<val2)) return false;
				break;
			case Inf_Eg :
				if(!(val1<=val2)) return false;
				break;
			case Eg :
				if(!(val1==val2)) return false;
				break;
			case Sup_Eg :
				if(!(val1>=val2)) return false;
				break;
			case Sup :
				if(!(val1>val2)) return false;
				break;
			default :
				break;
		}
	}
	return true;
}
