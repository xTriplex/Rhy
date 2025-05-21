#pragma once

#include "Rhy/Layer.h"

namespace Rhy
{
	class KeyTypedEvent;
	class WindowResizeEvent;
	class KeyReleasedEvent;
	class KeyPressedEvent;
	class MouseScrolledEvent;
	class MouseMovedEvent;
	class MouseButtonReleasedEvent;
	class MouseButtonPressedEvent;

	class RHY_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleased(MouseButtonReleasedEvent& e);
		bool OnMouseMoved(MouseMovedEvent& e);
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnKeyPressed(KeyPressedEvent& e);
		bool OnKeyReleased(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowsResizedEvent(WindowResizeEvent& e);  



	private:
		float m_Time = 0.0f;
	};
}


