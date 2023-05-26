#pragma once
//#include "../shared.h"

#include "linmath.h"
#include <map>
#include <string>
#include <algorithm>

#include "../core/compiler_toggles.h"
#include "bakkesmod/plugin/bakkesmodsdk.h"

#ifndef CONST_RadToUnrRot
#define CONST_RadToUnrRot    10430.3783504704527f
#endif

#ifndef CONST_UnrRotToRad
#define CONST_UnrRotToRad    0.00009587379924285f
#endif

#ifndef CONST_DegToUnrRot
#define CONST_DegToUnrRot    182.0444f
#endif

#ifndef CONST_PI_D
#define CONST_PI_D           3.14159265358979323846
#endif

#ifndef CONST_PI_F
#define CONST_PI_F           3.1415926f
#endif


enum ToastType
{
    ToastType_Info = 0,
    ToastType_OK = 1,
    ToastType_Warning = 2,
    ToastType_Error = 3
};

#pragma pack ( push, 0x8 )
struct FVector;
struct FRotator;

// #Vector
//Forward declarations of Vector non-member operator overloads
struct Vector;
inline Vector operator+(const Vector v1, const Vector v2);
inline Vector operator-(const Vector v1, const Vector v2);
inline Vector operator*(const Vector v1, const Vector v2);
inline Vector operator/(const Vector v1, const Vector v2);
inline Vector operator+(const Vector v1, const float f);
inline Vector operator-(const Vector v1, const float f);
inline Vector operator*(const Vector v1, const float f);
inline Vector operator/(const Vector v1, const float f);

struct Vector {
    float X, Y, Z;

    Vector(FVector v);
    Vector(float x, float y, float z) : X(x), Y(y), Z(z) {}
    Vector(float def) : X(def), Y(def), Z(def) {}
    Vector() : Vector(0.0) {}
    operator FVector();
    explicit operator FVector() const;

    //Vector member operator overloads
    inline Vector operator+=(const Vector v2) {
        X += v2.X;
        Y += v2.Y;
        Z += v2.Z;
        return *this;
    }
    inline Vector operator-=(const Vector v2) {
        X -= v2.X;
        Y -= v2.Y;
        Z -= v2.Z;
        return *this;
    }
    inline Vector operator*=(const Vector v2) {
        X *= v2.X;
        Y *= v2.Y;
        Z *= v2.Z;
        return *this;
    }
    inline Vector operator/=(const Vector v2) {
        X /= v2.X;
        Y /= v2.Y;
        Z /= v2.Z;
        return *this;
    }
    inline Vector operator+=(const float f) {
        X += f;
        Y += f;
        Z += f;
        return *this;
    }
    inline Vector operator-=(const float f) {
        X -= f;
        Y -= f;
        Z -= f;
        return *this;
    }
    inline Vector operator*=(const float f) {
        X *= f;
        Y *= f;
        Z *= f;
        return *this;
    }
    inline Vector operator/=(const float f) {
        X /= f;
        Y /= f;
        Z /= f;
        return *this;
    }

    inline float magnitude() const
    {
        return sqrtf(X * X + Y * Y + Z * Z);
    }

    inline void normalize()
    {
        float magnitudez = magnitude();
        X = X / magnitudez;
        Y = Y / magnitudez;
        Z = Z / magnitudez;
    }

    inline Vector getNormalized()
    {
        Vector normalized = *this;
        normalized.normalize();
        return normalized;
    }

    inline Vector clone() const
    {
        return Vector(X, Y, Z);
    }

    static inline float dot(const Vector v1, const Vector v2)
    {
        return v1.X * v2.X + v1.Y * v2.Y + v1.Z * v2.Z;
    }

    static inline Vector cross(const Vector v1, const Vector v2)
    {
        float x = v1.Y * v2.Z - v1.Z * v2.Y;
        float y = v1.Z * v2.X - v1.X * v2.Z;
        float z = v1.X * v2.Y - v1.Y * v2.X;
        return Vector(x, y, z);
    }

    static inline Vector lerp(const Vector v1, const Vector v2, const float t)
    {
        float x = (1.0f - t) * v1.X + t * v2.X;
        float y = (1.0f - t) * v1.Y + t * v2.Y;
        float z = (1.0f - t) * v1.Z + t * v2.Z;
        return Vector(x, y, z);
    }

