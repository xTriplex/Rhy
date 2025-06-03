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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}


