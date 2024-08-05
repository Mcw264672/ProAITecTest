#ifndef EXP_FUNCHANDLE_H
#define EXP_FUNCHANDLE_H

#include "CADLab_global.h"
#include "Exp_Management.h"

namespace CADHandle {
CADLab_EXPORT void PrintCmdMessage(const QString str);
CADLab_EXPORT void ShowDirectionArrow(const bool show);
CADLab_EXPORT void ShowSortNum(const bool show);

CADLab_EXPORT Exp_Vector GetRelativeZero();
CADLab_EXPORT void SetRelativeZero(Exp_Vector p);

CADLab_EXPORT QWidget*  GetGraphicViewPtr();
CADLab_EXPORT const int GetActiveFileIndex();
CADLab_EXPORT QWidget* GetGraphicViewPtr(const QString& docName);
CADLab_EXPORT QWidget* GetGraphicViewPtr(const int& idx);
CADLab_EXPORT const int GetAllGraphicViewCnt();
CADLab_EXPORT QVector<QWidget*> GetAllGraphicViewPtr();
CADLab_EXPORT void ResetAllGrahicView();
CADLab_EXPORT void ResetGraphicView(const QString& docName);
CADLab_EXPORT void ResetGraphicView(const int& index);
CADLab_EXPORT void ResetGraphicView(QWidget* graphicView);
CADLab_EXPORT void SetGraphicViewActived(const QString& docName);
CADLab_EXPORT void SetGraphicViewActived(const int& index);
CADLab_EXPORT void SetGraphicViewActived(QWidget* graphicView);
CADLab_EXPORT void CloseGraphicView(const QString& docName);
CADLab_EXPORT void CloseGraphicView(const int& index);
CADLab_EXPORT void ForceCloseGraphicView(const QString& docName);
CADLab_EXPORT void ForceCloseGraphicView(const int& index);
CADLab_EXPORT QSize GetGraphicViewSize();
CADLab_EXPORT Exp_Vector GetCoordLeftTop();
CADLab_EXPORT QPoint GetPixelLeftTop();
CADLab_EXPORT Exp_Vector GetFactor();

CADLab_EXPORT void SetCommandWidgetHeight(int height);
CADLab_EXPORT void SetCommandWidgetMiniHeight(int height);
CADLab_EXPORT void SetLayerWidgetWidth(int width);
CADLab_EXPORT void SetBlockWidgetWidth(int width);

CADLab_EXPORT void SetSnapButtonHidden(bool hide);
CADLab_EXPORT void SetOrthogonalButtonHidden(bool hide);
CADLab_EXPORT void SetPolarAxisButtonHidden(bool hide);
CADLab_EXPORT void SetLineWidthShowButtonHidden(bool hide);
CADLab_EXPORT void SetCloseDialogHidden(bool hidden);

CADLab_EXPORT void UpdateMouseCursor();
CADLab_EXPORT void UpdateCommandHints();
CADLab_EXPORT void UpdateDimensionTextScale(double scale);

CADLab_EXPORT Exp_Vector PointToGui(const Exp_Vector& p);
CADLab_EXPORT Exp_Vector PointToGraph(const Exp_Vector& p);

CADLab_EXPORT void SetPixmapData(QSharedPointer<QPixmap> pixmap, const Exp_Vector& factor,
                                 const Exp_Vector& leftTop);
CADLab_EXPORT void SetPixmapBkData(QSharedPointer<QPixmap> pixmap, const Exp_Vector& factor,
                                   const Exp_Vector& leftTop);

CADLab_EXPORT QPixmap CreatePreviewPixmap(QVector<Exp_Entity*>& entities, const QSize& size, bool useEntityColor = false);
CADLab_EXPORT QPixmap CreatePreviewPixmap(const QVector<PixmapLine>& segments, const QSize& size);
CADLab_EXPORT QWidget*  CreatePreviewWidget(const QVector<Exp_Entity*>& entities,
                                           QWidget* parent = nullptr,
                                           bool drawDirect = false);

CADLab_EXPORT void SetDefaultSplineSegments(int seg);

CADLab_EXPORT void SetLineWidthShow(const bool show);

CADLab_EXPORT std::function<void(void)>& GetAfterMoveByDragFunc();

CADLab_EXPORT void SetDrawSerialNumMode(int mode);

CADLab_EXPORT std::function<void(void)>& GetAfterMoveRefByDragFunc();

CADLab_EXPORT void SetActionToExternalAction(const RS2::ActionType& actionType, const std::function<void(void)>& func);

CADLab_EXPORT void SetCmdToExternalAction(const QString& cmd, const std::function<void(void)>& func);

CADLab_EXPORT void ResetActionToExternal();

CADLab_EXPORT void ResetActionToExternal(const RS2::ActionType& actionType);

CADLab_EXPORT void ResetCmdToExternal();

CADLab_EXPORT void ResetCmdToExternal(const QString& cmd);

CADLab_EXPORT std::function<bool(const QList<Exp_Entity*>&)>& GetBeforeModifyScaleFunc();

CADLab_EXPORT std::function<bool(const QList<Exp_Entity*>&)>& GetBeforeModifyMirrorFunc();

CADLab_EXPORT void DisableTargetShortcut(QShortcut* shortcut);

CADLab_EXPORT void SetEllipticArcTolerance(double tolerance);

CADLab_EXPORT void SetCouldBackLastAction(const bool& couldBack);

CADLab_EXPORT void SetIsAllowMultiple(const bool& allowed);

CADLab_EXPORT void ClearCommandFocus();

CADLab_EXPORT void SetUseCompleter(const bool& use);

CADLab_EXPORT void SetCommandHistoryShow(const bool& show);

}
// namespace CADHandle

