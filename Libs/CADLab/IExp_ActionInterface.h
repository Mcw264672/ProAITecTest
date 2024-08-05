#ifndef IExp_ActionInterface_H
#define IExp_ActionInterface_H

#include <QVector>
#include "Exp_Vector.h"
#include "CADLab_global.h"
#ifdef CADLab_LIBRARY
#include "lib/engine/rs.h"
#else
#include "rs.h"
#endif

class Exp_Entity;

/**
 * 用于在外部实现绘制或修改图元的Action，通过调用Exp_Management::SetCurrentAction
 * 切换至自定义Action,在需要结束时调用Exp_Management::KillAllActions结束当前Action，
 * 返回DefaultAction
 */
class IExp_ActionInterface
{
public:
    virtual ~IExp_ActionInterface() = default;

    /*************************************************
    Function    : 跟据鼠标所在位置显示预览图形
    Description :
    Input       : mouse 鼠标位置
    Output      :
    Return      : 鼠标移动时要显示的图形
    Note        : 输出部分的接口由CADLab内部释放
    *************************************************/
    virtual QVector<Exp_Entity*> PreviewForMouseMoveEvent(
        const Exp_Vector& mouse) = 0;

    /*************************************************
    Function    : 鼠标按下时调用此接口
    Description :
    Input       : mouse 鼠标位置
    Output      :
    Return      :
    Note        : 输入的坐标与RequiredSnapper()返回值有关，若为true，则输入捕捉到的点
    *************************************************/
    virtual void LeftButtonPressEvent(const Exp_Vector& mouse) = 0;

    virtual void RightButtonPressEvent(const Exp_Vector& mouse) = 0;

    /*************************************************
    Function    : 用户通过命令行输入点坐标时调用此接口
    Description :
    Input       : mouse 用户输入的坐标
    Output      :
    Return      :
    Note        :
    *************************************************/
    virtual void CoordinateEvent(const Exp_Vector& mouse) = 0;

    /*************************************************
    Function    : 用户通过命令行输入除坐标之外的内容时调用此接口
    Description :
    Input       : msg 用户输入的字符串
    Output      :
    Return      :
    Note        :
    *************************************************/
    virtual void CommandEvent(const QString& msg) = 0;

    /*************************************************
    Function    : 修改命令行上方的提示内容
    Description :
    Input       :
    Output      :
    Return      : 需要显示的提示
    Note        :
    *************************************************/
    virtual QString CommandHints() = 0;

    /*************************************************
    Function    : 修改光标样式
    Description :
    Input       :
    Output      :
    Return      : 光标样式
    Note        :
    *************************************************/
    virtual RS2::CursorType MouseCursorType() = 0;

    /*************************************************
    Function    : 是否需要捕捉
    Description :
    Input       :
    Output      :
    Return      : true：需要捕捉   false：不需要捕捉
    Note        :
    *************************************************/
    virtual bool RequiredSnapper() = 0;

    /*************************************************
    Function    : 是否需要移动相对零点
    Description :
    Input       :
    Output      :
    Return      : true：需要移动相对零点   false：不需要移动相对零点
    Note        : 若为true，则通过鼠标点击及命令行输入的点都会被作为相对零点
    *************************************************/
    virtual bool MoveRelativeZero() = 0;

    /*************************************************
    Function    : 键盘按下时调用此接口
    Description :
    Input       : 按键key值
    Output      :
    Return      :
    Note        : 该事件仅限焦点在画布上，且按键为Enter时生效，
                  按键事件会被命令行、全局控制等更上层的处理限制事件分发
    *************************************************/
    virtual void KeyPressEvent(const int & key) = 0;
};

#endif  // IExp_ActionInterface_H
