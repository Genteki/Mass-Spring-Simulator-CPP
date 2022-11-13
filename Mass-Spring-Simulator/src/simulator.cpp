//
//  Simulator.cpp
//  Mass-Spring-Simulator
//
//  Created by Genteki on 2022/11/12.
//

#include "simulator.hpp"
#include <math.h>
#include <iostream>

Simulator::Simulator(vector<Mass> m, list<SpringParam> spring_list, double pdt, double pk_ground, double pdamping, double pf_g, double pf_s) {
    dt = pdt;
    t = 0;
    f_g = pf_g;
    f_s = pf_s;
    k_ground = pk_ground;
    damping = pdamping;
    g = {0, 0, -9.801};
    vec_mass.reserve(m.size());
    vec_spring.reserve(spring_list.size());
    for (vector<Mass>::iterator iter = m.begin(); iter != m.end(); ++iter) {
        Mass new_mass(*iter);
        vec_mass.push_back(new_mass);
    }
    for (list<SpringParam>::iterator iter = spring_list.begin(); iter != spring_list.end(); ++iter) {
        vec_spring.push_back(Spring(vec_mass[iter->m1], vec_mass[iter->m2], iter->l0, iter->k));
    }
}

void Simulator::simulate() {
    t = t + dt;
    // Interaction step
    // reset f_external for mass, g
    for (vector<Mass>::iterator it = vec_mass.begin(); it !=vec_mass.end(); it++) {
        for (int i = 0; i < 3; ++i) {
            it->f_external[i] = it->m * g[i];
        }
    }
    // calculate tension
    for (vector<Spring>::iterator it = vec_spring.begin(); it != vec_spring.end(); ++it) {
        it -> cal_tension();
        for (int i = 0; i < 3; ++i) {
            (it -> pt_m1 -> f_external[i]) -= it -> tension[i];
            (it -> pt_m2 -> f_external[i]) += it -> tension[i];
        }
    }
    // collision to ground
    for (vector<Mass>::iterator it = vec_mass.begin(); it != vec_mass.end(); ++it) {
        if (it->pos[2] < 0) {
            // restoring force
            it->f_external[2] -= it->pos[2] * k_ground;
            // kinetic friction
            if (it->vel[0] != 0 && it->vel[1] != 0 && it->f_external[2] > 0) {
                double speed = sqrt(it->vel[0] * it->vel[0] + it->vel[1] * it->vel[1]);
                it->f_external[0] -= it->vel[0] * it->f_external[2] * f_g / speed;
                it->f_external[1] -= it->vel[1] * it->f_external[2] * f_g / speed;
            }
        }
    }
    // Integration Step
    for (vector<Mass>::iterator it = vec_mass.begin(); it != vec_mass.end(); ++it) {
        for (int i = 0; i < 3; ++i) {
            it->acc[i] = it->f_external[i] / it->m;
            it->vel[i] = it->vel[i] * damping + it->acc[i] * dt;
            it->pos[i] = it->pos[i] + it->vel[i] * dt;
        }
    }
}

double Simulator::grav() {
    return g[2];
}
