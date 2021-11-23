#ifndef RANDOMBOD_H
#define RANDOMBOD_H
#include <random>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<auto> v){
    for(int i = 0; i<v.size(); i++){
        cout << v[i] << " " ;
    }
    cout<< endl;
}

class RandomBod{
   public:
       const double PI = 3.141592653;
       double m_radius, m_x_center, m_y_center;
       int m_group;
       double uniform(){
        return (double)rand()/RAND_MAX;
       }
    RandomBod(double radius, double x_center, double y_center, int group)
    {
        srand(time(NULL));
        m_radius = radius; m_x_center = x_center; m_y_center = y_center;
        m_group = group;
    }
    vector <double> randPoint() {
        double phi = 2 * PI * uniform();
        double r = sqrt(uniform());
        return vector<double>{
            m_x_center + r * m_radius * cos(phi),
            m_y_center + r * m_radius * sin(phi),
            m_group
        };
    }

};

#endif // RANDOMBOD_H
