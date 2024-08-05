#ifndef EXP_MATH_H
#define EXP_MATH_H

#include "CADLab_global.h"

class CADLab_EXPORT Exp_Math
{
public:
    Exp_Math() = default;
    ~Exp_Math() = default;

    static int Round(const double& v);

    /*************************************************
    Function    : 弧度转换
    Description : 将弧度值转换为[0, +PI*2.0)的范围
    Input       : 弧度
    Output      :
    Return      : 转换后的弧度结果
    Note        :
    *************************************************/
    static double CorrectRadian(const double& r);

    /*************************************************
    Function    : 弧度转换
    Description : 将弧度值转换为[-PI, +PI)的范围
    Input       : 弧度
    Output      :
    Return      : 转换后的弧度结果
    Note        :
    *************************************************/
    static double CorrectRadian2(const double& r);

    /*************************************************
    Function    : 弧度转换
    Description : 将弧度值转换为[0, +PI)的范围
    Input       : 弧度
    Output      :
    Return      : 转换后的弧度结果
    Note        :
    *************************************************/
    static double CorrectRadianU(const double& r);

    static double GetRadianDifference(const double& r1, const double& r2, bool reversed = false);
    static double GetRadianDifferenceU(const double& r1, const double& r2);
    static double GetRadianDifference180(const double& r1, const double& r2);

    static bool IsRadianBetween(const double& r, const double& r1, const double& r2, bool reversed = false);

    static bool IsCWtoRadianNearest(const double& r1, const double& r2);
};

#endif // EXP_MATH_H
