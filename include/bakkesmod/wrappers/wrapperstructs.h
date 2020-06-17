#pragma once
//#include "../shared.h"

#include "linmath.h"
#include <algorithm> 

#define CONST_RadToUnrRot                                        10430.3783504704527f
#define CONST_UnrRotToRad                                        0.00009587379924285f


enum ToastType
{
	ToastType_Info = 0,
	ToastType_OK,
	ToastType_Warning,
	ToastType_Error
};

#pragma pack ( push, 0x8 )
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

	inline Vector operator*(float f) {
		return Vector(X * f, Y * f, Z * f);
	}

	inline Vector operator/(float f) {
		return Vector(X / f, Y / f, Z / f);
	}



	inline float magnitude()
	{
		return sqrt(X * X + Y * Y + Z * Z);
	}

	inline void normalize()
	{
		float magnitudez = magnitude();
		X = X / magnitudez;
		Y = Y / magnitudez;
		Z = Z / magnitudez;
	}

	inline Vector clone()
	{
		return Vector(X, Y, Z);
	}


	static inline float dot(Vector v1, Vector v2)
	{
		return v1.X * v2.X + v1.Y * v2.Y + v1.Z * v2.Z;
	}

	static inline Vector cross(Vector v1, Vector v2)
	{
		float x = v1.Y * v2.Z - v1.Z * v2.Y;
		float y = v1.Z * v2.X - v1.X * v2.Z;
		float z = v1.X * v2.Y - v1.Y * v2.X;
		return Vector(x, y, z);
	}

	static inline Vector lerp(Vector v1, Vector v2, float t)
	{
		float x = (1.0f - t) * v1.X + t * v2.X;
		float y = (1.0f - t) * v1.Y + t * v2.Y;
		float z = (1.0f - t) * v1.Z + t * v2.Z;
		return Vector(x, y, z);
	}

	static inline Vector slerp(Vector v1, Vector v2, float t)
	{
		Vector a = v1.clone();
		Vector b = v2.clone();

		float dot = Vector::dot(a, b);

		float theta = acos(dot) * t;

		Vector relVector = b - (a * dot);
		relVector.normalize();
		float cosTheta = cos(theta);
		float sinTheta = sin(theta);
		return a * cosTheta + relVector * sinTheta;
	}


};


struct PredictionInfo {
	float                                             Time;                                             		            
	float                                             ArchTopTime;                                      		             
	struct Vector                                     Location;                                         		              
	struct Vector                                     Velocity;                                         		          
	struct Vector                                     ArchTop;                                          		
	struct Vector                                     ArchTopVelocity;         
	unsigned long                                     bHitWall : 1;                                    
	unsigned long                                     bHitGround : 1;
};
//Player rotation Min(-16364, -32768, -32768)
//Player rotation Max(16340, 32764, 32764)

static inline int fixRotator(int newRotation) {// F THIS FOR NOW
	return newRotation;
	//newRotation = (((int)newRotation + 32768) % (32768 + 32764)) - 32768;
	//newRotation = (((int)newRotation - 32764) % (32768 + 32764)) + 32764;
	////if (newRotation >= 32767) {
	////	newRotation -= 65535;
	////	//newRotation = -32767 + (newRotation - 32767);
	////}
	////else if (newRotation <= -32767) { //-35000 
	////	newRotation += 65535;
	////	//newRotation = 32767 + (newRotation + 32767);
	////}
	//return newRotation;
}

struct SteamID
{
	unsigned long long ID;
};

struct SkillRating {
	float                                              Mu;                                               		// 0x0000 (0x0004) [0x0000000000000000]              
	float                                              Sigma;                                            		// 0x0004 (0x0004) [0x0000000000000000]              
};

struct SkillRank
{
	int Tier;
	int Division;
	int MatchesPlayed;
};

struct LinearColor
{
	float                                              R;                                                		// 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
	float                                              G;                                                		// 0x0004 (0x0004) [0x0000000000000001]              ( CPF_Edit )
	float                                              B;                                                		// 0x0008 (0x0004) [0x0000000000000001]              ( CPF_Edit )
	float                                              A;                                                		// 0x000C (0x0004) [0x0000000000000001]              ( CPF_Edit )
};

