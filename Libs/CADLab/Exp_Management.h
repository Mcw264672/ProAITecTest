/*******************************************************************************
 * Descript	:
 * Author   :
 * Data     :
 * Version	: 1.0.1.0126_Beta
 * History  :
 * Note     :
 *******************************************************************************/
#ifndef EXP_MANAGEMENT_H
#define EXP_MANAGEMENT_H

#include <QSharedPointer>
#include <memory>

#include "CADLab_global.h"
#include "Exp_Component.h"
#include "Exp_Entity.h"
#include "Exp_AtomicEntity.h"
#include "Exp_SnapMode.h"
#include "IExp_ImportOptimize.h"
#include "IExp_Sortable.h"
#include "ICAMData.h"
#include "IGlobalCAMData.h"

#ifdef CADLab_LIBRARY
#include "lib/engine/rs.h"
#else
#include "rs.h"
#endif

#define MANAGEMENT Exp_Management::Instance()

class QMouseEvent;
class QSize;
class QPixmap;
class Exp_Block;
class Exp_Polyline;
class IExp_ActionInterface;
class IExp_FilterImport;
class IExp_Serialize;
class RS_GraphicView;

struct CADLab_EXPORT PixmapLine{
    PixmapLine() : start(Exp_Vector{0., 0.}), end(Exp_Vector{0., 0.}), color(RS2::ColorWhite) {}
    PixmapLine(const Exp_Vector& sp, const Exp_Vector& ep,
               const RS2::LineColor& cl = RS2::ColorWhite)
        : start(sp), end(ep), color(cl) {}

    Exp_Vector start;
    Exp_Vector end;
    RS2::LineColor color;
};

enum EmValidDxfVer
{
    UNKNOWNV,     /** UNKNOWN VERSION. **/
    AC1006,       /** R10.             **/
    AC1009,       /** R11 & R12.       **/
    AC1012,       /** R13.             **/
    AC1014,       /** R14.             **/
    AC1015,       /** ACAD 2000.       **/
    AC1018,       /** ACAD 2004.       **/
    AC1021,       /** ACAD 2007.       **/
    AC1024,       /** ACAD 2010.       **/
    AC1027        /** ACAD 2013.       **/
};

enum EmSaveAsDefault
{
    FDxf2007RW,     /** Dxf File.       **/
    FBin            /** Binary File.    **/
};

class CADLab_EXPORT Exp_Management
{
    Exp_Management();

public:
    static Exp_Management* Instance();
    Exp_Management(Exp_Management const&) = delete;
    void operator=(Exp_Management const&) = delete;
    bool Update(const WId& winId);
    void SlotFileChanged(RS_GraphicView* view = nullptr);

    /*************************************************
    Function    : 打印信息
    Description : 调用此方法在命令窗口中输出指定的字符串信息
    Input       : 指定字符串
    Output      :
    Return      :
    Note        : 不带撤销重做功能
    *************************************************/
    void PrintCmdMessage(const QString str);

    /*************************************************
    Function    : 显示方向箭头
    Description : 调用此方法设置是否显示图元的方向箭头
    Input       : 是否显示
    Output      :
    Return      :
    Note        : 不带撤销重做功能
    *************************************************/
    void ShowDirectionArrow(const bool show);

    /*************************************************
    Function    : 显示序号
    Description : 调用此方法设置是否显示图元的序号
    Input       : 是否显示
    Output      :
    Return      :
    Note        : 不带撤销重做功能
    *************************************************/
    void ShowSortNum(const bool show);

    /*************************************************
    Function    : 设置相对零点位置
    Description : 调用此方法设置当前画布的相对零点位置
    Input       : 待设置点的位置
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetRelativeZero(Exp_Vector p);

    /*************************************************
    Function    : 获取相对零点位置
    Description : 调用此方法获取当前画布的相对零点位置
    Input       :
    Output      :
    Return      : 当前相对零点位置
    Note        :
    *************************************************/
    Exp_Vector GetRelativeZero();

    /*************************************************
    Function    : 获取当前GraphicView的指针
    Description :
    Input       :
    Output      :
    Return      : 获取当前GraphicView的指针
    Note        :
    *************************************************/
    QWidget* GetGraphicViewPtr();

    /*************************************************
    Function    : 获取当前活动画布的序号
    Description :
    Input       :
    Output      :
    Return      : 当前活动画布的序号
    Note        :
    *************************************************/
    const int GetActiveFileIndex();

    /*************************************************
    Function    : 获取指定文件名的画布指针
    Description :
    Input       : docName文件名
    Output      :
    Return      : 文件名为docName的画布指针
    Note        : 注意判断空指针
                  将指针添加到其他界面之后，若要关闭画布，需调用对应的Reset接口
    *************************************************/
    QWidget* GetGraphicViewPtr(const QString& docName);

    /*************************************************
    Function    : 获取第index个画布指针
    Description :
    Input       : index画布序号
    Output      :
    Return      : 第index个画布指针
    Note        : 注意判断空指针，序号从0开始
                  将指针添加到其他界面之后，若要关闭画布，需调用对应的Reset接口
    *************************************************/
    QWidget* GetGraphicViewPtr(const int& idx);

    /*************************************************
    Function    : 获取打开的画布总数
    Description :
    Input       :
    Output      : 打开的画布总数
    Return      :
    Note        :
    *************************************************/
    const int GetAllGraphicViewCnt();

    /*************************************************
    Function    : 获取所有的画布的指针
    Description :
    Input       :
    Output      :
    Return      : 所有的画布的Widget指针
    Note        : 将指针添加到其他界面之后，若要关闭画布，需调用对应的Reset接口
    *************************************************/
    QVector<QWidget*> GetAllGraphicViewPtr();

    /*************************************************
    Function    : 将所有画布还给CADLab管理
    Description :
    Input       :
    Output      :
    Return      :
    Note        : 用于单独获取画布指针后，关闭该画布前需将其交还CADLab
    *************************************************/
    void ResetAllGrahicView();

    /*************************************************
    Function    : 将指定文件名的画布还给CADLab管理
    Description :
    Input       : docName要还给CADLab管理的画布文件名
    Output      :
    Return      :
    Note        : 用于单独获取画布指针后，关闭该画布前需将其交还CADLab
    *************************************************/
    void ResetGraphicView(const QString& docName);

    /*************************************************
    Function    : 将第index个画布还给CADLab管理
    Description :
    Input       : index要还给CADLab管理的画布序号
    Output      :
    Return      :
    Note        : 用于单独获取画布指针后，关闭该画布前需将其交还CADLab
                  序号从0开始
    *************************************************/
    void ResetGraphicView(const int& index);

    /*************************************************
    Function    : 将指定画布还给CADLab管理
    Description :
    Input       : graphicView要还给CADLab管理的指定画布
    Output      :
    Return      :
    Note        : 用于单独获取画布指针后，关闭该画布前需将其交还CADLab
    *************************************************/
    void ResetGraphicView(QWidget* graphicView);

    /*************************************************
    Function    : 设置指定名称的画布为当前的活动画布
    Description :
    Input       : docName要设为活动的画布的文件名
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetGraphicViewActived(const QString& docName);

    /*************************************************
    Function    : 设置第index个画布为当前的活动画布
    Description :
    Input       : index要设为活动的画布的序号
    Output      :
    Return      :
    Note        : index从0开始
    *************************************************/
    void SetGraphicViewActived(const int& index);

    /*************************************************
    Function    : 设置指定画布为当前的活动画布
    Description :
    Input       : graphicView要设为活动的画布
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetGraphicViewActived(QWidget* graphicView);

    /*************************************************
    Function    : 关闭名称为docName的画布
    Description :
    Input       : docName要关闭的文件名
    Output      :
    Return      :
    Note        :
    *************************************************/
    void CloseGraphicView(const QString& docName);

