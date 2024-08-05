#ifndef EXP_ELLIPSE_H
#define EXP_ELLIPSE_H
#include "Exp_AtomicEntity.h"
#include "CADLab_global.h"

class CADLab_EXPORT Exp_Ellipse : public Exp_AtomicEntity
{
public:
    Exp_Ellipse(void* en);

    /*************************************************
    Function    : 生成椭圆（轴形式：中心点+长轴端点+短轴长度）
    Description : 调用此静态方法生成一个椭圆的图元对象
    Input       : 圆心坐标，长轴端点，短轴长度
    Output      :
    Return      : 返回生成的图元对象指针
    Note        : 当中心点与长轴端点重合时，椭圆生成失败并返回nullptr
    *************************************************/
    static Exp_Ellipse* CreateEllipseFromAxis(const Exp_Vector& centerP,
                                              const Exp_Vector& majorP,
                                              const double minorAxisLen);

    /*************************************************
    Function    : 生成椭圆（轴形式：中心点+长轴长度+短轴长度+旋转角度）
    Description : 调用此静态方法生成一个椭圆的图元对象
    Input       : 圆心坐标，长轴长度，短轴长度，旋转弧度
    Output      :
    Return      : 返回生成的图元对象指针
    Note        : 当长轴长度或短轴长度小于等于零时，椭圆生成失败并返回nullptr
    *************************************************/
    static Exp_Ellipse* CreateEllipseFromAxis(const Exp_Vector& centerP,
                                              const double majorAxisLen,
                                              const double minorAxisLen,
                                              const double rotateRadian);

    /*************************************************
    Function    : 生成椭圆弧（轴形式：中心点+长轴端点+短轴长度）
    Description : 调用此静态方法生成一个椭圆弧的图元对象
    Input       : 圆心坐标，长轴端点，短轴长度，起点弧度，终点弧度
    Output      :
    Return      : 返回生成的图元对象指针
    Note        : 当中心点与长轴端点重合时，椭圆弧生成失败并返回nullptr
    *************************************************/
    static Exp_Ellipse* CreateEllipticArcFromAxis(const Exp_Vector& centerP,
                                                  const Exp_Vector& majorP,
                                                  const double minorAxisLen,
                                                  const double radian1,
                                                  const double radian2,
                                                  const bool isACW = true);

    /*************************************************
    Function    : 生成椭圆弧（轴形式：中心点+长轴长度+短轴长度+旋转角度）
    Description : 调用此静态方法生成一个椭圆弧的图元对象
    Input       : 圆心坐标，长轴长度，短轴长度，旋转弧度，起点弧度，终点弧度
    Output      :
    Return      : 返回生成的图元对象指针
    Note        : 当长轴长度或短轴长度小于等于零时，椭圆弧生成失败并返回nullptr
    *************************************************/
    static Exp_Ellipse* CreateEllipticArcFromAxis(const Exp_Vector& centerP,
                                                  const double majorAxisLen,
                                                  const double minorAxisLen,
                                                  const double rotateRadian,
                                                  const double radian1,
                                                  const double radian2,
                                                  const bool isACW = true);

    /*************************************************
    Function    : 生成椭圆弧（轴形式：中心点+长轴长度+短轴长度+旋转角度）
    Description : 调用此静态方法生成一个椭圆弧的图元对象
    Input       : 圆心坐标，长轴长度，短轴长度，旋转弧度，起点坐标，终点坐标
    Output      :
    Return      : 返回生成的图元对象指针
    Note        : 当长轴长度或短轴长度小于等于零时，椭圆弧生成失败并返回nullptr
    *************************************************/
    static Exp_Ellipse* CreateEllipticaArcFromSEP(const Exp_Vector& centerP,
                                                  const double majorAxisLen,
                                                  const double minorAxisLen,
                                                  const double rotateRadian,
                                                  const Exp_Vector& startP,
                                                  const Exp_Vector& endP,
                                                  const bool isACW = true);

    /*************************************************
    Function    : 设置圆心
    Description : 调用生成的图元对象中的此方法，重新设置该椭圆的圆心
    Input       : 圆心坐标
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetCenter(const Exp_Vector &c);

    /*************************************************
    Function    : 获取中点
    Description : 调用此方法获取该椭圆弧的中点
    Input       :
    Output      :
    Return      : 中点坐标
    Note        :
    *************************************************/
    Exp_Vector GetMiddlePoint() const;

    /*************************************************
    Function    : 获取比率（短轴与长轴的比值）
    Description : 调用生成的图元对象中的此方法，获取该椭圆的(短轴长度/长轴长度)的值
    Input       :
    Output      :
    Return      : 比率数值
    Note        :
    *************************************************/
    double GetRatio() const;

    /*************************************************
    Function    : 设置比率（短轴与长轴的比值）
    Description : 调用生成的图元对象中的此方法，重新设置该椭圆的(短轴长度/长轴长度)的值
    Input       : 比率数值
    Output      :
    Return      :
    Note        : 当输入的比率值小于等于零时，则设置无效
    *************************************************/
    void SetRatio(const double r);

