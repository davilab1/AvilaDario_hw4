#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//Condiciones iniciales
float g=10.0;
float c=0.2;
float m=0.2;
float xi=0;
float v=300;
float tet=45;
int N=10000;



float funcion1(float y, float y2, float x);
float funcion2(float y, float y2, float x);


float vxp(float vx,float vy);
float vxp(float vx,float vy)
{
  return (-c*vx*(pow(vx,2)+pow(vy,2)))/(m*(sqrt(pow(vx,2)+pow(vy,2))));
}

float vyp(float vx,float vy);
float vyp(float vx,float vy)
{
  return (-g*(c*vy*(pow(vx,2)+pow(vy,2))))/(m*(sqrt(pow(vx,2)+pow(vy,2))));
}

float vxin=v*cos(tet);
float vyin=v*sin(tet);

int main()
{
  float tiempo[N];
  double velx[N];
  double vely[N];
  double posx[N];
  double posy[N];
  float delta=0.0001;
  //Colocando las condiciones iniciales
  tiempo[0]=0.0;
  velx=v*cos(tet);
  vely=v*sin(tet);
  posx[0]=0;
  posy[0]=0;



  

  return 0;
}
