#include "ia/Tools/Factories.hpp"
#include "ia/Behavior/Comportement.hpp"


Sentient_Entity * Factories::createAgent() {
	std::vector<int> characs;
	ifstream file (PATH_DATA"/Characteristics_Agent.json", ios::in);
	if (file.is_open()) {
		string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

		file.close();
		cJSON *root = cJSON_Parse(str.c_str());
		cJSON *child = cJSON_GetObjectItem(root, "characteristicsAgent");
		int	nb = cJSON_GetArraySize(child);
		cJSON *item;
		cJSON *id;
		for (int i = 0; i < nb; i++) {
			item = cJSON_GetArrayItem(child, i);
			id = cJSON_GetObjectItem(item, "id");
			if (id->type == cJSON_Number) {
				characs.push_back(id->valueint);
			}
		}
	} else {
		std::cout << "Unable to open file for the Agent Characteristics" << std::endl;
		return nullptr;
	}

	std::map<int, int> characs_val;
	for (unsigned int i = 0; i < characs.size(); i++)
	{
		characs_val.insert(std::pair<int, int>(characs[i], -1));
	}
	std::cout << std::endl;

	characs_val[C_VITALITY]             = 100;
	characs_val[C_AGE]                  = rand (0, 11);
	characs_val[C_SATIETY]              = 100;
	characs_val[C_STAMINA]              = 100;
	characs_val[C_SATIETY_THRESHOLD]    = rand(20, 31);
	characs_val[C_STAMINA_THRESHOLD]    = rand(20, 31);
	characs_val[C_SATIETY_DECADE_VALUE] = 1;
	characs_val[C_STAMINA_DECADE_VALUE] = 1;
	characs_val[C_CAPACITY] = 0;

	for (std::vector<int>::iterator it = characs.begin(); it != characs.end(); it++)
	{
		if (characs_val[*it] == -1)
		{
			int min = Characteristics::listCharacteristics[*it].getMin();
			int max = Characteristics::listCharacteristics[*it].getMax();
			int val = rand (min, max + 1);
			characs_val[*it] = val;
		}
	}

	int fitness = characs_val[C_FITNESS];
	if (fitness > 66) {
		characs_val[C_SATIETY_DECADE] = 15;
		characs_val[C_STAMINA_DECADE] = 15;
	}
	else if (fitness <= 66 && fitness > 33) {
		characs_val[C_SATIETY_DECADE] = 10;
		characs_val[C_STAMINA_DECADE] = 10;
	}
	else if (fitness <= 33) {
		characs_val[C_SATIETY_DECADE] = 5;
		characs_val[C_STAMINA_DECADE] = 5;
	}

	// std::cout << "fitness = " << fitness << std::endl;
	characs_val[C_CAPACITY] = 150 + (8 * fitness);


	std::string name;
	if (characs_val[1] == 0)
		name = getRandomMaleName();
	else
		name = getRandomFemaleName();

	Sentient_Entity * res = new Sentient_Entity(Position(0, 0), characs_val, name, ID_AGENT);

	res->setComportement(Comportement::listComportements[0]);

	return res;
}

Sentient_Entity * Factories::createAnimal() {
	std::vector<int> characs;

	ifstream file (PATH_DATA"/Characteristics_Animal.json", ios::in);
	if (file.is_open()) {
		string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

		file.close();

		cJSON *root = cJSON_Parse(str.c_str());

		cJSON *child = cJSON_GetObjectItem(root, "characteristicsAnimal");
		int	nb = cJSON_GetArraySize(child);
		for (int i = 0; i < nb; i++) {
			cJSON *item = cJSON_GetArrayItem(child, i);
			cJSON *id = cJSON_GetObjectItem(item, "id");
			if (id->type == cJSON_Number) {
				characs.push_back(id->valueint);
			}
		}

	} else {
		std::cout << "Unable to open file for the Animal Characteristics" << std::endl;
		return nullptr;
	}

	std::map<int, int> characs_val;
	for (unsigned int i = 0; i < characs_val.size(); i++)
	{
		characs_val.insert(std::pair<int, int>(characs[i], -1));
	}

	characs_val[C_VITALITY]             = 100;
	characs_val[C_AGE]                  = rand (0, 11);
	characs_val[C_SATIETY]              = 100;
	characs_val[C_STAMINA]              = 100;
	characs_val[C_SATIETY_THRESHOLD]    = rand(20, 31);
	characs_val[C_STAMINA_THRESHOLD]    = rand(20, 31);
	characs_val[C_SATIETY_DECADE_VALUE] = 1;
	characs_val[C_STAMINA_DECADE_VALUE] = 1;

	for (std::vector<int>::iterator it = characs.begin(); it != characs.end(); it++)
	{
		if (characs_val[*it] == -1) {
			int min = Characteristics::listCharacteristics[*it].getMin();
			int max = Characteristics::listCharacteristics[*it].getMax();
			int val = rand (min, max + 1);
			characs_val[*it] = val;
		}

	}

	int fitness = characs_val[C_FITNESS];
	if (fitness > 66) {
		characs_val[C_SATIETY_DECADE] = 15;
		characs_val[C_STAMINA_DECADE] = 15;
	}
	else if (fitness <= 66 && fitness > 33) {
		characs_val[C_SATIETY_DECADE] = 10;
		characs_val[C_STAMINA_DECADE] = 10;
	}
	else if (fitness <= 33) {
		characs_val[C_SATIETY_DECADE] = 5;
		characs_val[C_STAMINA_DECADE] = 5;
	}

	Sentient_Entity * res = new Sentient_Entity(Position(0, 0), characs_val, "mouton", ID_ANIMAL);

	res->setComportement(Comportement::listComportements[0]);

	return res;
}


