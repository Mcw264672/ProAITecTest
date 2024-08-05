#ifndef EXP_INSERT_H
#define EXP_INSERT_H

#include "Exp_EntityContainer.h"
#include "CADLab_global.h"

class CADLab_EXPORT Exp_Insert : public Exp_EntityContainer
{
public:
    Exp_Insert(void* en);

    /*************************************************
    Function    : 插入块
    Description : 将块列表中已有的块插入
    Input       : name:块名
                  insertPosi:插入点位置
                  scaleFactor:缩放比例
                  rotateRadian:旋转弧度
    Output      :
    Return      : 块对象指针
    Note        : 通过MANAGEMENT将块插入到画布中之后
                  须通过调用UpdateInsert()刷新方可正常显示！！
    *************************************************/
    static Exp_Insert* CreateInsert(const QString name,
                                    const Exp_Vector& insertPosi,
                                    const double scaleFactor,
                                    const double rotateRadian);

    /*************************************************
    Function    : 获取块名
    Description :
    Input       :
    Output      :
    Return      : 块名
    Note        :
    *************************************************/
    QString GetBlockName();

    /*************************************************
    Function    : 获取插入点位置
    Description :
    Input       :
    Output      :
    Return      : 插入点位置
    Note        :
    *************************************************/
    Exp_Vector GetInsertionPoint();

    /*************************************************
    Function    : 获取缩放比例
    Description :
    Input       :
    Output      :
    Return      : 缩放比例
    Note        :
    *************************************************/
    double GetScale();

    /*************************************************
    Function    : 获取旋转弧度
    Description :
    Input       :
    Output      :
    Return      : 弧度
    Note        :
    *************************************************/
    double GetAngle();

    /*************************************************
    Function    : 获取可见状态
    Description :
    Input       :
    Output      :
    Return      : 当前是否可见
    Note        :
    *************************************************/
    bool IsVisible();

    /*************************************************
    Function    : 刷新块显示
    Description :
    Input       :
    Output      :
    Return      :
    Note        : 将块插入画布后须调用一次后方可正常显示！！
    *************************************************/
    void UpdateInsert();
};

#endif // EXP_INSERT_H
