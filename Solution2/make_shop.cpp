#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

class Item {
private:
	std::string m_name;
	std::string m_description;
	int m_weight;
	int m_value;

public:
	Item(std::string name, std::string description, int weight, int value) :m_name(name), m_description(description), m_weight(weight), m_value(value) {}
	virtual void Describe() {
		std::cout << "Name        = " << m_name << std::endl;
		std::cout << "Description = " << m_description << std::endl;
		std::cout << "Weight      = " << m_weight << std::endl;
		std::cout << "Value       = " << m_value << std::endl;
	}
};

class Weapon : public Item {
private:
	int m_damage;

public:
	Weapon(std::string name, std::string description, int weight, int value, int damage) : Item(name, description, weight, value), m_damage(damage) {}
	void Describe() override {
		Item::Describe();
		std::cout << "Damage      = " << m_damage << "\n\n";
	}
	~Weapon() {}
};

class Armor : public Item {
private:
	int m_defense;

public:
	Armor(std::string name, std::string description, int weight, int value, int defense) : Item(name, description, weight, value), m_defense(defense) {}
	void Describe() override {
		Item::Describe();
		std::cout << "Defense     = " << m_defense << "\n\n";
	}
	~Armor() {}
};

class Potion : public Item {
private :
	std::string m_type;
	int m_capacity;

public:
	Potion(std::string name, std::string description, int weight, int value, std::string type, int capacity) : 
		Item(name, description, weight, value), m_type(type),m_capacity(capacity) {}
	void Describe() override {
		Item::Describe();
		std::cout << "Type        = " << m_type << std::endl;
		std::cout << "Capacity    = " << m_capacity << "\n\n";
	}
	~Potion() {}

};

class Shop {
private:
	std::string m_name;
	std::vector<std::shared_ptr<Item>> m_items;
public:
	Shop() {}
	Shop(std::string name, std::initializer_list<std::shared_ptr<Item>> items) : m_name(name), m_items(items) {}

	void ShowItemList() {
		std::cout << "Welcome to " << m_name << "!" << std::endl;
		std::cout << "- Item List -" << std::endl;
		for (auto& item : m_items)
		{
			item->Describe();
		}
	}
};

int main()
{
	Shop weaponArmorShop = Shop(
		"Weapon/Armor Shop",
		{
		std::make_shared<Weapon>("Sword", "Medium DMG", 3, 10, 10),
		std::make_shared<Armor>("Cap", "Light Armor", 1, 5, 5),
		std::make_shared<Armor>("Gloves", "Light Armor", 1, 5, 5),
		std::make_shared<Weapon>("Axe", "High DMG", 5, 1, 1),
		std::make_shared<Armor>("Boots", "Light Armor", 1, 5, 5)
		});

	Shop potionShop = Shop(
		"Potion Shop",
		{
		std::make_shared<Potion>("Small Health Potion", "Recovery 100 HP", 2, 5, "Health", 100),
		std::make_shared<Potion>("Small Mana Potion", "Recovery 50 MP", 1, 30, "Mana", 50),
		std::make_shared<Potion>("Medium Health Potion", "Recovery 200 HP", 4, 120, "Health", 200),
		std::make_shared<Potion>("Medium Mana Potion", "Recovery 100 MP", 2, 75, "Mana", 100),
		std::make_shared<Potion>("Large Health Potion", "Recovery 300 HP", 6, 200, "Health", 300)
		});

	int inputIndex = 0;
	while (true)
	{
		std::cout << " - Shop Select - " << std::endl;
		std::cout << "   1. Weapon/Armor Shop" << std::endl;
		std::cout << "   2. Potion Shop" << std::endl;
		std::cout << "   3. Exit" << std::endl;
		std::cout << std::endl;

		std::cout << "Select : ";
		std::cin >> inputIndex;

		switch (inputIndex) {
		case 1:
			system("cls");
			weaponArmorShop.ShowItemList();
			break;
		case 2:
			system("cls");
			potionShop.ShowItemList();
			break;
		case 3:
			exit(0);
			break;
		default:
			system("cls");
			std::cout << "Invalid number! Try again." << std::endl << std::endl;
			break;
		}
	}
}