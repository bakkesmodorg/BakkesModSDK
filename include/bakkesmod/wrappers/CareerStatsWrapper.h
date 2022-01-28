#pragma once


class BAKKESMOD_PLUGIN_IMPORT CareerStatsWrapper
{
public:
	struct StatValue
	{
		std::string stat_name;
		int32_t private_;
		int32_t unranked;
		int32_t ranked;
	};

	_NODISCARD static std::vector<StatValue> GetStatValues();
};
