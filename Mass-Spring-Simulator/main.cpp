//
//  main.cpp
//  Mass-Spring-Simulator
//
//  Created by Genteki on 2022/11/12.
//

#include <iostream>
#include <vector>
#include "mass.hpp"
#include "spring.hpp"
#include "simulator.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<double> p1 {0,0,5};
    vector<double> p2 {0,1,5};
    Mass m1(1, p1);
    Mass m2(2, p2);
    vector<Mass> vm;
    vm.reserve(2);
    vm[0] = m1; vm[1] = m2;
    vm.push_back(m1); vm.push_back(m2);
    SpringParam sp(0,1,0.5,10);
    list<SpringParam> lsp;
    lsp.push_back(sp);
    Simulator sim(vm, lsp);
    int ct = 0; int time_step = 100;
    while (sim.get_time() < 10) {
        sim.simulate();
        if (ct == time_step) {
            ct = 0;
            cout << "t: " << sim.get_time() << "\t";
            cout << "m1: " << sim.vec_mass[0].pos[1] << "\t";
            cout << "m2: " << sim.vec_mass[1].pos[1] << "\t";
            cout << "m1f: " << sim.vec_mass[0].f_external[1] << endl;
        }
        ct = ct + 1;
    }
    cout << (sim.vec_mass.begin()==sim.vec_mass.end());
    cout << sim.vec_mass.size();
    cout << vm.size();
    return 0;
}
