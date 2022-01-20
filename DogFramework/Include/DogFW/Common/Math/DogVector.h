#pragma once
#include "DogFW/Common/Math/SIMDVectorA.h"

namespace DogFW
{
	using Vector4 = SIMDVector4DAligned;



	//4D vector based on storing data into XMFloat
	class SIMDFVector4D
	{

#pragma region Contructors
	public:
		SIMDFVector4D() : xmfloat(DirectX::XMFLOAT4(0.f, 0.f, 0.f, 0.f)) {};
		SIMDFVector4D(DirectX::XMFLOAT4 infloat) : xmfloat (infloat)  {};

		SIMDFVector4D(float x, float y, float z, float w) : xmfloat(DirectX::XMFLOAT4(x, y, z, w)) {};
		//SIMDFVector4D(uint32 x, uint32 y, uint32 z, uint32 w) : xmfloat(DirectX::xmfloattorSetInt(x, y, z, w)) {};

		SIMDFVector4D(float value) : xmfloat(DirectX::XMFLOAT4(value, value, value, value)) {};
		//SIMDVector4D(uint32 value) :xmfloat(DirectX::xmfloattorReplicateInt(value)) {};

		//Copy Constr
		SIMDFVector4D(const SIMDFVector4D& in) noexcept : xmfloat(in.xmfloat) {};
		//Assign Constr
		SIMDFVector4D(SIMDFVector4D&& in) noexcept : xmfloat(in.xmfloat) {};
#pragma endregion Contructors
#pragma region Operators
	public:
		//Assign By Copy
		SIMDFVector4D& operator=(SIMDFVector4D const& in) noexcept
		{
			if (&in != this)
			{
				xmfloat = in.xmfloat;
			}
			return *this;
		}
		//Assign by Move
		SIMDFVector4D& operator=(SIMDFVector4D const&& in) noexcept
		{
			if (&in != this)
			{
				xmfloat = in.xmfloat;
			}
			return *this;
		}

		//Returns Negative(Vector)
		SIMDFVector4D operator-() const
		{
			SIMDFVector4D temp;
			DirectX::XMStoreFloat4(&(temp.xmfloat),DirectX::XMVectorNegate(DirectX::XMLoadFloat4(&xmfloat)));
			return temp;
		}

		SIMDFVector4D& operator+=(SIMDFVector4D const& in)
		{
			DirectX::XMStoreFloat4(&xmfloat, DirectX::XMVectorAdd(DirectX::XMLoadFloat4(&xmfloat), DirectX::XMLoadFloat4(&in.xmfloat)));
			return *this;
		}
		SIMDFVector4D& operator-=(SIMDFVector4D const& in)
		{
			DirectX::XMStoreFloat4(&xmfloat, DirectX::XMVectorSubtract(DirectX::XMLoadFloat4(&xmfloat), DirectX::XMLoadFloat4(&in.xmfloat)));
			return *this;
		}
		SIMDFVector4D& operator*=(SIMDFVector4D const& in)
		{
			DirectX::XMStoreFloat4(&xmfloat, DirectX::XMVectorMultiply(DirectX::XMLoadFloat4(&xmfloat), DirectX::XMLoadFloat4(&in.xmfloat)));
			return *this;
		}
		SIMDFVector4D& operator/=(SIMDFVector4D const& in)
		{
			DirectX::XMStoreFloat4(&xmfloat, DirectX::XMVectorDivide(DirectX::XMLoadFloat4(&xmfloat), DirectX::XMLoadFloat4(&in.xmfloat)));
			return *this;
		}

		SIMDFVector4D operator+ (SIMDFVector4D const& rin) 
		{
			DirectX::XMFLOAT4 temp;
			DirectX::XMStoreFloat4(&temp, DirectX::XMVectorAdd(DirectX::XMLoadFloat4(&xmfloat), DirectX::XMLoadFloat4(&rin.xmfloat)));
			return SIMDFVector4D(temp);
		}
		SIMDFVector4D operator- (SIMDFVector4D const& rin) 
		{
			DirectX::XMFLOAT4 temp;
			DirectX::XMStoreFloat4(&temp, DirectX::XMVectorSubtract(DirectX::XMLoadFloat4(&xmfloat), DirectX::XMLoadFloat4(&rin.xmfloat)));
			return SIMDFVector4D(temp);
		}
		SIMDFVector4D operator* (SIMDFVector4D const& rin) 
		{
			DirectX::XMFLOAT4 temp;
			DirectX::XMStoreFloat4(&temp, DirectX::XMVectorMultiply(DirectX::XMLoadFloat4(&xmfloat), DirectX::XMLoadFloat4(&rin.xmfloat)));
			return SIMDFVector4D(temp);
		}
		SIMDFVector4D operator/ (SIMDFVector4D const& rin) 
		{
			DirectX::XMFLOAT4 temp;
			DirectX::XMStoreFloat4(&temp, DirectX::XMVectorDivide(DirectX::XMLoadFloat4(&xmfloat), DirectX::XMLoadFloat4(&rin.xmfloat)));
			return SIMDFVector4D(temp);
		}
#pragma endregion Operators
#pragma region GetSet
	public:
		DirectX::XMFLOAT4 GetData() { return xmfloat; }
		void  SetData(DirectX::XMFLOAT4 in) { xmfloat = in; };
#pragma endregion GetSet
#pragma region Functions 
	public:
#pragma endregion Functions

	private:
		DirectX::XMFLOAT4 xmfloat;
	};
}
