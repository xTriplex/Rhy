#pragma once

namespace Rhy
{
	enum class RendererAPI
	{
		None = 0, // For unit testing etc. when you don't need a renderer.
		OpenGL = 1
	};

	class Renderer
	{
	public:
		inline static RendererAPI GetAPI() { return s_RendererAPI; }
	private:
		static RendererAPI s_RendererAPI;
	};
}
