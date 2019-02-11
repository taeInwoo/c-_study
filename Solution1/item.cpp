#include "pch.h"
#include <iostream>
#include <string>

#include "Item.h"


Item::Item(std::string name, std::string description, int weight, int value)
	: m_name(name), m_description(description), m_weight(weight), m_value(value) {}

void Item::Describe() {
	std::cout << "Name        = " << m_name << std::endl;
	std::cout << "Description = " << m_description << std::endl;
	std::cout << "Weight      = " << m_weight << std::endl;
	std::cout << "Value       = " << m_value << std::endl;
}

Weapon::Weapon(std::string name, std::string description, int weight, int value, int damage)
	: Item(name, description, weight, value), m_damage(damage) {}

void Weapon::Describe() {
	Item::Describe();
	std::cout << "Damage      = " << m_damage << "\n\n";
}

Armor::Armor(std::string name, std::string description, int weight, int value, int defense) 
	: Item(name, description, weight, value), m_defense(defense) {}

void Armor::Describe() {
	Item::Describe();
	std::cout << "Defense     = " << m_defense << "\n\n";
}