    /*************************************************
    Function    : 关闭第index个画布
    Description :
    Input       : 要关闭的文件序号
    Output      :
    Return      :
    Note        : index从0开始
    *************************************************/
    void CloseGraphicView(const int& index);

    /*************************************************
    Function    : 不询问是否保存强制关闭名称为docName的画布
    Description :
    Input       : docName要关闭的文件名
    Output      :
    Return      :
    Note        :
    *************************************************/
    void ForceCloseGraphicView(const QString& docName);

    /*************************************************
    Function    : 不询问是否保存强制关闭第index个画布
    Description :
    Input       : 要关闭的文件序号
    Output      :
    Return      :
    Note        : index从0开始
    *************************************************/
    void ForceCloseGraphicView(const int& index);

    /*************************************************
    Function    : 获取GraphicView的大小
    Description : 调用此方法获取画布大小
    Input       :
    Output      :
    Return      : 画布的尺寸
    Note        :
    *************************************************/
    QSize GetGraphicViewSize();

    /*************************************************
    Function    : 获取GraphicView左上角的坐标
    Description : 调用此方法获取画布左上角(0,0)点对应的实际坐标
    Input       :
    Output      :
    Return      : 画布左上角的实际坐标
    Note        : 此方法用于绘制实时轨迹时做坐标映射
    *************************************************/
    Exp_Vector GetCoordLeftTop();

    /*************************************************
    Function    : 获取GraphicView左上角的屏幕像素
    Description : 调用此方法获取画布左上角(0,0)点对应的屏幕实际像素位置
    Input       :
    Output      :
    Return      : 画布左上角的实际像素
    Note        : 此方法用于绘制截屏时做坐标映射时，可能需要后接
                  QWidget::mapFromGlobal转换为局部像素
    *************************************************/
    QPoint GetPixelLeftTop();

    /*************************************************
    Function    : 获取当前画布的绘制比例
    Description : 调用此方法获取当前画布的绘制比例（像素长度/实际长度）
    Input       :
    Output      :
    Return      : 画布的绘制比例
    Note        : 此方法用于绘制实时轨迹时做坐标映射
    *************************************************/
    Exp_Vector GetFactor();

    /*************************************************
    Function    : 设置文件另存为的默认保存格式
    Description :
    Input       : 文件格式
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetSaveAsDefault(EmSaveAsDefault type);

    /*************************************************
    Function    : 获取文件另存为的默认保存格式
    Description :
    Input       :
    Output      :
    Return      : 文件格式
    Note        :
    *************************************************/
    EmSaveAsDefault GetSaveAsDefault();

    /*************************************************
    Function    : 设置命令窗口高度
    Description : 给定高度数值重设当前命令窗口的高度
    Input       : height为高度
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetCommandWidgetHeight(int height);

    /*************************************************
    Function    : 设置命令窗口最小高度
    Description : 给定高度数值锁死当前命令窗口的最小高度
    Input       : height为最小高度
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetCommandWidgetMiniHeight(int height);

    /*************************************************
    Function    : 设置图层窗口宽度
    Description : 给定宽度数值重设当前图层窗口的宽度
    Input       : width为宽度
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetLayerWidgetWidth(int width);

    /*************************************************
    Function    : 设置图块窗口宽度
    Description : 给定宽度数值重设当前图块窗口的宽度
    Input       : width为宽度
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetBlockWidgetWidth(int width);

    /*************************************************
    Function    : 设置状态栏上的捕捉按钮是否隐藏
    Description :
    Input       : hide(true:隐藏，false:显示)
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetSnapButtonHidden(bool hide);

    /*************************************************
    Function    : 设置状态栏上的正交按钮是否隐藏
    Description :
    Input       : hide(true:隐藏，false:显示)
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetOrthogonalButtonHidden(bool hide);

    /*************************************************
    Function    : 设置状态栏上的极轴按钮是否隐藏
    Description :
    Input       : hide(true:隐藏，false:显示)
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetPolarAxisButtonHidden(bool hide);

    /*************************************************
    Function    : 设置状态栏上的线宽显示按钮是否隐藏
    Description :
    Input       : hide(true:隐藏，false:显示)
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetLineWidthShowButtonHidden(bool hide);

    /*************************************************
    Function    : 设置是否隐藏关闭窗口时的保存文件提示
    Description :
    Input       : hidden:true 隐藏，false:显示
    Output      :
    Return      :
    Note        : 隐藏窗口提示默认忽略文件修改，不做保存
    *************************************************/
    void SetCloseDialogHidden(bool hidden);

    /*************************************************
    Function    : 刷新光标样式
    Description : 刷新当前的光标样式（配合IExp_ActionActionInterface使用）
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    void UpdateMouseCursor();

    /*************************************************
    Function    : 刷新命令行上方提示信息
    Description : 刷新当前的命令行上方提示信息（配合IExp_ActionActionInterface使用）
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    void UpdateCommandHints();



    /*************************************************
    Function    : 修改标注文字比例
    Description : 修改当前图纸的标注文字比例（该值会随dxf存储:$DIMSCALE字段）
    Input       : scale(标注缩放比例)
    Output      :
    Return      :
    Note        :
    *************************************************/
    void UpdateDimensionTextScale(double scale);

    /*************************************************
    Function    : 将实际坐标转换为屏幕坐标（相对于画布窗口的坐标）
    Description :
    Input       : 实际坐标
    Output      :
    Return      : 屏幕坐标
    Note        :
    *************************************************/
    Exp_Vector PointToGui(const Exp_Vector& p);

    /*************************************************
    Function    : 将屏幕坐标（相对于画布窗口的坐标）转换为实际坐标
    Description :
    Input       : 屏幕坐标
    Output      :
    Return      : 实际坐标
    Note        :
    *************************************************/
    Exp_Vector PointToGraph(const Exp_Vector& p);

    /*************************************************
    Function    : 传入Pixmap的信息用于显示
    Description : 调用此方法传入Pixmap相关信息用于显示轨迹
    Input       : pixmap(轨迹pixmap),factor(pixmap中显示内容与像素的比值),
                  leftTop(pixmap左上角对齐的实际坐标)
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetPixmapData(QSharedPointer<QPixmap> pixmap, const Exp_Vector& factor,
                       const Exp_Vector& leftTop);

    /*************************************************
    Function    : 传入Pixmap的信息用于显示(同SetPixmapData)
    Description : 调用此方法传入Pixmap相关信息用于显示轨迹
    Input       : pixmap(轨迹pixmap),factor(pixmap中显示内容与像素的比值),
                  leftTop(pixmap左上角对齐的实际坐标)
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetPixmapBkData(QSharedPointer<QPixmap> pixmap, const Exp_Vector& factor,
                         const Exp_Vector& leftTop);

    /*************************************************
    Function    : 获取图形预览窗口
    Description :
    Input       : entities:图形集合，parent:窗口父对象
    Output      :
    Return      : 显示图形预览的Widget
    Note        : 内部预览时使用Clone的图形，输入entities的内存需要外部释放
    *************************************************/
    QWidget* CreatePreviewWidget(const QVector<Exp_Entity*>& entities, QWidget* parent = nullptr, bool drawDirect = false);

    /*************************************************
    Function    : 获取图形预览Pixmap
    Description :
    Input       : entities:图形集合， size:Pixmap尺寸
    Output      :
    Return      : 图形预览Pixmap
    Note        :
    *************************************************/
    QPixmap CreatePreviewPixmap(QVector<Exp_Entity*>& entities, const QSize& size, bool useEntityColor = false);

    /*************************************************
    Function    : 获取图形预览Pixmap
    Description :
    Input       : segments:线段集合， size:Pixmap尺寸
    Output      :
    Return      : 图形预览Pixmap
    Note        : 避免外部需要一次性创建大量的Exp_Entity而导致的巨额内存消耗
    *************************************************/
    QPixmap CreatePreviewPixmap(const QVector<PixmapLine>& segments, const QSize& size);

