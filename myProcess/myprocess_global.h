#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(MYPROCESS_LIB)
#  define MYPROCESS_EXPORT Q_DECL_EXPORT
# else
#  define MYPROCESS_EXPORT Q_DECL_IMPORT
# endif
#else
# define MYPROCESS_EXPORT
#endif
