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
};


struct Rotator {
	int Pitch, Yaw, Roll;

	Rotator(FRotator r);
	Rotator(int pitch, int yaw, int roll) : Pitch(pitch), Yaw(yaw), Roll(roll) {}
	Rotator(int def) : Pitch(def), Yaw(def), Roll(def) {}
	Rotator() : Rotator(0) {}
	operator FRotator();


	inline Rotator operator+(Rotator v2) {
		return Rotator(Pitch + v2.Pitch, Yaw + v2.Yaw, Roll + v2.Roll);
	}

	inline Rotator operator*(Rotator v2) {
		return Rotator(Pitch * v2.Pitch, Yaw * v2.Yaw, Roll * v2.Roll);
	}

	inline Rotator operator-(Rotator v2) {
		return Rotator(Pitch - v2.Pitch, Yaw - v2.Yaw, Roll - v2.Roll);
	}
};
