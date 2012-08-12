/*
 * =====================================================================================
 *
 *       Filename:  Vector3.cpp
 *
 *    Description:  vector3 implement
 *
 *        Version:  1.0
 *        Created:  2012年08月03日 00时05分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Vector3.h"

namespace Tengine {

    Vector3 &Vector3::operator =(const Vector3 &v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    bool Vector3::operator ==(const Vector3 &v) const {
        return x == v.x && y == v.y && z == v.z;
    }

    bool Vector3::operator !=(const Vector3 &v) const {
        return x != v.x || y != v.y || z != v.z;
    }

    Vector3 Vector3::operator -() const {
        return Vector3(-x, -y, -z);
    }    

    Vector3 Vector3::operator +(const Vector3 &v) const {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    Vector3 Vector3::operator -(const Vector3 &v) const {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    Vector3 Vector3::operator *(float a) const {
        return Vector3(a*x, a*y, a*z);
    }

    Vector3 Vector3::operator /(float a) const {
        float b = 1.0f / a;
        return Vector3(b*x, b*y, b*z);
    }

    Vector3& Vector3::operator +=(const Vector3 &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector3& Vector3::operator -=(const Vector3 &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    Vector3& Vector3::operator *=(float a) {
        x *= a;
        y *= a;
        z *= a;
        return *this;
    }

    Vector3& Vector3::operator /=(float a) {
        float b = 1.0f / a;
        x *= b;
        y *= b;
        z *= b;
        return *this;
    }

    float Vector3::operator *(const Vector3 &v) const {
        return x*v.x + y*v.y + z*v.z;
    }

    void Vector3::zero() {
        x = y = z = 0.0f;
    }

    void Vector3::normalize() {
        float magSq = x*x + y*y + z*z;
        if (magSq > 0.0f) {
            float b = 1.0f / magSq;
            x *= b;
            y *= b;
            z *= b;
        }
    }


    /*-----------------------------------------------------------------------------
     *  非成员函数
     *-----------------------------------------------------------------------------*/

    /** 
     * 求模, 为了代码更美观才设计成非成员函数
     */
    float vectorMag(const Vector3 &v) {
        return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    }

    Vector3 crossProduct(const Vector3 &a, const Vector3 &b) {
        return Vector3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
    }

    Vector3 operator *(float k, const Vector3 &v) {
        return Vector3(k*v.x, k*v.y, k*v.z);
    }

    float distance(const Vector3 &a, const Vector3 &b) {
        float dx = b.x - a.x;
        float dy = b.y - a.y;
        float dz = b.z - a.z;
        return sqrt(dx*dx + dy*dy + dz*dz);
    }

}
