#ifndef EXP_BLOCK_H
#define EXP_BLOCK_H

#include "Exp_EntityContainer.h"
#include "CADLab_global.h"

/**
 * Exp_Block与Exp_Insert的关系：
 * Block：构造块的原始图元数据(Group definition)，不能被插入到画布中
 * Insert：依据Block的数据而构造出的独立的图元对象(Group instance)，允许被插入到画布中
 *
 * Exp_Block的作用：
 * 修改已有的块的原始图元数据
 * 当您的需求复杂到需要修改已构造好的块的原始数据时，可通过修改Exp_Block后再重新插入全新的Exp_Insert实现
 * 以此避免重复构造Block，导致BlockList出现大量的无效数据
 *
 * 注意事项：
 * Exp_Block仅可用于修改用于构造Insert的原始数据，尽管其继承Exp_Entity，但并不能作为普通图元使用
 * 因此需谨慎使用Exp_Block
 */
class CADLab_EXPORT Exp_Block : public Exp_EntityContainer
{
public:
    Exp_Block(void* en);

    /*************************************************
    Function    : 获取块定义
    Description : 调用此静态方法生成一个块定义对象
    Input       : 块名
    Output      :
    Return      : 块定义对象
    Note        : 根据给定的块名，从块列表中查找已有的块定义对象并返回
                  若现有的块列表中没有此块名的块定义时返回nullptr
    *************************************************/
    static Exp_Block* CreateBlock(const QString& blockName);

    /*************************************************
    Function    : 获取块名
    Description :
    Input       :
    Output      :
    Return      : 块名
    Note        :
    *************************************************/
    QString GetBlockName() const;

    /*************************************************
    Function    : 获取插入点位置
    Description :
    Input       :
    Output      :
    Return      : 插入点位置
    Note        :
    *************************************************/
    Exp_Vector GetBasePoint() const;

    /// ?
    bool ResetEntities(const QVector<Exp_Entity*>&);
    bool ResetBasePoint(const Exp_Vector&);
};

#endif // EXP_BLOCK_H