    /*************************************************
    Function    : 获取长轴端点（相对向量）
    Description : 调用生成的图元对象中的此方法，获取该椭圆的长轴端点相对于圆心坐标的偏移向量
    Input       :
    Output      :
    Return      : 长轴端点相对向量
    Note        : 返回坐标为[相对于圆心坐标的偏移向量]，如圆心为（100，100），长轴端点为（200，50），则返回（100，-50）
    *************************************************/
    Exp_Vector GetMajorP() const;

    /*************************************************
    Function    : 设置长轴端点（相对向量）
    Description : 调用生成的图元对象中的此方法，重新设置该椭圆的长轴端点相对于圆心坐标的偏移向量
    Input       : 长轴端点相对向量
    Output      :
    Return      :
    Note        : 当输入的长轴端点坐标与圆心坐标重合时，即输入（0，0），则设置无效
    *************************************************/
    void SetMajorP(const Exp_Vector& p);

    /*************************************************
    Function    : 获取长轴端点
    Description : 调用生成的图元对象中的此方法，获取该椭圆的长轴端点坐标
    Input       :
    Output      :
    Return      : 长轴端点坐标
    Note        :
    *************************************************/
    Exp_Vector GetMajorPoint() const;

    /*************************************************
    Function    : 获取短轴端点
    Description : 调用生成的图元对象中的此方法，获取该椭圆的短轴端点坐标
    Input       :
    Output      :
    Return      : 短轴端点坐标
    Note        :
    *************************************************/
    Exp_Vector GetMinorPoint() const;

    /*************************************************
    Function    : 获取长轴的半径长度
    Description : 调用生成的图元对象中的此方法，获取该椭圆圆心到长轴端点的距离
    Input       :
    Output      :
    Return      : 长轴半长
    Note        :
    *************************************************/
    double GetMajorRadius() const;

    /*************************************************
    Function    : 获取短轴的半径长度
    Description : 调用生成的图元对象中的此方法，获取该椭圆圆心到短轴端点的距离
    Input       :
    Output      :
    Return      : 短轴半长
    Note        :
    *************************************************/
    double GetMinorRadius() const;

    /*************************************************
    Function    : 获取旋转角度
    Description :
    Input       :
    Output      :
    Return      : 旋转角度
    Note        : 若图元无效返回-1
    *************************************************/
    double GetAngle() const;

    /*************************************************
    Function    : 设置旋转角度
    Description :
    Input       : 旋转角度
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetAngle(const double angle);

    /*************************************************
    Function    : 获取起点角度
    Description :
    Input       :
    Output      :
    Return      : 起点角度
    Note        : 若图元无效返回-1
    *************************************************/
    double GetAngle1() const;

    /*************************************************
    Function    : 设置起点角度
    Description :
    Input       : 起点角度
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetAngle1(const double angle);

    /*************************************************
    Function    : 获取终点角度
    Description :
    Input       :
    Output      :
    Return      : 终点角度
    Note        : 若图元无效返回-1
    *************************************************/
    double GetAngle2() const;

    /*************************************************
    Function    : 设置终点角度
    Description :
    Input       : 终点角度
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetAngle2(const double angle);

    /*************************************************
    Function    : 根据圆心角设置起点角度
    Description :
    Input       : 起点的圆心角度
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetCenterAngle1(const double angle);

    /*************************************************
    Function    : 根据圆心角设置终点角度
    Description :
    Input       : 终点的圆心角度
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetCenterAngle2(const double angle);

    /*************************************************
    Function    : 获取起点的圆心角度
    Description :
    Input       :
    Output      :
    Return      : 终点角度
    Note        : 若图元无效返回-1
    *************************************************/
    double GetCenterAngle1() const;

    /*************************************************
    Function    : 获取终点的圆心角度
    Description :
    Input       :
    Output      :
    Return      : 终点角度
    Note        : 若图元无效返回-1
    *************************************************/
    double GetCenterAngle2() const;

    /*************************************************
    Function    : 设置起点
    Description :
    Input       : 起点坐标
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetStartPoint(const Exp_Vector& sp);

    /*************************************************
    Function    : 设置终点
    Description :
    Input       : 终点坐标
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetEndPoint(const Exp_Vector& ep);

    /*************************************************
    Function    : 获取椭圆状态
    Description : 当前图元是否为椭圆弧
    Input       :
    Output      :
    Return      : 是否为椭圆弧
    Note        :
    *************************************************/
    bool IsEllipticArc() const;

    /*************************************************
    Function    : 获取椭圆弧的内角弧度
    Description : 若非椭圆弧，返回2PI
    Input       :
    Output      :
    Return      : 椭圆弧的内角弧度
    Note        :
    *************************************************/
    double GetArcAngle() const;

    /*************************************************
    Function    : 获取椭圆弧的外角弧度
    Description : 若非椭圆弧，返回2PI
    Input       :
    Output      :
    Return      : 椭圆弧的外角弧度
    Note        :
    *************************************************/
    double GetOuterArcAngle() const;

    /*************************************************
    Function    : 获取椭圆弧的点切向
    Description :
    Input       : 椭圆弧的点坐标
    Output      :
    Return      : 切向坐标
    Note        :
    *************************************************/
    Exp_Vector GetTangentDirection(const Exp_Vector&) const;

    QVector<Exp_Vector> GetIntersectionByLine(const Exp_Vector& p1, const Exp_Vector& p2);
};

#endif  // EXP_ELLIPSE_H
