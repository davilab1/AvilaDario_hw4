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
int tetmax=70;

float funcion1(float y, float y2, float x);
float funcion2(float y, float y2, float x);

float vxp(float vx,float vy);
float vxp(float vx,float vy)
{
  //return (-c*vx*(pow(vx,2)+pow(vy,2)))/(m*(sqrt(pow(vx,2)+pow(vy,2))));
  return (-c*vx*vx)/m;
}

float vyp(float vx,float vy);
float vyp(float vx,float vy)
{
  //return (-g*(c*vy*(pow(vx,2)+pow(vy,2))))/(m*(sqrt(pow(vx,2)+pow(vy,2))));
  return -g*(-c*vy*vy)/m;
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
  velx[0]=v*cos(tet);
  vely[0]=v*sin(tet);
  posx[0]=0.0;
  posy[0]=0.0;


  for (int i=0;i<N;i++)
  {
    double norma_v=sqrt(velx[i-1]*velx[i-1]+vely[i-1]*vely[i-1]);
    velx[i]=velx[i-1]+delta*(-(c*norma_v*velx[i-1])/m);
    vely[i]=vely[i-1]+delta*(-g-(c*norma_v*vely[i-1])/m);
    posx[i]=posx[i-1]+velx[i-1]*delta;
    posy[i]=posy[i-1]+vely[i-1]*delta;
    tiempo[i]=tiempo[i-1]+delta;
    cout<<tiempo[i]<<","<<posx[i]<<","<<posy[i]<<","<<velx[i]<<","<<vely[i]<<endl;

  }
//Para los casos en los que varia el angulo
  for (int l=10;l<=tetmax;l+=10)
  {
    velx[0]=v*cos(l);
    vely[0]=v*sin(l);

    for (int k=0;k<=N;k++)
{
  double norma_v=sqrt(velx[k-1]*velx[k-1]+vely[k-1]*vely[k-1]);
  velx[k]=velx[k-1]+delta*(-(c*norma_v*velx[k-1])/m);
  vely[k]=vely[k-1]+delta*(-g-(c*norma_v*vely[k-1])/m);
  posx[k]=posx[k-1]+velx[k-1]*delta;
  posy[k]=posy[k-1]+vely[k-1]*delta;
  tiempo[k]=tiempo[k-1]+delta;
  cout<<tiempo[k]<<","<<posx[k]<<","<<posy[k]<<","<<velx[k]<<","<<vely[k]<<endl;

}

}



  return 0;
}
