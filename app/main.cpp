#include <iostream>
#include <iomanip>
#include <LMM/LMM.h>
#include <cmath>

double func1(double x) {
    return x * x;
}

double func2(double x) {
    return sin(x);
}

int main() {
    lmm::Graph graph(800, 600);
    std::pair<lmm::Func, Color> funcs[] = {{func1, RED}, {func2, BLUE}};
    graph.Draw(funcs, 2);
    return 0;
}