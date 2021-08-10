#pragma once


class BAKKESMOD_PLUGIN_IMPORT CareerStatsWrapper
{
public:
	struct StatValue
	{
		std::string stat_name;
		int private_;
		int unranked;
		int ranked;
	};

	_NODISCARD static std::vector<StatValue> GetStatValues();
};
