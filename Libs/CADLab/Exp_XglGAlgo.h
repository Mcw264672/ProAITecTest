#ifndef EXP_XGLGALGO_H
#define EXP_XGLGALGO_H

#include <QVariant>
#include <QVector>
#include "CADLab_global.h"
#ifdef CADLab_LIBRARY
#include "lib/engine/rs.h"
#else
#include "rs.h"
#endif

class Exp_Vector;
class Exp_Entity;
class Exp_AtomicEntity;
class Exp_EntityContainer;
class Exp_Point;
class Exp_Line;
class Exp_Arc;
class Exp_Circle;
class Exp_Ellipse;
class Exp_Polyline;
class Exp_Spline;
struct AlgoEntity;

#define Exp_GAlgo Exp_XglGAlgo::Instance()
class CADLab_EXPORT Exp_XglGAlgo
{
    Exp_XglGAlgo() = default;
public:
    static Exp_XglGAlgo& Instance();
    Exp_XglGAlgo(Exp_XglGAlgo const &) = delete;
    void operator=(Exp_XglGAlgo const &) = delete;

    void CerealToAlgoEntity(QVector<Exp_Entity*> expEns);

    Exp_Entity* TransTest(const Exp_Entity*);

    /*************************************************
    Function    : 获取版本号
    Description : 获取Xgl-GAlgo图形算法库的当前版本号
    Input       :
    Output      :
    Return      : 版本号
    Note        :
    *************************************************/
    std::string GetGAlgoVer() const;

    /*************************************************
    Function    : 图形转换接口
    Description : 将CAD的Exp_Entity转换为AlgoEntity（适用于算法库调用）
    Input       : expEns待转换的Exp_Entity的容器
    Output      : agEns转换结果
    Return      : 仅当返回值为0时表示转换成功
    Note        :
    *************************************************/
    int EXPEns2AGEns(const QVector<Exp_Entity*>& expEns, QVector<AlgoEntity>& agEns);

    /*************************************************
    Function    : 图形转换接口
    Description : 将算法库的AlgoEntity转换为CAD的Exp_Entity（适用于算法库调用）
    Input       : agEns待转换的AlgoEntity的容器
    Output      : expEns转换结果
    Return      : 仅当返回值为0时表示转换成功
    Note        :
    *************************************************/
    int AGEns2EXPEns(const QVector<AlgoEntity>& agEns, QVector<Exp_Entity*>& expEns);

    /*************************************************
    Function    : 图形转换接口
    Description : 将CAD的各类Exp_Entity转换为算法库的AlgoEntity（适用于算法库调用）
    Input       : curId为AlgoEntity的自定义ID
    Output      :
    Return      : 仅当返回值为0时表示转换成功
    Note        :
    *************************************************/
    int EXPPoint2AGPoint(const Exp_Point* rsPoint, AlgoEntity& agPoint, int curId = 0);
    int EXPLine2AGLine(const Exp_Line* rsLine, AlgoEntity& agLine, int curId = 0);
    int EXPArc2AGArc(const Exp_Arc* rsArc, AlgoEntity& agArc, int curId = 0);
    int EXPCir2AGCir(const Exp_Circle* rsCir, AlgoEntity& agCir, int curId = 0);
    int EXPElli2AGElli(const Exp_Ellipse* rsElli, AlgoEntity& agElli, int curId = 0);
    int EXPPline2AGPline(const Exp_Polyline* rsPline, AlgoEntity& agPline, int curId = 0);
    int EXPSpl2AGSpl(const Exp_Spline* rsSpl, AlgoEntity& agSpl, int curId = 0);

    /*************************************************
    Function    : 图形转换接口
    Description : 将算法库的AlgoEntity转换为CAD的各类Exp_Entity（适用于算法库调用）
    Input       :
    Output      :
    Return      : 仅当返回值为0时表示转换成功
    Note        :
    *************************************************/
    int AGPoint2EXPPoint(const AlgoEntity& agPoint, Exp_Point*& expPoint);
    int AGLine2EXPLine(const AlgoEntity& agLine, Exp_Line*& expLine);
    int AGArc2EXPArc(const AlgoEntity& agArc, Exp_Arc*& expArc);
    int AGCir2EXPCir(const AlgoEntity& agCir, Exp_Circle*& expCir);
    int AGElli2EXPElli(const AlgoEntity& agElli, Exp_Ellipse*& expElli);
    int AGPline2EXPPline(const AlgoEntity& agPline, Exp_Polyline*& expPline);
    int AGSpl2EXPSpl(const AlgoEntity& agSpl, Exp_Spline*& expSpl);

    /*************************************************
    Function    : 计算图元之间的交点
    Description :
    Input       : 图元的集合
    Output      : 交点的集合
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示交点计算成功
    *************************************************/
    int GetIntersection(const QVector<Exp_Entity*>& entities, QVector<Exp_Vector>& points, double err = 1e-4);

