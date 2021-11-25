#include "Perceptron.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    Perceptron perceptron;

    vector<vector<double>> data;

    data = perceptron.nacist_data("body.txt");

    perceptron.vektor_vah = {1, 1};

    perceptron.uceni(data, 0.2);
}
