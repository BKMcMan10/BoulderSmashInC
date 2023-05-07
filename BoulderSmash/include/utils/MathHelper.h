#ifndef MATHHELPER_H
#define MATHHELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <cglm/cglm.h>
#include <cglm/vec2.h>
#include <cglm/vec3.h>
#include <cglm/vec4.h>
#include "core/Logger.h"
#include "utils/MemoryHelper.h"

#define PI_2 GLM_PI_2
#define PI GLM_PI
#define radians(_x) ((_x) * (__typeof__(_x)) (PI / 180.0f))
#define degrees(_x) ((_x) * (__typeof__(_x)) (180.0f / PI))

typedef vec2 Vector2f;
typedef vec3 Vector3f;
typedef float Vector4f[4];

typedef ivec2 Vector2i;
typedef ivec3 Vector3i;
typedef ivec4 Vector4i;

typedef double Vector2d[2];
typedef double Vector3d[3];
typedef double Vector4d[4];

typedef vec2* Matrix2f[2];
typedef vec3* Matrix3f[3];
typedef Vector4f* Matrix4f[4];

typedef mat4 mat;

Vector2f* MathHelper_CreateVector2f(float x, float y)
{
    vec2* out = (vec2*)malloc(sizeof(out));
    *out[0] = x;
    *out[1] = y;
    return out;
}

Vector3f* MathHelper_CreateVector3f(float x, float y, float z)
{
    vec3* out = (vec3*)malloc(sizeof(out));
    Logger_WriteConsole("AAAA wif vecc3f", "MathHelper", LOGLEVEL_INFO);
    *out[0] = x;
    *out[1] = y;
    *out[2] = z;
    Logger_WriteConsole("AAAA wif vecc3f dun", "MathHelper", LOGLEVEL_INFO);
    return out;
}

vec4* MathHelper_CreateVector4f(float x, float y, float z, float w)
{
    vec4* out = malloc(sizeof(out));
    *out[0] = x;
    *out[1] = y;
    *out[2] = z;
    *out[3] = w;
    return out;
}

Vector2i* MathHelper_CreateVector2i(int x, int y)
{
    ivec2* out = (ivec2*)malloc(sizeof(out));
    *out[0] = x;
    *out[1] = y;
    return out;
}

Vector3i* MathHelper_CreateVector3i(int x, int y, int z)
{
    ivec3* out = (ivec3*)malloc(sizeof(out));
    *out[0] = x;
    *out[1] = y;
    *out[2] = z;
    return out;
}

Vector4i* MathHelper_CreateVector4i(int x, int y, int z, int w)
{
    ivec4* out = (ivec4*)malloc(sizeof(out));    *out[0] = x;
    *out[1] = y;
    *out[2] = z;
    *out[3] = w;
    return out;
}

Vector2d* MathHelper_CreateVector2d(double x, double y)
{
    Vector2d* out = (Vector2d*)malloc(sizeof(out));
    *out[0] = x;
    *out[1] = y;
    return out;
}

Vector3d* MathHelper_CreateVector3d(double x, double y, double z)
{
    Vector3d* out = (Vector3d*)malloc(sizeof(out));
    *out[0] = x;
    *out[1] = y;
    *out[2] = z;
    return out;
}

Vector4d* MathHelper_CreateVector4d(double x, double y, double z, double w)
{
    Vector4d* out = (Vector4d*)malloc(sizeof(out));
    *out[0] = x;
    *out[1] = y;
    *out[2] = z;
    *out[3] = w;
    return out;
}

Matrix2f* MathHelper_CreateMatrix2f(Vector2f* x, Vector2f* y)
{
    Matrix2f* out = (Matrix2f*)malloc(sizeof(out));
    *out[0] = x;
    *out[1] = y;
    return out;
}

Matrix3f* MathHelper_CreateMatrix3f(Vector3f* x, Vector3f* y, Vector3f* z)
{
    Matrix3f* out = (Matrix3f*)malloc(sizeof(out));
    *out[0] = x;
    *out[1] = y;
    *out[2] = z;
    return out;
}

Matrix4f* MathHelper_CreateMatrix4f(Vector4f* x, Vector4f* y, Vector4f* z, Vector4f* w)
{
    
    Matrix4f* out = malloc(sizeof(out));
    Logger_WriteConsole("Matttricc creatt", "MathHelper", LOGLEVEL_INFO);
    *out[0] = x;
    *out[1] = y;
    *out[2] = z;
    *out[3] = w;
    return out;
    Logger_WriteConsole("Matttricc creatt dun", "MathHelper", LOGLEVEL_INFO);
}

