/*******************************************************************************
 * Descript	:
 * Author   :
 * Data     :
 * Version	: 1.0.1.0126_Beta
 * History  :
 * Note     :
 *******************************************************************************/
#ifndef EXP_ENTITY_H
#define EXP_ENTITY_H
#include <QColor>
#include <memory>
#include <functional>
#include "CADLab_global.h"
#include "Exp_Vector.h"
#ifdef CADLab_LIBRARY
#include "lib/engine/rs.h"
#else
#include "rs.h"
#endif

class ICAMData;

class CADLab_EXPORT Exp_Entity
{
public:
    Exp_Entity(void* en = nullptr);
    virtual ~Exp_Entity() = default;
    void* GetEntity() const;
    void SetEntity(void* en);

    /*************************************************
    Function    : 内存释放
    Description : 调用此方法释放未添加到前台界面显示的图形
    Input       :
    Output      :
    Return      :
    Note        : 调用此接口后无需再使用delete关键字释放内存
    *************************************************/
    void DeleteEntity();

    /*************************************************
    Function    : 判定图元是否有效
    Description : 调用此方法判断图元是否有效
    Input       :
    Output      :
    Return      : true:有效（内部图元未被释放），false:无效（内部图元已被释放）
    Note        :
    *************************************************/
    bool IsValid() const;

    /*************************************************
    Function    : 判定图元是否可见
    Description : 调用此方法判断图元是否可见
    Input       :
    Output      :
    Return      : true:可见，false:不可见
    Note        :
    *************************************************/
    bool IsVisible() const;

    /*************************************************
    Function    : 获取类型
    Description : 调用此方法获取该图元实体的具体类型
    Input       :
    Output      :
    Return      : 图元类型
    Note        : 返回值各自对应的图元类型参考rs.h中的EntityType
    *************************************************/
    RS2::EntityType Rtti() const;

    /*************************************************
    Function    : 获取ID
    Description : 调用此方法获取该图元实体的ID号
    Input       :
    Output      :
    Return      : 图元ID
    Note        :
    *************************************************/
    unsigned long GetId() const;

    /*************************************************
    Function    : 获取起点
    Description : 调用此方法获取该图元实体的起始点坐标
    Input       :
    Output      :
    Return      : 起点坐标
    Note        : 若图元类型为圆时返回（0，0），其余类型正常返回
    *************************************************/
    Exp_Vector GetStartPoint() const;

    /*************************************************
    Function    : 获取终点
    Description : 调用此方法获取该图元实体的终止点坐标
    Input       :
    Output      :
    Return      : 终点坐标
    Note        : 若图元类型为圆时返回（0，0），其余类型正常返回
    *************************************************/
    Exp_Vector GetEndPoint() const;

    /*************************************************
    Function    : 设置线型
    Description : 调用此方法设置图元对象的线型效果
    Input       : 线型
    Output      :
    Return      :
    Note        : 已有线型参考rs.h中的LineType
    *************************************************/
    void SetAttributeLineType(const RS2::LineType type);

    /*************************************************
    Function    : 设置线宽
    Description : 调用此方法设置图元对象的线宽参数
    Input       : 线宽
    Output      :
    Return      :
    Note        : 已有线宽参考rs.h中的LineWidth
    *************************************************/
    void SetAttributeLineWidth(const RS2::LineWidth width);

    /*************************************************
    Function    : 设置颜色
    Description : 调用此方法设置图元对象的显示颜色
    Input       : 颜色
    Output      :
    Return      :
    Note        : 已有颜色参考rs.h中的LineColor
    *************************************************/
    void SetAttributeColor(const RS2::LineColor color);

    /*************************************************
    Function    : 设置属性
    Description : 调用此方法设置图元对象的颜色、线宽、线型
    Input       : 颜色，线宽，线型
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetAttribute(const RS2::LineColor color, const RS2::LineWidth width,
                      const RS2::LineType type);

    /*************************************************
    Function    : 获取图层
    Description : 调用此方法获取该图元对象所在的图层名称
    Input       :
    Output      :
    Return      : 图层名
    Note        :
    *************************************************/
    QString GetLayer() const;

    /*************************************************
    Function    : 设置图层
    Description : 调用此方法设置该图元对象的所在图层
    Input       : 图层名
    Output      :
    Return      :
    Note        : 若输入的图层名不存在，则设置无效
    *************************************************/
    void SetLayer(const QString layerName);

    /*************************************************
    Function    : 设置标签
    Description : 调用此方法设置该图元对象的标签
    Input       : 标签字符串
    Output      :
    Return      :
    Note        : 未对图元设置标签时默认为空字符串，标签可用于对图元的筛选
    *************************************************/
    void SetTag(QString tag);

