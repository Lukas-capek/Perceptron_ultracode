#include "Perceptron.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <stdlib.h>

using namespace std;

Algebra::Algebra() {}
vector<double> Algebra::soucet_vektoru(vector<double> a, vector<double> b)
{
    vector<double> soucet;
    for (int i = 0; i < a.size(); i++) {
        soucet.push_back(a[i] + b[i]);
    }
    return soucet;
}

double Algebra::skalarni_soucin(vector<double> a, vector<double> b)
{
    double produkt = 0;
    for (int i = 0; i < a.size(); i++) {
        produkt = produkt + a[i] * b[i];
    }
    return produkt;
}

vector<double> Algebra::vektor_skalar(vector<double> v, double k)
{
    for(int i = 0; i < v.size() ; ++i) {
        v[i] = v[i] * k;
    }
    return v;
}

vector<double> Algebra::jednotkovy_vektor(vector<double> a) {
    vector<double> u;
    double velikost_a;

    velikost_a = sqrt(Algebra::skalarni_soucin(a, a));

    u = Algebra::vektor_skalar(a, 1/velikost_a);

    return u;
}

Perceptron::Perceptron() {}
vector<vector<double>> Perceptron::nacist_data(string cesta)
{

    ifstream vstup(cesta);
    vector<vector<double>> vysledek;
    int i = 0;

    while (true) {

        string radek;

        getline(vstup, radek);
        if( vstup.eof() ) break;

        istringstream iss(radek);

        vector<double> prazdny;
        vysledek.push_back(prazdny);

        while (true) {
            double prvek;
            iss >> prvek;
            if( iss.eof() ) break;
            cerr << prvek << endl;
            vysledek[i].push_back(prvek);
        }

        i++;

    };

    return vysledek;

}

double Perceptron::vahova_funkce(vector<double> w, vector<double> bod)
{
    double h;
    double soucin = Perceptron::skalarni_soucin(w, bod);
    if (soucin >= 0) {
        h = 1;
    }
    else {
        h = 0;
    }
    return h;
}

void Perceptron::uceni(vector<vector<double>> data, double k)
{
    for (int i = 0; i < data.size(); i++) {
        vector<double> w0 = Perceptron::vektor_vah;
        vector<double> bod = data[i];
        double g = bod[bod.size()-1];
        cout << "hodnota g " << g << endl;
        bod.pop_back();
        double h = Perceptron::vahova_funkce(w0, bod);
        cout << "hodnota h " << h << endl;

        vector<double> korekce = Perceptron::vektor_skalar(bod, k*(g-h));
        vector<double> w1 = Perceptron::soucet_vektoru(w0, korekce);
        w1 = Perceptron::jednotkovy_vektor(w1);

        cout << "Prubezna hodnota" << endl;
        for (auto const& value : w1)
        {
            cout << value << endl;
        }

        Perceptron::vektor_vah = w1;
    }
}
