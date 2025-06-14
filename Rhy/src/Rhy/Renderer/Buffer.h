#pragma once

namespace Rhy
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer(){}

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		// To avoid creating a constructor
		static VertexBuffer* Create(float* vertices, uint32_t size);
	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer(){}

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual uint32_t GetCount() const = 0;

		// To avoid creating a constructor
		static IndexBuffer* Create(uint32_t* indices, uint32_t size);
	};
}
