#include "Perceptron.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;


vector<vector<double>> readInput(string filename) {
    ifstream MyReadFile(filename);
    string line;
    vector<vector<double>> result;
    while (getline (MyReadFile, line)) {
        stringstream stream(line);
        vector<double> point;
        while(1) {
            double n;
            stream >> n;
            if(!stream)
                break;
            point.push_back(n);
        }
        result.push_back(point);
    }
    MyReadFile.close();
    return result;
}

vector<vector<double>> compute(Perceptron perceptron, vector<vector<double>> input) {
    for(int i = 0; i < input.size(); i++) {
        vector<double> weights = perceptron.vektor_vah;
        vector<double> point = input[i];
        double result = perceptron.vahova_funkce(weights, point);
        input[i].push_back(result);
    }
    return input;
}

void writeOutput(string filename, vector<vector<double>> result) {
    ofstream myfile;
    myfile.open(filename);
    for (vector<double> line: result) {
        myfile << line[0] << " " << line[1] << " " << line[2] << endl;
    }
    myfile.close();
}

int main()
{
    Perceptron perceptron;

    vector<vector<double>> data;

    data = perceptron.nacist_data("body.txt");

    perceptron.vektor_vah = {1, 0};

    perceptron.uceni(data, 0.1);


     vector<vector<double>> data2;
    data2 = readInput("input.txt");
    data2 = compute(perceptron, data2);
    writeOutput("output.txt", data2);

}
