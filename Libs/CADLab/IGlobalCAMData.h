#ifndef IGLOBALCAMDATA_H
#define IGLOBALCAMDATA_H

#include <QStringList>
#include <memory>

/**
 * @brief
 * 用于绘制全局的附加工艺数据，例如：空移，非封闭图形的外框等，底板等，解析规格详见<<ICAMData解析规格.md>>
 */
class IGlobalCAMData
{
public:
    virtual ~IGlobalCAMData() = default;
    virtual std::shared_ptr<IGlobalCAMData> Clone() = 0;
    virtual QStringList CalToQStringListPre() = 0;
    virtual QStringList CalToQStringListPost() = 0;
};

#endif  // IGLOBALCAMDATA_H