    static inline Vector slerp(const Vector v1, const Vector v2, const float t)
    {
        Vector a = v1.clone();
        Vector b = v2.clone();
        
        float dot = Vector::dot(a, b);
        
        float theta = acosf(dot) * t;
        
        Vector relVector = b - (a * dot);
        relVector.normalize();
        float cosTheta = cosf(theta);
        float sinTheta = sinf(theta);
        return a * cosTheta + relVector * sinTheta;
    }
};

//Vector non-member operator overloads
inline Vector operator+(const Vector v1, const Vector v2) {
    return Vector(v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z);
}

inline Vector operator-(const Vector v1, const Vector v2) {
    return Vector(v1.X - v2.X, v1.Y - v2.Y, v1.Z - v2.Z);
}

inline Vector operator*(const Vector v1, const Vector v2) {
    return Vector(v1.X * v2.X, v1.Y * v2.Y, v1.Z * v2.Z);
}

inline Vector operator/(const Vector v1, const Vector v2) {
    return Vector(v1.X / v2.X, v1.Y / v2.Y, v1.Z / v2.Z);
}

inline Vector operator+(const Vector v1, const float f) {
    return Vector(v1.X + f, v1.Y + f, v1.Z + f);
}

inline Vector operator-(const Vector v1, const float f) {
    return Vector(v1.X - f, v1.Y - f, v1.Z - f);
}

inline Vector operator*(const Vector v1, const float f) {
    return Vector(v1.X * f, v1.Y * f, v1.Z * f);
}

inline Vector operator/(const Vector v1, const float f) {
    return Vector(v1.X / f, v1.Y / f, v1.Z / f);
}


// #Rotator
//Forward declarations of Rotator non-member operator overloads
struct Rotator;
inline Rotator operator+(const Rotator r1, const Rotator r2);
inline Rotator operator-(const Rotator r1, const Rotator r2);
inline Rotator operator*(const Rotator r1, const Rotator r2);
inline Rotator operator/(const Rotator r1, const Rotator r2);

struct Rotator {
    int Pitch, Yaw, Roll;
    //Player rotation Min(-16364, -32768, -32768)
    //Player rotation Max(16340, 32764, 32764)

    Rotator(FRotator r);
    Rotator(int pitch, int yaw, int roll) : Pitch(pitch), Yaw(yaw), Roll(roll) {}
    Rotator(int def) : Pitch(def), Yaw(def), Roll(def) {}
    Rotator() : Rotator(0) {}
    operator FRotator();
    explicit operator FRotator() const;

    inline Rotator operator+=(const Rotator r2) {
        Pitch += r2.Pitch;
        Yaw   += r2.Yaw;
        Roll  += r2.Roll;
        return *this;
    }
    inline Rotator operator-=(const Rotator r2) {
        Pitch -= r2.Pitch;
        Yaw   -= r2.Yaw;
        Roll  -= r2.Roll;
        return *this;
    }
    inline Rotator operator*=(const Rotator r2) {
        Pitch *= r2.Pitch;
        Yaw   *= r2.Yaw;
        Roll  *= r2.Roll;
        return *this;
    }
    inline Rotator operator/=(const Rotator r2) {
        Pitch /= r2.Pitch;
        Yaw   /= r2.Yaw;
        Roll  /= r2.Roll;
        return *this;
    }
};

static inline int fixRotator(int newRotation) {// F THIS FOR NOW
    return newRotation;
    //newRotation = (((int)newRotation + 32768) % (32768 + 32764)) - 32768;
    //newRotation = (((int)newRotation - 32764) % (32768 + 32764)) + 32764;
    ////if (newRotation >= 32767) {
    ////    newRotation -= 65535;
    ////    //newRotation = -32767 + (newRotation - 32767);
    ////}
    ////else if (newRotation <= -32767) { //-35000 
    ////    newRotation += 65535;
    ////    //newRotation = 32767 + (newRotation + 32767);
    ////}
    //return newRotation;
}

static inline int fixPitch(int newRotation) {// F THIS FOR NOW
    return newRotation;
    //newRotation = (((int)newRotation + 16384) % (32768)) - 16384;
    //newRotation = (((int)newRotation - 16384) % (32768)) + 16384;

    ////if (newRotation >= 16383) {
    ////    newRotation -= 32767;
    ////    //newRotation = -16383 + (newRotation - 16383);
    ////}
    ////else if (newRotation <= -16383) { //-35000 
    ////    newRotation += 32767;
    ////    //newRotation = 16383 + (newRotation + 16383);
    ////}
    //return newRotation;
}