    /*************************************************
    Function    : 设置样条曲线默认解析段数
    Description : 调用此方法设置样条曲线每两个控制点间解析的直线段数
    Input       : seg(段数)
    Output      :
    Return      :
    Note        :打开dxf文件时使用文件中存储的样条曲线解析段数来解析样条曲线，当样条曲线较多或样条曲线复杂度高时，
                 使用此接口降低解析段数可有效提高绘制速度（显示精度会下降）
    *************************************************/
    void SetDefaultSplineSegments(int seg);

    /*************************************************
    Function    : 获取所有图元
    Description : 调用此方法获取已有的所有图元对象列表
    Input       :
    Output      :
    Return      : 所有图元对象的指针
    Note        :
    *************************************************/
    QList<Exp_Entity*> GetAllEntities();

    /*************************************************
    Function    : 获取所有可见图元
    Description : 调用此方法获取已有的可见图元对象列表
    Input       :
    Output      :
    Return      : 所有可见图元对象的指针
    Note        :
    *************************************************/
    QList<Exp_Entity*> GetAllVisibleEntities();

    /*************************************************
    Function    : 获取所有选中图元
    Description : 调用此方法获取已有的选中图元对象列表
    Input       :
    Output      :
    Return      : 所有选中图元对象的指针
    Note        :
    *************************************************/
    QList<Exp_Entity*> GetAllSelectedEntities();

    /*************************************************
    Function    : 获取所有可见的可排序图元（普通图元）
    Description : 调用此方法获取所有的可见且可排序的图元
    Input       :
    Output      :
    Return      : 所有可见且可排序图元对象的指针
    Note        :
    可排序图元包括：直线，圆弧，圆，椭圆，样条曲线，多段线，文字，多行文字，块
    *************************************************/
    QList<Exp_Entity*> GetAllSortableEntities();

    /*************************************************
    Function    : 添加图元
    Description : 调用此方法将自行构建的图元对象添加到画布中显示
    Input       : 待添加的图元
    Output      :
    Return      :
    Note        : 添加后需手动调用Redraw刷新画布显示
    *************************************************/
    void AddNewEntity(Exp_Entity* en);

    /*************************************************
    Function    : 添加图元
    Description : 调用此方法将自行构建的图元对象添加到画布中显示
    Input       : 待添加的图元
    Output      :
    Return      :
    Note        : 该方法添加的图元不带撤销重做功能
                  添加后需手动调用Redraw刷新画布显示
    *************************************************/
    void AddNewEntityWithoutUndo(Exp_Entity* en);

    /*************************************************
    Function    : 移除
    Description : 调用此方法删除所有选中的图元对象
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    void Remove();

    /*************************************************
    Function    : 移除
    Description : 调用此方法删除指定的图元对象
    Input       : 图元指针
    Output      :
    Return      :
    Note        :
    *************************************************/
    void Remove(Exp_Entity* en);

    /*************************************************
    Function    : 移除
    Description : 调用此方法删除所有选中的图元对象
    Input       :
    Output      :
    Return      :
    Note        : 通过该方法移除图元无法被撤销重做
    *************************************************/
    void RemoveWithoutUndo();

    /*************************************************
    Function    : 移除
    Description : 调用此方法删除指定的图元对象
    Input       : 图元指针
    Output      :
    Return      :
    Note        : 通过该方法移除图元无法被撤销重做
    *************************************************/
    void RemoveWithoutUndo(Exp_Entity* en);

    /*************************************************
    Function    : 移除全部图元
    Description : 调用此方法删除所有可见的图元对象
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    void RemoveAll();

    /*************************************************
    Function    : 移除全部图元
    Description : 调用此方法删除所有可见的图元对象
    Input       :
    Output      :
    Return      :
    Note        : 通过该方法移除图元无法被撤销重做
    *************************************************/
    void RemoveAllWithoutUndo();

    /*************************************************
    Function    : 撤销重做
    Description : 调用此接口添加一组用于撤销重做的图形
    Input       : before(从当前界面中隐藏的图形，撤销后显示此部分）
                  after（添加到界面中的图形，撤销后隐藏此部分）
    Output      :
    Return      :
    Note        :
    *************************************************/
    void UndoRedo(const QVector<Exp_Entity*>& before, const QVector<Exp_Entity*>& after);
    /*************************************************
    Function    : 重绘
    Description : 调用此方法重新绘制画布上的所有对象
    Input       : 重绘方式
    Output      :
    Return      :
    Note        : 默认全部重绘，重绘类型参考rs.h
    *************************************************/
    void Redraw(RS2::RedrawMethod method = RS2::RedrawAll);

    /*************************************************
    Function    : 重绘指定图元
    Description : 调用此方法重新绘制画布上的指定图元
    Input       : 重绘方式
    Output      :
    Return      :
    Note        :
    *************************************************/
    void RedrawEntity(Exp_Entity* en);

    /*************************************************
    Function    : 图元移至顶层
    Description : 将图元移动至画布顶层进行绘制（避免被重叠图元所覆盖）
    Input       : 图元指针
    Output      :
    Return      :
    Note        : 内部已调用单个图元的重绘逻辑，无需重复调用外部重绘功能
    *************************************************/
    void MoveEntityToTop(Exp_Entity* en);

    /*************************************************
    Function    : 单个命中
    Description : 通过输入的坐标位置和误差以命中单个图元对象
    Input       : 命中点坐标，误差
    Output      :
    Return      : 被命中的图元对象指针
    Note        : 误差参数暂时无效
    *************************************************/
    Exp_Entity* SelectOne(const Exp_Vector& posi, double errorDist);

    /*************************************************
    Function    : 框选命中
    Description : 通过输入的两个点的坐标位置以命中两点形成的矩形中的图元对象
    Input       : 第一框选点坐标，第二框选点坐标
    Output      :
    Return      : 被命中的图元对象指针
    Note        : 输入参数的两点区分先后顺序
    *************************************************/
    QList<Exp_Entity*> SelectWindow(const Exp_Vector& v1, const Exp_Vector& v2);

    /*************************************************
    Function    : 全部选中
    Description : 通过调用此接口将所有可见图元设为选中状态
    Input       :
    Output      :
    Return      : 所有可见的图元对象指针
    Note        : 外部需自行调用Redraw
    *************************************************/
    QList<Exp_Entity*> SelectAll();

    /*************************************************
    Function    : 全部取消选中
    Description : 通过调用此接口将所有可见图元设为未选中状态
    Input       :
    Output      :
    Return      : 所有可见的图元对象指针
    Note        : 外部需自行调用Redraw
    *************************************************/
    QList<Exp_Entity*> DeselectAll();

    /*************************************************
    Function    : 单个获取
    Description : 通过输入的坐标位置获取单个图元对象
    Input       : 命中点坐标
    Output      :
    Return      : 被命中的图元对象指针
    Note        : 仅返回图元指针，不修改其选中状态
    *************************************************/
    Exp_Entity* CatchOne(const Exp_Vector& posi);

    /*************************************************
    Function    : 单个命中(用于底图)
    Description : 用于命中底图上的单个图形
    Input       : center（命中点坐标），errorDist（误差）
    Output      :
    Return      : 被命中的图元对象指针（未命中图形返回nullptr）
    Note        :
    *************************************************/
    Exp_Entity* SelectOneOnBaseMap(const Exp_Vector& center, double errorDist);

    /*************************************************
    Function    : 框选命中(用于底图)
    Description : 通过输入的两个点的坐标位置以命中底图中两点形成的矩形中的图元对象
    Input       : v1(第一框选点坐标)，v2(第二框选点坐标)
    Output      :
    Return      : 被命中的图元对象指针
    Note        : 输入参数的两点区分先后顺序
    *************************************************/
    QList<Exp_Entity*> SelectWindowOnBaseMap(const Exp_Vector& v1, const Exp_Vector& v2);

