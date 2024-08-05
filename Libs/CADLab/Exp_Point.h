#ifndef EXP_POINT_H
#define EXP_POINT_H

#include "Exp_AtomicEntity.h"
#include "CADLab_global.h"

class CADLab_EXPORT Exp_Point : public Exp_AtomicEntity
{
public:
    Exp_Point(void* en);

    /*************************************************
    Function    : 创建点图元
    Description :
    Input       : 点位置
    Output      :
    Return      : 图元指针
    Note        :
    *************************************************/
    static Exp_Point* CreatePoint(Exp_Vector vec);

    /*************************************************
    Function    : 获取当前位置
    Description :
    Input       :
    Output      :
    Return      : 当前点位
    Note        :
    *************************************************/
    Exp_Vector GetPos() const;

    /*************************************************
    Function    : 修改当前位置
    Description :
    Input       : 当前点位
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetPos(Exp_Vector vec);
};

#endif // EXP_POINT_H
