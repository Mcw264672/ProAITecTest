#ifndef EXP_COMPONENT_H
#define EXP_COMPONENT_H

#include "CADLab_global.h"
#include "Exp_Entity.h"

class CADLab_EXPORT Exp_Component
{
public:
    Exp_Component() = default;
    Exp_Component(Exp_Entity* en, int quantity, const QString& name)
        : m_Entity(en), m_Quantity(quantity), m_Name(name){}


    inline Exp_Entity* GetEntity() const { return m_Entity; }
    void SetEntity(Exp_Entity* newEntity) { m_Entity = newEntity; }

    inline int GetQuantity() const { return m_Quantity; }
    void SetQuantity(int newQuantity) { m_Quantity = newQuantity; }

    inline const QString& GetName() const { return m_Name; }
    void SetName(const QString& newName) { m_Name = newName; }

private:
    //零件图元
    Exp_Entity* m_Entity;
    //数量
    int m_Quantity;
    //名称
    QString m_Name;
};

#endif  // EXP_COMPONENT_H