//Rotator non-member operator overloads
inline Rotator operator+(const Rotator r1, const Rotator r2) {
    return Rotator(fixPitch(r1.Pitch + r2.Pitch), fixRotator(r1.Yaw + r2.Yaw), fixRotator(r1.Roll + r2.Roll));
}

inline Rotator operator-(const Rotator r1, const Rotator r2) {
    return Rotator(fixPitch(r1.Pitch - r2.Pitch), fixRotator(r1.Yaw - r2.Yaw), fixRotator(r1.Roll - r2.Roll));
}

inline Rotator operator*(const Rotator r1, const Rotator r2) {
    return Rotator(fixPitch(r1.Pitch * r2.Pitch), fixRotator(r1.Yaw * r2.Yaw), fixRotator(r1.Roll * r2.Roll));
}

inline Rotator operator/(const Rotator r1, const Rotator r2) {
    return Rotator(fixPitch(r1.Pitch / r2.Pitch), fixRotator(r1.Yaw / r2.Yaw), fixRotator(r1.Roll / r2.Roll));
}


// #VectorRotatorConversions
static Rotator inline VectorToRotator(const Vector vVector)
{
    Rotator rRotation;

    rRotation.Yaw = static_cast<int>(atan2(vVector.Y, vVector.X) * CONST_RadToUnrRot);
    rRotation.Pitch = static_cast<int>(atan2(vVector.Z, sqrtf(vVector.X * vVector.X + vVector.Y * vVector.Y)) * CONST_RadToUnrRot);
    rRotation.Roll = 0;

    return rRotation;
}

static inline Vector RotatorToVector(const Rotator R)
{
    Vector vec;

    float fYaw = R.Yaw * static_cast<float>(CONST_UnrRotToRad);
    float fPitch = R.Pitch * static_cast<float>(CONST_UnrRotToRad);
    float CosPitch = cosf(fPitch);
    vec.X = cosf(fYaw) * CosPitch;
    vec.Y = sinf(fYaw) * CosPitch;
    vec.Z = sinf(fPitch);
    
    return vec;
}


// #Quat
//Forward declaration of Quat non-member operator overload
struct Quat;
inline Quat operator*(const Quat q1, const Quat q2);

struct Quat {
    float X, Y, Z, W;

    Quat(float w, float x, float y, float z) : W(w), X(x), Y(y), Z(z) {}
    Quat() : Quat(1.0, 0.0, 0.0, 0.0) {}

    inline Quat conjugate() const
    {
        return Quat(W, -X, -Y, -Z);
    }

    inline Quat normalize()
    {
        float mag = sqrtf(X*X + Y*Y + Z*Z + W*W);
        X /= mag;
        Y /= mag;
        Z /= mag;
        return *this;
    }

    inline Quat operator*=(const Quat q2)
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

        W = mulW;
        X = mulX;
        Y = mulY;
        Z = mulZ;

        return *this;
    }
};

//Quat non-member operator overload
inline Quat operator*(const Quat q1, const Quat q2)
{
    float mulW = q1.W * q2.W;
    mulW -= q1.X * q2.X;
    mulW -= q1.Y * q2.Y;
    mulW -= q1.Z * q2.Z;

    float mulX = q1.W * q2.X;
    mulX += q1.X * q2.W;
    mulX += q1.Y * q2.Z;
    mulX -= q1.Z * q2.Y;

    float mulY = q1.W * q2.Y;
    mulY -= q1.X * q2.Z;
    mulY += q1.Y * q2.W;
    mulY += q1.Z * q2.X;

    float mulZ = q1.W * q2.Z;
    mulZ += q1.X * q2.Y;
    mulZ -= q1.Y * q2.X;
    mulZ += q1.Z * q2.W;

    return Quat(mulW, mulX, mulY, mulZ);
}

