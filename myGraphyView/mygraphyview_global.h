#pragma once

#include <QtCore/qglobal.h>
#include <qpoint.h>
#include <qlist.h>
#include <qstring.h>

#ifndef BUILD_STATIC
# if defined(MYGRAPHYVIEW_LIB)
#  define MYGRAPHYVIEW_EXPORT Q_DECL_EXPORT
# else
#  define MYGRAPHYVIEW_EXPORT Q_DECL_IMPORT
# endif
#else
# define MYGRAPHYVIEW_EXPORT
#endif

//��graphyview�йص����ݽṹ
typedef struct AnnoItemGroup {
	QPointF pos;
	QList<QString> itemsStr;
	AnnoItemGroup() {}
	~AnnoItemGroup() {}
}AnnoItemGroup;
