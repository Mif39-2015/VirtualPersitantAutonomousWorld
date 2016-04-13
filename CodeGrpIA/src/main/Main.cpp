#include <iostream>
#include <msgpack.hpp>
#include <string>
#include <sstream>

#include "Entity/Characteristics.hpp"
#include "Tools/Factories.hpp"
#include "Behavior/Comportement.hpp"
#include "Entity/Sentient_Entity.hpp"

void scenario(){
    std::string name = "Mykaz";
    type tid = ID_AGENT;
    Sentient_Entity* agent = new Sentient_Entity(Position(0, 0),name,tid);

    Comportement comp;
    Noeud noeudPasFaim;
    Noeud noeudFaim;

    std::vector<FONC_BOOL> vectFctTrue;
    vectFctTrue.push_back(Fonction_BOOL_TRUE);
    Arete areteTrue(&noeudPasFaim,&noeudFaim,vectFctTrue);

    std::vector<FONC_BOOL> vectFctFalse;
    vectFctFalse.push_back(Fonction_BOOL_FALSE);
    Arete areteFalse(&noeudFaim,&noeudPasFaim,vectFctFalse);

    noeudPasFaim.addAreteIn(&areteFalse);
    noeudPasFaim.addAreteOut(&areteTrue);
    noeudFaim.addAreteIn(&areteTrue);
    noeudFaim.addAreteOut(&areteFalse);

    Noeud* noeudCourant = &noeudPasFaim;

    comp.ajouterNoeud(&noeudPasFaim);
    comp.ajouterNoeud(&noeudFaim);

    for(int i = 0; i < 5; i++){
	    std::cout << "Noeud courant : " << noeudCourant << std::endl;
	    noeudCourant = noeudCourant->executerNoeud(agent);
	}
}

int testMsgpack(void)
{
    msgpack::type::tuple<int, bool, std::string> src(1, true, "example");

    // serialize the object into the buffer.
    // any classes that implements write(const char*,size_t) can be a buffer.
    std::stringstream buffer;
    msgpack::pack(buffer, src);

    // send the buffer ...
    buffer.seekg(0);

    // deserialize the buffer into msgpack::object instance.
    std::string str(buffer.str());

    msgpack::object_handle oh =
        msgpack::unpack(str.data(), str.size());

    // deserialized object is valid during the msgpack::object_handle instance is alive.
    msgpack::object deserialized = oh.get();

    // msgpack::object supports ostream.
    std::cout << deserialized << std::endl;

    // convert msgpack::object instance into the original type.
    // if the type is mismatched, it throws msgpack::type_error exception.
    msgpack::type::tuple<int, bool, std::string> dst;
    deserialized.convert(dst);

    return 0;
}

int main(int argc, char const *argv[])
{

    // scenario();
    int loadResult = CharacteristicsList::loadCharacteristicsFile("data/descriptionCharacteristics.txt");

    // if(loadResult != -1){
    //     for (auto it = begin (CharacteristicsList::listCharacteristics); it != end (CharacteristicsList::listCharacteristics); ++it) {
    //         std::cout <<it->getType() << std::endl ;
    //     }
    // }

    // testMsgpack();

    Sentient_Entity * agent = Factories::createAgent();
    std::cout << agent->getName() << std::endl;
    return 0;
}
