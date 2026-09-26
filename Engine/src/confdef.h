#pragma once

namespace Six {
	namespace SConfig {
		enum class SCRenderBackend {
			OpenGL,
			Vulkan,
			DirectX
		};
		inline constexpr int width = 500;
		inline constexpr int height = 500;
		inline constexpr const char* title = "Engine";

		inline constexpr SCRenderBackend renderbackend = SCRenderBackend::OpenGL;

	}

}