#pragma once
#include <cwchar>
#include "../WrapperStructs.h"
#include "../ArrayWrapper.h"
class PrimitiveComponentWrapper;
template class BAKKESMOD_PLUGIN_IMPORT ArrayWrapper<wchar_t>;

class BAKKESMOD_PLUGIN_IMPORT UnrealStringWrapper : public ArrayWrapper<wchar_t> {
public:
	CONSTRUCTORS(UnrealStringWrapper)
public:
	std::string ToString();
	std::wstring ToWideString();
	bool IsNull();
	explicit operator bool();
private:
	PIMPL
};
