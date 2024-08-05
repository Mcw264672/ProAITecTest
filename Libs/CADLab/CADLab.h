#ifndef CADLAB_H
#define CADLAB_H

#include "CADLab_global.h"
#include <QObject>
#include <QMouseEvent>
#include <functional>

class QApplication;
class QMainWindow;
class QToolBar;
class QPushButton;
class QTabWidget;
class Exp_Entity;

class CADLab_EXPORT CADLab: public QObject
{
    Q_OBJECT
public:
    explicit CADLab(QWidget *parent);
    ~CADLab();
    WId GetWinId() const;

    /*************************************************
    Function    : 设置项目注册名
    Description : 调用此方法设置CADLab软加密机制的项目注册名
    Input       : 注册名（任意字符串）
    Output      :
    Return      :
    Note        : 该接口与BaseDll库中的RGInital为相同接口，
                  根据注册名，用于在软加密注册机制下区分不同的项目，
                  仅在需要软加密机制的情况下调用！！！
    *************************************************/
    static void CADLabRegInitial(const QString&);

    /*************************************************
    Function    : 启动CADLab
    Description : 调用此方法以启动CADLab，完成实际初始化流程
    Input       :
    Output      :
    Return      :
    Note        : 将CADLab对象实例化后，必须通过手动调用此接口启动CAD！！！
    *************************************************/
    void LaunchCADWindow();

    /*************************************************
    Function    : 关闭CADLab
    Description : 调用此方法以关闭CADLab的界面显示
    Input       :
    Output      :
    Return      :
    Note        : CAD界面析构的实际流程，区分关闭时是否询问文件保存
    *************************************************/
    bool OnMainWindowExit();
    void OnMainWindowForceExit();

    /*************************************************
    Function    : 获取CADLab的界面指针
    Description :
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    void* GetMainWin();
    QMainWindow* GetQMainWin();

    /*************************************************
    Function    : 设置启动时是否显示CAD主窗口
    Description :
    Input       : 是否显示
    Output      :
    Return      :
    Note        : 需要调用LaunchCADWindow前进行设置
    *************************************************/
    void SetCADShowWhenInit(bool show);

    /*************************************************
    Function    : 设置启动画面是否显示
    Description :
    Input       : 是否显示
    Output      :
    Return      :
    Note        : 需要调用LaunchCADWindow前进行设置
    *************************************************/
    void SetSplashScreenShow(bool show);

    /*************************************************
    Function    : 设置启动画面（图片文件）的路径
    Description :
    Input       : 文件路径
    Output      :
    Return      :
    Note        : 当未设置该路径时则使用CADLab内部默认的启动画面显示
    *************************************************/
    static void SetSplashScreenPath(const QString&);

    /*************************************************
    Function    : 获取CADLab的App名称
    Description :
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    QString GetAppName() const;

    /*************************************************
    Function    : 获取CADLab的版本号
    Description :
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    QString GetAppVersion() const;

    /*************************************************
    Function    : 设置CADLab各界面元素的显示状态
    Description :
    Input       : 是否显示
    Output      :
    Return      :
    Note        : ShortcutActToolbar:   快捷按钮工具栏
                  PenToolbar:           画笔工具栏
                  LayerToolbar:         图层工具栏
                  EntityToolbar:        图元工具栏
                  DimensionToolbar:     标注工具栏
                  ModifyToolbar:        修改工具栏
                  OperateToolbar:       操作工具栏
                  CommandWidget:        命令行窗口
                  EntityAttributes:     图元属性窗口
                  Grid:                 画笔网格
                  GridRuler:            网格标尺
                  XYAxis:               X、Y轴0位分界
                  Direction:            图元方向
                  Rank:                 图元序号
                  SplashScreen:         启动画面
                  SubWidLabel:          快捷按钮工具栏子页面标签
    *************************************************/
    void SetShortcutToolbarShow(bool show);
    void SetPenToolbarShow(bool show);
    void SetLayerToolbarShow(bool show);
    void SetEntityToolbarShow(bool show);
    void SetDimensionToolbarShow(bool show);
    void SetModifyToolbarShow(bool show);
    void SetOperateToolbarShow(bool show);
    void SetCommandWidgetShow(bool show);
    void SetEntityAttributesShow(bool show);
    void SetGridShow(bool show);
    void SetGridRulerShow(bool show);
    void SetXYAxisShow(bool show);
    void SetDirectionShow(bool show);
    void SetRankShow(bool show);
    void SetShortcutSubWidLabelShow(bool show);

