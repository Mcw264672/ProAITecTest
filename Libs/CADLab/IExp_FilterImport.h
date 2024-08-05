#ifndef IEXP_FILTERIMPORT_H
#define IEXP_FILTERIMPORT_H

#include "Exp_Entity.h"

class IExp_FilterImport
{
public:
    virtual ~IExp_FilterImport() = default;

    /*************************************************
    Function    : 文件导入
    Description : 用于外部导入自定义文件类型
    Input       : filePath 文件路径+文件名
    Output      : enOut 文件解析后要添加到界面上的图元,此部分内存由内部释放
    Return      : false:内部导入此文件 true由外部操作此文件，内部不做干涉
    Note        : 根据文件后缀名判断是否由外部执行文件解析操作，若外部执行文件导入，return true，
                  否则由CADLab内部解析，返回false
    *************************************************/
    virtual bool FileImport(const QString& filePath, QVector<Exp_Entity*>& enOut) = 0;
};

#endif // IEXP_FILTERIMPORT_H
