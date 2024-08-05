#ifndef IEXP_SORTABLE_H
#define IEXP_SORTABLE_H

#include "CADLab_global.h"
#include <QList>
#include "Exp_Entity.h"

class IExp_Sortable
{
public:
    virtual ~IExp_Sortable() = default;

    /*************************************************
    Function    : 排序算法
    Description : 子类重写此方法设置排序算法，使用Exp_Entity::SetSerialNum(unsinged int)设置图形的序号
    Input       : 可显示序号的所有实体,按图形生成先后顺序排列
    Output      :
    Return      :
    Note        : 务必从序号1开始依次递增设置所有图形的序号
    *************************************************/
    virtual void Sort(QList<Exp_Entity*>&) = 0;
};

#endif // IEXP_SORTABLE_H
