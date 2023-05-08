#include <iostream>
#include <iomanip>
#include <LMM/LMM.h>
#include <cmath>


int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    // Create a graph object
    lmm::Graph graph(screenWidth, screenHeight);

    // Define the functions to draw
    const int numFuncs = 3;
    std::pair<lmm::Func, Color> funcs[numFuncs] = {{
        [](float x) { return 0.5 * x + 10; }, BLUE
    }, {
        [](float x) { return -0.25 * x * x + 5; }, RED
    }, {
        [](float x) { return 5 * std::sin(M_PI* x); }, GREEN
    }};

    // Define the bounds of the graph
    const float minX = -50;
    const float maxX = 50;
    const float minY = -50;
    const float maxY = 50;

    // Draw the graph
    graph.Draw(funcs, numFuncs, minX, maxX, minY, maxY);

    return 0;
}