    /*************************************************
    Function    : 框选命中(用于底图)
    Description : 通过输入的两个点的坐标位置以命中底图中两点形成的矩形中的图元对象
    Input       : v1(第一框选点坐标)，v2(第二框选点坐标)
    Output      :
    Return      : 被命中的图元对象指针
    Note        : 输入参数的两点区分先后顺序
    *************************************************/
    QList<Exp_Entity*> GetAllEntitiesFromBaseMap();

    /*************************************************
    Function    : 填加块图元到块列表中
    Description : 调用此方法创建块图元
    Input       : enList(添加到块中的图元列表), blockName(块名称),
    basicPoint(块的基点）
    Output      :
    Return      : true(添加成功),false(添加失败)
    Note        :
    可添加到块中的图元包括：直线，圆弧，圆，椭圆，样条曲线，多段线，文字，多行文字；
                  生成后块名称会去除其中的空白字符且不可使用空字符串作为块名称，无法添加重复名称的块
    *************************************************/
    bool AddBlockToList(const QVector<Exp_Entity*>& enList, QString blockName,
                        const Exp_Vector& basicPoint);

    /*************************************************
    Function    : 插入图块
    Description : 输入相关参数插入已有的图块到画布终
    Input       : blockName 图块名
                  insertPoint 插入点的位置（图块基点）
                  scaleFactor 缩放比例
                  rotateRadian 旋转角度（弧度值）
    Output      :
    Return      : 图块插入结果，true为插入成功，false为插入失败
    Note        :
    *************************************************/
    bool InsertBlock(QString blockName, Exp_Vector insertPoint, double scaleFactor,
                     double rotateRadian);

    /*************************************************
    Function    : 获取已有图块列表
    Description : 调用此方法获取所有已有的图块名称列表
    Input       :
    Output      :
    Return      : 图块名称列表
    Note        : 创建图块时不允许存在同名图块
                  因此可由图块名称确定唯一的图块
    *************************************************/
    QList<QString> GetAllBlocks();

    /*************************************************
    Function    : 设置不可打散的块的名称标志
    Description : 设置块不可被打散（通过文件导入优化或Explode操作均不能打散）
    Input       : keywords(不可被打散的块名包含的关键字)
    Output      :
    Return      :
    Note        : 如果块名包含keywords，均无法被打散
    *************************************************/
    void SetInseparableBlock(const QString& keywords);

    /*************************************************
    Function    : 标签查找
    Description : 调用此方法获取所有标签内容为指定内容的图元对象
    Input       : 标签字符串
    Output      :
    Return      : 查找到的图元对象指针
    Note        : 未对图元设置标签时默认为空字符串
    *************************************************/
    QList<Exp_Entity*> QueryEntities(QString m_Tag);

    /*************************************************
    Function    : 标签（编号）查找
    Description : 调用此方法获取所有标签内容为指定内容的图元对象
    Input       : 编号
    Output      :
    Return      : 查找到的图元对象指针
    Note        : 未对图元设置标签时默认为0
    *************************************************/
    QList<Exp_Entity*> QueryEntities(long long m_Identity);

    /*************************************************
    Function    : 标签查找
    Description : 调用此方法获取所有标签内容为指定内容的图元对象
    Input       : tag为标签字符串
                  type为标签查找的类型（0或1）
    Output      :
    Return      : 查找到的图元对象指针
    Note        : type为0时，标签查找类型为强等于，即查找到的图元标签必为tag
                  type为1时，标签查找类型为包含，即查找到的图元标签含有tag的内容
    *************************************************/
    QList<Exp_Entity*> QueryEntities(const QString& tag, int type);

    /*************************************************
    Function    : 轮廓查找
    Description : 调用此方法获取所有起点或终点在该图元轮廓上的图元对象
    Input       : 被查图元
    Output      :
    Return      : 查找到的图元对象指针
    Note        :
    *************************************************/
    QList<Exp_Entity*> QueryEntitiesByContour(Exp_Entity* en, bool includeEndP = true,
                                              double toleranceQuery = 1.e-10);

    /*************************************************
    Function    : 链式查找
    Description : 调用此方法获取所有起点或终点
                  在该图元起点或终点上的图元对象
    Input       : 被查图元
    Output      :
    Return      : 查找到的图元对象指针
    Note        :
    *************************************************/
    QList<Exp_Entity*> QueryEntitiesByEndpoint(Exp_Entity* en, double tolerance = 1.e-10);

    /*************************************************
    Function    : 链式查找（起点、终点区分）
    Description : 调用此方法获取所有起点或终点
                  在该图元指定端点上的图元对象
    Input       : en 被查图元
                  findStartP 指定端点
    Output      :
    Return      : 查找到的图元对象指针
    Note        : findStartP为true时，仅查找在该图元起点上的图元
                  findStartP为false时，仅查找在该图元终点上的图元
    *************************************************/
    QList<Exp_Entity*> QueryEntitiesByEndpoint(Exp_Entity* en, bool findStartP,
                                               double tolerance = 1.e-10);

    /*************************************************
    Function    : 移动
    Description : 调用此方法对选中的图元进行移动
    Input       : 参照点坐标，目标点坐标
    Output      :
    Return      : 返回移动后的图元列表
    Note        : 此方法设置的移动可进行撤销重做
    *************************************************/
    QList<Exp_Entity*> Move(const Exp_Vector& referPoint, const Exp_Vector& targetPoint);

    /*************************************************
    Function    : 复制
    Description : 调用此方法对选中的图元进行复制
    Input       : 参照点坐标，目标点坐标
    Output      :
    Return      : 返回复制后的图元列表
    Note        : 此方法设置的复制可进行撤销重做
    *************************************************/
    QList<Exp_Entity*> Copy(const Exp_Vector& referPoint, const Exp_Vector& targetPoint);

    /*************************************************
    Function    : 旋转（中心点+目标点）
    Description : 调用此方法对选中的图元进行旋转
    Input       : 旋转基点坐标，目标点坐标
    Output      :
    Return      : 返回旋转后的图元列表
    Note        : 此方法设置的旋转可进行撤销重做
    *************************************************/
    QList<Exp_Entity*> Rotate(const Exp_Vector& centerPoint, const Exp_Vector& targetPoint);

    /*************************************************
    Function    : 旋转（中心点+旋转角度）
    Description : 调用此方法对选中的图元进行旋转
    Input       : 旋转基点坐标，旋转角度
    Output      :
    Return      : 返回旋转后的图元列表
    Note        :
    此方法设置的旋转可进行撤销重做；输入参数angle为旋转的角度值，而非弧度值
    *************************************************/
    QList<Exp_Entity*> Rotate(const Exp_Vector& centerPoint, const double angle);

    /*************************************************
    Function    : 镜像
    Description : 调用此方法对选中的图元进行镜像
    Input       : 镜像线第一点坐标，镜像线第二点坐标，是否复制（即保留原对象）
    Output      :
    Return      : 返回镜像后的图元列表
    Note        : 此方法设置的镜像可进行撤销重做
    *************************************************/
    QList<Exp_Entity*> Mirror(const Exp_Vector& firstPoint, const Exp_Vector& secondPoint,
                              const bool copy);

    /*************************************************
    Function    : 炸开（分解）
    Description : 调用此方法对选中的复合性图元进行一级分解
    Input       : 是否删除原图元
    Output      :
    Return      : 返回炸开后的图元列表
    Note        : 此方法设置的炸开可进行撤销重做
                  若复合性图元本身由多个复合型图元组成，仅完成一级分解，即子项复合性图元不会被尽数分解
    *************************************************/
    QList<Exp_Entity*> Explode(const bool remove = true);

