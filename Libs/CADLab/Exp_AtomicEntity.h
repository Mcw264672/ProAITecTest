#ifndef EXP_ATOMICENTITY_H
#define EXP_ATOMICENTITY_H
#include "Exp_Entity.h"
#include "CADLab_global.h"

class CADLab_EXPORT Exp_AtomicEntity : public Exp_Entity
{
public:
    Exp_AtomicEntity(void* en = nullptr);

    /*************************************************
    Function    : 判定该原子图元是否为组合图元的子图元
    Description :
    Input       :
    Output      :
    Return      : 是否是子图元
    Note        :
    *************************************************/
    bool IsAtomInContainer() const;

    /*************************************************
    Function    : 获取父对象
    Description : 当该原子图元为组合图元的子图元时，通过此接口获取组合图元的指针
    Input       :
    Output      :
    Return      : 父对象的图元指针
    Note        : 仅当父对象为多段线、样条曲线、单行文字、多行文字、块时可返回图元指针
                  其余情况均返回nullptr（包括标注的子图元）
    *************************************************/
    Exp_Entity* GetParentEntity() const;
};

#endif  // EXP_ATOMICENTITY_H
