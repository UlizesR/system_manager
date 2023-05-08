# LIB MATHEMATICA

---

A simple c++ math library that allows calculations and the graphing and visualization of data

---

## How to use

1. Clone repo

2. Open terminal and run the following commands

    make sure to have cmake install or set up
    ```
    mkdir build
    cd build
    cmake ..
    make
    ./app
    ```

--- 

## Features

- Can calculate finite sums and products
- Can graph functions
- Can do Vector and Matrix Arithmetic
    - (vector, matrix) addition, subtraction, multiplication, scaliing
    - (matrix) rank, Dim, Col, Row, Null space, transpose, Inverse, Determinant


## How to use

### Examples

Matrix and Vector Example
```c++
#include <LMM/LMM.h>

int main()
{
    lmm::Mat A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    lmm::Mat B = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    std::cout << "Matrix A: \n";
    lmm::mat_print(A);
    std::cout << "Matrix B: \n";
    lmm::mat_print(B);

    lmm::Vec v = {1, 2, 3};
    std::cout << "Vector v: \n";
    lmm::vec_print(v);

    lmm::Mat C = {v, v, v};

    std::cout << "Matrix C: \n";
    lmm::mat_print(C);

    std::cout << "Matrix A + B: \n";
    lmm::mat_print(lmm::mat_add(A, B));

    return 0;
}
```

Graphing Example
```c++
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
```