    /*************************************************
    Function    : 矩形阵列
    Description : 调用此方法对选中图元进行矩形阵列
    Input       : 行数，列数，行偏移距离，列偏移距离，阵列角度
    Output      :
    Return      : 返回阵列后的图元列表
    Note        : 此方法设置的阵列可进行撤销重做
    *************************************************/
    QList<Exp_Entity*> ArrayRectangle(int rows, int cols, double offsetX, double offsetY,
                                      double angle);

    /*************************************************
    Function    : 环形阵列
    Description : 调用此方法对选中图元进行环形阵列
    Input       : 项目总数，填充角度，阵列中心点
    Output      :
    Return      : 返回阵列后的图元列表
    Note        : 此方法设置的阵列可进行撤销重做
    *************************************************/
    QList<Exp_Entity*> ArrayCircle(int num, int fillAngle, const Exp_Vector& center);

    /*************************************************
    Function    : 缩放
    Description : 调用此方法对图元设置缩放
    Input       : 参照点（缩放方向）坐标，缩放比例因子
    Output      :
    Return      : 返回缩放后的图元列表
    Note        : 此方法设置的缩放可进行撤销重做
    *************************************************/
    QList<Exp_Entity*> Scale(Exp_Vector refPoint, double scaleFactor);

    /*************************************************
    Function    : 偏移
    Description : 调用此方法对图元设置偏移
    Input       : 参照点（偏移方向）坐标，偏移距离
    Output      :
    Return      : 返回偏移后的图元列表
    Note        : 此方法设置的偏移可进行撤销重做
    *************************************************/
    QList<Exp_Entity*> Offset(Exp_Vector position, double offsetDistance);

    /*************************************************
    Function    : 获取两个原子图形的交点
    Description :
    Input       : 图形1，图形2
    Output      :
    Return      : 所有交点的集合
    Note        :
    *************************************************/
    QVector<Exp_Vector> GetIntersection(Exp_AtomicEntity * e1,Exp_AtomicEntity* e2);

    /*************************************************
    Function    : 获取原子图元和多段线的交点
    Description :
    Input       : 原子图元e1，多段线pl
    Output      :
    Return      : 所有交点的集合
    Note        :
    *************************************************/
    QVector<Exp_Vector> GetIntersectionAtomicPolyline(Exp_AtomicEntity* e1, Exp_Polyline* pl);

    /*************************************************
    Function    : 将输入的图形合并为一条多段线
    Description :
    Input       : 多段线的子图元
    Output      :
    Return      : 多段线
    Note        :
    *************************************************/
    Exp_Polyline* JoinToPolyline(const QList<Exp_Entity*>& entities,
                                 bool mustSelect = true);

    /*************************************************
    Function    : 组合为块
    Description : 将给定图元中首尾相连的图元组合为块
    Input       : sourceEns为图元的集合，insertName为新块的名称
    Output      :
    Return      : 组合结果，仅当返回值为0时组合成功
    Note        : 块名必须不为空，且为块列表中不存在的名称，否则组合失败
                  成功组合后，可通过Exp_Insert的CreateInsert方法构建独立的块图元对象
    *************************************************/
    int JoinToInsertByETS(const QVector<Exp_Entity*> sourceEns, QVector<Exp_Entity*>& realInsertEns, const QString insertName, Exp_Vector& newStart);

    /*************************************************
    Function    : 向多段线添加节点
    Description :
    Input       : pl:原多段线
                  v:待添加的节点位置
    Output      :
    Return      : 添加节点后的多段线
    Note        :
    *************************************************/
    Exp_Polyline* AddNodeToPolyline(Exp_Polyline *pl,
                                    Exp_Vector v);

    /*************************************************
    Function    : 向多段线删除节点
    Description :
    Input       : pl:原多段线
                  v:待删除的节点位置
    Output      :
    Return      : 删除节点后的多段线
    Note        :
    *************************************************/
    Exp_Polyline* RemoveNodeFromPolyline(Exp_Polyline *pl,
                                         Exp_Vector v);

    /*************************************************
    Function    : 曲线测量
    Description :
    Input       : entity:待测图元，sp:图元上的测量起点，ep:图元上的测量终点
                  isCW:测量方向（仅针对封闭图元时有效）
    Output      :
    Return      : 测量结果，返回负数表示测量失败
    Note        :
    *************************************************/
    double CurvyMeasure(Exp_Entity* entity,
                        Exp_Vector sp, Exp_Vector ep,
                        bool isCW = false);

    /*************************************************
    Function    : DataStream导出
    Description : 将图元数据以文件形式导出
    Input       : fileName:文件名
                  tag:标识
                  ver:版本号
                  entities:待导出数据的图元对象
    Output      :
    Return      : 导出是否成功
    Note        :
    *************************************************/
    //bool ExportEntitiesDataStream(const QString& fileName, const QString& tag, const int& ver,
    //                              const QVector<Exp_Entity*>& entities);

    /*************************************************
    Function    : DataStream导入
    Description : 将文件中暂存的图元数据转换为图元对象
    Input       : fileName:文件名
    Output      : tag:标识
                  ver:版本号
                  entities:转换后的图元对象
    Return      : 导入结果
    Note        :
    *************************************************/
    //bool ImportEntitiesDataStream(const QString& fileName, QString& tag, int& ver,
    //                              QVector<Exp_Entity*>& entities);

    /*************************************************
    Function    : 获取当前文件名
    Description :
    Input       :
    Output      : 文件名
    Return      :
    Note        : 当前不存在正常打开的文件时返回空字符串
    *************************************************/
    QString GetFileName();

    /*************************************************
    Function    : 获取第index个文件名
    Description :
    Input       :
    Output      : 文件名
    Return      :
    Note        : 多文件时使用，当前不存在正常打开的文件时返回空字符串
    *************************************************/
    QString GetFileNameAt(const int& index);

    /*************************************************
    Function    : 打开文件
    Description : 通过给定文件名及其类型实现文件打开
    Input       : fileName为文件名，type为文件类型
    Output      :
    Return      :
    Note        :
    *************************************************/
    void FileOpen(const QString& fileName, RS2::FormatType type = RS2::FormatDXFRW);

    /*************************************************
    Function    : 文件另存为
    Description : 通过给定文件名及其类型实现文件另存为
    Input       : fileName为文件名，type为文件类型
    Output      :
    Return      :
    Note        :
    *************************************************/
    void FileSaveAs(const QString& fileName, RS2::FormatType type = RS2::FormatDXFRW);

    /*************************************************
    Function    : 新建文件
    Description : 关闭当前文件，新建空文件
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    void FileNew();

    /*************************************************
    Function    : 强制新建文件
    Description : 不关闭当前文件，无视是否启用多文件，强制多文件新建空文件
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    void ForceFileNew();

    /*************************************************
    Function    : 设置可解析的Dxf文件版本上限
    Description :
    Input       : 版本上限
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetLatestDxfVer(EmValidDxfVer latestVer);

    /*************************************************
    Function    : 获取可解析的Dxf文件版本上限
    Description :
    Input       :
    Output      :
    Return      : 版本上限
    Note        : 默认为AC1027
    *************************************************/
    EmValidDxfVer GetLatestDxfVer();

    /*************************************************
    Function    : 设置Dxf文件的空间过滤模式
    Description :
    Input       : 过滤模式
    Output      :
    Return      :
    Note        : 0为不过滤，1为过滤布局空间，2为过滤模型空间
    *************************************************/
    void SetDxfSpaceFilterMode(int mode);

    /*************************************************
    Function    : 获取当前Dxf文件的空间过滤模式
    Description :
    Input       :
    Output      :
    Return      : 过滤模式
    Note        : 0为不过滤，1为过滤布局空间，2为过滤模型空间
    *************************************************/
    int GetDxfSpaceFilterMode();

