#pragma once
#include "DogFW/DogBasicTypes.h"
#include "DogFW/External/Windows/DogDX12.h"

namespace DogFW
{
	//4D vector based on storing data into xmFloat_
	class SIMDFVector4D
	{
#pragma region Contructors
	public:
		SIMDFVector4D() : xmFloat_(DirectX::XMFLOAT4(0.f, 0.f, 0.f, 0.f)) {};
		SIMDFVector4D(DirectX::XMFLOAT4 infloat) : xmFloat_(infloat) {};

		SIMDFVector4D(Float x, Float y, Float z, Float w) : xmFloat_(DirectX::XMFLOAT4(x, y, z, w)) {};
		//SIMDFVector4D(uint32 x, uint32 y, uint32 z, uint32 w) : xmFloat_(DirectX::xmfloattorSetInt(x, y, z, w)) {};

		SIMDFVector4D(Float value) : xmFloat_(DirectX::XMFLOAT4(value, value, value, value)) {};
		//SIMDVector4D(uint32 value) :xmFloat_(DirectX::xmfloattorReplicateInt(value)) {};

		//Copy Constr
		SIMDFVector4D(const SIMDFVector4D& in) noexcept : xmFloat_(in.xmFloat_) {};
		//Assign Constr
		SIMDFVector4D(SIMDFVector4D&& in) noexcept : xmFloat_(in.xmFloat_) {};
#pragma endregion Contructors
#pragma region Operators
	public:
		//Assign By Copy
		SIMDFVector4D& operator=(SIMDFVector4D const& in) noexcept
		{
			if (&in != this)
			{
				xmFloat_ = in.xmFloat_;
			}
			return *this;
		}
		//Assign by Move
		SIMDFVector4D& operator=(SIMDFVector4D const&& in) noexcept
		{
			if (&in != this)
			{
				xmFloat_ = in.xmFloat_;
			}
			return *this;
		}

		//Returns Negative(Vector)
		SIMDFVector4D operator-() const
		{
			SIMDFVector4D temp;
			DirectX::XMStoreFloat4(&(temp.xmFloat_), DirectX::XMVectorNegate(DirectX::XMLoadFloat4(&xmFloat_)));
			return temp;
		}

		SIMDFVector4D& operator+=(SIMDFVector4D const& in)
		{
			DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorAdd(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
			return *this;
		}
		SIMDFVector4D& operator-=(SIMDFVector4D const& in)
		{
			DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorSubtract(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
			return *this;
		}
		SIMDFVector4D& operator*=(SIMDFVector4D const& in)
		{
			DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorMultiply(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
			return *this;
		}
		SIMDFVector4D& operator/=(SIMDFVector4D const& in)
		{
			DirectX::XMStoreFloat4(&xmFloat_, DirectX::XMVectorDivide(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&in.xmFloat_)));
			return *this;
		}

		SIMDFVector4D operator+ (SIMDFVector4D const& rin)
		{
			DirectX::XMFLOAT4 temp;
			DirectX::XMStoreFloat4(&temp, DirectX::XMVectorAdd(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
			return SIMDFVector4D(temp);
		}
		SIMDFVector4D operator- (SIMDFVector4D const& rin)
		{
			DirectX::XMFLOAT4 temp;
			DirectX::XMStoreFloat4(&temp, DirectX::XMVectorSubtract(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
			return SIMDFVector4D(temp);
		}
		SIMDFVector4D operator* (SIMDFVector4D const& rin)
		{
			DirectX::XMFLOAT4 temp;
			DirectX::XMStoreFloat4(&temp, DirectX::XMVectorMultiply(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
			return SIMDFVector4D(temp);
		}
		SIMDFVector4D operator/ (SIMDFVector4D const& rin)
		{
			DirectX::XMFLOAT4 temp;
			DirectX::XMStoreFloat4(&temp, DirectX::XMVectorDivide(DirectX::XMLoadFloat4(&xmFloat_), DirectX::XMLoadFloat4(&rin.xmFloat_)));
			return SIMDFVector4D(temp);
		}
#pragma endregion Operators
#pragma region GetSet
	public:
		DirectX::XMFLOAT4 getData() { return xmFloat_; }
		void  setData(DirectX::XMFLOAT4 in) { xmFloat_ = in; };
#pragma endregion GetSet
#pragma region Functions 
	public:
#pragma endregion Functions

	private:
		DirectX::XMFLOAT4 xmFloat_;
	};
}