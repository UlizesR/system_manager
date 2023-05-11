#include <iostream>
#include <iomanip>
#include <LMM/LMM.h>
#include <cmath>

int main(int argc, char *argv[]) {
    // Create a list of graph data
    lmm::GraphDataList dataList;

    // Create a Vec data
    lmm::Vec vecData = {1.2, 2.5, 3.8, 2.1, 4.6};
    dataList.push_back({vecData, Qt::red});

    // Create a function data
    lmm::Func funcData = [](double x) { return x * x; };
    dataList.push_back({funcData, Qt::blue});

    // Create a DataPoints
    lmm::DataPoints pointsData;
    pointsData.append(QPointF(1, 5));
    pointsData.append(QPointF(2, 7));
    pointsData.append(QPointF(3, 3));
    dataList.push_back({pointsData, Qt::green});

    // Create the graph window
    lmm::createGraphWindow(dataList);

    return 0;
}