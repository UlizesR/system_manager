#include <iostream>
#include <iomanip>
#include <LMM/LMM.h>

int main(int argc, char *argv[]) 
{
    lmm::Func square = [](double x) { return x * x; };

    std::cout << "Summation of squares from 1 to 10: " << lmm::summation(square, 1, 10) << std::endl;


    return 0;
}

