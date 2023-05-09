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