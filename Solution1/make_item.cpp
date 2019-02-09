#include "pch.h"
#include <iostream>
#include <string>

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

int main()
{
	Item* item = new Weapon("Excalibur", "The legendary sword of King Arthur", 12, 1024, 24);
	item->Describe();

	item = new Armor("Steel Armor", "Protective covering made by steel", 15, 805, 18);
	item->Describe();

	delete item;
	std::cout << "test";
}