static inline Quat QuatSlerp(const Quat q1, const Quat q2, float percent)
{
    //percent range: 0-1
    //https://www.euclideanspace.com/maths/algebra/realNormedAlgebra/quaternions/slerp/index.htm
    float dot = q1.W*q2.W + q1.X*q2.X + q1.Y*q2.Y + q1.Z*q2.Z;
    // if qa=qb or qa=-qb then theta = 0 and we can return qa
    if (abs(dot) >= 1.f)
    {
        return q1;
    }
    // Calculate temporary values.
    float halfTheta = acosf(dot);
    float sinHalfTheta = sqrtf(1.f - dot*dot);
    // if theta = 180 degrees then result is not fully defined
    // we could rotate around any axis normal to qa or qb
    if (fabsf(sinHalfTheta) < 0.001f)
    {
        Quat q;
        q.W = q1.W * 0.5f + q2.W * 0.5f;
        q.X = q1.X * 0.5f + q2.X * 0.5f;
        q.Y = q1.Y * 0.5f + q2.Y * 0.5f;
        q.Z = q1.Z * 0.5f + q2.Z * 0.5f;
        return q;
    }
    float ratioA = sinf((1.f - percent) * halfTheta) / sinHalfTheta;
    float ratioB = sinf(percent * halfTheta) / sinHalfTheta;

    Quat q;
    q.W = (q1.W * ratioA + q2.W * ratioB);
    q.X = (q1.X * ratioA + q2.X * ratioB);
    q.Y = (q1.Y * ratioA + q2.Y * ratioB);
    q.Z = (q1.Z * ratioA + q2.Z * ratioB);
    
    return q;
}


// #RotateVector
static inline Vector RotateVectorWithQuat(const Vector v, const Quat q)
{
    Quat p = Quat(0 ,v.X ,v.Y ,v.Z);
    Quat result = (q * p) * q.conjugate();

    return Vector{result.X, result.Y, result.Z};
}


// #RotatorQuatConversions
static inline Quat RotatorToQuat(const Rotator rot)
{
    float rotatorToRadian = ((CONST_PI_F / 180.f) * .5f) / CONST_DegToUnrRot;
    float sinPitch = sinf(rot.Pitch * rotatorToRadian);
    float cosPitch = cosf(rot.Pitch * rotatorToRadian);
    float sinYaw   = sinf(rot.Yaw   * rotatorToRadian);
    float cosYaw   = cosf(rot.Yaw   * rotatorToRadian);
    float sinRoll  = sinf(rot.Roll  * rotatorToRadian);
    float cosRoll  = cosf(rot.Roll  * rotatorToRadian);
    
    Quat convertedQuat;
    convertedQuat.X = (cosRoll  * sinPitch * sinYaw) - (sinRoll * cosPitch * cosYaw);
    convertedQuat.Y = (-cosRoll * sinPitch * cosYaw) - (sinRoll * cosPitch * sinYaw);
    convertedQuat.Z = (cosRoll  * cosPitch * sinYaw) - (sinRoll * sinPitch * cosYaw);
    convertedQuat.W = (cosRoll  * cosPitch * cosYaw) + (sinRoll * sinPitch * sinYaw);

    return convertedQuat;
}

static inline Rotator QuatToRotator(const Quat q)
{
    //From Arator's HelperFunctions
    Vector fwd   = RotateVectorWithQuat(Vector(1, 0, 0), q);
    Vector right = RotateVectorWithQuat(Vector(0, 1, 0), q);
    Vector up    = RotateVectorWithQuat(Vector(0, 0, 1), q);
    fwd.normalize();
    right.normalize();
    up.normalize();

    //Pitch
    float pitch_f = asinf(fwd.Z);
    int PITCH = static_cast<int>((pitch_f / (CONST_PI_F / 2.f)) * 16384.f);

    //Yaw
    float hor_mag = sqrtf(fwd.X * fwd.X + fwd.Y * fwd.Y);
    float fwd_y = asinf(fwd.Y / hor_mag);
    if (fwd_y >= 0)
    {
        if (fwd.X < 0)
            fwd_y = CONST_PI_F - fwd_y;
    }
    else
    {
        if (fwd.X < 0)
            fwd_y = -CONST_PI_F - fwd_y;
    }
    int YAW = static_cast<int>((fwd_y / CONST_PI_F) * 32768.f);

    //Roll
    Vector vert = (up.Z < 0) ? Vector(0, 0, -1) : Vector(0, 0, 1);
    Vector hor_right = Vector::cross(fwd, vert) * -1;// left-handed coordinate system
    hor_right.normalize();

    float roll_cos = Vector::dot(hor_right, right);
    float roll_f = acosf(roll_cos);
    float up_f = asinf(up.Z);
    
    if (right.Z >= 0)
    {
        if (up.Z >= 0)
            roll_f = -roll_f;
        else
            roll_f  = -CONST_PI_F + roll_f;
    }
    else
    {
        if (up.Z < 0)
            roll_f = CONST_PI_F - roll_f;
    }
    int ROLL = static_cast<int>((roll_f / CONST_PI_F) * 32768.f);

    return Rotator(PITCH, YAW, ROLL);
}



