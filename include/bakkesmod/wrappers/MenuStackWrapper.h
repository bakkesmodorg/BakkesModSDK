#pragma once
#include "Engine/ObjectWrapper.h"
#include <string>
#include <vector>

/**
 * Notable Events:\n
 * Function TAGame.GFxData_MenuStack_TA.PopMenu\n
 * Function TAGame.GFxData_MenuStack_TA.PushMenu\n
 */
class BAKKESMOD_PLUGIN_IMPORT MenuStackWrapper : public ObjectWrapper
{
	public:
    CONSTRUCTORS(MenuStackWrapper)

    _NODISCARD std::string GetTopMenu() const;
    _NODISCARD std::vector<std::string> GetMenuStack() const;
    _NODISCARD bool IsNull() const;
	_NODISCARD explicit operator bool() const;


private:
    PIMPL
};
