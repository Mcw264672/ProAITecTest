#ifndef IEXP_SERIALIZE_H
#define IEXP_SERIALIZE_H

#include <memory>

class QDataStream;
class QString;
class ICAMData;
class IGlobalCAMData;

class IExp_Serialize
{
public:
    virtual ~IExp_Serialize() = default;

    /*************************************************
    Function    : 设置二进制文件导出的DocName(内部默认使用"CADLab")
    Description : 设置二进制文件导出的DocName,若文件解析时解析到的DocName与此方法获取的DocName不同，将停止解析
    Input       :
    Output      :
    Return      : docName
    Note        : 若使用此接口，请勿将docName设置为“CADLab"
    *************************************************/
    virtual QString DocName() = 0;

    /*************************************************
    Function    : 文件导入
    Description : 用于外部保存版本号等全局数据
    Input       : stream
    Output      : stream
    Return      : 0:文件正常导入， else:停止文件导入
    Note        :
    *************************************************/
    virtual int FileImport(QDataStream& stream) = 0;

    /*************************************************
    Function    : 文件导出
    Description : 用于对保存的全局数据做解析（版本号判定等）
    Input       : stream
    Output      : stream
    Return      : 0:文件正常导出， else:停止文件导出
    Note        :
    *************************************************/
    virtual int FileExport(QDataStream& stream) = 0;

    /*************************************************
    Function    : ICAMData序列化
    Description : 对图形附加的工艺数据进行序列化
    Input       : stream, data(图形附带的工艺数据）
    Output      : stream
    Return      :
    Note        :
    *************************************************/
    virtual void SerializeCAMData(QDataStream& stream, const std::shared_ptr<ICAMData>& data) = 0;

    /*************************************************
    Function    : ICAMData反序列化
    Description : 对图形附加的工艺数据进行反序列化
    Input       : stream
    Output      : stream
    Return      : 图形附加工艺数据
    Note        :
    *************************************************/
    virtual std::shared_ptr<ICAMData> DeserializeCAMData(QDataStream& stream) = 0;
};

#endif // IEXP_SERIALIZE_H