    /*************************************************
    Function    : 设置标签(编号)
    Description : 调用此方法设置该图元对象的编号标签
    Input       : 编号
    Output      :
    Return      :
    Note        : 未对图元设置标签时默认为0，标签可用于对图元的筛选
    *************************************************/
    void SetIdentity(long long m_Identity);

    /*************************************************
    Function    : 获取标签
    Description : 调用此方法获取该图元对象的编号标签
    Input       :
    Output      :
    Return      : 标签字符串
    Note        :
    *************************************************/
    QString GetTag(void) const;

    /*************************************************
    Function    : 获取标签（编号）
    Description : 调用此方法获取该图元对象的标签
    Input       :
    Output      :
    Return      : 编号
    Note        : 平替Tag QString
    *************************************************/
    long long GetIdentity() const;

    /*************************************************
    Function    : 图元克隆
    Description : 调用此方法获取一个与该图元对象数据一致的新图元
    Input       :
    Output      :
    Return      : 克隆的图元对象指针
    Note        :
    *************************************************/
    Exp_Entity* Clone() const;

    /*************************************************
    Function    : 获取中心
    Description : 调用此方法获取该图元对象的圆心坐标
    Input       :
    Output      :
    Return      : 中心坐标
    Note        : 仅有弧、圆、椭圆拥有正常的中心点，其余图元返回（0,0）
    *************************************************/
    Exp_Vector GetCenter() const;

    /*************************************************
    Function    : 获取长度
    Description : 调用此方法获取该图元对象的长度
    Input       :
    Output      :
    Return      : 长度
    Note        :
    *************************************************/
    double GetLength() const;

    /*************************************************
    Function    : 获取半径
    Description : 调用此方法获取该图元对象的半径长度
    Input       :
    Output      :
    Return      : 半径
    Note        : 仅有弧、圆拥有正常的半径参数，其余图元返回1.0e+10
    *************************************************/
    double GetRadius() const;

    /*************************************************
    Function    : 是否为复合图元
    Description : 调用此方法获取该图元对象是否为复合图元
    Input       :
    Output      :
    Return      : 复合图元判定
    Note        : 仅有样条曲线和多段线为true，其余图元为false
    *************************************************/
    bool IsContainer() const;
    /*************************************************
    Function    : 是否为原子图元
    Description : 调用此方法获取该图元对象是否为原子图元
    Input       :
    Output      :
    Return      : 原子图元判定
    Note        : 仅有样条曲线和多段线为false，其余图元为true
    *************************************************/
    bool IsAtomic() const;

    /*************************************************
    Function    : 设置选中
    Description : 调用此方法设置该图元对象当前是否被选中
    Input       : 选中状态
    Output      :
    Return      : bool返回状态表示是否成功设置
    Note        : 若图元对象被锁定或为空指针等情况使选中失败时，返回false
    *************************************************/
    bool SetSelected(bool select);

    /*************************************************
    Function    : 获取选中
    Description : 调用此方法获取该图元对象当前是否被选中
    Input       :
    Output      :
    Return      : 选中状态
    Note        :
    *************************************************/
    bool GetSelected() const;

    /*************************************************
    Function    : 翻转选中
    Description : 调用此方法翻转该图元对象当前选中的选中状态
    Input       :
    Output      :
    Return      : 返回状态表示是否成功设置
    Note        : 若图元对象被锁定或为空指针等情况使选中失败时，返回false
    *************************************************/
    bool ToggleSelected();

    /*************************************************
    Function    : 偏移
    Description : 调用此方法对图元设置偏移
    Input       : const Exp_Vector& position,
                  const double offsetDistance
    Output      :
    Return      : 返回状态表示是否成功设置
    Note        : 此方法设置的偏移无法被撤销重做
    *************************************************/
    bool Offset(const Exp_Vector& position, const double offsetDistance);

    /*************************************************
    Function    : 移动
    Description : 调用此方法对图元设置移动
    Input       : 参照点，目标点
    Output      :
    Return      :
    Note        : 此方法设置的移动无法被撤销重做
    *************************************************/
    void Move(const Exp_Vector& referPoint, const Exp_Vector& targetPoint);

    /*************************************************
    Function    : 旋转（中心点+目标点）
    Description : 调用此方法对图元设置旋转
    Input       : 旋转基点，目标点
    Output      :
    Return      :
    Note        : 此方法设置的旋转无法被撤销重做
    *************************************************/
    void Rotate(const Exp_Vector& centerPoint, const Exp_Vector& targetPoint);

