#pragma once
#include "bakkesmod/core/compiler_toggles.h"

namespace pluginsdk
{
	using Tex = std::shared_ptr<ImageWrapper>;
	using TextureOverride = std::map<std::string, Tex>;
	using ColorOverride = std::map<std::string, LinearColor>;
	using ScalarOverride = std::map<std::string, float>;

	struct ShaderOverride
	{
		TextureOverride textures;
		ColorOverride colors;
		ScalarOverride scalar;

		DEFAULTEQUALITY(ShaderOverride)
	};

	struct BodyShaderOverride
	{
		ShaderOverride body_mic_override;
		ShaderOverride chassis_mic_override;
		int body_id = -1;
		int skin_id = -1;

		DEFAULTEQUALITY(BodyShaderOverride)
	};
}