    /*************************************************
    Function    : 获取CADLab各控件的指针
    Description :
    Input       :
    Output      :
    Return      :
    Note        : ShortcutActToolbar:   快捷按钮工具栏
                  ShortcutActTabWid:    快捷按钮标签界面
                  ShortcutActWidget:    快捷按钮标签界面中Widget
                  EntityToolbar:        图元工具栏
                  DimensionToolbar:     标注工具栏
                  ModifyToolbar:        修改工具栏
                  OperationToolbar:     操作工具栏
                  PenToolbar:           画笔工具栏
                  LayerWidget:          图层工具栏（QWidget）
                  btnSnapperObject:     对象捕捉(F3)按钮
                  btnOrthogonal:        正交限制(F8)按钮
                  btnPolarAxis:         极轴追踪(F10)按钮
                  btnLineWidthShow:     线宽显示按钮
                  CommandWidget:        命令行窗口
                  SelectionWidget:      选中图元个数
    *************************************************/
    QToolBar*GetShortcutActToolbarPtr();
    QTabWidget*GetShortcutActTabWidPtr();
    QWidget*GetShortcutActWidgetPtr();
    QToolBar*GetEntityToolbarPtr();
    QToolBar*GetDimensionToolbarPtr();
    QToolBar*GetModifyToolbarPtr();
    QToolBar*GetOperationToolbarPtr();
    QToolBar*GetPenToolbarPtr();
    QWidget* GetLayerWidgetPtr();
    QPushButton*GetSnapperButtonPtr();
    QPushButton*GetOrthogonalButtonPtr();
    QPushButton*GetPolarAxisButtonPtr();
    QPushButton*GetLineWidthShowButtonPtr();
    QWidget* GetCommandWidget();
    QWidget* GetSelectionWidget();

    /*************************************************
    Function    : 获取CADLab的各Action指针
    Description :
    Input       : 需要获取的Action的名称
    Output      :
    Return      :
    Note        :
    *************************************************/
    QAction* GetAction(const QString& actionName);

    /*************************************************
    Function    : 底图加载
    Description :
    Input       : fileName 文件名
                  filter 图形过滤（使用输入Clone的图形作为输出）
    Output      :
    Return      :
    *************************************************/
    void LoadBaseMap(const QString& fileName,
                     const std::function<QList<Exp_Entity*>(const QList<Exp_Entity*>&)>& filter);

    void ToggleNestingDisplayStatus();

    /*************************************************
    Function    : 重设所有快捷键的parent
    Description :
    Input       : 快捷键的新父对象
    Output      :
    Return      :
    Note        : 由于快捷键只有在父对象为活动时才能触发，如果CADLab主窗口不活动，
                  仅提取画布插入到界面上，需要调用此接口设置新的父对象以保证快捷键启用
    *************************************************/
    void ResetAllShortcutParent(QObject* newParent);

    /*************************************************
    Function    : 手动触发键盘按下事件
    Description :
    Input       : 键盘按下事件
    Output      :
    Return      :
    Note        : 如果因为焦点问题导致键盘事件不生效,可手动调用触发键盘事件
    *************************************************/
    void TriggerKeyPressEvent(QKeyEvent *event);

    /*************************************************
    Function    : 手动触发键盘抬起事件
    Description :
    Input       : 键盘抬起事件
    Output      :
    Return      :
    Note        : 如果因为焦点问题导致键盘事件不生效,可手动调用触发键盘事件
    *************************************************/
    void TriggerKeyReleaseEvent(QKeyEvent *event);

    /*************************************************
    Function    : 设置CADLab的语言
    Description :
    Input       : transFileName翻译文件的文件路径
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetLanguage(const QString transFileName);

private slots:
    void SlotRealInitial();
    void SlotForceExit();
    void SlotMdiWinAlive(bool alive);

signals:
    void CadExit();
    void SigMdiWinAlive(bool alive);

    void SigActiveMdiWinChange(int index);

    void SigMouseMove(QMouseEvent* e, double x, double y);
    void SigMousePress(QMouseEvent* e, double x, double y);
    void SigMouseRelease(QMouseEvent* e, double x, double y);
    void SigMouseDoubleClick(QMouseEvent* e, double x, double y);

    void SigKeyPress(QKeyEvent* e);
    void SigKeyRelease(QKeyEvent* e);

    void SigLastSelectedEntityChanged(Exp_Entity* entity);
    void SigSelectEntityHandle();
    void SigAddNewEntity(Exp_Entity* entity);

    void SigRedrawAll();

    void SigEntrySpecialAction(int id);

    void SigCurrentActionChanged(int id);

private:
    QWidget* m_superWidget;
    void* m_mainWin{};
    static QString s_SplashScreenPath;
    bool m_IsShowSplashScreen{true};
    bool m_IsMainWinShow{true};
    QString m_TransFileName{};
};

#endif // CADLAB_H
