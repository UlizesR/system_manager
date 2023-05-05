#include <iostream>
#include "LMM/include/LMM/lmm_matrix.h"

int main(int argc, char *argv[]) 
{
    lmm::Mat a = {{1, 2, 3}, {4, 5, 6}};
    lmm::Mat b = {{7, 8}, {9, 10}, {11, 12}};
    lmm::Mat c = lmm::mat_mul(a, b);
    lmm::Mat d = lmm::mat_inverse(c);
    for (int i = 0; i < d.size(); i++) {
        for (int j = 0; j < d[i].size(); j++) {
            std::cout << d[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}