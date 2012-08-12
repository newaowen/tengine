/*
 * =====================================================================================
 *
 *       Filename:  MathUtil.cpp
 *
 *    Description:  math util implement
 *
 *        Version:  1.0
 *        Created:  2012年08月11日 20时45分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */
#include <math>

#include "MathUtil.h"
#include "Vector3.h"

namespace Tengine {

    // 常量0向量?
    const Vector3 kZeroVector(0.0f, 0.0f, 0.0f);

    // 通过加上2pi倍数，将角度限制在-pi ~ pi 内
    float wrapPi(float theta) {
        theta += Pi;
        theta -= floor(theta * OneOver2Pi) * TwoPi;
        theta -= Pi;
        return theta;
    }

    // 和acos类似，但当x超出范围时返回最接近的有效值
    // 返回值在 0 ~ pi 间(想象acos函数图像即清楚)
    float safeAcos(float x) {
        if (x <= -1.0f) {
            return Pi;
        }
        if (x >= 1.0f) {
            return 0.0f;
        }

        return acos(x);
    }

}
