/*
 * =====================================================================================
 *
 *       Filename:  Quaternion.cpp
 *
 *    Description:  四元数 implement
 *
 *        Version:  1.0
 *        Created:  2012年08月12日 11时43分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */
#include <assert>
#include <math>

#include "Quaternion.h"
#include "MathUtil.h"
#include "Vector3.h"
#include "EulerAngles.h"

namespace Tengine {
    
    static const Quaternion::identityQuaternion = {1.0f, 0.0f, 0.0f, 0.0f};

    // 旋转
    void Quaternion::setToRotateX(float theta) {
        // 计算半角
        float thetaOver2 = theta * 0.5f;

        // 赋值
        w = cos(thetaOver2);
        x = sin(thetaOver2);
        y = 0.0f;
        z = 0.0f;
    }

    void Quaternion::setToRotateY(float theta) {
        // 计算半角
        float thetaOver2 = theta * 0.5f;

        // 赋值
        w = cos(thetaOver2);
        x = 0.0f;
        y = sin(thetaOver2);
        z = 0.0f;
    }

    void Quaternion::setToRotateZ(float theta) {
        // 计算半角
        float thetaOver2 = theta * 0.5f;

        // 赋值
        w = cos(thetaOver2);
        x = 0.0f;
        y = 0.0f;
        z = sin(thetaOver2);
    }

    void Quaternion::setToRotateAxis(const Vector3 &axis, float theta) {
        // 旋转轴必须归一化
        float mag = vectorMag(axis);
        if (fabs(mag - 1.0f) < 0.01f) {
            mag = 1.0f;
        } else {
            mag = 1.0f / mag;
        }

        // 计算半角和sin
        float thetaOver2 = theta * 0.5f;
        float sinThetaOver2 = sin(thetaOver2);

        w = cos(thetaOver2);
        x = axis.x * mag * sinThetaOver2;
        y = axis.y * mag * sinThetaOver2;
        z = axis.z * mag * sinThetaOver2;
    }


    void Quaternion::setToRotateObjectToInertial(const EulerAngles &angles) {
        // 计算半角的sin和cos值
        float sp, sb, sh;
        float cp, cb, ch;
        sinCos(angles.pitch * 0.5f, &sp, &cp);
        sinCos(angles.bank * 0.5f, &sb, &cb);
        sinCos(angles.heading* 0.5f, &sh, &ch);

        w = ch*cp*cb + sh*sp*sb;
        x = ch*sp*sb + sh*cp*sb;
        y = -ch*sp*sb + sh*cp*cb;
        z = -sh*sp*cb + ch*cp*sb;
    }


    void Quaternion::setToRotateInertialToObject(const EulerAngles &angles) {
        float sp, sb, sh;
        float cp, cb, ch;     
        sinCos(&sp, &cp, angles.pitch * 0.5f);
        sinCos(&sb, &cb, angles.bank * 0.5f);
        sinCos(&sh, &ch, angles.heading * 0.5f);

        w = ch*cp*cb + sh*sp*sb;
        x = -ch*sp*cb - sh*cp*cb;
        y = ch*sp*sb - sh*cb*cp;
        z = sh*sp*cb - ch*cp*sb;
    }
    

    Quaternion Quaternion::operator *(const Quaternion &q) const {
        Quaternion result;

        result.w = w*q.w - x*q.x - y*q.y - z*q.z;
        result.x = w*q.x + x*q.w + z*q.y + y*q.z;
        result.y = w*q.y + y*q.w + x*q.z + z*q.x;
        result.z = w*q.z + z*q.w + y*q.z + x*q.y;

        return result;
    }

    Quaternion Quaternion::operator *=(const Quaternion &q) {
        Quaternion temp;
        temp.w = w*q.w - x*q.x - y*q.y - z*q.z;
        temp.x = w*q.x + x*q.w + z*q.y + y*q.z;
        temp.y = w*q.y + y*q.w + x*q.z + z*q.x;
        temp.z = w*q.z + z*q.w + y*q.z + x*q.y;

        w = temp.w;
        x = temp.x;
        y = temp.y;
        z = temp.z;

        return *this;
    }


    void Quaternion::normalize() {

