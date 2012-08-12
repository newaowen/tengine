/*
 * =====================================================================================
 *
 *       Filename:  EulerAngles.cpp
 *
 *    Description:  欧拉角类实现
 *
 *        Version:  1.0
 *        Created:  2012年08月11日 21时17分57秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */
#include <math>
#include "EulerAngles.h"
#include "Quaternion.h"
#include "MathUtil.h"
#include "Matrix4x3.h"
#include "RotationMatrix.h"

namespace Tengine {
    // 全局0欧拉角
    const EulerAngles identityEulerAngle(0.0f, 0.0f, 0.0f);

    void EulerAngles::canonize() {
        // 角度限制
        pitch = wrapPi(pitch);

        if (pitch < -PiOver2) {
            pitch = -Pi - pitch;
            heading += Pi;
            bank += Pi;
        } else if (pitch > PiOver2) {
            pitch = Pi - pitch;
            heading += Pi;
            bank += Pi;
        }

        // 检查万向锁（有误差？)
        if (fabs(pitch) > PiOver2 - 1e-4) {
            // 将所有绕垂直轴的旋转转换到heading
            heading += bank;
            bank = 0.0;
        } else { // 非万向锁时， 将bank转换到限制集中
            bank = wrapPi(bank);
        }
                
        heading = wrapPi(heading);
    }


    void EulerAngles::fromObjectToInertialQuternion(const Quaternion &q) {
        float sp = -2.0f * (q.y*q.z - q.w*q.x);

        // 检查万向锁(pitch角度为90)
        if (fabs(sp) > 0.9999f) {
            // 向正上方或正下方看
            pitch = PiOver2 * sp;
            // bank置0， 计算heading
            heading = atan2(-q.x*q.z + q.w*q.y, 0.5f - q.y*q.y - q.z*q.z);
            bank = 0.0f;	
        } else {
            pitch = asin(sp);
            heading = atan2(q.x*q.z + q.w*q.y, 0.5f - q.x*q.x - q.y*q.y);
            bank = atan2(q.x*q.y + q.w*q.z, 0.5f - q.x*q.x - q.z*q.z);
        }
    }


    void EulerAngles::fromInertialToObjectQuternion(const Quaternion &q) {
        float sp = -2.0f * (q.y*q.z - q.w*q.x);

        // 检查万向锁(pitch角度为90)
        if (fabs(sp) > 0.9999f) {
            // 向正上方或正下方看
            pitch = PiOver2 * sp;
            // bank置0， 计算heading
            heading = atan2(-q.x*q.z - q.w*q.y, 0.5f - q.y*q.y - q.z*q.z);
            bank = 0.0f;	
        } else {
            pitch = asin(sp);
            heading = atan2(q.x*q.z - q.w*q.y, 0.5f - q.x*q.x - q.y*q.y);
            bank = atan2(q.x*q.y - q.w*q.z, 0.5f - q.x*q.x - q.z*q.z);
        }
    }

    // 物体 - 世界变换矩阵 到欧拉角
    void EulerAngles::fromObjectToWorldMatrix(const Matrix4x3 &m) {
        // 通过m32计算sin(pitch)
        float   sp = -m.m32;
        // 检查万向锁
        if (fabs(sp) > 0.99999f) {
            pitch = PiOver2 * sp;
            heading = atan2(-m.m23, m.m11);
            bank = 0.0f;
        } else {
            heading = atan2(m.m31, m.m33);
            pitch = asin(sp);
            bank = atan2(m.m12, m.m22);
        }
    }


    void EulerAngles::fromWorldToObjectMatrix(const Matrix4x3 &m) {
        float sp = -m.m23;

        if (fabs(sp) > 0.99999f) {
            pitch = PiOver2 * sp;
            heading = atan2(-m.m31, m.m11);
            bank = 0.0f;
        } else {
            heading = atan2(m.m13, m.m33);
            pitch = asin(sp);
            bank = atan2(m.m21, m.m22);
        }
    }

    // 与从世界(惯性)坐标-物体坐标 变换矩阵类似
    void EulerAngles::fromRotationMatrix(const RotationMatrix &m) {
        float sp = -m.m23;
        if (fabs(sp) > 0.99999f) {
            pitch = PiOver2 * sp;
            heading = atan2(-m.m31, m.m11);
            bank = 0.0f;
        } else {
            heading = atan2(m.m13, m.m33);
            pitch = asin(sp);
            bank = atan2(m.m21, m.m22);
        }
    }

}
