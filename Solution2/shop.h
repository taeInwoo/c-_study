#ifndef SHOP
#define SHOP

#include "ITEM.h"

class Potion : public Item {

public:
	Potion(std::string name, std::string description, int weight, int value, std::string type, int capacity);
	void Describe() override;

protected:
	std::string m_type;
	int m_capacity;
};

class Shop {

public:
	Shop();
	Shop(std::string name, std::initializer_list<std::shared_ptr<Item>> items);
	void ShowItemList();

protected:
	std::string m_name;
	std::vector<std::shared_ptr<Item>> m_items;
};
#endif