    /*************************************************
    Function    : 旋转（中心点+旋转角度）
    Description : 调用此方法对图元设置旋转
    Input       : 旋转基点，旋转角度
    Output      :
    Return      :
    Note        : 此方法设置的旋转无法被撤销重做；输入参数angle为旋转的角度值，而非弧度值
    *************************************************/
    void Rotate(const Exp_Vector& centerPoint,
                const double angle);

    /*************************************************
    Function    : 缩放
    Description : 调用此方法对图元设置缩放
    Input       : 缩放方向的参照点，缩放比例因子
    Output      :
    Return      :
    Note        : 此方法设置的缩放无法被撤销重做
    *************************************************/
    void Scale(const Exp_Vector& refPoint, const double scaleFactor);

    /*************************************************
    Function    : 镜像
    Description : 调用此方法对图元设置镜像
    Input       : 镜像线第一点，镜像线第二点
    Output      :
    Return      :
    Note        : 此方法设置的镜像无法被撤销重做
    *************************************************/
    void Mirror(const Exp_Vector& firstPoint, const Exp_Vector& secondPoint);

    /*************************************************
    Function    : 更新边界范围
    Description : 修改图元数据后调用此方法，根据新数据重新计算该图元的边界范围
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    void CalculateBorders();

    /*************************************************
    Function    : 为图形设置序号
    Description : 此方法仅限在IExp_Sortable子类的Sort()方法中使用，务必从1开始
                  依次排序，否则会打乱后续图形绘制时的序号
    Input       : 图形序号
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetSerialNum(unsigned int num);

    /*************************************************
    Function    : 获取图形序号
    Description : 获取图形序号，若存在返回图形序号，不存在则返回0
    Input       :
    Output      : 图形序号
    Return      :
    Note        :
    *************************************************/
    unsigned int GetSerialNum() const;

    /*************************************************
    Function    : 反向
    Description : 调用此方法翻转该图元对象的方向
    Input       :
    Output      :
    Return      :
    Note        :
    *************************************************/
    void ReverseOrientation();

    /*************************************************
    Function    : 设置方向
    Description : 调用此方法设置该图元对象的方向状态
    Input       : mOrientation:方向状态（true:正向 / false:反向）
                  （圆弧下true:逆时针(正向)，false:顺时针（反向））
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetOrientation(bool mOrientation);

    /*************************************************
    Function    : 获取方向
    Description : 调用此方法获取该图元对象当前的方向状态
    Input       :
    Output      :  mOrientation:方向状态（true:正向 / false:反向）
                  （圆弧下true:逆时针(正向)，false:顺时针（反向））
    Return      :
    Note        :
    *************************************************/
    void GetOrientation(bool &mOrientation) const;

    /*************************************************
    Function    : 获取反向
    Description : 调用此方法获取该图元对象当前的方向状态
    Input       :
    Output      :  mOrientation:方向状态（true:正向 / false:反向）
                  （圆弧下true:逆时针(正向)，false:顺时针（反向））
    Return      :
    Note        :
    *************************************************/
    bool GetOrientation() const;

    /*************************************************
    Function    : 设置专有文本显示状态
    Description : 调用此方法设置该图元对象当前的专用信息显示文本
                  的显示状态
    Input       : show 是否显示
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetSpecialTextShow(bool show);

    /*************************************************
    Function    : 获取专有文本显示状态
    Description : 调用此方法获取该图元对象当前的专用信息显示文本
                  的显示状态
    Input       :
    Output      : show 是否显示
    Return      :
    Note        :
    *************************************************/
    void GetSpecialTextShow(bool &show) const;

    /*************************************************
    Function    : 设置专有文本显示位置
    Description : 调用此方法设置该图元对象当前的专用信息显示文本
                  所在的位置
    Input       : 显示位置的坐标
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetSpecialTextPosi(Exp_Vector p);

    /*************************************************
    Function    : 获取专有文本显示位置
    Description : 调用此方法获取该图元对象当前的专用信息显示文本
                  所在的位置
    Input       :
    Output      : 显示位置的坐标
    Return      :
    Note        :
    *************************************************/
    Exp_Vector GetSpecialTextPosi() const;
    
    /*************************************************
    Function    : 设置专有文本显示内容
    Description : 调用此方法设置该图元对象当前的专用信息显示文本
                  的具体内容
    Input       : str 文本内容
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetSpecialTextContent(QString str);

    /*************************************************
    Function    : 获取专有文本显示内容
    Description : 调用此方法获取该图元对象当前的专用信息显示文本
                  的具体内容
    Input       :
    Output      :
    Return      : 文本内容
    Note        :
    *************************************************/
    QString GetSpecialTextContent() const;

