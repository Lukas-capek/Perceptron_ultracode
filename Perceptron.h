#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

class Algebra
{
    public:
        Algebra();
        vector<double> soucet_vektoru(vector<double> a, vector<double> b);      // soucet vektoru stejnych delek
        double skalarni_soucin(vector<double> a, vector<double> b);             // skalarni soucin dvou vektoru
        vector<double> vektor_skalar(vector<double> v, double k);               // nasobeni vektoru skalarem
        vector<double> jednotkovy_vektor(vector<double> a);                     // spocte jednotkovy vektor
    protected:
    private:
};

class Perceptron : public Algebra
{
    public:
        Perceptron();
        vector<double> vektor_vah = {1, 0};

        vector<vector<double>> nacist_data(string cesta);               // nacte data z .txt a ulozi je ve formatu {{a,b,c},{d,e,f}...}
        double vahova_funkce(vector<double> w, vector<double> bod);     // implementace vahove funkce
        void uceni(vector<vector<double>> data, double k);              // aplikace samotneho perceptronu
    protected:
    private:
};

#endif // PERCEPTRON_H
