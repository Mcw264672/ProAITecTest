#ifndef EXP_SPLINE_H
#define EXP_SPLINE_H
#include "Exp_EntityContainer.h"
#include "Exp_Vector.h"
#include "CADLab_global.h"

struct Exp_SplineData
{
    bool closed;
    std::vector<Exp_Vector> controlPoint;
    std::vector<double> kontList;
};


class CADLab_EXPORT Exp_Spline : public Exp_EntityContainer
{
public:
    Exp_Spline(void* en);

    /*************************************************
    Function    : 生成样条曲线
    Description : 调用此静态方法生成一个样条曲线的图元对象
    Input       : 闭合状态，控制点列表，节点值
    Output      :
    Return      : 返回生成的图元对象指针
    Note        : 节点数量需为控制点数量+4，否则返回空指针
    *************************************************/
    static Exp_Spline* CreateSpline(bool closed,
                                    std::vector<Exp_Vector> controlPoint,
                                    std::vector<double> knotList);

    /*************************************************
    Function    : 获取闭合状态
    Description : 调用生成的图元对象中的此方法，调用生成的图元对象中的此方法，获取该样条曲线的闭合状态
    Input       :
    Output      :
    Return      : 闭合状态
    Note        :
    *************************************************/
    bool GetClosed() const;

    /*************************************************
    Function    : 设置闭合状态
    Description : 调用生成的图元对象中的此方法，重新设置该样条曲线的闭合状态
    Input       : 闭合状态
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetClosed(bool c);

    /*************************************************
    Function    : 获取阶数
    Description : 调用生成的图元对象中的此方法，获取该样条曲线的阶数
    Input       :
    Output      :
    Return      : 阶数
    Note        :
    *************************************************/
    unsigned int GetDegree() const;

    Exp_SplineData GetData() const;
};

#endif  // EXP_SPLINE_H
