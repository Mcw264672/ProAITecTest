#ifndef EXP_ARROW_H
#define EXP_ARROW_H

#include "CADLab_global.h"
#include "Exp_EntityContainer.h"
#include "Exp_Vector.h"

struct CADLab_EXPORT Exp_ArrowData
{
    /*************************************************
    Function    : 构造箭头的数据结构
    Description :
    Input       : point(参照点), totalLength(总长度：以像素为单位), an(箭头指向的弧度),
                  arrowLength(箭头部分两侧直线的长度：以像素为单位)
    Output      :
    Return      :
    Note        : 起始点以实际坐标作为参照， 总长度与箭头部分的长度均以像素为单位，不随着缩放变化
    *************************************************/
    Exp_ArrowData(const Exp_Vector& point, double totalLength, double an,
                  double arrowLength = 20.);

    Exp_Vector refPoint;
    double totalLen;
    double angle;
    double arrowLen;
};

class CADLab_EXPORT Exp_Arrow : public Exp_EntityContainer
{
public:
    Exp_Arrow(void* en);

    /*************************************************
    Function    : 生成箭头
    Description : 调用此静态方法生成一个箭头的图元对象
    Input       : data(构造箭头的数据结构体)
    Output      :
    Return      : 返回生成的图元对象指针
    Note        :
    *************************************************/
    static Exp_Arrow* CreateArrow(const Exp_ArrowData& data);

    /*************************************************
    Function    : 设置参照点
    Description : 调用生成的图元对象中的此方法，重新设置该箭头的参照点
    Input       : point(参照点坐标)
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetRefPoint(const Exp_Vector& point);

    /*************************************************
    Function    : 设置总长度
    Description : 调用生成的图元对象中的此方法，重新设置该箭头的总长度
    Input       : len(箭头总长度)
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetTotalLength(double len);

    /*************************************************
    Function    : 设置箭头指向
    Description : 调用生成的图元对象中的此方法，重新设置该箭头指向的弧度
    Input       : an(箭头指向的弧度)
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetAngle(double an);

    /*************************************************
    Function    : 设置箭头部分的长度
    Description : 调用生成的图元对象中的此方法，重新设置该箭头两侧直线的长度
    Input       : len(箭头两侧直线的长度)
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetArrowLength(double len);

    /*************************************************
    Function    : 获取箭头的数据
    Description : 调用生成的图元对象中的此方法，获取该图元的数据
    Input       :
    Output      : 箭头数据的结构体
    Return      :
    Note        :
    *************************************************/
    Exp_ArrowData GetData();

};

#endif  // EXP_ARROW_H
