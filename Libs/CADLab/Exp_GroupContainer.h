#ifndef EXP_GROUPCONTAINER_H
#define EXP_GROUPCONTAINER_H

#include <functional>
#include "CADLab_global.h"
#include "Exp_EntityContainer.h"
#include "Exp_Vector.h"
class Exp_Polyline;

class CADLab_EXPORT Exp_GroupContainer : public Exp_EntityContainer
{
public:
    Exp_GroupContainer(void* en);

    /*************************************************
    Function    : 生成GroupContainer
    Description : 调用此静态方法生成一个GroupContainer的图元对象
    Input       : GroupContainer的数据
    Output      :
    Return      : 返回生成的图元对象指针
    Note        :
    *************************************************/
    static Exp_GroupContainer* CreateGroupContainer(const QVector<Exp_Entity*>& entities,
                                                    const bool& allowExplode = true);
    /*************************************************
    Function    : 向GroupContainer中添加图元
    Description : 调用生成的图元对象中的此方法,向GroupContainer中添加图元
    Input       : 要添加的图元
    Output      :
    Return      :
    Note        :
    *************************************************/
    void AddSubEntity(const Exp_Entity* en);

    /*************************************************
    Function    : 移除GroupContainer中的指定图元
    Description : 调用生成的图元对象中的此方法,移除GroupContainer中的指定图元
    Input       : 要移除的图元在子图元容器中的位置
    Output      :
    Return      :
    Note        :
    *************************************************/
    bool RemoveSubEntity(const int index);

    /*************************************************
    Function    : 获取Group是否允许打散
    Description :
    Input       :
    Output      :
    Return      : 是否允许打散
    Note        :
    *************************************************/
    bool IsAllowExplode() const;

    /*************************************************
    Function    : 设置Group是否允许打散
    Description :
    Input       : 是否允许打散
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetAllowExplode(const bool&);

    // std::function<bool(const Exp_Entity*)> m_FuncAddSubAnalyze{nullptr};
    // std::function<bool(const Exp_Entity*)> m_FuncRemoveSubAnalyze{nullptr};
};

#endif  // EXP_GROUPCONTAINER_H