    /*************************************************
    Function    : 设置Dxf解析是否拉伸
    Description : 设置Dxf中210、220、230的拉伸参数是否参与到点位的实际解析过程中
    Input       : 是否拉伸
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetParseDxfExt(bool isExt);

    /*************************************************
    Function    : 获取Dxf解析是否拉伸
    Description : 获取Dxf中210、220、230的拉伸参数是否参与到点位的实际解析过程中
    Input       :
    Output      :
    Return      : 是否拉伸
    Note        : 默认为参与解析
    *************************************************/
    bool GetParseDxfExt();

    /*************************************************
    Function    : 设置Dxf解析样条曲线权重是否有效
    Description :
    Input       : isValid:是否有效,err:误差
    Output      :
    Return      :
    Note        : 默认为false
    *************************************************/
    void SetWeightValidInSpl(bool isValid, double err = 0.001);

    /*************************************************
    Function    : 获取Dxf解析样条曲线权重是否有效
    Description :
    Input       :
    Output      :
    Return      : 是否有效
    Note        :
    *************************************************/
    bool GetWeightValidInSpl();

    /*************************************************
    Function    : 设置Dxf解析是否修改字体文件，强制解析中文
    Description : 设置Dxf中是否强制修改字体文件，以此解析中文并显示
    Input       : 是否修改字体文件
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetParseChinese(bool isChinese);

    /*************************************************
    Function    : 获取Dxf解析是否修改字体文件，强制解析中文
    Description : 获取Dxf中是否强制修改字体文件，以此解析中文并显示
    Input       :
    Output      :
    Return      : 是否修改字体文件
    Note        : 默认为修改字体
    *************************************************/
    bool GetParseChinese();

    /*************************************************
    Function    : 获取前处理function
    Description : 获取文件打开时优化处理执行的前处理的function
    Input       :
    Output      :
    Return      : function
    Note        : 获取function后外部实现
    *************************************************/
    std::function<QList<Exp_Entity*>(const QList<Exp_Entity*>&)>& GetOptimizePreFunc();

    /*************************************************
    Function    : 获取后处理function
    Description : 获取文件打开时优化处理执行的后处理的function
    Input       :
    Output      :
    Return      : function
    Note        : 获取function后外部实现
    *************************************************/
    std::function<QList<Exp_Entity*>(const QList<Exp_Entity*>&)>& GetOptimizePostFunc();

    /*************************************************
    Function    : 获取文件打开后function
    Description : 文件打开后调用此function
    Input       :
    Output      :
    Return      : function
    Note        : 获取function后外部实现
    *************************************************/
    std::function<void(void)> &GetAfterOpenFunc();

    /*************************************************
    Function    : 获取当前二进制文件保存的格式
    Description :
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    QString GetBinaryNameFilter();

    /*************************************************
    Function    : 设置二进制文件保存的格式
    Description :
    Input       : fBin(二进制文件保存格式)
    Output      :
    Return      :
    Note        : 示例："My Binary File (*.mbf)”
    *************************************************/
    void SetBinaryNameFilter(const QString& fBin);

    /*************************************************
    Function    : 设置文件导入过滤器
    Description : 文件导入时由外部进行处理（详见IExp_FilterImport.h）
    Input       : filter过滤器
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetFilterImport(const std::shared_ptr<IExp_FilterImport>& filter);

    /*************************************************
    Function    : 设置序列化工具
    Description : 调用此方法提供ICAMData的序列化和反序列化方法
    Input       : seriral(提供ICAMData序列化和反序列化方法的类）
    Output      :
    Return      :
    Note        : 若CAM数据需要保存，需实现此部分功能
    *************************************************/
    void SetSerializeTool(const std::shared_ptr<IExp_Serialize>& serial);

    /*************************************************
    Function    : 设置捕捉状态
    Description : 调用此方法设置当前捕捉模式是否启用
    Input       : 是否启用
    Output      :
    Return      :
    Note        : 不带撤销重做功能
    *************************************************/
    void SetSnapOpen(bool open);

    /*************************************************
    Function    : 获取捕捉状态
    Description : 调用此方法获取当前捕捉功能是否启用
    Input       :
    Output      :
    Return      : 是否启用
    Note        :
    *************************************************/
    bool GetSnapOpen();

    /*************************************************
    Function    : 设置捕捉模式
    Description : 调用此方法设置当前具体生效的捕捉模式
    Input       : 捕捉模式
    Output      :
    Return      :
    Note        : 不带撤销重做功能
    *************************************************/
    void SetSnapMode(Exp_SnapMode mSnapMode);

    /*************************************************
    Function    : 获取捕捉模式
    Description : 调用此方法获取当前具体生效的捕捉模式
    Input       :
    Output      :
    Return      : 捕捉模式
    Note        :
    *************************************************/
    Exp_SnapMode GetSnapMode();

    /*************************************************
    Function    : 设置是否捕捉椭圆的两个焦点
    Description :
    Input       : isSnap:true 捕捉;false 不捕捉
    Output      :
    Return      :
    Note        : CADLab默认为捕捉
    *************************************************/
    void SetIsSnapEllipseFoci(const bool& isSnap);

    /*************************************************
    Function    : 设置正交捕捉是否按照正交获取最近点
    Description :
    Input       : isGetNearest:true 是;false 否
    Output      :
    Return      :
    Note        : CADLab默认为否
    *************************************************/
    void SetSnapOrthogonalCanGetNearestP(const bool& isGetNearest);

    /*************************************************
    Function    : 获取捕捉点
    Description : 调用此方法获取当前鼠标事件所实际捕捉的点位
    Input       : 鼠标事件（鼠标当前位置）
    Output      :
    Return      : 捕捉到的点
    Note        : 当未捕捉到实际点位时，返回值坐标即为鼠标当前坐标
    *************************************************/
    Exp_Vector GetSnapPoint(QMouseEvent* e);

    /*************************************************
    Function    : 自动缩放
    Description : 调用此方法自动设置画布的绘制比例
    Input       :
    Output      :
    Return      :
    Note        :
    重新计算所有图形的外边框，修改画布的缩放比例和偏移，使所有图形正好处于可见范围
    *************************************************/
    void ZoomAuto();

    /*************************************************
    Function    : 视图平移
    Description : 调用此方法设置当前画布视图平移
    Input       : dx：x方向的移动量； dy：y方向的移动量
    Output      :
    Return      :
    Note        :
    *************************************************/
    void ZoomPan(int dx, int dy);

    /*************************************************
    Function    : 窗口缩放
    Description : 将给定两个角点组成的矩形框内的图形自动缩放至窗口大小
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    void ZoomWindow(const Exp_Vector& v1, const Exp_Vector& v2);

    /*************************************************
    Function    : 切换至自定义的Action
    Description : 继承Exp_ActionInterface创建自定义Action，切换至自定义的Action
    Input       : action(外部自定义Action)
    Output      :
    Return      :
    Note        : 输入的内存由内部进行管理，外部无需释放
    *************************************************/
    void SetCurrentAction(IExp_ActionInterface* action);

    /*************************************************
    Function    : 设置默认Action
    Description : 继承Exp_ActionInterface创建自定义Action，并将系统默认Action设置为自定义的Action
    Input       : action(外部自定义Action)
    Output      :
    Return      :
    Note        : 输入的内存由内部进行管理，外部无需释放
    *************************************************/
    void SetDefaultAction(IExp_ActionInterface* action);

    /*************************************************
    Function    : 恢复默认Action
    Description : 将默认Action恢复为CADLab原始的默认Action
    Input       : action(外部自定义Action)
    Output      :
    Return      :
    Note        : 输入的内存由内部进行管理，外部无需释放
    *************************************************/
    void ResetDefaultAction();

    /*************************************************
    Function    : 切换到一个空Action中
    Description : 切换到空Action中，用于外部利用CADLab的鼠标事件信号
    Input       : action(外部自定义Action)
    Output      :
    Return      :
    Note        :
    *************************************************/
    void JumpToEmptyAction();

