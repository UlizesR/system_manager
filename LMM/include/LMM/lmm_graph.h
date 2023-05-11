#ifndef LMM_GRAPH_H
#define LMM_GRAPH_H

#include "lmm_vectors.h"
#include "lmm_functions.h"

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QLegend>
#include <QtCharts/QScatterSeries>
#include <QtCore/QObject>
#include <QtCore/QPair>
#include <QtCore/QPointF>
#include <QtGui/QPen>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>


namespace lmm
{
    typedef QVector<QPointF> DataPoints;
    typedef std::list<std::pair<std::variant<Vec, Func, DataPoints>, QColor>> GraphDataList;

    // Function declaration for creating a graph window
    void createGraphWindow(const GraphDataList& dataList);
}

#endif // LMM_GRAPH_H
