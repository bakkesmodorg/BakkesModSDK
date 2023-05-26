#pragma once
#include "bakkesmod/wrappers/wrapperstructs.h"
#include "bakkesmod/core/compiler_toggles.h"

struct FColorPosition;
struct FLoadoutTeamPaint;

namespace pluginsdk
{
	enum class Itempaint: int
	{
		NONE = 0,
		CRIMSON = 1,
		LIME = 2,
		BLACK = 3,
		SKYBLUE = 4,
		COBALT = 5,
		BURNTSIENNA = 6,
		FORESTGREEN = 7,
		PURPLE = 8,
		PINK = 9,
		ORANGE = 10,
		GREY = 11,
		TITANIUMWHITE = 12,
		SAFFRON = 13,
		GOLD = 14,
		ROSEGOLD = 15,
		WHITEGOLD = 16,
		ONYX = 17,
		PLATINUM = 18
	};

	enum class Equipslot: int
	{
		BODY = 0,
		DECAL = 1,
		WHEELS = 2,
		ROCKETBOOST = 3,
		ANTENNA = 4,
		TOPPER = 5,
		BUMPER = 6,
		PAINTFINISH = 7,
		BOT = 8,
		LOGO = 9,
		UNDERGLOW = 10,
		CRATES = 11,
		CUSTOMFINISH = 12,
		ENGINEAUDIO = 13,
		TRAIL = 14,
		GOALEXPLOSION = 15,
		PLAYERBANNER = 16,
		GARAGECOMPLEXROW = 17,
		GOALSTINGER = 18,
		PLAYERAVATAR = 19,
		AVATARBORDER = 20,
		PLAYERTITLE = 21,
		ESPORTSTEAM = 22,
		ARCHIVEDITEMS = 23,
		BLUEPRINTS = 24,
		SHOPITEM = 25,
		CURRENCY = 26,
		MAX = 27,
	};

	struct TeamPaint
	{
		unsigned char team;
		unsigned char team_color_id = 255;
		unsigned char custom_color_id = 255;

		DEFAULTEQUALITY(TeamPaint)
	};

	struct CarColors
	{
		std::optional<TeamPaint> team_paint;

		inline static LinearColor const default_color{0.0f, 0.0f, 0.0f, 1.0f};
		// null or default_color for the overrides means that the value from team_paint will be used
		std::optional<LinearColor> team_color_override = std::nullopt;
		std::optional<LinearColor> custom_color_override = std::nullopt;

		DEFAULTEQUALITY(CarColors)
	};

	struct ColorPosition
	{
		ColorPosition() = default;
		ColorPosition(int row, int column): row{row}, column{column} {}
		explicit ColorPosition(const FColorPosition& other);
		explicit operator FColorPosition() const;

		int row;
		int column;

		DEFAULTEQUALITY(ColorPosition)
	};

	struct PaintFinishColor
	{
		LinearColor color{0, 0, 0, 1};
		ColorPosition position{-1, -1};
		int index = 0;

		DEFAULTEQUALITY(PaintFinishColor)
	};

	struct ItemAttribute
	{
		enum class AttributeType { UNKNOWN, PAINT, ESPORT, SPECIALEDITION, USERCOLOR };

		AttributeType type = AttributeType::UNKNOWN;
		int value = 0;
		UnrealColor color{0, 0, 0, 0};

		DEFAULTEQUALITY(ItemAttribute)
	};

	struct ItemData
	{
		Equipslot slot = Equipslot::MAX;
		int product_id = 0;
		std::vector<ItemAttribute> attributes = {};

		DEFAULTEQUALITY(ItemData)
	};

	using ItemDataMap = std::map<Equipslot, ItemData>;

	struct Loadout
	{
		ItemDataMap items;
		CarColors paint_finish;

		DEFAULTEQUALITY(Loadout)
	};
}
