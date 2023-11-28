#pragma once
#include <QPen>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
class myCrossItem : public QGraphicsLineItem
{
public:
	myCrossItem(QGraphicsLineItem *parent=0); 
	~myCrossItem();
	int type() const;
protected:

private:
};
