#pragma once
#include "../plugin/bakkesmodsdk.h"
#include "wrapperstructs.h"
#include <memory>
#include <typeindex>
#include <functional>
#include <string>

class CVarWrapper;

class BAKKESMOD_PLUGIN_IMPORT CVarWrapper
{
public:
	CVarWrapper(std::uintptr_t mem, std::type_index pluginIdx);
	CVarWrapper(const CVarWrapper& other);
	CVarWrapper& operator=(CVarWrapper rhs);
	~CVarWrapper();

private:
	PIMPL

public:
	std::string getCVarName();
	int getIntValue();
	float getFloatValue();
	bool getBoolValue();
    LinearColor getColorValue();//Returns {0,0,0,0} if bad formatting. Good: "(R, G, B, A)" (0-255 range), or 6/8 hex ("#123ABC" or "#1234ABCD", capitalization doesn't matter)
	std::string getStringValue();
	std::string getDescription();
	const std::string GetDefaultValue();
	bool HasMinimum();
	bool HasMaximum();
	float GetMinimum();
	float GetMaximum();
	bool IsHidden();
	bool ShouldSaveToCfg();
	void ResetToDefault();
	void notify(); //Will send a notification to all listeners, (for example when new gameevent is loaded or cvar is changed)
	void setValue(std::string value);
	void setValue(int value);
	void setValue(float value);
    void setValue(LinearColor value);//Input should be 0-255 range
	void addOnValueChanged(std::function<void(std::string, CVarWrapper)> changeFunc); //string is old value, cvarwrapper is cvar now.
	void removeOnValueChanged();
	void bindTo(std::shared_ptr<int> var);
	void bindTo(std::shared_ptr<float> var);
	void bindTo(std::shared_ptr<std::string> var);
	void bindTo(std::shared_ptr<bool> var);
    void bindTo(std::shared_ptr<LinearColor> var);
	bool IsNull();
	explicit operator bool();
};

