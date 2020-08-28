/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2020 Bolder Flight Systems
*/

#include "filter/filter.h"
#include <array>
#include <iostream>

/*
* MATLAB's moving average filter example from: 
* https://www.mathworks.com/help/matlab/ref/filter.html
*/

std::array<float, 100> x = {
  0.2037,
  0.1630,
  -0.0948,
  0.0391,
  -0.0931,
  -0.2876,
  -0.3020,
  -0.2931,
  -0.2468,
  -0.2994,
  -0.5535,
  -0.4001,
  -0.4508,
  -0.6132,
  -0.5761,
  -0.7791,
  -0.7443,
  -0.6525,
  -0.7116,
  -0.6943,
  -0.7910,
  -0.9629,
  -0.7725,
  -0.7603,
  -0.8292,
  -0.8104,
  -0.8111,
  -0.8918,
  -0.8149,
  -0.9210,
  -0.7685,
  -0.9144,
  -0.8268,
  -0.8545,
  -0.8083,
  -0.5899,
  -0.5820,
  -0.6334,
  -0.4292,
  -0.6095,
  -0.4574,
  -0.4183,
  -0.2668,
  -0.2021,
  -0.2953,
  -0.1593,
  -0.1089,
  0.0036,
  0.0823,
  0.1569,
  0.1007,
  0.2650,
  0.3218,
  0.2610,
  0.3115,
  0.4666,
  0.6409,
  0.5433,
  0.6600,
  0.6230,
  0.8060,
  0.7305,
  0.8392,
  0.9305,
  1.0185,
  1.0724,
  1.0028,
  0.9306,
  0.9597,
  1.0094,
  1.1740,
  1.0424,
  1.1934,
  1.0577,
  1.2322,
  1.0864,
  1.0430,
  1.0476,
  1.1258,
  1.0732,
  1.0221,
  1.1173,
  1.0278,
  0.9872,
  1.0439,
  0.8476,
  0.9239,
  0.8785,
  0.7379,
  0.7349,
  0.5596,
  0.4997,
  0.5625,
  0.5665,
  0.5455,
  0.2836,
  0.3315,
  0.2439,
  0.0664,
  0.0843
};

std::array<float, 100> y;

int main() {
  std::array<float, 5> b = {0.2, 0.2, 0.2, 0.2, 0.2};
  std::array<float, 1> a = {1};
  filters::DigitalFilter1D<float, 5, 1> dlpf(b, a);
  for (std::size_t i = 0; i < x.size(); i++) {
    y[i] = dlpf.Filter(x[i]);
    std::cout << y[i] << std::endl;
  }
}