    /*************************************************
    Function    : 设置图元预览状态
    Description : 调用此方法设置该图元对象当前的预览状态
    Input       : true:预览图元; flase:实际图元
    Output      :
    Return      :
    Note        : 若不希望此图元的存在影响到其他功能的正常使用
                  如捕捉（不捕捉此图元的相关点）
                  则可将此图元的预览状态设置为true
    *************************************************/
    void SetPreviewStatus(bool isPreview);

    /*************************************************
    Function    : 获取预览状态
    Description : 调用此方法获取该图元对象当前的预览状态
    Input       :
    Output      :
    Return      : true:预览图元; flase:实际图元
    Note        :
    *************************************************/
    bool GetPreviewStatus() const;

    /*************************************************
    Function    : 设置附加数据
    Description : 调用此方法为图元设置附加数据（可随图元保存至DXF文件）
    Input       : data:附加数据
    Output      :
    Return      :
    Note        : 附加数据不保存到DXF中
    *************************************************/
    void SetAdditionalData(const QStringList& data);

    /*************************************************
    Function    : 设置附加数据
    Description : 调用此方法为图元设置附加数据（无法随图元保存至DXF文件）
    Input       : data:附加数据
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetAdditionalDataNoSave(const QStringList& data);

    /*************************************************
    Function    : 获取附加数据
    Description : 调用此方法获取图元的附加数据（可从DXF文件中读取）
    Input       :
    Output      :
    Return      : 图元的附加数据
    Note        :
    *************************************************/
    QStringList GetAdditionalData() const;

    /*************************************************
    Function    : 获取附加数据
    Description : 调用此方法获取图元的附加数据（无法从DXF文件中读取）
    Input       :
    Output      :
    Return      : 图元的附加数据
    Note        : 附加数据不保存到DXF中
    *************************************************/
    QStringList GetAdditionalDataNoSave() const;

    /*************************************************
    Function    : 为图元设置工艺数据
    Description : 调用此接口为图元附加工艺数据
    Input       : 工艺数据
    Output      :
    Return      :
    Note        :
    *************************************************/
    void SetCAMData(const std::shared_ptr<ICAMData>&);

    /*************************************************
    Function    : 获取图元的工艺数据
    Description : 获取图元的工艺数据，不存在则返回空
    Input       :
    Output      :
    Return      : 存在：图元的工艺数据，不存在：nullptr
    Note        :
    *************************************************/
    std::shared_ptr<ICAMData> GetCAMData() const;

    /*************************************************
    Function    : 获取图形外包络矩形左下角的点
    Description :
    Input       :
    Output      :
    Return      : 图形外包络矩形左下角的点
    Note        :
    *************************************************/
    Exp_Vector GetMinV() const;

    /*************************************************
    Function    : 获取图形外包络矩形右上角的点
    Description :
    Input       :
    Output      :
    Return      : 图形外包络矩形左下角的点
    Note        :
    *************************************************/
    Exp_Vector GetMaxV() const;

    /*************************************************
    Function    : 获取图形上距离给定点最近的点
    Description :
    Input       : coord(给定点坐标)
    Output      : dist(最短距离)
    Return      : 图形上距离给定点最近的点
    Note        :
    *************************************************/
    Exp_Vector GetNearestPointOnEntity(const Exp_Vector& coord, double* dist) const;

    /*************************************************
    Function    : 判断给定点是否在图形上
    Description :
    Input       : coord(给定点坐标), tolerance(误差)
    Output      :
    Return      : true:点在图形上，false:点不在图形上
    Note        :
    *************************************************/
    bool IsPointOnEntity(const Exp_Vector& coord, double tolerance) const;

    /*************************************************
    Function    : 设置CAM参数的后处理函数指针
    Description :
    Input       :
    Output      :
    Return      : 函数指针
    Note        :
    *************************************************/
    static std::function<void(Exp_Entity*)>& GetFuncSetCAMPost();

    /*************************************************
    Function    : 获取CAM参数的前处理函数指针
    Description :
    Input       :
    Output      :
    Return      : 函数指针
    Note        :
    *************************************************/
    static std::function<void(Exp_Entity*)>& GetFuncGetCAMPre();

protected:
    void* entity;
    static std::function<void(Exp_Entity*)> funcSetCAMPost;
    static std::function<void(Exp_Entity*)> funcGetCAMPre;
};

#endif  // EXP_ENTITY_H
