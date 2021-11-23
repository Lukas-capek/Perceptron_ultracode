#include <iostream>
#include <random>
#include <cmath>
#include "RandomBod.h"
#include <algorithm>

using namespace std;

int main()
{

    int n = 15; //pocet bodu
    RandomBod ob(5, 0, 12, 0); // Polomer, x_stred, y_stred, skupina
    vector <vector<double>> Res1;

    for(int i = 1; i<n; i++)
    {
        Res1.push_back(ob.randPoint()); // matice bodu skupiny 1
    }

    RandomBod bo(5, 10, 2, 1); // Polomer, x_stred, y_stred, skupina
    vector <vector<double>> Res2;

    for(int i = 1; i<n; i++)
    {
        Res2.push_back(bo.randPoint()); //matice bodu skupiny 2
    }

    Res1.insert(Res1.end(),Res2.begin(),Res2.end()); //napojeni matic

    random_shuffle(begin(Res1), end(Res1)); //zamichani matic

     for(int i=0; i<Res1.size(); i++){
       for (int j=0; j<Res1[i].size();j++){
            cout<< Res1[i][j]<< " ";
        }
        cout <<endl;
    }
    return 0;
}
