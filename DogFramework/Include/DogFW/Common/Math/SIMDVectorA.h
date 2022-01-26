#pragma once
#include <DirectXMath.h>
#include "DogFW/Common/Math/DogInt.h"


namespace DogFW
{
	//4D vector based on XMVector aligned struct
	class SIMDVector4DAligned
	{
#pragma region Contructors
	public:
		SIMDVector4DAligned() : xmvec(DirectX::XMVectorZero()) {};
		SIMDVector4DAligned(DirectX::XMVECTOR invec) : xmvec(invec) {};

		SIMDVector4DAligned(float x, float y, float z, float w) : xmvec(DirectX::XMVectorSet(x, y, z, w)) {};
		SIMDVector4DAligned(uint32 x, uint32 y, uint32 z, uint32 w) : xmvec(DirectX::XMVectorSetInt(x, y, z, w)) {};

		SIMDVector4DAligned(float value) :xmvec(DirectX::XMVectorReplicate(value)) {};
		SIMDVector4DAligned(uint32 value) :xmvec(DirectX::XMVectorReplicateInt(value)) {};

		//Copy Constr
		SIMDVector4DAligned(const SIMDVector4DAligned& in) noexcept : xmvec(in.xmvec) {};
		//Assign Constr
		SIMDVector4DAligned(SIMDVector4DAligned&& in) noexcept : xmvec(in.xmvec) {};
#pragma endregion Contructors
#pragma region Operators
	public:
		//Assign By Copy
		SIMDVector4DAligned& operator=(SIMDVector4DAligned const& in) noexcept
		{
			if (&in != this)
			{
				xmvec = in.xmvec;
			}
			return *this;
		}
		//Assign by Move
		SIMDVector4DAligned& operator=(SIMDVector4DAligned const&& in) noexcept
		{
			if (&in != this)
			{
				xmvec = in.xmvec;
			}
			return *this;
		}

		//Returns Negative(Vector)
		SIMDVector4DAligned operator-() const
		{
			SIMDVector4DAligned temp;
			temp.xmvec = DirectX::XMVectorNegate(xmvec);
			return temp;
		}

		SIMDVector4DAligned& operator+=(SIMDVector4DAligned const& in)
		{
			xmvec = DirectX::XMVectorAdd(xmvec, in.xmvec);
			return *this;
		}
		SIMDVector4DAligned& operator-=(SIMDVector4DAligned const& in)
		{
			//using namespace DirectX;
			xmvec = DirectX::XMVectorSubtract(xmvec, in.xmvec);
			return *this;
		}
		SIMDVector4DAligned& operator*=(SIMDVector4DAligned const& in)
		{
			xmvec = DirectX::XMVectorMultiply(xmvec, in.xmvec);
			return *this;
		}
		SIMDVector4DAligned& operator/=(SIMDVector4DAligned const& in)
		{
			xmvec = DirectX::XMVectorMultiply(xmvec, DirectX::XMVectorReciprocal(in.xmvec));
			return *this;
		}

		SIMDVector4DAligned operator+ (SIMDVector4DAligned const& rin) {
			return SIMDVector4DAligned(DirectX::XMVectorAdd(xmvec, rin.xmvec));
		}
		SIMDVector4DAligned operator- (SIMDVector4DAligned const& rin) {
			return SIMDVector4DAligned(DirectX::XMVectorSubtract(xmvec, rin.xmvec));
		}
		SIMDVector4DAligned operator* (SIMDVector4DAligned const& rin) {
			return SIMDVector4DAligned(DirectX::XMVectorMultiply(xmvec, rin.xmvec));
		}
		SIMDVector4DAligned operator/ (SIMDVector4DAligned const& rin) {
			return SIMDVector4DAligned(DirectX::XMVectorDivide(xmvec, rin.xmvec));
		}
#pragma endregion Operators
#pragma region GetSet
	public:
		float GetX() const { return DirectX::XMVectorGetX(xmvec); }
		float GetY() const { return DirectX::XMVectorGetY(xmvec); }
		float GetZ() const { return DirectX::XMVectorGetZ(xmvec); }
		float GetW() const { return DirectX::XMVectorGetW(xmvec); }
		uint32  GetIntX() const { return DirectX::XMVectorGetIntX(xmvec); }
		uint32  GetIntY() const { return DirectX::XMVectorGetIntY(xmvec); }
		uint32  GetIntZ() const { return DirectX::XMVectorGetIntZ(xmvec); }
		uint32  GetIntW() const { return DirectX::XMVectorGetIntW(xmvec); }

		void SetX(const float value) { xmvec = DirectX::XMVectorSetX(xmvec, value); }
		void SetY(const float value) { xmvec = DirectX::XMVectorSetY(xmvec, value); }
		void SetZ(const float value) { xmvec = DirectX::XMVectorSetZ(xmvec, value); }
		void SetW(const float value) { xmvec = DirectX::XMVectorSetW(xmvec, value); }

		void SetIntX(const uint32 value) { xmvec = DirectX::XMVectorSetIntX(xmvec, value); }
		void SetIntY(const uint32 value) { xmvec = DirectX::XMVectorSetIntY(xmvec, value); }
		void SetIntZ(const uint32 value) { xmvec = DirectX::XMVectorSetIntZ(xmvec, value); }
		void SetIntW(const uint32 value) { xmvec = DirectX::XMVectorSetIntW(xmvec, value); }
#pragma endregion GetSet
#pragma region Functions 
	public:
		//Returns Abs(Vector)
		SIMDVector4DAligned Abs() const
		{
			SIMDVector4DAligned temp;
			temp.xmvec = DirectX::XMVectorAbs(xmvec);
			return temp;
		}
#pragma endregion Functions
	private:
		alignas(16) DirectX::XMVECTOR xmvec;
	};
}