// #Vector2
//Forward declarations of Vector2 non-member operator overloads
struct Vector2;
inline Vector2 operator+(const Vector2 v1, const Vector2 v2);
inline Vector2 operator-(const Vector2 v1, const Vector2 v2);
inline Vector2 operator*(const Vector2 v1, const Vector2 v2);
inline Vector2 operator/(const Vector2 v1, const Vector2 v2);
inline Vector2 operator+(const Vector2 v1, const int i);
inline Vector2 operator-(const Vector2 v1, const int i);
inline Vector2 operator*(const Vector2 v1, const int i);
inline Vector2 operator/(const Vector2 v1, const int i);

struct Vector2 {
    int X, Y;

    Vector2 minus(const Vector2 other) const {
        return{ X - other.X,  Y - other.Y };
    }

    inline Vector2 operator+=(const Vector2 v2) {
        X += v2.X;
        Y += v2.Y;
        return *this;
    }
    inline Vector2 operator-=(const Vector2 v2) {
        X -= v2.X;
        Y -= v2.Y;
        return *this;
    }
    inline Vector2 operator*=(const Vector2 v2) {
        X *= v2.X;
        Y *= v2.Y;
        return *this;
    }
    inline Vector2 operator/=(const Vector2 v2) {
        X /= v2.X;
        Y /= v2.Y;
        return *this;
    }
    inline Vector2 operator+=(const int i) {
        X += i;
        Y += i;
        return *this;
    }
    inline Vector2 operator-=(const int i) {
        X -= i;
        Y -= i;
        return *this;
    }
    inline Vector2 operator*=(const int i) {
        X *= i;
        Y *= i;
        return *this;
    }
    inline Vector2 operator/=(const int i) {
        X /= i;
        Y /= i;
        return *this;
    }
};

//Vector2 non-member operator overloads
inline Vector2 operator+(const Vector2 v1, const Vector2 v2) {
    return Vector2{v1.X + v2.X, v1.Y + v2.Y};
}

inline Vector2 operator-(const Vector2 v1, const Vector2 v2) {
    return Vector2{v1.X - v2.X, v1.Y - v2.Y};
}

inline Vector2 operator*(const Vector2 v1, const Vector2 v2) {
    return Vector2{v1.X * v2.X, v1.Y * v2.Y};
}

inline Vector2 operator/(const Vector2 v1, const Vector2 v2) {
    return Vector2{v1.X / v2.X, v1.Y / v2.Y};
}

inline Vector2 operator+(const Vector2 v1, const int i) {
    return Vector2{v1.X + i, v1.Y + i};
}

inline Vector2 operator-(const Vector2 v1, const int i) {
    return Vector2{v1.X - i, v1.Y - i};
}

inline Vector2 operator*(const Vector2 v1, const int i) {
    return Vector2{v1.X * i, v1.Y * i};
}

inline Vector2 operator/(const Vector2 v1, const int i) {
    return Vector2{v1.X / i, v1.Y / i};
}



// #Vector2F
//Forward declarations of Vector2F non-member operator overloads
struct Vector2F;
inline Vector2F operator+(const Vector2F v1, const Vector2 v2);
inline Vector2F operator-(const Vector2F v1, const Vector2 v2);
inline Vector2F operator*(const Vector2F v1, const Vector2 v2);
inline Vector2F operator/(const Vector2F v1, const Vector2 v2);
inline Vector2F operator+(const Vector2F v1, const Vector2F v2);
inline Vector2F operator-(const Vector2F v1, const Vector2F v2);
inline Vector2F operator*(const Vector2F v1, const Vector2F v2);
inline Vector2F operator/(const Vector2F v1, const Vector2F v2);
inline Vector2F operator+(const Vector2F v1, const float f);
inline Vector2F operator-(const Vector2F v1, const float f);
inline Vector2F operator*(const Vector2F v1, const float f);
inline Vector2F operator/(const Vector2F v1, const float f);

