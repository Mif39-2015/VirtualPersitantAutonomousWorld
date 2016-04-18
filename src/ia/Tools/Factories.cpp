#include "ia/Tools/Factories.hpp"

Sentient_Entity * Factories::createAgent() {
	std::vector<int> characs;

	ifstream file (PATH_DATA"/Characteristics_Agent.json", ios::in);
	if (file.is_open()) {
		string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

		file.close();

		cJSON *root = cJSON_Parse(str.c_str());

		cJSON *child = cJSON_GetObjectItem(root, "characteristicsAgent");
		int	nb = cJSON_GetArraySize(child);
		for (int i = 0; i < nb; i++) {
			cJSON *item = cJSON_GetArrayItem(child, i);
			cJSON *id = cJSON_GetObjectItem(item, "id");
			if (id->type == cJSON_Number) {
				characs.push_back(id->valueint);
			}
		}

	} else {
		std::cout << "Unable to open file for the Agent Characteristics" << std::endl;
		return nullptr;
	}

	std::map<int, int> characs_val;
	for (unsigned int i = 0; i < characs_val.size(); i++)
	{
		characs_val.insert(std::pair<int, int>(characs[i], -1));
	}

	characs_val[C_VITALITY] = 100;
	characs_val[C_AGE] = 0;
	characs_val[C_SATIETY] = 100;

	for (std::vector<int>::iterator it = characs.begin(); it != characs.end(); it++)
	{
		if (characs_val.at(*it) == -1)
		{
			int min = Characteristics::listCharacteristics[*it].getMin();
			int max = Characteristics::listCharacteristics[*it].getMax();
			int val = rand (min, max + 1);
			characs_val[*it] = val;
		}
	}

	std::string name;
	if (characs_val[1] == 0)
		name = getRandomMaleName();
	else
		name = getRandomFemaleName();

	return new Sentient_Entity(Position(0, 0), characs_val, name,  ID_AGENT);
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

	characs_val[C_VITALITY] = 100;
	characs_val[C_AGE] = 0;
	characs_val[C_SATIETY] = 100;

	for (std::vector<int>::iterator it = characs.begin(); it != characs.end(); it++)
	{
		int min = Characteristics::listCharacteristics[*it].getMin();
		int max = Characteristics::listCharacteristics[*it].getMax();
		int val = rand (min, max + 1);
		characs_val[*it] = val;
	}

	return new Sentient_Entity(Position(0, 0), characs_val, "mouton", ID_ANIMAL);
}

Item * Factories::createItem() {
	std::vector<int> characs;

	ifstream file (PATH_DATA"/Characteristics_Item.json", ios::in);
	if (file.is_open()) {
		string str((std::istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

		file.close();

		cJSON *root = cJSON_Parse(str.c_str());

		cJSON *child = cJSON_GetObjectItem(root, "characteristicsItem");
		int	nb = cJSON_GetArraySize(child);
		for (int i = 0; i < nb; i++) {
			cJSON *item = cJSON_GetArrayItem(child, i);
			cJSON *id = cJSON_GetObjectItem(item, "id");
			if (id->type == cJSON_Number) {
				characs.push_back(id->valueint);
			}
		}

	} else {
		std::cout << "Unable to open file for the Item Characteristics" << std::endl;
		return nullptr;
	}

	std::map<int, int> characs_val;
	for (unsigned int i = 0; i < characs_val.size(); i++)
	{
		characs_val.insert(std::pair<int, int>(characs[i], -1));
	}

	for (std::vector<int>::iterator it = characs.begin(); it != characs.end(); it++)
	{
		int min = Characteristics::listCharacteristics[*it].getMin();
		int max = Characteristics::listCharacteristics[*it].getMax();
		int val = rand (min, max + 1);
		characs_val[*it] = val;
	}

	return new Item("placeholder_item_name", ID_ITEM, characs_val);
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

	switch (type) {
	case ResourceType::T_BOIS:
		break;
	case ResourceType::T_PIERRE:
		break;
	case ResourceType::T_METAL:
		break;
	}

	/*std::string name;
	if (characs_val[1] == 0)
	    name = getRandomMaleName();
	else
	    name = getRandomFemaleName();*/

	return new Insentient_Entity("name",  ID_RESSOURCE, characs_val, 0, 0, 0);
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
		int min = Characteristics::listCharacteristics[*it].getMin();
		int max = Characteristics::listCharacteristics[*it].getMax();
		int val = rand (min, max + 1);
		characs_val[*it] = val;
	}

	std::string name;
	if (characs_val[1] == 0)
		name = getRandomMaleName();
	else
		name = getRandomFemaleName();

	return new Insentient_Entity(name,  ID_RESSOURCE, characs_val, 0, 0, 0);
}
