#ifndef EXP_MTEXT_H
#define EXP_MTEXT_H
#include "Exp_Entity.h"
#include "Exp_EntityContainer.h"
#include "CADLab_global.h"

struct CADLab_EXPORT Exp_MTextData
{
    Exp_MTextData(const Exp_Vector& startP,
                 const QString str,
                 double height = 10.,
                 double angle = 0.,
                 double lineSpacing = 1.);

    Exp_Vector startP;
    double height;
    double angle;
    double lineSpacing;
    QString str;
};

class CADLab_EXPORT Exp_MText : public Exp_EntityContainer
{
public:
    Exp_MText(void* en);

    /*************************************************
    Function    : 生成多行文字
    Description : 调用此静态方法生成一个多行文字的图元对象
    Input       : 多行文字的数据
    Output      :
    Return      : 返回生成的图元对象指针
    Note        : mtextData包括插入点坐标、文字高度、旋转角度、
                  行间距（比率，默认为1）、文本内容
    *************************************************/
    static Exp_MText* CreateMText(const Exp_MTextData& mtextData);

    /*************************************************
    Function    : 设置字体
    Description : 调用此方法设置该文本图元的字体
    Input       : 已有的字体名
    Output      :
    Return      : 是否成功设置
    Note        : 字体参考/resources/fonts/
    *************************************************/
    bool SetStyle(const QString& style);

    /*************************************************
    Function    : 获取字体
    Description : 调用此方法获取该文本图元的字体
    Input       :
    Output      :
    Return      : 已有的字体名
    Note        : 字体参考/resources/fonts/
    *************************************************/
    QString GetStyle();

    /*************************************************
    Function    : 设置旋转
    Description : 调用此方法设置该文本图元的旋转弧度
    Input       : 弧度值
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetAngle(double angle);

    /*************************************************
    Function    : 获取旋转
    Description : 调用此方法获取该文本图元的旋转弧度
    Input       :
    Output      :
    Return      : 弧度值
    Note        :
    *************************************************/
    double GetAngle();

    /*************************************************
    Function    : 设置高度
    Description : 调用此方法设置该文本图元的高度
    Input       : 高度值
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetHeight(double height);

    /*************************************************
    Function    : 获取高度
    Description : 调用此方法获取该文本图元的高度
    Input       :
    Output      :
    Return      : 高度值
    Note        :
    *************************************************/
    double GetHeight();

    /*************************************************
    Function    : 设置行间距
    Description : 调用此方法设置该文本图元的行间距
    Input       : 行间距
    Output      :
    Return      :
    Note        : 行间距为比率（ratio），默认为1
    *************************************************/
    void SetLineSpacingFactor(double ls);

    /*************************************************
    Function    : 获取行间距
    Description : 调用此方法获取该文本图元的行间距
    Input       :
    Output      :
    Return      : 行间距
    Note        :
    *************************************************/
    double GetLineSpacingFactor();

    /*************************************************
    Function    : 设置文本
    Description : 调用此方法设置该文本图元的文本内容
    Input       : 文本内容
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetText(QString text);

    /*************************************************
    Function    : 获取文本
    Description : 调用此方法获取该文本图元的文本内容
    Input       :
    Output      :
    Return      : 文本内容
    Note        :
    *************************************************/
    QString GetText();

    /*************************************************
    Function    : 获取插入点坐标
    Description : 调用此方法获取该文本图元的插入点坐标
    Input       :
    Output      :
    Return      : 坐标值
    Note        :
    *************************************************/
    Exp_Vector GetInsertionPoint();

    /*************************************************
    Function    : 获取行数
    Description : 调用此方法获取该文本图元的行数
    Input       :
    Output      :
    Return      : 行数
    Note        :
    *************************************************/
    int GetNumberOfLines();

    /*************************************************
    Function    : 设置对齐方式
    Description : 调用此方法设置该文本图元的对齐方式
    Input       : 对齐方式
    Output      :
    Return      :
    Note        : 对齐方式参数为1~9的值
                  1~3 : TopLeft / TopCenter / TopRight
                  4~6 : MidLeft  MidCenter / MidRight
                  7~9 : BotLeft / BotCenter / BotRight
    *************************************************/
    void SetAlignment(int a);

    /*************************************************
    Function    : 获取对齐方式
    Description : 调用此方法获取该文本图元的对齐方式
    Input       :
    Output      :
    Return      : 对齐方式
    Note        :
    *************************************************/
    int GetAlignment();

    /*************************************************
    Function    : 获取是否为特殊绘制的文字
    Description : 调用此方法获取该文本图元是否为特殊绘制
    Input       :
    Output      :
    Return      : 是否为特殊绘制
    Note        : 即利用QPainter绘制，当特殊绘制时禁用该图元的打散和捕捉，
                  无法设置字体，默认为微软雅黑
    *************************************************/
    bool IsSpecialShowText();

    /*************************************************
    Function    : 设置该文本图元是否为特殊绘制
    Description : 调用此方设置取该文本图元是否为特殊绘制
    Input       : isSpecial: true,特殊绘制;false，正常绘制
    Output      :
    Return      :
    Note        : cadLab默认为false
    *************************************************/
    void SetIsSpeicalShowText(const bool& isSpecial);
};

#endif // EXP_MTEXT_H