struct Vector2F {
    float X, Y;

    Vector2F minus(const Vector2 other) const {
        return{ X - static_cast<float>(other.X),  Y - static_cast<float>(other.Y) };
    }

    Vector2F minus(const Vector2F other) const {
        return{ X - other.X,  Y - other.Y };
    }

    inline Vector2F operator+=(const Vector2 v2) {
        X += v2.X;
        Y += v2.Y;
        return *this;
    }
    inline Vector2F operator-=(const Vector2 v2) {
        X -= v2.X;
        Y -= v2.Y;
        return *this;
    }
    inline Vector2F operator*=(const Vector2 v2) {
        X *= v2.X;
        Y *= v2.Y;
        return *this;
    }
    inline Vector2F operator/=(const Vector2 v2) {
        X /= v2.X;
        Y /= v2.Y;
        return *this;
    }
    inline Vector2F operator+=(const Vector2F v2) {
        X += v2.X;
        Y += v2.Y;
        return *this;
    }
    inline Vector2F operator-=(const Vector2F v2) {
        X -= v2.X;
        Y -= v2.Y;
        return *this;
    }
    inline Vector2F operator*=(const Vector2F v2) {
        X *= v2.X;
        Y *= v2.Y;
        return *this;
    }
    inline Vector2F operator/=(const Vector2F v2) {
        X /= v2.X;
        Y /= v2.Y;
        return *this;
    }
    inline Vector2F operator+=(const float f) {
        X += f;
        Y += f;
        return *this;
    }
    inline Vector2F operator-=(const float f) {
        X -= f;
        Y -= f;
        return *this;
    }
    inline Vector2F operator*=(const float f) {
        X *= f;
        Y *= f;
        return *this;
    }
    inline Vector2F operator/=(const float f) {
        X /= f;
        Y /= f;
        return *this;
    }
};

//Vector2F non-member operator overloads
inline Vector2F operator+(const Vector2F v1, const Vector2 v2) {
    return Vector2F{v1.X + v2.X, v1.Y + v2.Y};
}

inline Vector2F operator-(const Vector2F v1, const Vector2 v2) {
    return Vector2F{v1.X - v2.X, v1.Y - v2.Y};
}

inline Vector2F operator*(const Vector2F v1, const Vector2 v2) {
    return Vector2F{v1.X * v2.X, v1.Y * v2.Y};
}

inline Vector2F operator/(const Vector2F v1, const Vector2 v2) {
    return Vector2F{v1.X / v2.X, v1.Y / v2.Y};
}

inline Vector2F operator+(const Vector2F v1, const Vector2F v2) {
    return Vector2F{v1.X + v2.X, v1.Y + v2.Y};
}

inline Vector2F operator-(const Vector2F v1, const Vector2F v2) {
    return Vector2F{v1.X - v2.X, v1.Y - v2.Y};
}

inline Vector2F operator*(const Vector2F v1, const Vector2F v2) {
    return Vector2F{v1.X * v2.X, v1.Y * v2.Y};
}

inline Vector2F operator/(const Vector2F v1, const Vector2F v2) {
    return Vector2F{v1.X / v2.X, v1.Y / v2.Y};
}

inline Vector2F operator+(const Vector2F v1, const float f) {
    return Vector2F{v1.X + f, v1.Y + f};
}

inline Vector2F operator-(const Vector2F v1, const float f) {
    return Vector2F{v1.X - f, v1.Y - f};
}

inline Vector2F operator*(const Vector2F v1, const float f) {
    return Vector2F{v1.X * f, v1.Y * f};
}

inline Vector2F operator/(const Vector2F v1, const float f) {
    return Vector2F{v1.X / f, v1.Y / f};
}



// #LinearColor
//Forward declarations of LinearColor non-member operator overloads
struct LinearColor;
struct FLinearColor;
inline LinearColor operator*(const LinearColor c1, const float f);
inline LinearColor operator/(const LinearColor c1, const float f);
inline bool operator==(const LinearColor c1, const LinearColor c2);


