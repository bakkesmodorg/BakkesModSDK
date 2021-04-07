#pragma once

#include <map>
#include <vector>

struct BotLoadoutData
{
	struct Attribute
	{
		enum class Type { PAINT, ESPORTWHEEL, SPECIALEDITION };

		Type type;
		int value;
	};

	std::map<int, int> products;
	std::map<int, std::vector<Attribute>> product_attributes;

	// not used, but leaving it in here "just in case" for later.
	unsigned char team = 0;

	int team_finish_id = 0;
	int custom_finish_id = 0;
	unsigned char team_color_id = 0;
	unsigned char custom_color_id = 0;
};
