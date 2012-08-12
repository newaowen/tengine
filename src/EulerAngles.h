/*
 * =====================================================================================
 *
 *       Filename:  EulerAngles.h
 *
 *    Description:  欧拉角类, 用来表示方位，head-pitch-bank 
 *
 *        Version:  1.0
 *        Created:  2012年08月11日 21时00分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _EULERANGLES_
#define _EULERANGLES_

namespace Tengine {
    // 预声明
    class Quaternion;
    class Matrix4x3;
    class RotationMatrix;

    class EulerAngles {
    public:
        float heading;
        float pitch;
        float bank;

        EulerAngles() {}
        EulerAngles(float h, float p, float b) : heading(h), pitch(p), bank(b) {}
        
        // 置0{
        inline void    identity() { heading = pitch = bank = 0.0f; } 
        // 变换为限制的欧拉角
        void	canonize();

        // 从四元数转化为欧拉角(物体坐标系 - 惯性坐标系)
        void	fromObjectToInertialQuternion(const Quaternion &q); 
        void    fromInertialToObjectQuternion(const Quaternion &q); 

        // 从变换矩阵转换到欧拉角(物体坐标系 - 世界坐标系) 
        void	fromObjectToWorldMatrix(const Matrix4x3 &m);
        void    fromWorldToObjectMatrix(const Matrix4x3 &m);

        // 从旋转矩阵变换到欧拉角
        void    fromRotationMatrix(const RotationMatrix &m);
    };

    // 全局0欧拉角
    extern const EulerAngles identityEulerAngle;
}

#endif