Tribe * Factories::createTribe() {
	std::vector<int> characs;

	ifstream file (PATH_DATA"/Characteristics_Tribe.json", ios::in);
	if (file.is_open()) {
		string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

		file.close();

		cJSON *root = cJSON_Parse(str.c_str());

		cJSON *child = cJSON_GetObjectItem(root, "characteristicsTribe");
		int	nb = cJSON_GetArraySize(child);
		for (int i = 0; i < nb; i++) {
			cJSON *item = cJSON_GetArrayItem(child, i);
			cJSON *id = cJSON_GetObjectItem(item, "id");
			if (id->type == cJSON_Number) {
				characs.push_back(id->valueint);
			}
		}

	} else {
		std::cout << "Unable to open file for the Tribe Characteristics" << std::endl;
		return nullptr;
	}

	std::map<int, int> characs_val;
	for (std::vector<int>::iterator it = characs.begin(); it != characs.end(); it++)
	{
		int min = Characteristics::listCharacteristics[*it].getMin();
		int max = Characteristics::listCharacteristics[*it].getMax();
		int val = rand (min, max + 1);
		characs_val.insert(std::pair<int, int>(*it, val));
	}

	return new Tribe("placeholder_tribe_name", 0, ID_TRIBE, characs_val);
}


Insentient_Entity * Factories::createResource(ResourceType type) {
	std::vector<int> characs;
	ifstream file (PATH_DATA"/Characteristics_Resource.json", ios::in);
	if (file.is_open()) {
		string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

		file.close();

		cJSON *root = cJSON_Parse(str.c_str());

		cJSON *child = cJSON_GetObjectItem(root, "characteristicsResource");
		int	nb = cJSON_GetArraySize(child);
		for (int i = 0; i < nb; i++) {
			cJSON *item = cJSON_GetArrayItem(child, i);
			cJSON *id = cJSON_GetObjectItem(item, "id");
			if (id->type == cJSON_Number) {
				characs.push_back(id->valueint);
			}
		}

	} else {
		std::cout << "Unable to open file for the Resource Characteristics" << std::endl;
		return nullptr;
	}
	std::map<int, int> characs_val;
	for (std::vector<int>::iterator it = characs.begin(); it != characs.end(); it++)
	{
		int min = Characteristics::listCharacteristics[*it].getMin();
		int max = Characteristics::listCharacteristics[*it].getMax();
		int val = rand (min, max + 1);
		characs_val.insert(std::pair<int, int>(*it, val));
	}

	Insentient_Entity * res = new Insentient_Entity("", ID_VOID, characs_val, 0, 0);

	std::string name;
	Characteristics * c = Characteristics::getCharacById(Characs::C_MAXRESSTOCK);
	int val2 = rand (c->getMin(), c->getMax() + 1);
	switch (type) {
	case ResourceType::T_BOIS:
		name = "Arbre";
		res->setTypeId(ID_RESSOURCE_BOIS);
		res->setVal(C_RESPAWN_VALUE, res->getVal(C_RESPAWN_VALUE) + 5);
		res->addItemToStock(Item::getItemByName("Bois"), val2);
		break;
	case ResourceType::T_PIERRE:
		name = "Caillou";
		res->setTypeId(ID_RESSOURCE_PIERRE);
		res->setVal(C_RESPAWN_VALUE, 0);
		res->addItemToStock(Item::getItemByName("Pierre"), val2);
		break;
	case ResourceType::T_METAL:
		name = "Gisement de metal";
		res->setTypeId(ID_RESSOURCE_METAL);
		res->setVal(C_RESPAWN_VALUE, 0);
		res->addItemToStock(Item::getItemByName("Metal"), val2);
		break;
	case ResourceType::T_LEGUME:
		name = "Un légume";
		res->setTypeId(ID_RESSOURCE_LEGUME);
		res->addItemToStock(Item::getItemByName("Legume"), val2);
		break;
	case ResourceType::T_VIANDE:
		name = "Un steak";
		res->setTypeId(ID_RESSOURCE_VIANDE);
		res->setVal(C_RESPAWN_VALUE, 0);
		res->addItemToStock(Item::getItemByName("Viande"), val2);
		break;
	}

	res->setName(name);
	return res;
}

Insentient_Entity * Factories::createBuilding() {
	std::vector<int> characs;

	ifstream file (PATH_DATA"/Characteristics_Building.json", ios::in);
	if (file.is_open()) {
		string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

		file.close();

		cJSON *root = cJSON_Parse(str.c_str());

		cJSON *child = cJSON_GetObjectItem(root, "characteristicsBuilding");
		int	nb = cJSON_GetArraySize(child);
		for (int i = 0; i < nb; i++) {
			cJSON *item = cJSON_GetArrayItem(child, i);
			cJSON *id = cJSON_GetObjectItem(item, "id");
			if (id->type == cJSON_Number) {
				characs.push_back(id->valueint);
			}
		}

	} else {
		std::cout << "Unable to open file for the Building Characteristics" << std::endl;
		return nullptr;
	}

	std::map<int, int> characs_val;
	for (unsigned int i = 0; i < characs_val.size(); i++)
	{
		characs_val.insert(std::pair<int, int>(characs[i], -1));
	}

	for (std::vector<int>::iterator it = characs.begin(); it != characs.end(); it++)
	{
		if (characs_val[*it] == -1) {
			int min = Characteristics::listCharacteristics[*it].getMin();
			int max = Characteristics::listCharacteristics[*it].getMax();
			int val = rand (min, max + 1);
			characs_val[*it] = val;
		}

	}

	std::string name = "Building";
	// if (characs_val[1] == 0)
	// 	name = getRandomMaleName();
	// else
	// 	name = getRandomFemaleName();

	return new Insentient_Entity(name,  ID_BUILDING, characs_val, 0, 0);
}
