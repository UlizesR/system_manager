#include <iostream>
#include <iomanip>
#include <LMM/LMM.h>

float square(float x)
{
    return x * x;
}

int main(int argc, char *argv[]) 
{
    

    std::cout << "Factorial of 5: " << lmm::factorial(5) << std::endl;

    std::cout << "Summation of squares from 1 to 10: " << lmm::summation(square, 1, 10) << std::endl;


    return 0;
}

