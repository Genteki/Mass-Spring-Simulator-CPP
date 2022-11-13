//
//  Simulator.hpp
//  Mass-Spring-Simulator
//
//  Created by Genteki on 2022/11/12.
//

#ifndef Simulator_hpp
#define Simulator_hpp

#include <stdio.h>
#include <vector>
#include <list>
#include "mass.hpp"
#include "spring.hpp"
using namespace std;

class Simulator{
private:
    double dt;
    double t;
    double f_g;
    double f_s;
    double k_ground;
    double damping;
    vector<double> g;
public:
    vector<Spring> vec_spring;
    vector<Mass> vec_mass;
//    Simulator();
    Simulator(vector<Mass> m, list<SpringParam> spring_list, double pdt = 0.0004, double pk_ground = 20000, double pdamping = 1, double pf_g = 0.7, double pf_s = 0.6);
    inline double get_time() {return t;}
    void reset_mass(vector<Mass> m);
    void generate_spring(list<SpringParam> spring_list);
    void simulate();
    double grav();
};


#endif /* Simulator_hpp */
