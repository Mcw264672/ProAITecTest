#ifndef ICAMDATA_H
#define ICAMDATA_H

#include <memory>
#include <QStringList>

class Exp_Entity;

/**
 * @brief 用于外部绘制附加工艺数据，绘制的规格详见<<ICAMData解析规格.md>>
 */
class ICAMData
{
public:
    virtual ~ICAMData() = default;
    virtual std::shared_ptr<ICAMData> Clone() = 0;
    virtual QStringList CalculateToQStringList() = 0;
    virtual void Update(Exp_Entity*) = 0;
};

#endif // ICAMDATA_H
