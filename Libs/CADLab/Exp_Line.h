#ifndef EXP_LINE_H
#define EXP_LINE_H
#include "CADLab_global.h"
#include "Exp_AtomicEntity.h"
#include "Exp_Vector.h"

class CADLab_EXPORT Exp_Line : public Exp_AtomicEntity
{
public:
    Exp_Line(void* en);

    /*************************************************
    Function    : 生成直线（起始点+终止点）
    Description : 调用此静态方法生成一个直线的图元对象
    Input       : 起点坐标，终点坐标
    Output      :
    Return      : 返回生成的图元对象指针
    Note        :
    *************************************************/
    static Exp_Line* CreateFrom2P(const Exp_Vector& pStart,
                                  const Exp_Vector& pEnd);

    /*************************************************
    Function    : 设置起点
    Description : 调用生成的图元对象中的此方法，重新设置该直线的起始点坐标
    Input       : 起点坐标
    Output      :
    Return      :
    Note        : 若设置的起点与原终点相重合，则设置无效
    *************************************************/
    void SetStartpoint(const Exp_Vector& pos);

    /*************************************************
    Function    : 设置终点
    Description : 调用生成的图元对象中的此方法，重新设置该直线的终止点坐标
    Input       : 终点坐标
    Output      :
    Return      :
    Note        : 若设置的终点与原起点相重合，则设置无效
    *************************************************/
    void SetEndpoint(const Exp_Vector& pos);

    /*************************************************
    Function    : 设置中点
    Description : 调用生成的图元对象中的此方法，获取该直线的中心点坐标
    Input       :
    Output      :
    Return      : 中点坐标
    Note        :
    *************************************************/
    Exp_Vector GetMiddlePoint() const;
};

#endif  // EXP_LINE_H
