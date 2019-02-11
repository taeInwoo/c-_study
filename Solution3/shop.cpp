#include "pch.h"
#include <iostream>
#include <string>
#include <vector>


#include "shop.h"

Potion::Potion(std::string name, std::string description, int weight, int value, std::string type, int capacity) :
	Item(name, description, weight, value), m_type(type), m_capacity(capacity) {}

void Potion::Describe(){
	Item::Describe();
	std::cout << "Type        = " << m_type << std::endl;
	std::cout << "Capacity    = " << m_capacity << "\n\n";
}

Shop::Shop(std::string name, std::initializer_list<std::shared_ptr<Item>> items) : m_name(name), m_items(items) {}

Shop::Shop(std::string name, std::string fileName) : m_fileStream(name), m_fileName(fileName) {
	m_fileStream.open(m_fileName);
	if (!m_fileStream.is_open()) throw std::bad_exception();
}

Shop::~Shop() {
	m_fileStream.close();
}

void Shop::ReadDataFromFile() {
	std::string imformation;

	std::string type, name, description, potionType;
	int weight,value,damage,defense,capacity;

	while (std::getline(m_fileStream, imformation))
	{
		std::string imformation_2 = imformation;
		
		imformation_2 = imformation_2.substr(imformation_2.find("\"") + 1);
		type = imformation_2.substr(0, imformation_2.find("\""));
		imformation_2 = imformation_2.substr(imformation_2.find("\"") + 1);

		imformation_2 = imformation_2.substr(imformation_2.find("\"") + 1);
		name = imformation_2.substr(0, imformation_2.find("\""));
		imformation_2 = imformation_2.substr(imformation_2.find("\"") + 1);

		imformation_2 = imformation_2.substr(imformation_2.find("\"") + 1);
		description = imformation_2.substr(0, imformation_2.find("\""));
		imformation_2 = imformation_2.substr(imformation_2.find("\"") + 1);

		imformation_2 = imformation_2.substr(1);
		weight = atoi(imformation_2.substr(0, imformation_2.find(" ")).c_str());
		imformation_2 = imformation_2.substr(imformation_2.find(" ") + 1);
		value = atoi(imformation_2.substr(0, imformation_2.find(" ")).c_str());
		imformation_2 = imformation_2.substr(imformation_2.find(" ") + 1);
		
		if (type == "Weapon") {
			damage = atoi(imformation_2.c_str());

			m_items.push_back(std::make_shared<Weapon>(name, description, weight, value, damage));
		}

		else if (type == "Armor") {
			defense = atoi(imformation_2.c_str());

			m_items.push_back(std::make_shared<Armor>(name, description, weight, value, defense));
		}

		else if (type == "Potion") {
			imformation_2 = imformation_2.substr(imformation_2.find("\"") + 1);
			potionType = imformation_2.substr(0, imformation_2.find("\""));
			imformation_2 = imformation_2.substr(imformation_2.find(" ") + 1);
			capacity = atoi(imformation_2.c_str());

			m_items.push_back(std::make_shared<Potion>(name, description, weight, value, potionType, capacity));
		}
		else throw std::bad_exception();
	}
}

void Shop::ShowShopMessage() {
	int inputIndex = 0;

	while (true)
	{
		std::cout << "Welcome to " << m_name << "!" << std::endl;
		std::cout << "-----------------------------" << std::endl;
		std::cout << "1. Show Item List" << std::endl;
		std::cout << "2. Exit" << std::endl;
		std::cout << std::endl;

		std::cout << "Select : ";
		std::cin >> inputIndex;

		switch (inputIndex) {
		case 1:
			ShowItemList();
			break;
		case 2:
			return;
			break;
		default:
			std::cout << "Error: Invalid number, please input again." << std::endl;
			break;
		}
	}
}

void Shop::ShowItemList() {
	std::cout << "Welcome to " << m_name << "!" << std::endl;
	std::cout << "- Item List -" << std::endl;
	for (auto& item : m_items)
	{
		item->Describe();
	}
}