#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;


struct flagKnowns
{
    string name;
    int x;
    int y;
    float distancia;
    float direccion;
};

void relative2Abssolute(vector<shared_ptr<flagKnowns>> &flags);
void abs2rel(vector<shared_ptr<flagKnowns>> &flags, float &x, float &y, float &alpha);
void positionBall(vector<shared_ptr<flagKnowns>> &flags, float &x, float &y);