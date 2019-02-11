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

void Shop::ShowItemList() {
	std::cout << "Welcome to " << m_name << "!" << std::endl;
	std::cout << "- Item List -" << std::endl;
	for (auto& item : m_items)
	{
		item->Describe();
	}
}