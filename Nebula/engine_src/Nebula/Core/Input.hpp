#pragma once

#include "Nebula/Core/KeyCodes.hpp"
#include "Nebula/Core/MouseCodes.hpp"

#include <glm/glm.hpp>

namespace Nebula {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);
		static void Init();

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}