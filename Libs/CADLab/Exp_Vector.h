#ifndef EXP_VECTOR_H
#define EXP_VECTOR_H
#include "CADLab_global.h"
#ifdef CADLab_LIBRARY
#include "lib/engine/rs.h"
#else
#include "rs.h"
#endif

class CADLab_EXPORT Exp_Vector
{
public:
    Exp_Vector() = default;
    Exp_Vector(double vx, double vy, double vz = 0.0);
    Exp_Vector(double angle);
    Exp_Vector(bool valid);
    ~Exp_Vector() = default;

    double x = 0.;
    double y = 0.;
    double z = 0.;
    bool valid = false;

    bool operator == (const Exp_Vector& v) const;
    bool operator != (const Exp_Vector& v) const {
        return !operator==(v);
    }

    /*************************************************
    Function    : 获取到目标点的距离
    Description :
    Input       : p(目标点)
    Output      :
    Return      : 到目标点的距离
    Note        :
    *************************************************/
    double DistanceTo(const Exp_Vector& p) const;

    /*************************************************
    Function    : 点位旋转
    Description : 根据参数计算旋转后的点位坐标
    Input       :
    Output      :
    Return      : 旋转后的坐标
    Note        :
    *************************************************/
    Exp_Vector Rotate(double rad) const;
    Exp_Vector Rotate(const Exp_Vector& angleVector) const;
    Exp_Vector Rotate(const Exp_Vector& center, double rad) const;
    Exp_Vector Rotate(const Exp_Vector& center, const Exp_Vector& angleVector) const;

    /*************************************************
    Function    : 单位转换
    Description : 将点位坐标从源单位类型转换至目标单位类型
    Input       : val(输入点), src(源单位)， dest(目标单位)
    Output      :
    Return      : 单位转换后的点位
    Note        :
    *************************************************/
    static Exp_Vector Convert(const Exp_Vector& val, RS2::Unit src, RS2::Unit dest);

    /*************************************************
    Function    : 获取坐标
    Description : 通过指定相对于一点的距离与角度，确定另一点的坐标
    Input       : 原坐标，距离，旋转角度
    Output      :
    Return      : 新点的坐标
    Note        :
    *************************************************/
    static Exp_Vector GetPointByDistAngle(const Exp_Vector& referP,
                                          const double distance,
                                          const double rotateAngle);

    /*************************************************
    Function    : 获取坐标
    Description : 通过指定相对于一点的距离与弧度，确定另一点的坐标
    Input       : 原坐标，距离，旋转弧度
    Output      :
    Return      : 新点的坐标
    Note        :
    *************************************************/
    static Exp_Vector GetPointByDistRadian(const Exp_Vector& referP,
                                           const double distance,
                                           const double rotateAngle);

    /*************************************************
    Function    : 获取弧度
    Description : 获取一点到另一点的弧度值
    Input       : 两点坐标
    Output      :
    Return      : 弧度值
    Note        :
    *************************************************/
    static double GetAngleTo(const Exp_Vector& p1, const Exp_Vector& p2);

    /*************************************************
    Function    : 获取对称点
    Description : 根据参考点获取其相对于中间点位置的对称点坐标
    Input       : 参考点，中间位置
    Output      :
    Return      : 对称点
    Note        :
    *************************************************/
    static Exp_Vector GetPointByMiddlePoint(const Exp_Vector& referP, const Exp_Vector& middleP);

    /*************************************************
    Function    : 获取中间点
    Description : 根据两点坐标计算其中间点坐标
    Input       : 参考点1，参考点2
    Output      :
    Return      : 中间点
    Note        :
    *************************************************/
    static Exp_Vector GetMiddleByTwoPoint(const Exp_Vector& p1, const Exp_Vector& p2);

    /*************************************************
    Function    : 获取圆弧的圆心
    Description : 指定相关参数计算其圆弧的圆心坐标
    Input       : 圆弧起点，圆弧终点，半径，方向
    Output      : 圆心坐标
    Return      : 计算是否成功
    Note        : 当给定的参数无法计算出一个合理的圆心坐标时，
                  函数将返回false，需进行判断
    *************************************************/
    static bool GetArcCenter(const Exp_Vector& sp, const Exp_Vector& ep, const double radius,
                             const bool isClockwise, Exp_Vector& center);

};

#endif  // EXP_VECTOR_H
