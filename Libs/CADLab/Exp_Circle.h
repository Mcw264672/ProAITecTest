#ifndef EXP_CIRCLE_H
#define EXP_CIRCLE_H
#include "Exp_AtomicEntity.h"
#include "CADLab_global.h"

class CADLab_EXPORT Exp_Circle : public Exp_AtomicEntity
{
public:
    Exp_Circle(void* en);

    /*************************************************
    Function    : 生成圆（中心点+半径）
    Description : 调用此静态方法生成一个圆的图元对象
    Input       : 圆心坐标，半径值
    Output      :
    Return      : 返回生成的图元对象指针
    Note        : 当输入的半径参数小于等于零时，圆生成失败并返回nullptr
    *************************************************/
    static Exp_Circle* CreateCircleFromCR(const Exp_Vector& centerPoint,
                                          double radius);

    /*************************************************
    Function    : 设置圆心
    Description : 调用生成的图元对象中的此方法，重新设置该圆的圆心坐标
    Input       : 圆心坐标
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetCenter(const Exp_Vector &c);

    /*************************************************
    Function    : 设置半径
    Description : 调用生成的图元对象中的此方法，重新设置该圆的半径
    Input       : 半径值
    Output      :
    Return      :
    Note        : 当输入的半径参数小于等于零时则设置失败
    *************************************************/
    void SetRadius(const double r);
};

#endif  // EXP_CIRCLE_H
