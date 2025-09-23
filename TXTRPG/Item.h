#pragma once
class Item
{
public:
	std::string name;
	std::string effect;
	Item(std::string n, std::string e)
		:name(n), effect(e) {}
};

