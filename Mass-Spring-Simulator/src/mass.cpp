//
//  Mass.cpp
//  Mass-Spring-Simulator
//
//  Created by Genteki on 2022/11/12.
//

#include "mass.hpp"

Mass::Mass(double ms, vector<double> p, vector<double> v, vector<double> a) {
    m = ms;
    pos = p;
    vel = v;
    acc = a;
    f_external = {0,0,0};
}

Mass::Mass(double ms, vector<double> p) {
    m = ms;
    pos = p;
    vector<double> zero_arr(3,0);
    vel = zero_arr;
    acc = zero_arr;
    f_external = zero_arr;
}

// copy constructor
Mass::Mass(const Mass& other) {
    m = other.m;
    pos = other.pos;
    vel = other.vel;
    acc = other.acc;
    f_external = other.f_external;
}

Mass& Mass::operator=(const Mass& other) {
    m = other.m;
    pos = other.pos;
    vel = other.vel;
    acc = other.acc;
    f_external = other.f_external;
    return *this;
}

double mass_distance(const Mass m1, const Mass m2) {
    double d = 0;
    for (int i = 0; i < 3; ++i) {
        d = d + (m1.pos[i] - m2.pos[i]) * (m1.pos[i] - m2.pos[i]);
    }
    d = sqrt(d);
    return d;
}

