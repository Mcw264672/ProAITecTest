#ifndef EXP_ARC_H
#define EXP_ARC_H
#include "Exp_AtomicEntity.h"
#include "CADLab_global.h"

class CADLab_EXPORT Exp_Arc : public Exp_AtomicEntity
{
public:
    Exp_Arc(void* en);

    /*************************************************
    Function    : 生成圆弧（中心点+圆弧起点+圆弧端点）
    Description : 调用此静态方法生成一个圆弧的图元对象
    Input       : 圆心坐标，起点坐标，终点坐标
    Output      :
    Return      : 返回生成的图元对象指针
    Note        :
    *************************************************/
    static Exp_Arc* CreateFromCenter2P(const Exp_Vector& center,
                                       const Exp_Vector& pStart,
                                       const Exp_Vector& pEnd);

    /*************************************************
    Function    : 生成圆弧（中心点+半径+起点弧度+终点弧度+顺逆时针）
    Description : 调用此静态方法生成一个圆弧的图元对象
    Input       : 中心点，半径，起点弧度，终点弧度，顺逆时针
    Output      :
    Return      : 返回生成的图元对象指针
    Note        :
    *************************************************/
    static Exp_Arc* CreateFromCRAA(const Exp_Vector& center,
                                   const double radius,
                                   const double sAng,
                                   const double eAng,
                                   const bool isACW);

    /*************************************************
    Function    : 生成圆弧（起点坐标+终点坐标+凸度）
    Description : 调用此静态方法生成一个圆弧的图元对象
    Input       : 起点坐标，终点坐标，凸度
    Output      :
    Return      : 返回生成的图元对象指针
    Note        :
    *************************************************/
    static Exp_Arc* CreateFromBulge(const Exp_Vector& pStart,
                                    const Exp_Vector& pEnd,
                                    const double& bulge);

    /*************************************************
    Function    : 生成圆弧（三点式）
    Description : 调用此静态方法生成一个圆弧的图元对象
    Input       : 圆弧上的三点坐标
    Output      :
    Return      : 返回生成的图元对象指针
    Note        :
    *************************************************/
    static Exp_Arc* CreateFrom3P(const Exp_Vector& p1,
                                 const Exp_Vector& p2,
                                 const Exp_Vector& p3);

    /*************************************************
    Function    : 设置中心
    Description : 调用生成的图元对象中的此方法，重新设置该圆弧的中心点坐标
    Input       : 圆心坐标
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetCenter(const Exp_Vector &c);

    /*************************************************
    Function    : 设置半径
    Description : 调用生成的图元对象中的此方法，重新设置该圆弧的半径
    Input       : 半径值
    Output      :
    Return      :
    Note        : 半径小于等于0则设置无效
    *************************************************/
    void SetRadius(const double r);

    /*************************************************
    Function    : 获取中点
    Description : 调用生成的图元对象中的此方法，获取该圆弧上的中点坐标
    Input       :
    Output      :
    Return      : 中点坐标
    Note        :
    *************************************************/
    Exp_Vector GetMiddlePoint() const;

    /*************************************************
    Function    : 获取凸度
    Description : 调用生成的图元对象中的此方法，获取该圆弧上的中点坐标
    Input       :
    Output      :
    Return      : 圆弧的凸度值
    Note        :
    *************************************************/
    double GetBulge() const;

    /*************************************************
    Function    : 获取起点弧度
    Description : 调用生成的图元对象中的此方法，获取该圆弧上起点坐标相对于X轴的弧度值
    Input       :
    Output      :
    Return      : 起点坐标弧度值
    Note        :
    *************************************************/
    double GetAngle1() const;

    /*************************************************
    Function    : 设置起点弧度
    Description : 调用生成的图元对象中的此方法，重新设置该圆弧上起点坐标相对于X轴的弧度值
    Input       : 起点坐标弧度值
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetAngle1(double a1);

    /*************************************************
    Function    : 获取终点弧度
    Description : 调用生成的图元对象中的此方法，获取该圆弧上起点坐标相对于X轴的弧度值
    Input       :
    Output      :
    Return      : 终点坐标弧度值
    Note        :
    *************************************************/
    double GetAngle2() const;

    /*************************************************
    Function    : 设置终点弧度
    Description : 调用生成的图元对象中的此方法，重新设置该圆弧上终点坐标相对于X轴的弧度值
    Input       : 终点坐标弧度值
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetAngle2(double a2);

    /*************************************************
    Function    : 获取圆弧的内角弧度
    Description :
    Input       :
    Output      :
    Return      : 内角弧度
    Note        :
    *************************************************/
    double GetArcAngle() const;

    /*************************************************
    Function    : 移动起点坐标
    Description :
    Input       : 坐标
    Output      :
    Return      :
    Note        :
    *************************************************/
    void MoveStartPoint(const Exp_Vector pos);

    /*************************************************
    Function    : 移动终点坐标
    Description :
    Input       : 坐标
    Output      :
    Return      :
    Note        :
    *************************************************/
    void MoveEndPoint(const Exp_Vector pos);

    /*************************************************
    Function    : 获取顺逆时针标识
    Description : 调用生成的图元对象中的此方法，获取当前圆弧的顺逆时针标识
    Input       :
    Output      :
    Return      : 顺逆时针标识
    Note        : 默认为false（逆时针），该标识仅做用户记录用，与实际绘制与显示效果无关
                  （！！！已弃用，建议使用Exp_Entity中的GetOrientation接口）
    *************************************************/
    bool GetArcClockwise() const;

    /*************************************************
    Function    : 设置顺逆时针标识
    Description : 调用生成的图元对象中的此方法，设置当前圆弧的顺逆时针标识
    Input       : 顺逆时针标识
    Output      :
    Return      :
    Note        : 该标识仅做用户记录用，与实际绘制与显示效果无关
                  （！！！已弃用，建议使用Exp_Entity中的SetOrientation接口）
    *************************************************/
    void SetArcClockwise(bool clockwise);

    /*************************************************
    Function    : 顺逆时针标识取反
    Description : 调用生成的图元对象中的此方法，对当前圆弧的顺逆时针标识取反
    Input       :
    Output      :
    Return      :
    Note        : 该标识仅做用户记录用，与实际绘制与显示效果无关
                  （！！！已弃用，建议使用Exp_Entity中的ReverseOrientation接口）
    *************************************************/
    void RevertArcClockwise();

    /*************************************************
    Function    : 判断圆弧顺逆时针
    Description :
    Input       :
    Output      :
    Return      : true:逆时针, false:顺时针
    Note        : （！！！已弃用，建议使用Exp_Entity中的GetOrientation接口）
    *************************************************/
    bool IsCCW() const;
};

#endif  // EXP_ARC_H
