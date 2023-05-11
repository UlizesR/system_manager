#ifndef LMM_GRAPH_H
#define LMM_GRAPH_H

#include "lmm_vectors.h"
#include "lmm_functions.h"
#include "lmm_qt.h"


namespace lmm
{
    typedef QVector<QPointF> DataPoints;
    typedef std::list<std::pair<std::variant<Vec, Func, DataPoints>, QColor>> GraphDataList;

    // Function declaration for creating a graph window
    void createGraphWindow(const GraphDataList& dataList);
}

#endif // LMM_GRAPH_H
