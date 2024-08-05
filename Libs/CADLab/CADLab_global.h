#ifndef CADLAB_GLOBAL_H
#define CADLAB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CADLab_LIBRARY)
#  define CADLab_EXPORT Q_DECL_EXPORT
#else
#  define CADLab_EXPORT Q_DECL_IMPORT
#endif

#endif // CADLAB_GLOBAL_H
