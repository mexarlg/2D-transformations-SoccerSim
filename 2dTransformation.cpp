#include "2dTransformation.h"


void relative2Abssolute(vector<shared_ptr<flagKnowns>> &flags)
{
// declaration of flags
float theta1 = -flags.at(0)->direccion;
float d1 = flags.at(0)->distancia;
float x1 = flags.at(0)->x;
float y1 = flags.at(0)->y;

float theta2 = -flags.at(1)->direccion;
float d2 = flags.at(1)->distancia;
float x2 = flags.at(1)->x;
float y2 = flags.at(1)->y;

float theta3 = -flags.at(2)->direccion;
float d3 = flags.at(2)->distancia;
float x3 = flags.at(2)->x;
float y3 = flags.at(2)->y;

// If f1 and f2 are almost collinear, change f2 to f3
float errorTheta = abs((theta1 - theta2)/theta1);
if(errorTheta < 0.01)
{
    float auxTheta = theta2;
    float auxD = d2;
    float auxX = x2;
    float auxY = y2;

    theta2 = theta3;
    d2 = d3;
    x2 = x3;
    y2 = y3;

    theta3 = auxTheta;
    d3 = auxD;
    x3 = auxX;
    y3 = auxY;

    cout << "f1 and f2 collinear, changing to f3" << endl;
}


float cosTheta1 = cos((M_PI/180)*theta1);
float sinTheta1 = sin((M_PI/180)*theta1);
float cosTheta2 = cos((M_PI/180)*theta2);
float sinTheta2 = sin((M_PI/180)*theta2);

// From the triangle, we are gonna solve for R and alpha. We gotta take care of signs and exceptions
// Does not work for collinear points
float R;
R = sqrt(d1*d1 + d2*d2 -2*d1*d2*cos((M_PI/180)*(theta1 - theta2)));
cout << "R: " << R << endl;

float psi;      // phase angle [rad]
float b = d2*sinTheta2 - d1*sinTheta1;
float a = d1*cosTheta1 - d2*cosTheta2;

if(abs(a) < 0.01){
    a = 0;}
if(abs(b) < 0.01){
    b = 0;}
cout << "a: " << a << "\t" << "b: " << b << endl;

psi = atan2(b,a);
cout << "psiº: " << (180/M_PI)*psi << endl;
cout << endl;

float beta;     // angle [rad]
float cosBeta = (x1 - x2)/R;
cout << "cosBeta: " << cosBeta << endl;

if(abs(cosBeta) <= 1){
    beta = acos(cosBeta);}
else{
    beta = 0;       // should throw error
    cout << "error, cosBeta > 1" << endl;
    }
cout << "beta: " << beta << endl;

// 2 possible solutions given alpha1 and alpha2
float alpha1 = psi + beta;
float alpha2 = psi - beta;

cout << "alpha1º: " << (180/M_PI)*alpha1 << "\t" << "alpha2º: " << (180/M_PI)*alpha2 << endl;
cout << endl;

float xp1 = x1 - d1*(cosTheta1*cos(alpha1) - sinTheta1*sin(alpha1));
float yp1 = y1 - d1*(cosTheta1*sin(alpha1) + sinTheta1*cos(alpha1));
cout << "x1: " << xp1 << "\t" << "y1: " << yp1 << endl;


float xp2 = x1 - d1*(cosTheta1*cos(alpha2) - sinTheta1*sin(alpha2));
float yp2 = y1 - d1*(cosTheta1*sin(alpha2) + sinTheta1*cos(alpha2));
cout << "x2: " << xp2 << "\t" << "y2: " << yp2 << endl;

// Make sure that the solution gives a similar distance to third flag
float distPlayer1Flag3 = sqrt((xp1 - x3)*(xp1 - x3) + (yp1 - y3)*(yp1 - y3));
float distPlayer2Flag3 = sqrt((xp2 - x3)*(xp2 - x3) + (yp2 - y3)*(yp2 - y3));

float x_player;
float y_player;

float error1 = abs((d3-distPlayer1Flag3)/d3);
float error2 = abs((d3-distPlayer2Flag3)/d3);

// check if solutions are accurate, if not give estimation and print error
if(error1 >= 0.5 && error2 >= 0.5)
{
    x_player = (xp1 + xp2)/2;
    y_player = (yp1 + yp2)/2;
    cout << "Position not accurate, approximation given" << endl; 

}
else if(error1 < error2)    // use solution 1 if error1 is smaller
{
    x_player = xp1;
    y_player = yp1;
}
else                        // use solution 2 if error2 is smaller
{
    x_player = xp2;
    y_player = yp2;
}

cout << "xPlayer: " << x_player << "\t" << "yPlayer: " << y_player << endl;

}

void abs2rel(vector<shared_ptr<flagKnowns>> &flags, float &x, float &y, float xBall, float yBall)
{

// Function estimates the alpha angle with the position of the ball, which is not correct as the
// head direction will not be really coincident

float x1 = flags.at(0)->x;
float y1 = flags.at(0)->y;

float x2 = flags.at(1)->x;
float y2 = flags.at(1)->y;

float dy1 = y1 - y;
float dx1 = x1 - x;

float dy2 = y2 - y;
float dx2 = x2 - x;

float dyBall = yBall - y;
float dxBall = xBall - x;

// Try to not have small numbers
if(dy1 <= 0.01){
    dy1 = 0;
}else if(dx1 <= 0.01){
    dx1 = 0;
}

if(dy2 <= 0.01){
    dy2 = 0;
}else if(dx2 <= 0.01){
    dx2 = 0;
}

if(dyBall <= 0.01){
    dyBall = 0;
}else if(dx2 <= 0.01){
    dxBall = 0;
}

float alpha = atan2(dyBall, dxBall);

// beta = theta + alpha [rad]
float beta1 = atan2(dy1,dx1);
float beta2 = atan2(dy2,dx2);

float theta1 = beta1 - alpha;
float theta2 = beta2 - alpha;

// directions are negative ccw
float direccion1 = -(180/M_PI)*theta1;
float direccion2 = -(180/M_PI)*theta2;

cout << "dir1º: " << direccion1 << "\t" << "dir2º:" << direccion2 << endl; 

}

void positionBall(vector<shared_ptr<flagKnowns>> &flags, float &x, float &y)
{
    
}