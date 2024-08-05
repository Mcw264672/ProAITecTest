#ifndef EXP_POLYLINE_H
#define EXP_POLYLINE_H
#include "Exp_Entity.h"
#include "Exp_EntityContainer.h"
#include "CADLab_global.h"

struct CADLab_EXPORT Exp_PolylineVertexData
{
    /*************************************************
    Function    : 构造多段线线段数据的结构
    Description : 线段数据struct结构的构造方式
    Input       : 点坐标，下一段（！）线段的凸度，是否添加到多段线首部
    Output      :
    Return      :
    Note        : 输入参数中，nextBulge为下一段线段（并非当前插入的线段）的凸度值；
                  prepend表示当前插入线段是否插到多段线首部位置
    *************************************************/
    Exp_PolylineVertexData(const Exp_Vector& point,
                           double nextBulge,
                           bool prepend = false);

    Exp_Vector nextPoint;
    double nextBulge;
    bool prepend;
};

class CADLab_EXPORT Exp_Polyline : public Exp_EntityContainer
{
public:
    Exp_Polyline(void* en);

    /*************************************************
    Function    : 生成多段线
    Description : 调用此静态方法生成一个多段线的图元对象
    Input       : 起点坐标
    Output      :
    Return      : 返回生成的图元对象指针
    Note        : 指定起点即可生成多段线的图元对象
    *************************************************/
    static Exp_Polyline* CreatePolyline(const Exp_Vector& startPoint);

    /*************************************************
    Function    : 生成多段线
    Description : 调用此静态方法生成一个多段线的图元对象
    Input       : 起点坐标，线段数据，是否闭合
    Output      :
    Return      : 返回生成的图元对象指针
    Note        : 指点起点，以及包含所有的多段线线段的容器，以及指定是否闭合以确定一个多段线对象
    *************************************************/
    static Exp_Polyline* CreatePolyline(
        const Exp_Vector& startPoint,
        const QList<Exp_PolylineVertexData>& vertexData, bool closed);

    /*************************************************
    Function    : 添加线段
    Description : 调用生成的图元对象中的此方法，为该多段线添加一段线段
    Input       : 点坐标，下一段（！）线段的凸度，是否添加到多段线首部
    Output      :
    Return      :
    Note        :
    *************************************************/
    void AddVertex(const Exp_Vector& point, double nextBulge,
                   bool prepend = false);

    /*************************************************
    Function    : 获取闭合状态
    Description : 调用生成的图元对象中的此方法,获取该多段线的闭合状态
    Input       :
    Output      :
    Return      : 闭合状态
    Note        :
    *************************************************/
    bool GetClosed() const;

    /*************************************************
    Function    : 设置闭合状态
    Description : 调用生成的图元对象中的此方法,设置该多段线的闭合状态
    Input       : 闭合状态
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetClosed(bool cl);

    /*************************************************
    Function    : 设置下一段线段凸度
    Description : 调用生成的图元对象中的此方法,设置该多段线下一段线段的凸度值
    Input       : 凸度值
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetNextBulge(const double bulge);

    /*************************************************
    Function    : 完成多段线的构造
    Description : 通过AddVertex的方式构造多段线后需要通过该接口完成构造
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    void EndPolyline();

    /*************************************************
    Function    : 移除末尾线段
    Description : 调用生成的图元对象中的此方法，将多段线最后一段线段删除
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    void RemoveLastVertex();

    /*************************************************
    Function    : 正多边形判断
    Description : 调用此方法判断该多段线是否为一个正多边形
    Input       :
    Output      :
    Return      : 是否为正多边形
    Note        :
    *************************************************/
    bool IsRegularPolygon();

    /*************************************************
    Function    : 获取正多边形中心
    Description : 调用此方法获取正多边形的中心点坐标
    Input       :
    Output      :
    Return      : 中心点坐标
    Note        : 若该多段线不为正多边形等其他原因无法正常获取坐标
                  则返回的Exp_Vector无效
                  （Exp_Vector的valid为false）
    *************************************************/
    Exp_Vector GetRegularPolygonCenter();

    /*************************************************
    Function    : 获取是否是特殊多段线
    Description :
    Input       :
    Output      : 特殊多段线类型
    Return      : 判定结果，仅当结果为0时判定成功
    Note        : -1：不是特殊类型
                  0：三角形
                  1：扇形
                  2：平行四边形 3：矩形 4：梯形  5：远端半扇区
                  6：正多边形 7：圆角矩形
    *************************************************/
    int GetPlineSpecialType(int& type) const;

    /*************************************************
    Function    : 多段线插入顶点
    Description : 调用此方法向指定index插入新的顶点
    Input       : index，要插入的顶点在现有第几个顶点后；vertex，插入的顶点
    Output      :
    Return      : 是否插入成功
    Note        : index下标从0开始
    *************************************************/
    bool InsertVertex(const int& index, const Exp_Vector& vertex);

    /*************************************************
    Function    : 拉直多段线
    Description : 调用此方法拉直多段线的两个顶点
    Input       : index1，第一个顶点；index2，第二个顶点
    Output      :
    Return      : 是否拉直成功
    Note        : index下标从0开始
    *************************************************/
    bool StraightenPl(int index1, int index2);

    /*************************************************
    Function    : 设置多段线某段为圆弧经过指定点
    Description : 调用此方法设置多段线某段变为圆弧且经过指定点
    Input       : index，设置的第几段；pos，经过的指定点
    Output      :
    Return      : 是否转换成功
    Note        : index下标从0开始
    *************************************************/
    bool SetBulgeCrossP(const int& index, const Exp_Vector& pos);

    /*************************************************
    Function    : 获取重心
    Description : 调用此方法获取封闭多段线的重心
    Input       :
    Output      :
    Return      : 重心
    Note        :
    *************************************************/
    Exp_Vector GetBaryCenter() const;

    /*************************************************
    Function    : 向多段线添加节点
    Description :
    Input       : v:待添加的节点位置
    Output      :
    Return      : 是否添加成功
    Note        :
    *************************************************/
    bool AddNode(Exp_Vector v);

    /*************************************************
    Function    : 向多段线删除节点
    Description :
    Input       : v:待删除的节点位置
    Output      :
    Return      : 是否删除成功
    Note        :
    *************************************************/
    bool RemoveNode(Exp_Vector v);
};

#endif  // EXP_POLYLINE_H