    /*************************************************
    Function    : 直线分割
    Description : 根据一点坐标，将直线进行分割处理
    Input       : line:直线，p:坐标
    Output      : result:分割后的图元结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示分割处理成功
    *************************************************/
    int SplitLine(const Exp_Line* line, const Exp_Vector& p, QVector<Exp_Line*>& result);

    /*************************************************
    Function    : 圆弧分割
    Description : 根据一点坐标，将圆弧进行分割处理
    Input       : arc:圆弧，p:坐标
    Output      : result:分割后的图元结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示分割处理成功
    *************************************************/
    int SplitArc(const Exp_Arc* arc, const Exp_Vector& p, QVector<Exp_Arc*>& result);

    /*************************************************
    Function    : 圆弧分割
    Description : 根据两点坐标，将圆进行分割处理
    Input       : circle:圆，p1:坐标1，p2:坐标2
    Output      : result:分割后的图元结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示分割处理成功
    *************************************************/
    int SplitCircle(const Exp_Circle* circle, const Exp_Vector& p1, const Exp_Vector& p2, QVector<Exp_Arc*>& result);

    /*************************************************
    Function    : 椭圆分割
    Description : 根据两点坐标，将椭圆进行分割处理
    Input       : ellipse:椭圆，p1:坐标1，p2:坐标2
    Output      : result:分割后的图元结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示分割处理成功
    *************************************************/
    int SplitEllipse(const Exp_Ellipse* ellipse, const Exp_Vector& p1, const Exp_Vector& p2, QVector<Exp_Ellipse*>& result);

    /*************************************************
    Function    : 椭圆弧分割
    Description : 根据一点坐标，将椭圆弧进行分割处理
    Input       : ellipse:椭圆，p:坐标
    Output      : result:分割后的图元结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示分割处理成功，需提前判定Ellipse是否为椭圆弧
    *************************************************/
    int SplitEllipticArc(const Exp_Ellipse* ellipse, const Exp_Vector& p, QVector<Exp_Ellipse*>& result);

    /*************************************************
    Function    : 多段线分割
    Description : 根据两点坐标，将多段线进行分割处理
    Input       : polyline:多段线，p1:坐标1，p2:坐标2
    Output      : result:分割后的图元结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示分割处理成功，若内部判定多段线为封闭图元时，p2不发挥作用
    *************************************************/
    int SplitPolyline(const Exp_Polyline* polyline, const Exp_Vector& p1, const Exp_Vector& p2, QVector<Exp_Polyline*>& result);

    /*************************************************
    Function    : 样条曲线分割
    Description : 根据两点坐标，将样条曲线进行分割处理
    Input       : spline:样条曲线，p1:坐标1，p2:坐标2
    Output      : result:分割后的图元结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示分割处理成功，若内部判定样条曲线为封闭图元时，p2不发挥作用
    *************************************************/
    int SplitSpline(const Exp_Spline* spline, const Exp_Vector& p1, const Exp_Vector& p2, QVector<Exp_Spline*>& result);


