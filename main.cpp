#include "2dTransformation.h"

int main()
{
    int x1 = 3;
    int y1 = 2;

    int x2 = 4;
    int y2 = 3;
    
    int x3 = 5;
    int y3 = 2;

    float d1 = sqrt(5);
    float dir1 = -90-26.565;
    
    float d2 = 2*sqrt(5);
    float dir2 = -90-26.565;

    float d3 = sqrt(17);
    float dir3 = -104.036;


    vector<shared_ptr<flagKnowns>> flagVec;
    shared_ptr<flagKnowns> f1 = make_shared<flagKnowns>(flagKnowns{"f1",x1,y1,d1,dir1});
    shared_ptr<flagKnowns> f2 = make_shared<flagKnowns>(flagKnowns{"f2",x2,y2,d2,dir2});
    shared_ptr<flagKnowns> f3 = make_shared<flagKnowns>(flagKnowns{"f3",x3,y3,d3,dir3});

    flagVec.push_back(f1);
    flagVec.push_back(f2);
    flagVec.push_back(f3);

    relative2Abssolute(flagVec);
    return 0;
}