struct LinearColor
{
	LinearColor() = default;
	explicit LinearColor(const FLinearColor& r);

	LinearColor(float r, float g, float b, float a):
		R{r},G{g},B{b},A{a} {}

	explicit operator FLinearColor() const;

	float R, G, B, A;

	inline LinearColor operator*=(const float f)
	{
		R *= f;
		G *= f;
		B *= f;
		A *= f;
		return *this;
	}

	inline LinearColor operator/=(const float f)
	{
		R /= f;
		G /= f;
		B /= f;
		A /= f;
		return *this;
	}
};

//LinearColor non-member operator overloads
inline LinearColor operator*(const LinearColor c1, const float f) {
    return LinearColor{c1.R * f, c1.G * f, c1.B * f, c1.A * f};
}

inline LinearColor operator/(const LinearColor c1, const float f) {
    return LinearColor{c1.R / f, c1.G / f, c1.B / f, c1.A / f};
}

inline bool operator==(const LinearColor c1, const LinearColor c2) {
    return c1.R == c2.R &&
           c1.G == c2.G &&
           c1.B == c2.B &&
           c1.A == c2.A;
}

inline bool operator!=(const LinearColor c1, const LinearColor c2) {
    return !(c1 == c2);
}



// #OtherStructs
struct PredictionInfo {
    float Time;
    float ArchTopTime;
    Vector Location;
    Vector Velocity;
    Vector ArchTop;
    Vector ArchTopVelocity;
    unsigned long bHitWall : 1;
    unsigned long bHitGround : 1;
};

struct SteamID
{
    unsigned long long ID;
};

struct SkillRating {
    float Mu;
    float Sigma;
};

struct SkillRank
{
    int Tier;
    int Division;
    int MatchesPlayed;
};

struct FColor;

struct UnrealColor
{
	unsigned char B;
	unsigned char G;
	unsigned char R;
	unsigned char A;

	UnrealColor() = default;
    explicit UnrealColor(const FColor& other);
	explicit operator FColor() const;
	UnrealColor(unsigned char b, unsigned char g, unsigned char r, unsigned char a): B{b}, G{g}, R{r}, A{a} {}


	DEFAULTEQUALITY(UnrealColor)
	DEFAULTCOMPARE(UnrealColor)
};

struct ControllerInput {
    float Throttle = .0f;
    float Steer = .0f;
    float Pitch = .0f;
    float Yaw = .0f;
    float Roll = .0f;
    float DodgeForward = .0f;
    float DodgeStrafe = .0f;
    unsigned long Handbrake : 1;
    unsigned long Jump :1;
    unsigned long ActivateBoost : 1;
    unsigned long HoldingBoost : 1;
    unsigned long Jumped : 1;
};

struct RecordedSample
{
    float Low;
    float High;
};

struct POV {
    Vector location;
    Rotator rotation;
    float FOV;
};

struct ViewTarget {
    void* Target;      // ActorWrapper(Target)
    void* Controller;  // PlayerControllerWrapper(Controller)
    struct POV POV;    // 
    float AspectRatio; // 
    void* PRI;         // PRIWrapper(PRI)
};

struct CameraSave
{
    bool InvertSwivelPitch;
    bool CameraShake;
};

struct FProfileCameraSettings;

struct ProfileCameraSettings
{
    ProfileCameraSettings() = default;
    explicit ProfileCameraSettings(const FProfileCameraSettings& other);
    explicit operator FProfileCameraSettings() const;

    float FOV;
    float Height;
    float Pitch;
    float Distance;
    float Stiffness;
    float SwivelSpeed;
    float TransitionSpeed;
};

struct GamepadSettings
{
    float ControllerDeadzone;
    float DodgeInputThreshold;
    float SteeringSensitivity;
    float AirControlSensitivity;
};

struct RBState
{
    Quat Quaternion;
    Vector Location;
    Vector LinearVelocity;
    Vector AngularVelocity;
    float Time;
    unsigned long bSleeping : 1;
    unsigned long bNewData : 1;
};

struct WorldContactData
{
    unsigned long bHasContact : 1;
    Vector Location;
    Vector Velocity;
    Vector Normal;
};

struct StickyForceData {
    float Ground;
    float Wall;
};

