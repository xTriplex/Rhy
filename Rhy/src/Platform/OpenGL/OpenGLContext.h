#pragma once

#include <backends/imgui_impl_glfw.h>

#include "GLFW/glfw3.h"
#include "Rhy/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Rhy
{

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_WindowHandle;
	};
}

