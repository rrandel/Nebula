#include "nbpch.hpp"
#include "WindowsInput.hpp"

#include "Nebula/Core/Application.hpp"

namespace Nebula {

	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		//To-do
		return 0;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		//To-do
		return 0;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		//To-do
		float mouseX = 0.0f; // Replace with actual X coordinate retrieval logic
		float mouseY = 0.0f; // Replace with actual Y coordinate retrieval logic

		// Return the mouse position as a pair of floats
		return std::make_pair(mouseX, mouseY);
	}

	float WindowsInput::GetMouseXImpl()
	{
		//To-do
		return 0;
	}

	float WindowsInput::GetMouseYImpl()
	{
		//To-do
		return 0;
	}

}