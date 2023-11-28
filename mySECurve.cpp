#include "mySECurve.h"

mySECurve::mySECurve(QWidget *parent)
{
	Q_UNUSED(parent)
	curvePlot = new QCustomPlot;
	curvePlot->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);
	curvePlot->axisRect()->setRangeZoom(Qt::Orientation::Vertical | Qt::Orientation::Horizontal);
	curvePlot->axisRect()->setRangeDrag(Qt::Orientation::Vertical | Qt::Orientation::Horizontal);
	curvePlot->xAxis->setNumberFormat("g");
	curvePlot->yAxis->setTickLabels(true);
	curvePlot->setBackground(QBrush("#000033"));
	curvePlot->xAxis->setTickLabelColor(Qt::white);
	curvePlot->yAxis->setTickLabelColor(Qt::white);
	curvePlot->xAxis->setTickPen(QPen(Qt::white));
	curvePlot->yAxis->setTickPen(QPen(Qt::white));
	curvePlot->xAxis->setBasePen(QPen(Qt::white, 1, Qt::PenStyle::SolidLine));
	curvePlot->yAxis->setBasePen(QPen(Qt::white, 1, Qt::PenStyle::SolidLine));
	curvePlot->xAxis->setSubTicks(true);
	curvePlot->yAxis->setSubTicks(true);
	curvePlot->xAxis->grid()->setVisible(true);
	curvePlot->yAxis->grid()->setVisible(true);

	QFont legendFont = font();
	legendFont.setPointSize(10);
	curvePlot->legend->setVisible(true);
	curvePlot->legend->setFont(legendFont);
	curvePlot->legend->setSelectedFont(legendFont);
	curvePlot->legend->setBrush(QBrush("#000033"));
	curvePlot->legend->setTextColor(Qt::white);
	curvePlot->legend->setSelectableParts(QCPLegend::spItems); // legend box shall not be selectable, only legend items

	QHBoxLayout *hlay = new QHBoxLayout;
	hlay->addWidget(curvePlot);
	setLayout(hlay);
}


void mySECurve::updateCurve(QList<QPair<QVector<double>, QVector<double>>> curveList, QList<ROImode> ROIList)
{
	int curveNum = curveList.size();
	double xmaxtemp=0, ymaxtemp=0;
	xmaxvalue = 0; ymaxvalue = 0;
	for (int icurve = 0; icurve < curveNum; icurve++)
	{
		QCPGraph *cb = new QCPGraph(curvePlot->xAxis, curvePlot->yAxis);
		cb->setName(ROIList.at(icurve).disp);
		QPen graphPen;
		graphPen.setColor(ROIList.at(icurve).ROIColor);
		graphPen.setWidthF(2);
		cb->setPen(graphPen);
		cb->setData(curveList.at(icurve).first, curveList.at(icurve).second);
		xmaxtemp= *std::max_element(curveList.at(icurve).first.constBegin(), curveList.at(icurve).first.constEnd());
		ymaxtemp = *std::max_element(curveList.at(icurve).second.constBegin(), curveList.at(icurve).second.constEnd());
		xmaxvalue = (xmaxvalue > xmaxtemp ? xmaxvalue : xmaxtemp);
		ymaxvalue = (ymaxvalue > ymaxtemp ? ymaxvalue : ymaxtemp);
	}
	setAutoXY();
}

void mySECurve::clearCurves()
{
	curvePlot->clearGraphs();
}

void mySECurve::setAutoXY()
{
	curvePlot->yAxis->setRangeLower(0);
	curvePlot->yAxis->setRangeUpper(ymaxvalue+10);
	curvePlot->xAxis->setRangeLower(0);
	curvePlot->xAxis->setRangeUpper(xmaxvalue+0.5);
	curvePlot->replot();
}
mySECurve::~mySECurve()
{
}
