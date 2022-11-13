//
//  Spring.cpp
//  Mass-Spring-Simulator
//
//  Created by Genteki on 2022/11/12.
//

#include "spring.hpp"

Spring::Spring(Mass& mass1, Mass& mass2, double rest_length, double k_spring) {
    pt_m1 = &mass1;
    pt_m2 = &mass2;
    l00 = rest_length;
    l0 = rest_length;
    k = k_spring;
    tension = {0, 0, 0};
}

Spring::Spring(const Spring& other) {
    pt_m1 = other.pt_m1;
    pt_m2 = other.pt_m2;
    l00 = other.l00;
    l0 = other.l0;
    k = other.k;
    tension = {0, 0, 0};
}

Spring& Spring::operator=(const Spring &other) {
    pt_m1 = other.pt_m1;
    pt_m2 = other.pt_m2;
    l00 = other.l00;
    l0 = other.l0;
    k = other.k;
    tension = {0, 0, 0};
    return *this;
}

vector<double> Spring::cal_tension() {
    double l = mass_distance(*pt_m1, *pt_m2);
    double f_scale = k * (l - l0);
    for (int i = 0; i < 3; ++i) {
        tension[i] = (pt_m1->pos[i] - pt_m2->pos[i]) * f_scale / l;
    }
    return tension;
}

SpringParam::SpringParam(int pm1, int pm2, double pl0, double pk) {
    m1 = pm1;
    m2 = pm2;
    l0 = pl0;
    k = pk;
}

SpringParam::SpringParam(const SpringParam& other) {
    m1 = other.m1;
    m2 = other.m2;
    l0 = other.l0;
    k = other.k;
}

SpringParam& SpringParam::operator=(const SpringParam &other) {
    m1 = other.m1;
    m2 = other.m2;
    l0 = other.l0;
    k = other.k;
    return *this;
}
