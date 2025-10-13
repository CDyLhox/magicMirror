//
// Created by cashu on 31/05/2025.
//

#include "low-passFilter.h"
#include <iostream>

LPF::LPF(float g)
{
    std::cout << "LPF - constructor" << std::endl;
    this->g = g;
}

LPF::~LPF()
{
    std::cout << "LPF - destructor" << std::endl;
}

double LPF::process(double input)
{

    double output = input + g * y1;
    y1 = output;

    return output;
    std::cout << "LPF - destructor" << std::endl;
}