    /*************************************************
    Function    : 获取最近最远点
    Description : 根据一点坐标，计算图元轮廓上距离该点最近或最远点的坐标
    Input       : graph:图元，p:坐标，closest:求最近点
    Output      : result:分割后的图元结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int GetNearestPointOnEntity(const Exp_Entity* graph, const Exp_Vector&p, QVector<Exp_Vector>& result, bool closest = true);

    /*************************************************
    Function    : 获取直线的最近最远点
    Description : 根据一点坐标，计算图元轮廓上距离该点最近或最远点的坐标
    Input       : line:直线，p:坐标，closest:求最近点
    Output      : result:分割后的图元结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int GetNearestPointOnLine(const Exp_Line* line, const Exp_Vector&p, QVector<Exp_Vector>& result, bool closest = true);

    /*************************************************
    Function    : 获取圆弧的最近最远点
    Description : 根据一点坐标，计算图元轮廓上距离该点最近或最远点的坐标
    Input       : arc:圆弧，p:坐标，closest:求最近点
    Output      : result:分割后的图元结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int GetNearestPointOnArc(const Exp_Arc* arc, const Exp_Vector&p, QVector<Exp_Vector>& result, bool closest = true);

    /*************************************************
    Function    : 获取圆的最近最远点
    Description : 根据一点坐标，计算图元轮廓上距离该点最近或最远点的坐标
    Input       : circle:圆，p:坐标，closest:求最近点
    Output      : result:分割后的图元结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int GetNearestPointOnCircle(const Exp_Circle* circle, const Exp_Vector&p, QVector<Exp_Vector>& result, bool closest = true);

    /*************************************************
    Function    : 获取椭圆的最近最远点
    Description : 根据一点坐标，计算图元轮廓上距离该点最近或最远点的坐标
    Input       : ellipse:椭圆，p:坐标，closest:求最近点
    Output      : result:分割后的图元结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int GetNearestPointOnEllipse(const Exp_Ellipse* ellipse, const Exp_Vector&p, QVector<Exp_Vector>& result, bool closest = true);

    /*************************************************
    Function    : 获取椭圆弧的最近最远点
    Description : 根据一点坐标，计算图元轮廓上距离该点最近或最远点的坐标
    Input       : ellipse:椭圆弧，p:坐标，closest:求最近点
    Output      : result:分割后的图元结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int GetNearestPointOnEllipticArc(const Exp_Ellipse* ellipse, const Exp_Vector&p, QVector<Exp_Vector>& result, bool closest = true);

    /*************************************************
    Function    : 获取多段线的最近最远点
    Description : 根据一点坐标，计算图元轮廓上距离该点最近或最远点的坐标
    Input       : pline:多段线，p:坐标，closest:求最近点
    Output      : result:分割后的图元结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int GetNearestPointOnPolyline(const Exp_Polyline* pline, const Exp_Vector&p, QVector<Exp_Vector>& result, bool closest = true);

    /*************************************************
    Function    : 获取样条曲线的最近最远点
    Description : 根据一点坐标，计算图元轮廓上距离该点最近或最远点的坐标
    Input       : spline:样条曲线，p:坐标，closest:求最近点
    Output      : result:分割后的图元结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int GetNearestPointOnSpline(const Exp_Spline* spline, const Exp_Vector&p, QVector<Exp_Vector>& result, bool closest = true);


    /*************************************************
    Function    : 图元离散
    Description : 根据功高误差将图元离散成仅有直线的多段线
    Input       : sourceEn为原始图元，err为弓高误差
    Output      : retPline为离散后的多段线
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int Discrete(const Exp_Entity* sourceEn, Exp_Polyline*& retPline, const double err);

    /*************************************************
    Function    : 图元偏移
    Description :
    Input       : sourceEn为原始图元，
                  transitionType为过渡类型：0为直线过渡，非0为圆弧过渡
                  ioScaleType为内缩/外扩：0为内缩，非0为外扩
                  overcutOffset为是否使用过切补偿：0为不使用，非0为使用
                  offsetDist为补偿距离
    Output      : retEns为偏移结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int Offset(const Exp_Entity* sourceEn, QVector<Exp_Entity*>& retEns, const int transitionType = 0, const int ioScaleType = 0, const int overcutOffset = 0, const double offsetDist = 0.);


    bool FindE2SList(const QVector<Exp_Entity*> entities,
                     QVector<QVector<Exp_Entity*>>& retEntities,
                     const double tolerance = 1.e-3);

    int IsThroughPline(const QVector<Exp_AtomicEntity*> sources, const Exp_Line* line, bool& cross);
    int IsThroughPline(const Exp_Entity* source, const Exp_Line* line, bool& cross);


    /*************************************************
    Function    : 获取多段线上的封闭图形
    Description :
    Input       : pl传入的多段线，upperLimit上限
    Output      : result计算结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int GetClosedOnPolyline(const Exp_Polyline* pl, QVector<Exp_Polyline*>& result, unsigned int upperLimit = 1);

    // 顶点拉伸
    int GraphVertexStretch(const Exp_Entity* input, const Exp_Vector previous, const Exp_Vector later, Exp_Entity*& res);

    // 框选拉伸
    int GraphStretch(QVector<Exp_Entity*> input, const Exp_Vector& minrect,const Exp_Vector& maxrect, const Exp_Vector& move, QVector<Exp_Entity*>& res);

    /*************************************************
    Function    : 去重检测
    Description :
    Input       : entities需要检测重叠的图元，err误差
    Output      : removeEntities需要去除的重叠图元
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int OverKill(const QVector<Exp_Entity*>& entities, QVector<Exp_Entity*>& removeEntities, const double err);

    /*************************************************
    Function    : 按轴方向缩放
    Description :
    Input       : entity需要缩放的图元，ratio缩放比例，type缩放类型
    Output      : result计算结果
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int ScaleByAxis(const Exp_Entity*& entity, Exp_Entity*& result, double ratio, int type);

    /*************************************************
    Function    : 获取图形外轮廓
    Description :
    Input       : input封闭图形的集合，
    Output      : result查找出的外轮廓
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int GetOutlinePolyline(const QVector<Exp_Entity*> input, QVector<Exp_Polyline*>& result);

    /*************************************************
    Function    : 重叠检测
    Description :
    Input       : enVec作为基础的图元集合，dragEn移动的图元
    Output      : isOverlap移动的图元是否与作为基础的图元重合
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int OverlapDetect(const QVector<Exp_Entity*>& enVec, const Exp_Entity*& dragEn,
                      bool& isOverlap);

    /*************************************************
    Function    : 获取从封闭多段线的顶部开始，水平方向距离为distance的两个点
    Description :
    Input       : pl封闭多段线，distance水平方向距离
    Output      : p1计算得出点1，p2计算得出点2
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功，帆船点焊机使用
    *************************************************/
    int LengthToPFromTop(const Exp_Polyline* pl, double distance, Exp_Vector& p1, Exp_Vector& p2);

