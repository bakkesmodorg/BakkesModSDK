#pragma once
#include "../Engine/ObjectWrapper.h"

class BAKKESMOD_PLUGIN_IMPORT ModalWrapper : public ObjectWrapper
{
public:
	CONSTRUCTORS(ModalWrapper)

	void ShowModal() const;
	void CloseModal();
	void SetColor(float r, float g, float b);
	void SetIcon(const std::string& iconName);
	void SetBody(const std::string& bodyHtml);
	void AddButton(const std::string& button_text, bool is_cancel_button, std::function<void()> click_callback = nullptr);


private:
	PIMPL
};


