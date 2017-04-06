#pragma once
#include "../shared.h"
#include "linmath.h"
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


struct PredictionInfo {
	float Time;
	Vector Location;
	Vector Velocity;
	bool HitWall;
	bool HitFloor;
};


static inline float fixRotator(float newRotation) {
	if (newRotation >= 32767) {
		newRotation -= 65535;
		//newRotation = -32767 + (newRotation - 32767);
	}
	else if (newRotation <= -32767) { //-35000 
		newRotation += 65535;
		//newRotation = 32767 + (newRotation + 32767);
	}
	return newRotation;
}

static inline float fixPitch(float newRotation) {
	if (newRotation >= 16383) {
		newRotation -= 32767;
		//newRotation = -16383 + (newRotation - 16383);
	}
	else if (newRotation <= -16383) { //-35000 
		newRotation += 32767;
		//newRotation = 16383 + (newRotation + 16383);
	}
	return newRotation;
}

struct ControllerInput {
	float Throttle = 0.0f;
	float Steer = 0.0f;
	float Pitch = 0.0f;
	float Yaw = 0.0f;
	float Roll = 0.0f;
	bool Jump = false;
	bool Jumped = false;
	bool ActivateBoost = false;
	bool HoldingBoost = false;
	bool Handbrake = false;
};

//Player rotation Min(-16364, -32768, -32768)
//Player rotation Max(16340, 32764, 32764)
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
		return Rotator(fixPitch(Pitch * v2.Pitch), fixPitch(Yaw * v2.Yaw), fixPitch(Roll * v2.Roll));
	}

	inline Rotator operator-(Rotator v2) {
		return Rotator(fixPitch(Pitch - v2.Pitch), fixPitch(Yaw - v2.Yaw), fixPitch(Roll - v2.Roll));
	}

	inline Rotator operator/(Rotator v2) {
		return Rotator(fixPitch(Pitch / v2.Pitch), fixPitch(Yaw / v2.Yaw), fixPitch(Roll / v2.Roll));
	}
};

struct POV {
	Vector location;
	Rotator rotation;
	float FOV;
};

struct Vector2 {
	int X;
	int Y;
};

struct ProfileCameraSettings
{
	float                                              FOV;                                              		// 0x0000 (0x0004) [0x0000000000000000]              
	float                                              Height;                                           		// 0x0004 (0x0004) [0x0000000000000000]              
	float                                              Pitch;                                            		// 0x0008 (0x0004) [0x0000000000000000]              
	float                                              Distance;                                         		// 0x000C (0x0004) [0x0000000000000000]              
	float                                              Stiffness;                                        		// 0x0010 (0x0004) [0x0000000000000000]              
	float                                              SwivelSpeed;                                      		// 0x0014 (0x0004) [0x0000000000000000]              
};