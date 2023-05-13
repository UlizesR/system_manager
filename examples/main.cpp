#include <iostream>
#include <iomanip>
#include <LMM/LMM.h>
#include <cmath>

int main()
{
    // Create vectors
    lmm::Vector vec1({1.0f, 2.0f, 3.0f});
    lmm::Vector vec2({4.0f, 5.0f, 6.0f});

    // Perform vector operations
    lmm::Vector vecSum = vec1 + vec2;
    lmm::Vector vecSub = vec1 - vec2;
    float dotProduct = vec1 * vec2;

    // Print vector results
    std::cout << "Vector Sum:" << std::endl;
    vecSum.print();
    std::cout << "Vector Subtraction:" << std::endl;
    vecSub.print();
    std::cout << "Dot Product:" << dotProduct << std::endl;

    // Create matrices
    // Create matrices with matching dimensions
    std::vector<lmm::Vector> matrixData1 = {lmm::Vector({1.0f, 2.0f}), lmm::Vector({3.0f, 4.0f})};
    std::vector<lmm::Vector> matrixData2 = {lmm::Vector({5.0f, 6.0f}), lmm::Vector({7.0f, 8.0f})};

    lmm::Matrix mat1(matrixData1);
    lmm::Matrix mat2(matrixData2);

    // Perform matrix operations
    lmm::Matrix matSum = mat1 + mat2;
    lmm::Matrix matSub = mat1 - mat2;

    // Print matrix results
    std::cout << "Matrix Sum:" << std::endl;
    matSum.print();
    std::cout << "Matrix Subtraction:" << std::endl;
    matSub.print();

    return 0;
}