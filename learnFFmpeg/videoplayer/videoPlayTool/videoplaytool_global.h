#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(VIDEOPLAYTOOL_LIB)
#  define VIDEOPLAYTOOL_EXPORT Q_DECL_EXPORT
# else
#  define VIDEOPLAYTOOL_EXPORT Q_DECL_IMPORT
# endif
#else
# define VIDEOPLAYTOOL_EXPORT
#endif
