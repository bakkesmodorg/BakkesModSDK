#pragma once
#include "bakkesmod/core/loadout_structs.h"

class BAKKESMOD_PLUGIN_IMPORT LoadoutUtilities
{
public:

	// only works in replays
	void static SetLoadoutItems(const PriWrapper& pri_wrapper, const pluginsdk::ItemDataMap& loadout);
	void static SetCarProductAttributes(const CarWrapper& car_wrapper, const pluginsdk::ItemDataMap& loadout);
	void static SetLoadoutPaintFinishColors(const CarWrapper& car_wrapper, const pluginsdk::CarColors& paint_finish);
	void static ForceSetLoadout(const PriWrapper& pri_wrapper, const pluginsdk::Loadout& loadout);

	// can be called any time
	_NODISCARD static pluginsdk::CarColors GetPaintFinishColors(const CarWrapper& car_wrapper);
	_NODISCARD static std::optional<pluginsdk::Loadout> GetLoadoutFromPri(const PriWrapper& pri_wrapper, int team_index);
	_NODISCARD static std::vector<pluginsdk::PaintFinishColor> GetBlueColorSet();
	_NODISCARD static std::vector<pluginsdk::PaintFinishColor> GetOrangeColorSet();
	_NODISCARD static std::vector<pluginsdk::PaintFinishColor> GetCustomColorSet();

};
