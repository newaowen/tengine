/*
 * =====================================================================================
 *
 *       Filename:  Quaternion.h
 *
 *    Description:  四元数
 *
 *        Version:  1.0
 *        Created:  2012年08月12日 11时21分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */

#ifdef  _QUATERNION_
#define _QUATERNION_

namespace Tengine {

    class Vector3;
    class EulerAngles;

    class Quaternion {
    public:
        float w, x, y, z; // 四元数 四个参数
        static const Quaternion identityQuaternion;

        // 单位化
        inline void identity() { w = 1.0f; x = y = z = 0.0f;}
        // 归一化
        void normalize();

        // 构造绕轴旋转的四元数
        void setToRotateX(float theta);
        void setToRotateY(float theta);
        void setToRotateZ(float theta);
        void setToRotateAxis(const Vector3 &axis, float theta);

        // 构造执行物体-惯性旋转的四元数(欧拉角转换到四元数)
        void setToRotateObjectToInertial(const EulerAngles &angles);
        void setToRotateInertialToObject(const EulerAngles &angles);

        // 叉乘 (与向量类意义不同，*指叉乘，因为该运算用的更多)
        Quaternion operator *(const Quaternion &q) const;
        Quaternion &operator *= (const Quaternion *q);
        
        // 根据四元数对应轴-角旋转的意义，提取出轴和角度 
        float   getRotationAngle() const;
        Vector3 getRotationAxis() const;
    }

    // 点乘
    extern float dotProduct(const Quaternion &a, const Quaternion &b);
    // 球面线性插值
    extern Quaternion slerp(const Quaternion &a, const Quaternion &b);
    // 共轭
    extern Quaternion conjugate(const Quaternion &q);
    // 幂运算
    extern Quaternion pow(const Quaternion &q, float e);

}

#endif

