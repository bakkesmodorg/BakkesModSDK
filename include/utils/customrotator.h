#pragma once
#include "bakkesmod/plugin/bakkesmodsdk.h"
#include "bakkesmod/wrappers/WrapperStructs.h"
#include "finiteelement.h"

//Player rotation Min(-16364, -32768, -32768)
//Player rotation Max(16340, 32764, 32764)
class BAKKESMOD_PLUGIN_IMPORT CustomRotator {
public:
	FiniteElement<float> Pitch = FiniteElement<float>(0, -16364, 16340);
	FiniteElement<float> Yaw = FiniteElement<float>(0, -32768, 32764);
	FiniteElement<float> Roll = FiniteElement<float>(0, -32768, 32764);

	CustomRotator(); 
	CustomRotator(float defaultValue);
	CustomRotator(float pitch, float yaw, float roll); 
	CustomRotator(FiniteElement<float> pitch, FiniteElement<float> yaw, FiniteElement<float> roll);
	CustomRotator(struct Rotator& rot);
	CustomRotator(const CustomRotator& other);

	CustomRotator& operator=(CustomRotator& other) noexcept;
	CustomRotator& operator=(Rotator& other) noexcept;

	CustomRotator diffTo(CustomRotator& other);
	//operator Rotator() { return Rotator((float)Pitch, (float)Yaw, (float)Roll); } //Do we actually want this?
	Rotator ToRotator();

	CustomRotator& operator*=(const CustomRotator &other);
	CustomRotator& operator+=(const CustomRotator &other);
	CustomRotator& operator-=(const CustomRotator &other);
	CustomRotator& operator/=(const CustomRotator &other);
	CustomRotator& operator* (const CustomRotator &other);
	CustomRotator& operator+ (const CustomRotator &other);
	CustomRotator& operator- (const CustomRotator &other);
	CustomRotator& operator/ (const CustomRotator &other);

	template<typename T2>
	CustomRotator& operator+=(T2 f)
	{
		Pitch += f;
		Yaw += f;
		Roll += f;
		return *this;
	}

	template<typename T2>
	CustomRotator& operator*=(T2 f)
	{
		Pitch *= f;
		Yaw *= f;
		Roll *= f;
		return *this;
	}

	template<typename T2>
	CustomRotator& operator-=(T2 f)
	{
		Pitch -= f;
		Yaw -= f;
		Roll -= f;
		return *this;
	}

	template<typename T2>
	CustomRotator& operator/=(T2 f)
	{
		Pitch /= f;
		Yaw /= f;
		Roll /= f;
		return *this;
	}
};

//template<typename T2>
//CustomRotator operator* (T2 f, CustomRotator V) 
//{ 
//	CustomRotator result = CustomRotator(f, f, f);
//	result *= V;
//	return result;
//}

template<typename T2>
CustomRotator operator* (CustomRotator V, T2 f) 
{
	CustomRotator result = CustomRotator(V);
	result *= f;
	return result;
}
//template<typename T2>
//CustomRotator operator/ (T2 f, CustomRotator V) 
//{
//	CustomRotator result = CustomRotator(f, f, f);
//	result /= V;
//	return result;
//}

template<typename T2>
CustomRotator operator/ (CustomRotator V, T2 f) 
{
	CustomRotator result = CustomRotator(V);
	result /= f;
	return result;
}
//template<typename T2>
//CustomRotator operator+ (T2 f, CustomRotator V) 
//{
//	CustomRotator result = CustomRotator(f, f, f);
//	result += V;
//	return result;
//}

//template<typename T2>
//CustomRotator operator+ (CustomRotator V, T2 f) 
//{
//	CustomRotator result = CustomRotator(V);
//	result += f;
//	return result;
//}

//template<typename T2>
//CustomRotator operator- (T2 f, CustomRotator V)
//{
//	CustomRotator result = CustomRotator(f, f, f);
//	result -= V;
//	return result;
//}

template<typename T2>
CustomRotator operator- (CustomRotator V, T2 f)
{
	CustomRotator result = CustomRotator(V);
	result -= f;
	return result;
}