namespace EntityHandle {
CADLab_EXPORT QList<Exp_Entity*> GetAllEntities();
CADLab_EXPORT QList<Exp_Entity*> GetAllVisibleEntities();
CADLab_EXPORT QList<Exp_Entity*> GetAllSelectedEntities();
CADLab_EXPORT QList<Exp_Entity*> GetAllSortableEntities();

CADLab_EXPORT void AddNewEntity(Exp_Entity* en);
CADLab_EXPORT void AddNewEntityWithoutUndo(Exp_Entity* en);
CADLab_EXPORT void Remove();
CADLab_EXPORT void Remove(Exp_Entity* en);
CADLab_EXPORT void RemoveAll();
CADLab_EXPORT void RemoveWithoutUndo();
CADLab_EXPORT void RemoveWithoutUndo(Exp_Entity* en);
CADLab_EXPORT void RemoveAllWithoutUndo();
CADLab_EXPORT void UndoRedo(const QVector<Exp_Entity*>& before, const QVector<Exp_Entity*>& after);
CADLab_EXPORT void Redraw(RS2::RedrawMethod method = RS2::RedrawAll);
CADLab_EXPORT void RedrawEntity(Exp_Entity* en);
CADLab_EXPORT void MoveEntityToTop(Exp_Entity* en);

CADLab_EXPORT Exp_Entity* SelectOne(const Exp_Vector& center, double errorDist);
CADLab_EXPORT Exp_Entity* CatchOne(const Exp_Vector& posi);
CADLab_EXPORT QList<Exp_Entity*> SelectWindow(const Exp_Vector& v1, const Exp_Vector& v2);
CADLab_EXPORT QList<Exp_Entity*> SelectAll();
CADLab_EXPORT QList<Exp_Entity*> DeselectAll();
CADLab_EXPORT Exp_Entity* SelectOneOnBaseMap(const Exp_Vector& center, double errorDist);
CADLab_EXPORT QList<Exp_Entity*> SelectWindowOnBaseMap(const Exp_Vector& v1, const Exp_Vector& v2);
CADLab_EXPORT QList<Exp_Entity*> GetAllEntitiesFromBaseMap();

CADLab_EXPORT bool AddBlockToList(const QVector<Exp_Entity*>& enList, QString blockName,
                                  const Exp_Vector& basicPoint);
CADLab_EXPORT bool InsertBlock(QString blockName, Exp_Vector insertPoint, double scaleFactor,
                               double rotateRadian);
CADLab_EXPORT QList<QString> GetAllBlocks();
CADLab_EXPORT void SetInseparableBlock(const QString& keywords);

CADLab_EXPORT void SetEntityCanBeDrag(bool canBeDrag);
CADLab_EXPORT void SetEntityRefCanBeDrag(bool canBeDrag);
CADLab_EXPORT QVector<QVector<Exp_Entity*>> GetETSClosedInWindow(const Exp_Vector& v1,
                                                                 const Exp_Vector& v2,
                                                                 bool cross = true);
CADLab_EXPORT void SetSpecialParseText(const bool& isSpecial);
CADLab_EXPORT void SetAlwaysSpecialDrawText(const bool& isSpecial);
}

