//
//  Spring.hpp
//  Mass-Spring-Simulator
//
//  Created by Genteki on 2022/11/12.
//

#ifndef Spring_hpp
#define Spring_hpp

#include <stdio.h>
#include <vector>
#include "mass.hpp"

class Spring{
private:
public:
    Mass* pt_m1;
    Mass* pt_m2;
    double l0;
    double l00;
    double k;
    vector<double> tension;
    
    Spring(Mass& mass1, Mass& mass2, double rest_length, double k_spring);
    Spring(const Spring& other);
    Spring& operator=(const Spring& other);
    vector<double> cal_tension();
};

struct SpringParam{
    int m1;
    int m2;
    double l0;
    double k;
    SpringParam(int pm1, int pm2, double pl0, double pk);
    SpringParam(const SpringParam& other);
    SpringParam& operator=(const SpringParam& other);
};

#endif /* Spring_hpp */