    /*************************************************
    Function    : 结束所有Action
    Description : 结束所有Action并切换回DefaultAction
    Input       :
    Output      :
    Return      :
    Note        : 调用此接口用于结束自定义的Action(IExp_ActionInterface)
    *************************************************/
    void KillAllActions();

    /*************************************************
    Function    : 获取当前Action类型
    Description :
    Input       :
    Output      :
    Return      : 当前Action类型
    Note        :
    *************************************************/
    RS2::ActionType GetCurrentActionType();

    /*************************************************
    Function    : 设置GlobalCAMData
    Description : 设置全局的CAMData用于做全局的绘制
    Input       : 全局的CAMData
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetGlobalCAMData(const std::shared_ptr<IGlobalCAMData>& camData);

    /*************************************************
    Function    : 获取当前的GlobalCAMData
    Description : 获取当前全局正在使用的CAMData
    Input       :
    Output      :
    Return      : 当前正在使用的CAMData
    Note        :
    *************************************************/
    std::shared_ptr<IGlobalCAMData> GetGlobalCAMData();

    /*************************************************
    Function    : 获取构造图元时是否初始化CAMData的状态
    Description :
    Input       :
    Output      :
    Return      : 是否初始化CAMData
    Note        :
    *************************************************/
    bool GetIsInitCAMData();

    /*************************************************
    Function    : 设置构造图元时是否初始化CAMData的状态
    Description :
    Input       : 是否初始化CAMData
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetIsInitCAMData(const bool& isInitCAMData);

    /*************************************************
    Function    : 获取构造图元时初始化CAMData的对象
    Description :
    Input       :
    Output      :
    Return      : 初始化CAMData对象
    Note        :
    *************************************************/
    const std::shared_ptr<ICAMData>& GetInitCAMData();

    /*************************************************
    Function    : 设置构造图元时初始化CAMData的对象
    Description :
    Input       : 初始化CAMData对象
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetInitCAMData(const std::shared_ptr<ICAMData>& initCAMData);

    /*************************************************
    Function    : 设置排序算法,更新界面上所有图形的序号
    Description : 传入IExp_Sortable的子类作为当前排序算法
    Input       : IExp_Sortable的子类
    Output      :
    Return      :
    Note        :
    调用此方法使用给定排序算法中的序号对当前界面上显示的图形进行排序，
                  此操作支持撤销重做，调用后之前获取的图形失效，需重新获取
    *************************************************/
    void SetSortAlgo(IExp_Sortable* algo);

    /*************************************************
    Function    : 设置导入优化算法,更新文件导入策略
    Description : 传入IExp_ImportOptimize的子类作为当前优化算法
    Input       : IExp_ImportOptimize的子类
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetImportOptimizeAlgo(IExp_ImportOptimize* algo);

    /*************************************************
    Function    : 添加排样结果用于显示
    Description : 外部将排样结果传入，在排样列表中显示排样结果
    Input       : entities(每张板材上的图元),plateSize(板材的尺寸),
    Output      :
    Return      :
    Note        : 输入的Exp_Entity由外部释放
    *************************************************/
    void AddNestingResult(const QVector<QVector<Exp_Entity*> >& entities,
                          const Exp_Vector& plateSize);

    /*************************************************
    Function    : 获取零件列表中的所有零件
    Description :
    Input       :
    Output      :
    Return      : 零件列表中的所有零件
    Note        : Exp_Component中的Exp_Entity由外部释放
    *************************************************/
    QVector<Exp_Component> GetAllComponent();

    /*************************************************
    Function    : 获取零件列表中的选中的零件
    Description :
    Input       :
    Output      :
    Return      : 零件列表中选中的所有零件
    Note        : Exp_Component中的Exp_Entity由外部释放
    *************************************************/
    QVector<Exp_Component> GetSelectedComponent();

    /*************************************************
    Function    : 添加零件到零件库
    Description :
    Input       : comp(零件)
    Output      :
    Return      : true:添加成功， false:添加失败（存在同名零件）
    Note        : 请勿将界面中的图形直接添加到零件库，可通过Clone或Create方法创建图元
                  comp中的Exp_Entity由外部释放
    *************************************************/
    bool AddCompont(Exp_Component comp);

    /*************************************************
    Function    : 设置是否显示线宽
    Description :
    Input       : 是否显示
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetLineWidthShow(const bool show);

    /*************************************************
    Function    : 获取拖动图元后处理function
    Description : 获取拖动图元后执行的后处理的function
    Input       :
    Output      :
    Return      : function
    Note        : 该function需要获取之后外部实现
    *************************************************/
    std::function<void(void)>& GetAfterMoveByDragFunc();

    /*************************************************
    Function    : 设置序号的绘制模式
    Description :
    Input       : mode:序号的绘制模式
    Output      :
    Return      :
    Note        : mode:0默认绘制模式，1绘制在图元中心
    *************************************************/
    void SetDrawSerialNumMode(int mode);

    /*************************************************
    Function    : 获取拖动图元顶点后处理function
    Description : 获取拖动图元顶点后执行的后处理的function
    Input       :
    Output      :
    Return      : function
    Note        : 该function需要获取之后外部实现
    *************************************************/
    std::function<void(void)>& GetAfterMoveRefByDragFunc();

    /*************************************************
    Function    : 设置图元是否可以被拖拽
    Description :
    Input       : canBeMove:是否可以被拖拽
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetEntityCanBeDrag(bool canBeMove);

    /*************************************************
    Function    : 设置图元顶点是否可以被拖拽
    Description :
    Input       : canBeMove:是否可以被拖拽
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetEntityRefCanBeDrag(bool canBeMove);

    /*************************************************
    Function    : 计算定数等分点
    Description :
    Input       : entity:被定数等分的图元,segNum:段数
    Output      : res:计算出的点位结果
    Return      : 当返回值为true时计算成功
    Note        : 支持直线、圆弧、圆、多段线
    *************************************************/
    bool CalcDivideOnEntity(const Exp_Entity* entity, const int segNum, QVector<Exp_Vector>& res);

    /*************************************************
    Function    : 计算定距等分点
    Description :
    Input       : entity:被定数等分的图元,segLenth:每段的长度
    Output      : res:计算出的点位结果
    Return      : 当返回值为true时计算成功
    Note        : 支持直线、圆弧、圆、多段线,通过每段长度计算出的段数大于INT16_MAX时返回false
    *************************************************/
    bool CalcMeasureOnEntity(const Exp_Entity* entity, const double segLenth, QVector<Exp_Vector>& res, const Exp_Vector checkPoint, const double startOffset = .0f);

    /*************************************************
    Function    : 设置内部Action的触发方式
    Description :
    Input       : actionType:被替换的ActionType,func:替换的目标触发function
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetActionToExternalAction(const RS2::ActionType& actionType, const std::function<void(void)>& func);

    /*************************************************
    Function    : 设置内部命令行的触发方式
    Description :
    Input       : cmd:被替换的命令,func:替换的目标触发function
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetCmdToExternalAction(const QString& cmd, const std::function<void(void)>& func);

    /*************************************************
    Function    : 重置内部Action的触发
    Description :
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    void ResetActionToExternal();

    /*************************************************
    Function    : 重置内部Action的触发
    Description :
    Input       : actionType:被重置的ActionType
    Output      :
    Return      :
    Note        :
    *************************************************/
    void ResetActionToExternal(const RS2::ActionType& actionType);

    /*************************************************
    Function    : 重置内部命令行的触发
    Description :
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    void ResetCmdToExternal();

    /*************************************************
    Function    : 重置内部命令行的触发
    Description :
    Input       : cmd:被重置的命令
    Output      :
    Return      :
    Note        :
    *************************************************/
    void ResetCmdToExternal(const QString& cmd);

