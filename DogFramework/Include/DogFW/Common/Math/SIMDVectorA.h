#pragma once
#include "DogFW/DogBasicTypes.h"
#include "DogFW/External/Windows/DogDX12.h"

namespace DogFW
{
	//4D vector based on XMVector aligned struct
	class SIMDVector4DAligned
	{
#pragma region Contructors
	public:
		SIMDVector4DAligned() : xmVec_(DirectX::XMVectorZero()) {};
		SIMDVector4DAligned(DirectX::XMVECTOR invec) : xmVec_(invec) {};

		SIMDVector4DAligned(Float x, Float y, Float z, Float w) : xmVec_(DirectX::XMVectorSet(x, y, z, w)) {};
		SIMDVector4DAligned(UInt32 x, UInt32 y, UInt32 z, UInt32 w) : xmVec_(DirectX::XMVectorSetInt(x, y, z, w)) {};

		SIMDVector4DAligned(Float value) :xmVec_(DirectX::XMVectorReplicate(value)) {};
		SIMDVector4DAligned(UInt32 value) :xmVec_(DirectX::XMVectorReplicateInt(value)) {};

		//Copy Constr
		SIMDVector4DAligned(const SIMDVector4DAligned& in) noexcept : xmVec_(in.xmVec_) {};
		//Assign Constr
		SIMDVector4DAligned(SIMDVector4DAligned&& in) noexcept : xmVec_(in.xmVec_) {};
#pragma endregion Contructors
#pragma region Operators
	public:
		//Assign By Copy
		SIMDVector4DAligned& operator=(SIMDVector4DAligned const& in) noexcept
		{
			if (&in != this)
			{
				xmVec_ = in.xmVec_;
			}
			return *this;
		}
		//Assign by Move
		SIMDVector4DAligned& operator=(SIMDVector4DAligned const&& in) noexcept
		{
			if (&in != this)
			{
				xmVec_ = in.xmVec_;
			}
			return *this;
		}

		//Returns Negative(Vector)
		SIMDVector4DAligned operator-() const
		{
			SIMDVector4DAligned temp;
			temp.xmVec_ = DirectX::XMVectorNegate(xmVec_);
			return temp;
		}

		SIMDVector4DAligned& operator+=(SIMDVector4DAligned const& in)
		{
			xmVec_ = DirectX::XMVectorAdd(xmVec_, in.xmVec_);
			return *this;
		}
		SIMDVector4DAligned& operator-=(SIMDVector4DAligned const& in)
		{
			//using namespace DirectX;
			xmVec_ = DirectX::XMVectorSubtract(xmVec_, in.xmVec_);
			return *this;
		}
		SIMDVector4DAligned& operator*=(SIMDVector4DAligned const& in)
		{
			xmVec_ = DirectX::XMVectorMultiply(xmVec_, in.xmVec_);
			return *this;
		}
		SIMDVector4DAligned& operator/=(SIMDVector4DAligned const& in)
		{
			xmVec_ = DirectX::XMVectorMultiply(xmVec_, DirectX::XMVectorReciprocal(in.xmVec_));
			return *this;
		}

		SIMDVector4DAligned operator+ (SIMDVector4DAligned const& rin) {
			return SIMDVector4DAligned(DirectX::XMVectorAdd(xmVec_, rin.xmVec_));
		}
		SIMDVector4DAligned operator- (SIMDVector4DAligned const& rin) {
			return SIMDVector4DAligned(DirectX::XMVectorSubtract(xmVec_, rin.xmVec_));
		}
		SIMDVector4DAligned operator* (SIMDVector4DAligned const& rin) {
			return SIMDVector4DAligned(DirectX::XMVectorMultiply(xmVec_, rin.xmVec_));
		}
		SIMDVector4DAligned operator/ (SIMDVector4DAligned const& rin) {
			return SIMDVector4DAligned(DirectX::XMVectorDivide(xmVec_, rin.xmVec_));
		}
#pragma endregion Operators
#pragma region GetSet
	public:
		Float getX() const { return DirectX::XMVectorGetX(xmVec_); }
		Float getY() const { return DirectX::XMVectorGetY(xmVec_); }
		Float getZ() const { return DirectX::XMVectorGetZ(xmVec_); }
		Float getW() const { return DirectX::XMVectorGetW(xmVec_); }
		UInt32  getIntX() const { return DirectX::XMVectorGetIntX(xmVec_); }
		UInt32  getIntY() const { return DirectX::XMVectorGetIntY(xmVec_); }
		UInt32  getIntZ() const { return DirectX::XMVectorGetIntZ(xmVec_); }
		UInt32  getIntW() const { return DirectX::XMVectorGetIntW(xmVec_); }

		void setX(const Float value) { xmVec_ = DirectX::XMVectorSetX(xmVec_, value); }
		void setY(const Float value) { xmVec_ = DirectX::XMVectorSetY(xmVec_, value); }
		void setZ(const Float value) { xmVec_ = DirectX::XMVectorSetZ(xmVec_, value); }
		void setW(const Float value) { xmVec_ = DirectX::XMVectorSetW(xmVec_, value); }

		void setIntX(const UInt32 value) { xmVec_ = DirectX::XMVectorSetIntX(xmVec_, value); }
		void setIntY(const UInt32 value) { xmVec_ = DirectX::XMVectorSetIntY(xmVec_, value); }
		void setIntZ(const UInt32 value) { xmVec_ = DirectX::XMVectorSetIntZ(xmVec_, value); }
		void setIntW(const UInt32 value) { xmVec_ = DirectX::XMVectorSetIntW(xmVec_, value); }
#pragma endregion GetSet
#pragma region Functions 
	public:
		//Returns Abs(Vector)
		SIMDVector4DAligned abs() const
		{
			SIMDVector4DAligned temp;
			temp.xmVec_ = DirectX::XMVectorAbs(xmVec_);
			return temp;
		}
#pragma endregion Functions
	private:
		alignas(16) DirectX::XMVECTOR xmVec_;
	};
}