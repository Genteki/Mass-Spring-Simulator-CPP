//
//  Mass.hpp
//  Mass-Spring-Simulator
//
//  Created by Genteki on 2022/11/12.
//

#ifndef Mass_hpp
#define Mass_hpp

#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
class Mass {
private:
public:
    vector <double> pos;
    vector <double> vel;
    vector <double> acc;
    vector <double> f_external;
    double m;
    Mass(double ms, vector<double> p, vector<double> v, vector<double> a);
    Mass(double ms, vector<double> p);
    Mass(const Mass& other);
    Mass& operator=(const Mass& other);
};

double mass_distance(const Mass m1, const Mass m2);

#endif /* Mass_hpp */