Vector2f* MathHelper_CombineVector2f(Vector2f* x, Vector2f* y)
{
    Vector2f* out = (Vector2f*)malloc(sizeof(out));
    *out[0] = *x[0] + *y[0];
    *out[1] = *x[1] + *y[1];
    return out;
}

Vector3f* MathHelper_CombineVector3f(Vector3f* x, Vector3f* y)
{
    Vector3f* out = (Vector3f*)malloc(sizeof(out));
    *out[0] = *x[0] + *y[0];
    *out[1] = *x[1] + *y[1];
    *out[2] = *x[2] + *y[2];
    return out;
}

Vector4f* MathHelper_CombineVector4f(Vector4f* x, Vector4f* y)
{
    Vector4f* out = (Vector4f*)malloc(sizeof(out));
    *out[0] = *x[0] + *y[0];
    *out[1] = *x[1] + *y[1];
    *out[2] = *x[2] + *y[2];
    *out[3] = *x[3] + *y[3];
    return out;
}

Vector2f* MathHelper_SubtractVector2f(Vector2f* x, Vector2f* y)
{
    Vector2f* out = (Vector2f*)malloc(sizeof(out));
    *out[0] = *x[0] - *y[0];
    *out[1] = *x[1] - *y[1];
    return out;
}

Vector3f* MathHelper_SubtractVector3f(Vector3f* x, Vector3f* y)
{
    Vector3f* out = (Vector3f*)malloc(sizeof(out));
    *out[0] = *x[0] - *y[0];
    *out[1] = *x[1] - *y[1];
    *out[2] = *x[2] - *y[2];
    return out;
}

Vector4f* MathHelper_SubtractVector4f(Vector4f* x, Vector4f* y)
{
    Vector4f* out = (Vector4f*)malloc(sizeof(out));
    *out[0] = *x[0] - *y[0];
    *out[1] = *x[1] - *y[1];
    *out[2] = *x[2] - *y[2];
    *out[3] = *x[3] - *y[3];
    return out;
}

Vector2f* MathHelper_MultiplyVector2f(float x, Vector2f* y)
{
    Vector2f* out = (Vector2f*)malloc(sizeof(out));
    *out[0] = *out[0] * x;
    *out[1] = *out[1] * x;
    return out;
}

Vector3f* MathHelper_MultiplyVector3f(float x, Vector3f* y)
{
    Vector3f* out = (Vector3f*)malloc(sizeof(out));
    *out[0] = *out[0] * x;
    *out[1] = *out[1] * x;
    *out[2] = *out[2] * x;
    return out;
}

Vector4f* MathHelper_MultiplyVector4f(float x, Vector4f* y)
{
    Vector4f* out = (Vector4f*)malloc(sizeof(out));
    *out[0] = *out[0] * x;
    *out[1] = *out[1] * x;
    *out[2] = *out[2] * x;
    *out[3] = *out[3] * x;
    return out;
}

Matrix4f* MathHelper_Matrix4fIdentity()
{
    Logger_WriteConsole("Matttricc", "MathHelper", LOGLEVEL_INFO);
    Matrix4f* out = MathHelper_CreateMatrix4f
    (
        MathHelper_CreateVector4f(1, 0, 0, 0), 
        MathHelper_CreateVector4f(0, 1, 0, 0),
        MathHelper_CreateVector4f(0, 0, 1, 0), 
        MathHelper_CreateVector4f(0, 0, 0, 1)
    );
    return out;
    Logger_WriteConsole("Matttricc dun", "MathHelper", LOGLEVEL_INFO);
}

Vector3f* MathHelper_Cross(Vector3f* x, Vector3f* y)
{
    Vector3f* out = (Vector3f*)malloc(sizeof(out));
    glm_cross(*x, *y, *out);
    return out;
}

Vector3f* MathHelper_Normalize(Vector3f* x)
{
    Vector3f* out = (Vector3f*)malloc(sizeof(out));
    glm_normalize_to(*x, *out);
    return out;
}

mat* CPMToDPM(Matrix4f* f)
{
    return (mat4*)*f;
}

#endif