static inline int fixPitch(int newRotation) {// F THIS FOR NOW
	return newRotation;
	//newRotation = (((int)newRotation + 16384) % (32768)) - 16384;
	//newRotation = (((int)newRotation - 16384) % (32768)) + 16384;

	////if (newRotation >= 16383) {
	////	newRotation -= 32767;
	////	//newRotation = -16383 + (newRotation - 16383);
	////}
	////else if (newRotation <= -16383) { //-35000 
	////	newRotation += 32767;
	////	//newRotation = 16383 + (newRotation + 16383);
	////}
	//return newRotation;
}

struct ControllerInput {
	float Throttle = .0f;
	float Steer = .0f;
	float Pitch = .0f;
	float Yaw = .0f;
	float Roll = .0f;
	float DodgeForward = .0f;
	float DodgeStrafe = .0f;
	unsigned long Jump :1;
	unsigned long ActivateBoost : 1;
	unsigned long HoldingBoost : 1;
	unsigned long Handbrake : 1;
	unsigned long Jumped : 1;
};

struct RecordedSample
{
	float                                              Low;                                              		// 0x0000 (0x0004) [0x0000000000000000]              
	float                                              High;                                             		// 0x0004 (0x0004) [0x0000000000000000]              
};

//Player rotation Min(-16364, -32768, -32768)
//Player rotation Max(16340, 32764, 32764)
struct Rotator {
	int Pitch, Yaw, Roll;

	Rotator(FRotator r);
	Rotator(int pitch, int yaw, int roll) : Pitch(pitch), Yaw(yaw), Roll(roll) {}
	Rotator(int def) : Pitch(def), Yaw(def), Roll(def) {}
	Rotator() : Rotator(0) {}
	operator FRotator();


