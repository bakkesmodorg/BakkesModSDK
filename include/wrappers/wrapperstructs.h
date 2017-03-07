#pragma once
#include "../shared.h"

struct FVector;
struct FRotator;
struct Vector {
	float X, Y, Z;

	Vector(FVector v);
	Vector(float x, float y, float z) : X(x), Y(y), Z(z) {}
	Vector(float def) : X(def), Y(def), Z(def) {}
	Vector() : Vector(0.0) {}
	operator FVector();
	
	inline Vector operator+(Vector v2) {
		return Vector(X + v2.X, Y + v2.Y, Z + v2.Z);
	}

	inline Vector operator*(Vector v2) {
		return Vector(X * v2.X, Y * v2.Y, Z * v2.Z);
	}

	inline Vector operator-(Vector v2) {
		return Vector(X - v2.X, Y - v2.Y, Z - v2.Z);
	}

	inline Vector operator/(Vector v2) {
		return Vector(X / v2.X, Y / v2.Y, Z / v2.Z);
	}
};

static inline float fixRotator(float newRotation) {
	if (newRotation >= 32767) {
		newRotation = -32767 + (newRotation - 32767);
	}
	else if (newRotation <= -32767) { //-35000 
		newRotation = 32767 + (newRotation + 32767);
	}
	return newRotation;
}

static inline float fixPitch(float newRotation) {
	if (newRotation >= 16383) {
		newRotation = -16383 + (newRotation - 16383);
	}
	else if (newRotation <= -16383) { //-35000 
		newRotation = 16383 + (newRotation + 16383);
	}
	return newRotation;
}

struct Rotator {
	float Pitch, Yaw, Roll;

	Rotator(FRotator r);
	Rotator(float pitch, float yaw, float roll) : Pitch(pitch), Yaw(yaw), Roll(roll) {}
	Rotator(float def) : Pitch(def), Yaw(def), Roll(def) {}
	Rotator() : Rotator(0) {}
	operator FRotator();


	inline Rotator operator+(Rotator v2) {
		return Rotator(fixPitch(Pitch + v2.Pitch), fixRotator(Yaw + v2.Yaw), fixRotator(Roll +v2.Roll));
	}

	inline Rotator operator*(Rotator v2) {
		return Rotator(fixPitch(Pitch * v2.Pitch), fixRotator(Yaw * v2.Yaw), fixRotator(Roll * v2.Roll));
	}

	inline Rotator operator-(Rotator v2) {
		return Rotator(fixPitch(Pitch - v2.Pitch), fixRotator(Yaw - v2.Yaw), fixRotator(Roll - v2.Roll));
	}

	inline Rotator operator/(Rotator v2) {
		return Rotator(fixPitch(Pitch / v2.Pitch), fixRotator(Yaw / v2.Yaw), fixRotator(Roll / v2.Roll));
	}
};
