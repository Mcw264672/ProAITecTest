#ifndef IEXP_IMPORTOPTIMIZE_H
#define IEXP_IMPORTOPTIMIZE_H

#include "CADLab_global.h"
#include <QList>
#include "Exp_Entity.h"

/**
 * @brief
 * 由外部实现的图元合并算法
 */
class IExp_ImportOptimize
{
public:
    virtual ~IExp_ImportOptimize() = default;

    virtual QList<Exp_Entity*> JoinSegmentsByDirection() = 0;
    virtual QList<Exp_Entity*> JoinSegmentsByLength() = 0;
    virtual QList<Exp_Entity*> JoinSegmentsByDistance() = 0;
};

#endif // IEXP_IMPORTOPTIMIZE_H