    /*************************************************
    Function    : 获取样条上的点的切向量
    Description :
    Input       : spl需要计算的样条，point样条上的点
    Output      : res计算出的的向量
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int GetSplineTangetVector(const Exp_Spline* spl, const Exp_Vector& point, Exp_Vector& res);

    /*************************************************
    Function    : 获取椭圆上的点的切向量
    Description :
    Input       : el需要计算的椭圆，point椭圆上的点
    Output      : res计算出的的向量
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int GetEllipseTangetVector(const Exp_Ellipse* el, const Exp_Vector& point, Exp_Vector& res);

    /*************************************************
    Function    : 判断点是否在图形内
    Description :
    Input       : point需要判断的点，entities拼接起来的封闭图形（线段、圆弧组成的封闭图形或单个圆）
    Output      :
    Return      : 计算结果
    Note        : 0_点在图元上，1_点在图元内，-1_点在图元外,-2_输入图形非法
    *************************************************/
    int PointInEntity(const Exp_Vector& point, const QVector<Exp_Entity*>& entities);

    /*************************************************
    Function    : 线切割刀补
    Description :
    Input       : inputEns输入的待刀补的图元集合，comp钼丝补偿，margin每刀余量，
                  isLeft是否前进方向左刀补，isCCW输入图形是否逆时针排列，
                  funcGetProperty用于获取工艺的func，funcSetProperty用于设置工艺的func
    Output      : outputEns刀补的结果，
    Return      : 计算结果
    Note        : 当且仅当输出结果为0时表示计算成功，
                  两个func中的QVariant按照总数17个，四组[bool,double,double,int]外加一个int的形式设置属性
    *************************************************/
    int WireCutOffset(const QVector<Exp_Entity*>& inputEns,
                      QVector<QVector<Exp_Entity*>>& outputEns, double comp, double margin,
                      bool isLeft, bool isCCW,
                      std::function<QVector<QVariant>(Exp_Entity*)> funcGetProperty,
                      std::function<void(Exp_Entity*&, QVector<QVariant>)> funcSetProperty);

    int FitArcPlan(const Exp_Polyline*& plIn, Exp_Polyline*& plOut, const QVector<double>& paramIn,
                   QVector<double>& paramOut);

    int GraphTangentPoint(const Exp_Entity*& entity, const Exp_Vector& tanStartPoint,
                          QVector<QVector<Exp_Vector>>& resPoint, QVector<int>& isGlobalTanPoint);

    int GraphTangentPoint(const Exp_Entity*& entity, const Exp_Vector& tanStartPoint,
                          QVector<QVector<Exp_Vector>>& resPoint);

    int AllGraphTangentPoint(const QVector<Exp_Entity*>& entities, const Exp_Vector& tanStartPoint,
                             QVector<QVector<Exp_Vector>>& resPoint, QVector<int>& isGlobalTanPoint);

    int AllGraphTangentPoint(const QVector<Exp_Entity*>& entities, const Exp_Vector& tanStartPoint,
                             QVector<QVector<Exp_Vector>>& resPoint);

    /*************************************************
    Function    : 计算面积
    Description :
    Input       : entities需要计算面积的图形
    Output      : area计算出的面积,paramIn预留的输入参数,可以不管
    Return      : 计算结果
    Note        : 仅当计算结果为0时表示获取成功
    *************************************************/
    int GetArea(const QVector<Exp_Entity*>& entities, double& area, const QVector<double>& paramIn = {});

    int GetPointByParameterize(const Exp_Entity* en, const double param, Exp_Vector& point);

    //int JoinToArc(const Exp_Arc* sourceArc, const QVector<Exp_Arc*>& arcs, Exp_Entity*& retEn);
    //int JoinToEllipse(const Exp_Ellipse* sourceElli, const QVector<Exp_Ellipse*>& ellis, Exp_Ellipse*& retEn);

    // 不开放
    // int EllipticalArc2Spline(const Exp_Ellipse*& el, QVector<Exp_Spline*>& spl);
    // int EllipticalArc2SplineTest(const Exp_Ellipse*& el, Exp_Spline*& spl);

    // Test
    // int JoinToSpline(const Exp_Spline* sourceSpl, const QVector<Exp_Spline*> splVec, Exp_Spline*& retSpl);
};

#endif // EXP_XGLGALGO_H