namespace EntityQuery {
CADLab_EXPORT QList<Exp_Entity*> QueryEntities(QString m_Tag);
CADLab_EXPORT QList<Exp_Entity*> QueryEntities(long long m_Identity);
CADLab_EXPORT QList<Exp_Entity*> QueryEntities(const QString& tag, int type);
CADLab_EXPORT QList<Exp_Entity*> QueryEntitiesByContour(Exp_Entity* en, bool includeEndP = true,
                                                        double toleranceQuery = 1.e-10);
CADLab_EXPORT QList<Exp_Entity*> QueryEntitiesByEndpoint(Exp_Entity* en, double tolerance = 1.e-10);
CADLab_EXPORT QList<Exp_Entity*> QueryEntitiesByEndpoint(Exp_Entity* en, bool findStartP,
                                                         double tolerance = 1.e-10);
}

namespace EntityModify {
CADLab_EXPORT QList<Exp_Entity*> Move(const Exp_Vector& referPoint, const Exp_Vector& targetPoint);
CADLab_EXPORT QList<Exp_Entity*> Copy(const Exp_Vector& referPoint, const Exp_Vector& targetPoint);
CADLab_EXPORT QList<Exp_Entity*> Rotate(const Exp_Vector& centerPoint,
                                        const Exp_Vector& targetPoint);
CADLab_EXPORT QList<Exp_Entity*> Rotate(const Exp_Vector& centerPoint, const double angle);
CADLab_EXPORT QList<Exp_Entity*> Mirror(const Exp_Vector& firstPoint, const Exp_Vector& secondPoint,
                                        const bool copy);
CADLab_EXPORT QList<Exp_Entity*> Explode(const bool remove = true);
CADLab_EXPORT QList<Exp_Entity*> ArrayRectangle(int rows, int cols, double offsetX, double offsetY,
                                                double angle);
CADLab_EXPORT QList<Exp_Entity*> ArrayCircle(int num, int fillAngle, const Exp_Vector& center);
CADLab_EXPORT QList<Exp_Entity*> Scale(Exp_Vector refPoint, double scaleFactor);
CADLab_EXPORT QList<Exp_Entity*> Offset(Exp_Vector position, double offsetDistance);
}

namespace ShapeHandle {
CADLab_EXPORT QVector<Exp_Vector> GetIntersection(Exp_AtomicEntity* e1, Exp_AtomicEntity* e2);

CADLab_EXPORT double CurvyMeasure(Exp_Entity* entity, Exp_Vector sp, Exp_Vector ep,
                                  bool isCW = false);

CADLab_EXPORT int JoinToInsertByETS(const QVector<Exp_Entity*> sourceEns, QVector<Exp_Entity*>& realInsertEns, const QString insertName, Exp_Vector& newStart);

CADLab_EXPORT Exp_Polyline* JoinToPolyline(const QList<Exp_Entity*>& entities,
                                           bool mustSelect = true);
CADLab_EXPORT Exp_Polyline* AddNodeToPolyline(Exp_Polyline* pl, Exp_Vector v);
CADLab_EXPORT bool CalcDivideOnEntity(const Exp_Entity* entity, const int segNum, QVector<Exp_Vector>& res);
CADLab_EXPORT bool CalcMeasureOnEntity(const Exp_Entity* entity, const double segLenth, QVector<Exp_Vector>& res, const Exp_Vector checkpoint, const double startOffset = .0f);
}

