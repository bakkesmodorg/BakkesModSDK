#pragma once
#include "ProductAttributeWrapper.h"
#include <vector>

struct SpecialEdition {
	int productId;
	int editionId;
	std::string label;
};


class BAKKESMOD_PLUGIN_IMPORT ProductAttribute_SpecialEditionSettingsWrapper : public ProductAttributeWrapper {
public:
	CONSTRUCTORS(ProductAttribute_SpecialEditionSettingsWrapper)

		std::vector<SpecialEdition> GetEditions();



private:
	PIMPL
};