    /*************************************************
    Function    : 获取缩放前的function
    Description : 获取缩放前执行的function
    Input       :
    Output      :
    Return      : function
    Note        : 该function需要获取之后外部实现，
                  实现的function返回true时正常执行action，
                  返回false时不再执行scale的action
    *************************************************/
    std::function<bool(const QList<Exp_Entity*>&)>& GetBeforeModifyScaleFunc();

    /*************************************************
    Function    : 获取镜像前的function
    Description : 获取镜像前执行的function
    Input       :
    Output      :
    Return      : function
    Note        : 该function需要获取之后外部实现，
                  实现的function返回true时正常执行action，
                  返回false时不再执行mirror的action
    *************************************************/
    std::function<bool(const QList<Exp_Entity*>&)>& GetBeforeModifyMirrorFunc();

    /*************************************************
    Function    : 设置导入文件时是否打散块
    Description :
    Input       : isExplode:导入文件是否打散块，true为打散，false为不打散
    Output      :
    Return      :
    Note        : 用于设置导入配置中是否勾选该选项
    *************************************************/
    void SetAutoExplode(const bool isExplode);

    /*************************************************
    Function    : 设置导入文件时是否删除小图形
    Description :
    Input       : isDelete:导入文件是否删除小图形，true为删除，false为不删除
                  lessThan:小于多少的图形将被删除
    Output      :
    Return      :
    Note        : 用于设置导入配置中是否勾选该选项
    *************************************************/
    void SetDeleteInvisible(const bool isDelete, const double lessThan = .0f);

    /*************************************************
    Function    : 设置导入文件时是否删除标注
    Description :
    Input       : isDelete:导入文件是否删除标注，true为删除，false为不删除
    Output      :
    Return      :
    Note        : 用于设置导入配置中是否勾选该选项
    *************************************************/
    void SetDeleteDimension(const bool isDelete);

    /*************************************************
    Function    : 设置导入文件时是否删除完全相同的图形
    Description :
    Input       : isDelete:导入文件删除完全相同的图形，true为删除，false为不删除
    Output      :
    Return      :
    Note        : 用于设置导入配置中是否勾选该选项
    *************************************************/
    void SetDeleteDuplicate(const bool isDelete);

    /*************************************************
    Function    : 设置导入文件时是否使用去重
    Description :
    Input       : isUse:导入文件是否使用去重，true为使用，false为不使用
                  err:算法的误差，不允许小于等于0
    Output      :
    Return      :
    Note        : 用于设置导入配置中是否勾选该选项
    *************************************************/
    void SetUseOverKill(const bool isUse, const double err = 0.1);

    /*************************************************
    Function    : 禁用快捷键或按键
    Description :
    Input       : shortcut: 需要禁用的快捷键
    Output      :
    Return      :
    Note        : 使用该接口禁用的qshortcut无法被启用
    *************************************************/
    void DisableTargetShortcut(QShortcut* shortcut);

    /*************************************************
    Function    : 通过keyCode禁用快捷键
    Description :
    Input       : keyCode: 需要禁用的快捷键
    Output      :
    Return      :
    Note        :
    *************************************************/
    void DisableTargetShortcut(const QKeySequence keyCode);

    /*************************************************
    Function    : 通过keyCode启用快捷键
    Description :
    Input       : keyCode: 需要启用的快捷键
    Output      :
    Return      :
    Note        :
    *************************************************/
    void EnableTargetShortcut(const QKeySequence keyCode);

    /*************************************************
    Function    : 设置启用/禁用所有快捷键
    Description :
    Input       : isEnable: 为false时禁用
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetIsEnableAllShortCut(const bool &isEnable);

    /*************************************************
    Function    : 设置判断椭圆弧的误差
    Description :
    Input       : tolerance: 误差
    Output      :
    Return      :
    Note        : 默认误差为1.0e-8
    *************************************************/
    void SetEllipticArcTolerance(double tolerance);

    /*************************************************
    Function    : 获取当前活跃的文件
    Description :
    Input       :
    Output      :
    Return      : 当前活跃的文件
    Note        :
    *************************************************/
    QString GetCurrentFileName();

    /*************************************************
    Function    : 获取矩形区域内的首尾相连的无交叉封闭图形
    Description :
    Input       : 矩形区域的角点v1和v2，是否查找与矩形区域相交的图元cross
    Output      :
    Return      : 查找的结果
    Note        : 返回值是一个QVector<QVector<Exp_Entity*>>，
                  外层QVector存储有n个首尾相连的图形，内层QVector存储每个首尾相连的图形的图元
    *************************************************/
    QVector<QVector<Exp_Entity*>> GetETSClosedInWindow(const Exp_Vector& v1, const Exp_Vector& v2,
                                                       bool cross = true);

    /*************************************************
    Function    : 设置是否允许按空格返回上一次执行的Action
    Description :
    Input       : 是否允许返回上一次执行的Action
    Output      :
    Return      :
    Note        : 默认为true
    *************************************************/
    void SetCouldBackLastAction(const bool& couldBack);

    /*************************************************
    Function    : 设置是否启用CADLab多文件处理
    Description :
    Input       : allowed，是否启用CADLab多文件处理
    Output      :
    Return      :
    Note        : 默认为false，单文件
    *************************************************/
    void SetIsAllowMultiple(const bool& allowed);

    /*************************************************
    Function    : 设置读取文件时是否设置文本图元为特殊绘制
    Description :
    Input       : isSpecial:true,特殊绘制;false,正常绘制
    Output      :
    Return      :
    Note        : 特殊绘制即使用QPainter进行绘制，CADLab默认为false
    *************************************************/
    void SetSpecialParseText(const bool& isSpecial);

    /*************************************************
    Function    : 设置文本图元是否始终为特殊绘制
    Description :
    Input       : isSpecial:true,特殊绘制;false,正常绘制
    Output      :
    Return      :
    Note        : 特殊绘制即使用QPainter进行绘制，CADLab默认为false
    *************************************************/
    void SetAlwaysSpecialDrawText(const bool& isSpecial);

    /*************************************************
    Function    : 清除命令行的焦点
    Description :
    Input       :
    Output      :
    Return      :
    Note        : 清除命令行的焦点并将焦点设置回画布
    *************************************************/
    void ClearCommandFocus();

    /*************************************************
    Function    : 设置是否启用命令行自动补全
    Description :
    Input       : use:true为启用，false为禁用
    Output      :
    Return      :
    Note        : 默认启用
    *************************************************/
    void SetUseCompleter(const bool& use);

    /*************************************************
    Function    : 设置命令行是否显示历史命令按钮
    Description :
    Input       : use:true为显示，false为隐藏
    Output      :
    Return      :
    Note        : 默认显示
    *************************************************/
    void SetCommandHistoryShow(const bool& show);

    /*************************************************
    Function    : 设置序号的显示颜色
    Description :
    Input       : color序号的显示颜色
    Output      :
    Return      :
    Note        : 默认颜色为ColorWhite
    *************************************************/
    void SetSerialNumColor(const RS2::LineColor& color);

    //! 注释待补充
    //! 设置多文件显示形式
    void SetMultipleDisplayMode(const int mode);

    //! 注释待补充
    //! 设置是否自动关闭空文件和未修改的文件
    void SetAutoCloseEmptyFile(const bool autoClose);

    //! 注释待补充
    //! 设置画布的文件名
    void SetDocName(QWidget* graphicView, const QString docName);

    //! 注释待补充
    //! 是否启用动态输入,仅供测试，不要使用
    void SetUseDynamicInput(const bool& use);

    //! 注释待补充
    //! 从其他dxf获取图元，未测试
    QVector<Exp_Entity*> GetEntitiesByDxf(const QString& filePath, bool asInsert);
};

#endif  // EXP_MANAGEMENT_H
