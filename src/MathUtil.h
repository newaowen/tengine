/*
 * =====================================================================================
 *
 *       Filename:  MathUtil.h
 *
 *    Description:  math base util functions
 *
 *        Version:  1.0
 *        Created:  2012年08月11日 20时37分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  newaowen (敖文兵), newaowen@yahoo.com.cn
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _MATHUTIL_
#define _MATHUTIL_

#include <math>

namespace Tengine {
    // define pi constans
    const float Pi = 3.14159265f;
    const float TwoPi = Pi * 2.0f;
    const float PiOver2 = Pi / 2.0f;
    const float OneOverPi = 1.0f / Pi;
    const float OneOver2Pi = 0.5f / Pi;

    // 将角度限制在-pi ~ pi的区间内
    extern float wrapPi(float theta);

    // 安全 反三角函数
    extern float safeAcos(float x);

    // 在某些平台上，需要sin、cos时，同时计算较快
    inline void sinCos(float theta, float *sin, float *cos) {
        *sin = sin(theta);
        *cos = cos(theta);
    }
}

#endif


