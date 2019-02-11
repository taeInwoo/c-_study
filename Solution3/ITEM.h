#ifndef ITEM_H
#define ITEM_H

class Item
{
public:
	Item(std::string name, std::string description, int weight, int value);
	virtual void Describe();

protected:
	std::string m_name;
	std::string m_description;
	int m_weight;
	int m_value;
};

class Weapon : public Item {
public:
	Weapon(std::string name, std::string description, int weight, int value, int damage);
	void Describe() override;
protected:
	int m_damage;
};

class Armor : public Item {
public:
	Armor(std::string name, std::string description, int weight, int value, int defense);
	void Describe() override;
protected:
	int m_defense;
};
#endif