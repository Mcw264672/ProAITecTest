#ifndef BASEDLL_H
#define BASEDLL_H

class QString;

#define BASEDLLSHARED_EXPORT __declspec(dllexport)
#ifdef BASEDLLSHARED_EXPORT
#else
#define BASEDLLSHARED_EXPORT __declspec(dllimport)
#endif

/// \brief  Try You Best to Make the Project Unique
BASEDLLSHARED_EXPORT void RGInital(const QString& name);

/// \brief  Get You Serial Code
BASEDLLSHARED_EXPORT QString GetSerial();

/// \brief Make You APP Regiester
BASEDLLSHARED_EXPORT void RegisterDll(const QString& licence);

/// \brief Check You APP Status
/// \return 1: Permission Granted
///         2: Permission Not Found
///         3: Permission Denied
///         4: Project Error
BASEDLLSHARED_EXPORT int Check();

/// \brief Clear Permission
BASEDLLSHARED_EXPORT void RGClear();


/*--------------------------------- FakeMode -------------------------------*/

/// \brief Make You APP Regiester, but Fake
BASEDLLSHARED_EXPORT void RegisterDllFake(const QString& Serial,const QString& licence);

/// \brief Check You APP Status, but Fake
/// \return 1: Permission Granted
///         2: Permission Not Found
///         3: Permission Denied
///         4: Serial Error
BASEDLLSHARED_EXPORT int CheckFake(const QString& Serial);

/// \brief Clear Permission, but Fake
BASEDLLSHARED_EXPORT void RGClearFake(const QString& Serial);


/*--------------------------------- Others -------------------------------*/

/// \brief Version 1.1.1.20221103R
BASEDLLSHARED_EXPORT QString RGVersion();

/// \brief DO NOT USE IF U DO NOT KNOWN
BASEDLLSHARED_EXPORT void RGClearALL();

#endif  // BASEDLL_H