struct WheelContactData {
    unsigned long bHasContact : 1;
    unsigned long bHasContactWithWorldGeometry : 1;
    float HasContactChangeTime;
    void* Actor;
    void* Component;
    Vector Location;
    Vector Normal;
    Vector LatDirection;
    Vector LongDirection;
    void* PhysMatProp;
};

struct ReplayScoreData
{
    uintptr_t ScoredBy;   //PriWrapper
    uintptr_t AssistedBy; //PriWrapper
    float Speed;
    float Time;
    unsigned char ScoreTeam;
};

struct VideoSettings
{
    bool bVsync;
    bool bShowWeatherFX;
    bool bShowLightShafts;
    bool bTranslucentArenaShaders;
    bool bShowLensFlares;
    bool bEnableHDRSideBySideVisualizer;
    bool bUncappedFramerate;
    float HDRBrightnessScale;
    float HDRPaperWhiteScale;
    float HDRGammaScale;

    int WindowMode;
    std::string Resolution;
    int MaxFPS;
    std::map<std::string, std::string> VideoOptions;
};

struct ProductInstanceID
{
	unsigned long long upper_bits;
	unsigned long long lower_bits;

	friend bool operator==(const ProductInstanceID& lhs, const ProductInstanceID& rhs)
	{
		return lhs.upper_bits == rhs.upper_bits
			&& lhs.lower_bits == rhs.lower_bits;
	}

	friend bool operator!=(const ProductInstanceID& lhs, const ProductInstanceID& rhs)
	{
		return !(lhs == rhs);
	}
};

struct BAKKESMOD_PLUGIN_IMPORT GUIDWrapper
{
    GUIDWrapper() = default;
	GUIDWrapper(int32_t a, int32_t b, int32_t c, int32_t d);
	explicit GUIDWrapper(const struct FGuid& guid);
    static GUIDWrapper Create();

	enum class EGuidFormats : uint8_t
	{
		Digits =							0, // Example: 00000000000000000000000000000000
		DigitsWithHyphens =					1, // Example: 00000000-0000-0000-0000-000000000000
		DigitsWithHyphensInBraces =			2, // Example: {00000000-0000-0000-0000-000000000000}
		DigitsWithHyphensInParentheses =	3, // Example: (00000000-0000-0000-0000-000000000000)
		HexValuesInBraces =					4, // Example: {0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}}
		UniqueObjectGuid =					5, // Example: 00000000-00000000-00000000-00000000
	};
	int32_t A = 0, B = 0, C = 0, D = 0;

    bool IsValid() const;
	std::string ToString(EGuidFormats format = EGuidFormats::UniqueObjectGuid) const;
	
};



struct TrainingRoundProgress {
    int RoundNumber; 
    unsigned char Status; //See: EnumWrapper::GetTrainingRoundAttempts
    unsigned char Padding[0x3];
};

// #Enums
enum TRADEHOLD
{
    TRADEHOLD_P2P = -2,
    TRADEHOLD_ALL = -1,
    TRADEHOLD_NONE = 0,
};

enum [[deprecated("Not guaranteed to be up to date, use EnumWrapper::GetProductQualities() to future proof your code.")]] PRODUCTQUALITY
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
    Legacy = 9,
    MAX = 10
};

enum [[deprecated("Not guaranteed to be up to date, use EnumWrapper::GetUnlockMethods() to future proof your code.")]] UNLOCKMETHOD
{
    Default = 0,
    Drop = 1,
    Special = 2,
    Reward = 3,
    DLC = 4,
    Never = 5,
    MAX_ = 6
};

enum [[deprecated("Not guaranteed to be up to date, use the ProductWrappers to future proof your code.")]]  CARBODY
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

enum OnlinePlatform
{
    OnlinePlatform_Unknown = 0,
    OnlinePlatform_Steam = 1,
    OnlinePlatform_PS4 = 2,
    OnlinePlatform_PS3 = 3,
    OnlinePlatform_Dingo = 4, //XBox?
    OnlinePlatform_QQ = 5,
    OnlinePlatform_OldNNX = 6,
    OnlinePlatform_NNX = 7,
    OnlinePlatform_PsyNet = 8,
    OnlinePlatform_Deleted = 9,
    OnlinePlatform_WeGame = 10,
    OnlinePlatform_Epic = 11,
    OnlinePlatform_MAX = 12
};




// #Defines
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