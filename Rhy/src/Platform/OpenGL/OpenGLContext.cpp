#include "rpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Rhy
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		R_CORE_ASSERT(windowHandle, "Window Handle was not found! NULL");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		R_CORE_ASSERT(status, "Failed to initialize GLAD!!!");

		R_CORE_INFO("OpenGL Renderer: {0}", (const char*)glGetString(GL_RENDERER));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