namespace FileHandle {
CADLab_EXPORT QString GetFileName();
CADLab_EXPORT QString GetFileNameAt(const int& index);

CADLab_EXPORT void FileNew();
CADLab_EXPORT void ForceFileNew();
CADLab_EXPORT void FileOpen(const QString& fileName, RS2::FormatType type = RS2::FormatDXFRW);
CADLab_EXPORT void FileSaveAs(const QString& fileName, RS2::FormatType type = RS2::FormatDXFRW);

CADLab_EXPORT void SetLatestDxfVer(EmValidDxfVer latestVer);
CADLab_EXPORT EmValidDxfVer GetLatestDxfVer();
CADLab_EXPORT void SetParseDxfExt(bool isExt);
CADLab_EXPORT bool GetParseDxfExt();
CADLab_EXPORT void SetParseChinese(bool isChinese);
CADLab_EXPORT bool GetParseChinese();
CADLab_EXPORT void SetDxfSpaceFilterMode(int mode);
CADLab_EXPORT int GetDxfSpaceFilterMode();
CADLab_EXPORT void SetWeightValidInSpl(bool valid, double err = 0.001);
CADLab_EXPORT bool GetWeightValidInSpl();

CADLab_EXPORT QString GetCurrentFileName();


CADLab_EXPORT void SetSaveAsDefualt(EmSaveAsDefault type);
CADLab_EXPORT EmSaveAsDefault GetSaveAsDefualt();

CADLab_EXPORT std::function<QList<Exp_Entity*>(const QList<Exp_Entity*>&)>& GetOptimizePreFunc();
CADLab_EXPORT std::function<QList<Exp_Entity*>(const QList<Exp_Entity*>&)>& GetOptimizePostFunc();

CADLab_EXPORT std::function<void(void)> &GetAfterOpenFunc();

CADLab_EXPORT QString GetBinaryNameFilter();
CADLab_EXPORT void SetBinaryNameFilter(const QString& fBin);

CADLab_EXPORT void SetFilterImport(const std::shared_ptr<IExp_FilterImport>& filter);
CADLab_EXPORT void SetSerializeTool(const std::shared_ptr<IExp_Serialize>& serial);
}

namespace SnapHandle {
CADLab_EXPORT void SetSnapOpen(bool open);
CADLab_EXPORT bool GetSnapOpen();
CADLab_EXPORT void SetSnapMode(Exp_SnapMode mSnapMode);
CADLab_EXPORT Exp_SnapMode GetSnapMode();
CADLab_EXPORT Exp_Vector GetSnapPoint(QMouseEvent* e);
CADLab_EXPORT void SetIsSnapEllipseFoci(const bool& isSnap);
CADLab_EXPORT void SetSnapOrthogonalCanGetNearestP(const bool& isGetNearest);
}

namespace ZoomHandle {
CADLab_EXPORT void ZoomAuto();
CADLab_EXPORT void ZoomPan(int dx, int dy);
CADLab_EXPORT void ZoomWindow(const Exp_Vector& v1, const Exp_Vector& v2);
}

namespace ActionHandle {
CADLab_EXPORT void SetCurrentAction(IExp_ActionInterface* action);
CADLab_EXPORT void SetDefaultAction(IExp_ActionInterface* action);
CADLab_EXPORT void ResetDefaultAction();
CADLab_EXPORT void JumpToEmptyAction();
CADLab_EXPORT void KillAllActions();
CADLab_EXPORT RS2::ActionType GetCurrentActionType();
}

namespace CAMHandle {
CADLab_EXPORT void SetGlobalCAMData(const std::shared_ptr<IGlobalCAMData>& camData);
CADLab_EXPORT std::shared_ptr<IGlobalCAMData> GetGlobalCAMData();

CADLab_EXPORT bool GetIsInitCAMData();
CADLab_EXPORT void SetIsInitCAMData(const bool& isInitCAMData);
CADLab_EXPORT const std::shared_ptr<ICAMData>& GetInitCAMData();
CADLab_EXPORT void SetInitCAMData(const std::shared_ptr<ICAMData>& initCAMData);
}

namespace IAlgoHandle {
CADLab_EXPORT void SetSortAlgo(IExp_Sortable* algo);
CADLab_EXPORT void SetImportOptimizeAlgo(IExp_ImportOptimize* algo);
}

namespace NestingHandle {
CADLab_EXPORT bool AddCompont(Exp_Component comp);
CADLab_EXPORT QVector<Exp_Component> GetAllComponent();
CADLab_EXPORT QVector<Exp_Component> GetSelectedComponent();
CADLab_EXPORT void AddNestingResult(const QVector<QVector<Exp_Entity*> >& entities,
                                    const Exp_Vector& plateSize);
}

namespace ImportConfigHandle{
CADLab_EXPORT void SetAutoExplode(const bool isExplode);
CADLab_EXPORT void SetDeleteInvisible(const bool isDelete, const double lessThan = .0f);
CADLab_EXPORT void SetDeleteDimension(const bool isDelete);
CADLab_EXPORT void SetDeleteDuplicate(const bool isDelete);
CADLab_EXPORT void SetUseOverKill(const bool isUse, const double err = 0.1);
}

#endif // EXP_FUNCHANDLE_H
