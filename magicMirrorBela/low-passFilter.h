//
//
// Created by cashu on 31/05/2025.
//

#pragma once

class LPF{
public:
    LPF() = default;
    LPF(float g);
    ~LPF();

    double process(double input);

private:
    double y1 = 0.0; // feedbackline 
    float g = 0.0f; // feedback (gain coeff)
};

