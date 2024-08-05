#ifndef EXP_ENTITYCONTAINER_H
#define EXP_ENTITYCONTAINER_H
#include <QList>
#include "Exp_Entity.h"
#include "CADLab_global.h"

class CADLab_EXPORT Exp_EntityContainer : public Exp_Entity
{
public:
    Exp_EntityContainer(void* en = nullptr);

    /*************************************************
    Function    : 获取组合图元的所有子图元
    Description :
    Input       :
    Output      :
    Return      : 子图元集合
    Note        :
    *************************************************/
    QList<Exp_Entity*> GetEntities() const;

    /*************************************************
    Function    : 获取组合图元中距离指定点最近的子图元
    Description :
    Input       : posi:指定点
    Output      : dist:最近图元到指定点的距离
    Return      : 最近子图元对象
    Note        :
    *************************************************/
    Exp_Entity* GetNearestEntity(const Exp_Vector& posi, double* dist) const;
};

#endif  // EXP_ENTITYCONTAINER_H