	inline Rotator operator+(Rotator v2) {
		return Rotator(fixPitch(Pitch + v2.Pitch), fixRotator(Yaw + v2.Yaw), fixRotator(Roll + v2.Roll));
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

struct POV {
	Vector location;
	Rotator rotation;
	float FOV;
};


struct UnrealColor {
	unsigned char                                      B;                                                		// 0x0000 (0x0001) [0x0000000000000001]              ( CPF_Edit )
	unsigned char                                      G;                                                		// 0x0001 (0x0001) [0x0000000000000001]              ( CPF_Edit )
	unsigned char                                      R;                                                		// 0x0002 (0x0001) [0x0000000000000001]              ( CPF_Edit )
	unsigned char                                      A;                                                		// 0x0003 (0x0001) [0x0000000000000001]              ( CPF_Edit )
};



struct ViewTarget {
	void*				                               Target;                                           		// ActorWrapper(Target)
	void*								               Controller;                                       		// PlayerControllerWrapper(Controller)
	struct POV									       POV;                                              		// 
	float                                              AspectRatio;                                      		// 
	void*											   PRI;                                              		// PRIWrapper(PRI)
};

struct Vector2 {
	int X;
	int Y;
	Vector2 minus(Vector2 other)
	{
		return{ X - other.X,  Y - other.Y };
	}

	inline Vector2 operator-(Vector2 v2) {
		return minus(v2);
	}

	inline Vector2 operator+(Vector2 v2) {
		return{ X + v2.X,  Y + v2.Y };
	}

	inline Vector2 operator*(int mult) {
		return{ X * mult, Y * mult };
	}

	inline Vector2 operator/(int div) {
		return{ X / div, Y / div };
	}
};

struct Vector2F {
	float X;
	float Y;
	Vector2F minus(Vector2 other)
	{
		return{ X - (float)other.X,  Y - (float)other.Y };
	}

	Vector2F minus(Vector2F other)
	{
		return{ X - other.X,  Y - other.Y };
	}

	inline Vector2F operator-(Vector2 v2) {
		return minus(v2);
	}

	inline Vector2F operator-(Vector2F v2F) {
		return minus(v2F);
	}

	inline Vector2F operator+(Vector2 v2) {
		return{ X + v2.X,  Y + v2.Y };
	}

	inline Vector2F operator+(Vector2F v2F) {
		return{ X + v2F.X,  Y + v2F.Y };
	}

	inline Vector2F operator*(float mult) {
		return{ X * mult, Y * mult };
	}

	inline Vector2F operator/(float div) {
		return{ X / div, Y / div };
	}
};

struct ProfileCameraSettings
{
	float                                              FOV;                                              		// 0x0000 (0x0004) [0x0000000000000000]              
	float                                              Height;                                           		// 0x0004 (0x0004) [0x0000000000000000]              
	float                                              Pitch;                                            		// 0x0008 (0x0004) [0x0000000000000000]              
	float                                              Distance;                                         		// 0x000C (0x0004) [0x0000000000000000]              
	float                                              Stiffness;                                        		// 0x0010 (0x0004) [0x0000000000000000]              
	float                                              SwivelSpeed;                                      		// 0x0014 (0x0004) [0x0000000000000000]              
	float                                              TransitionSpeed;                                  		// 0x0018 (0x0004) [0x0000000000000000]             
};



static Rotator inline VectorToRotator(Vector vVector)
{
	Rotator rRotation;

	rRotation.Yaw = atan2(vVector.Y, vVector.X) * CONST_RadToUnrRot;
	rRotation.Pitch = atan2(vVector.Z, sqrt((vVector.X * vVector.X) + (vVector.Y * vVector.Y))) * CONST_RadToUnrRot;
	rRotation.Roll = 0;

	return rRotation;
}

static inline Vector RotatorToVector(Rotator R)
{
	Vector vec;
	float fYaw = R.Yaw * CONST_UnrRotToRad;
	float fPitch = R.Pitch * CONST_UnrRotToRad;
	float CosPitch = cos(fPitch);
	vec.X = cos(fYaw) * CosPitch;
	vec.Y = sin(fYaw) * CosPitch;
	vec.Z = sin(fPitch);
	return vec;
}

enum CARBODY
{
	CAR_BACKFIRE = 21,
	CAR_BREAKOUT = 22,
	CAR_BREAKOUTTYPES = 1416,
	CAR_OCTANE = 23,
	CAR_OCTANEZSR = 1568,
	CAR_PALADIN = 24,
	CAR_ROADHOG = 25,
	CAR_ROADHOGXL = 1300,
	CAR_GIZMO = 26,
	CAR_SWEETTOOTH = 27, //Will just spawn merc i guess, ps4 exclusive
	CAR_XDEVIL = 28,
	CAR_XDEVILMK2 = 1159,
	CAR_HOTSHOT = 29,
	CAR_MERC = 30,
	CAR_VENOM = 31,
	CAR_TAKUMI = 402,
	CAR_TAKUMIRXT = 1295,
	CAR_DOMINUS = 403,
	CAR_DOMINUSGT = 1018,
	CAR_SCARAB = 404,
	CAR_ZIPPY = 523,
	CAR_DELOREAN = 597,
	CAR_RIPPER = 600,
	CAR_GROG = 607,
	CAR_ARMADILLO = 625, //gears of war car, XBOX exclusive?
	CAR_WARTHOG = 723, //Halo car, XBOX exclusive
	CAR_BATMOBILE = 803,
	CAR_MASAMUNE = 1171,
	CAR_MARAUDER = 1172,
	CAR_AFTERSHOCK = 1286,
	CAR_ESPER = 1317,
	CAR_PROTEUS = 1475,
	CAR_TRITON = 1478,
	CAR_VULCAN = 1533,
	CAR_TWINMILL = 1603,
	CAR_BONESHAKER = 1623,
	CAR_ENDO = 1624,
	CAR_ICECHARGER = 1675,
	CAR_MANTIS = 1691,
	CAR_JOGER619RS = 1856,
	CAR_CENTIO = 1919,
	CAR_ANIMUSGP = 1932,
};
struct Quat {
	float X, Y, Z, W;

	Quat(float w, float x, float y, float z) : W(w), X(x), Y(y), Z(z) {}
	Quat() : Quat(1.0, 0.0, 0.0, 0.0) {}

	inline Quat conjugate()
	{
		return Quat(W, -X, -Y, -Z);
	}

	inline Quat operator*(Quat q2)
	{
		float mulW = W * q2.W;
		mulW -= X * q2.X;
		mulW -= Y * q2.Y;
		mulW -= Z * q2.Z;

		float mulX = W * q2.X;
		mulX += X * q2.W;
		mulX += Y * q2.Z;
		mulX -= Z * q2.Y;

		float mulY = W * q2.Y;
		mulY -= X * q2.Z;
		mulY += Y * q2.W;
		mulY += Z * q2.X;

		float mulZ = W * q2.Z;
		mulZ += X * q2.Y;
		mulZ -= Y * q2.X;
		mulZ += Z * q2.W;

		return Quat(mulW, mulX, mulY, mulZ);
	}
};
struct RBState
{
	struct Quat                                       Quaternion;                                         		// 0x0000 (0x0010) [0x0000000000000000]              
	struct Vector                                     Location;                                         		// 0x0010 (0x000C) [0x0000000000000000]              
	struct Vector                                     LinearVelocity;                                   		// 0x001C (0x000C) [0x0000000000000000]              
	struct Vector                                     AngularVelocity;                                  		// 0x0028 (0x000C) [0x0000000000000000] 
	float                                             Time;                                             		// 0x0034 (0x0004) [0x0000000000000000]              	
	unsigned long                                     bSleeping : 1;                                    		// 0x0038 (0x0004) [0x0000000000000000] [0x00000001] 
	unsigned long                                     bNewData : 1;                                     		// 0x0038 (0x0004) [0x0000000000000000] [0x00000002] 
};

struct WorldContactData
{
	unsigned long                                     bHasContact : 1;                                  		// 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
	struct Vector                                     Location;                                         		// 0x0004 (0x000C) [0x0000000000000000]              
	struct Vector                                     Velocity;                                         		// 0x0010 (0x000C) [0x0000000000000000]              
	struct Vector                                     Normal;                                           		// 0x001C (0x000C) [0x0000000000000000]              
};



struct StickyForceData {
	float                                             Ground;                                           		// 0x0000 (0x0004) [0x0000000000000001]              ( CPF_Edit )
	float                                             Wall;                                             		// 0x0004 (0x0004) [0x0000000000000001]              ( CPF_Edit )
};

struct WheelContactData {
	unsigned long                                     bHasContact : 1;                                  		// 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
	unsigned long                                     bHasContactWithWorldGeometry : 1;                 		// 0x0000 (0x0004) [0x0000000000000000] [0x00000002] 
	float                                             HasContactChangeTime;                             		// 0x0004 (0x0004) [0x0000000000000000]              
	void*                                             Actor;                                            		// 0x0008 (0x0004) [0x0000000000000000]              
	void*										      Component;                                        		// 0x000C (0x0004) [0x0000000004080008]              ( CPF_ExportObject | CPF_Component | CPF_EditInline )
	struct Vector                                     Location;                                         		// 0x0010 (0x000C) [0x0000000000000000]              
	struct Vector                                     Normal;                                           		// 0x001C (0x000C) [0x0000000000000000]              
	struct Vector                                     LatDirection;                                     		// 0x0028 (0x000C) [0x0000000000000000]              
	struct Vector                                     LongDirection;                                    		// 0x0034 (0x000C) [0x0000000000000000]              
	void*									          PhysMatProp;                                      		// 0x0040 (0x0004) [0x0000000000000000]              
};

enum TRADEHOLD
{
 TRADEHOLD_P2P = -2,
 TRADEHOLD_ALL = -1,
 TRADEHOLD_NONE = 0,
};

enum PRODUCTQUALITY
{
	Common = 0,
	Uncommon = 1,
	Rare = 2,
	VeryRare = 3,
	Import = 4,
	Exotic = 5,
	BlackMarket = 6,
	Premium = 7,
	Limited = 8,
	MAX = 9
};

enum UNLOCKMETHOD
{
	Default = 0,
	Drop = 1,
	Special = 2,
	Reward = 3,
	DLC = 4,
	Never = 5,
	MAX_ = 6
};

#define CONSTRUCTORS(name)\
name(std::uintptr_t mem);\
name(const name& other);\
name& operator=(name rhs);\
~name();

#define PIMPL \
struct Impl;\
__pragma(warning(suppress:4251));\
std::unique_ptr<Impl> pimpl;

#define GETSETH(type, name) \
void Set##name(type name);\
type Get##name();

#define GETH(type, name)\
type Get##name();

#pragma pack ( pop )