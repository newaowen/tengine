/*
 * =====================================================================================
 *
 *       Filename:  Vector3.h
 *
 *    Description:  vector3 header, 也可以表示3维点
 *
 *        Version:  1.0
 *        Created:  2012年08月03日 00时02分0秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _VECTOR3_
#define _VECTOR3_

#include <math.h>

class Vector3 {
public 
    float x, y, z;

    Vector3() {}

    Vector3(const Vector3 &v) : x(v.x), y(v.y), z(v.z) {}
    Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

    Vector3 &operator =(const Vector3 &v);
    bool operator ==(const Vector3 &v) const;
    bool operator !=(const Vector3 &v) const;

    // 取反重载
    Vector3 operator -() const;
    Vector3 operator +(const Vector3 &v) const;
    Vector3 operator -(const Vector3 &v) const;
    Vector3 operator *(float a) const;
    Vector3 operator /(float a) const;

    Vector3 &operator +=(const Vector3 &v);
    Vector3 &operator -=(const Vector3 &v);
    Vector3 &operator *=(float a);
    Vector3 &operator /=(float a);

    float operator *(const Vector3 &v) const;

    void zero();
    void normalize();
}

// 非成员函数

// 求模
inline float vectorMag(const Vector3 &v);
// 向量叉乘
inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b);
// 标量乘法
inline Vector3 operator *(float k, const Vector3 &v);
// 两点间距离
inline float distance(const Vector3 &a, const Vector3 &b);

#endif
