#include <iostream>
#include <iomanip>
#include <LMM/LMM.h>
#include <cmath>

int main(int argc, char *argv[]) {
    // Create a list of graph data
    lmm::GraphDataList dataList;

    // Create a Vec data (vector)
    lmm::Vec vecData = {1.2, 2.5, 3.8, 2.0, 4.2};
    dataList.push_back({vecData, LMM_MAGENTA});

    // Create a function data
    lmm::Func funcData = [](double x) { return x * x; };
    dataList.push_back({funcData, LMM_BLUE});

    lmm::Func funcData2 = [](double x) { return std::sin(x); };

    // Create a points data
    lmm::DataPoints pointsData = {{1.0, 1.0}, {2.0, 4.0}, {3.0, 9.0}, {4.0, 16.0}};
    dataList.push_back({pointsData, LMM_GREEN});

    // Create the graph window
    lmm::createGraphWindow(dataList);

    return 0;
}
