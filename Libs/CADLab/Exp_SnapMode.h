#ifndef EXP_SNAPMODE_H
#define EXP_SNAPMODE_H

#include "CADLab_global.h"

struct CADLab_EXPORT Exp_SnapMode
{
    enum{
        ExpSnapEndPoint         = 1 << 0,
        ExpSnapMiddlePoint      = 1 << 1,
        ExpSnapCircleCenter     = 1 << 2,
        ExpSnapPolygonCenter    = 1 << 3,
        ExpSnapIntersectPoint   = 1 << 4,
        ExpSnapPedalPoint       = 1 << 5,
        ExpSnapTangentPoint     = 1 << 6,
        ExpSnapExtensionLine    = 1 << 7,
        ExpSnapOrthogonal       = 1 << 8,
        ExpSnapPolarAxis        = 1 << 9,
        ExpSnapQuadrantalP      = 1 << 10,
        ExpSnapNearestP         = 1 << 11,
        ExpSnapGridP            = 1 << 12
    };

    bool expSnapEndPoint        {false};
    bool expSnapMiddlePoint     {false};
    bool expSnapCircleCenter    {false};
    bool expSnapPolygonCenter   {false};
    bool expSnapIntersectPoint  {false};
    bool expSnapPedalPoint      {false};
    bool expSnapTangentPoint    {false};
    bool expSnapExtensionLine   {false};
    bool expSnapOrthogonal      {false};
    bool expSnapPolarAxis       {false};
    bool expSnapQuadrantalP     {false};
    bool expSnapNearestP        {false};
    bool expSnapGridPoint       {false};

    /*************************************************
    Function    : 捕捉模式构造
    Description :
    Input       :
    Output      :
    Return      :
    Note        : 该构造所创建的捕捉模式为全部关闭，即0
                  亦可直接将结构体中的布尔量expSnapXXXX设置为true或false
    *************************************************/
    Exp_SnapMode();

    /*************************************************
    Function    : 捕捉模式构造
    Description :
    Input       : 具体的捕捉模式
    Output      :
    Return      :
    Note        : 具体捕捉模式是各捕捉模式由低位到高位构成的unsigned int
                  如输入39，其二进制为0010 0111
                  由低位至高位分别对应enum中的模式，1为开启，0为关闭
                  则39为EndPoint、MiddlePoint、CircleCenter、以及PedalPoint被开启
    *************************************************/
    Exp_SnapMode(unsigned int mSnapMode);

    /*************************************************
    Function    : 清空捕捉模式
    Description : 将所有的捕捉模式均设置为false
    Input       :
    Output      :
    Return      : 当前的捕捉模式
    Note        :
    *************************************************/
    Exp_SnapMode const & Clear(void);

    /*************************************************
    Function    : 捕捉模式类型转换
    Description : 将Exp_SnapMode转换为对应的unsigned int
    Input       :
    Output      :
    Return      : 转换后的uint格式的捕捉模式
    Note        :
    *************************************************/
    static unsigned int ToInt(const Exp_SnapMode& s);

    /*************************************************
    Function    : 捕捉模式类型转换
    Description : 将unsigned int转换为对应的Exp_SnapMode
    Input       :
    Output      :
    Return      : 转换后的Exp_SnapMode格式的捕捉模式
    Note        :
    *************************************************/
    static Exp_SnapMode FromInt(unsigned int);
};

#endif // EXP_SNAPMODE_H
