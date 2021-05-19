#pragma once
#include "ModalWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT TextInputModalWrapper : public ModalWrapper
{
public:
	CONSTRUCTORS(TextInputModalWrapper)
	
	void SetTextInput(const std::string& defaultText, int32_t max_text_length, bool password, std::function<void(std::string, bool)> input_callback);

private:
	PIMPL
};
