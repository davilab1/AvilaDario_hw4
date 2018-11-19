#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

//Condiciones iniciales
float g=10.0;
double c=0.2;
float m=0.2;
float xi=0;
float yi=0;
float v=300;
float tet=45;
int N=1800;
#define pi 3.14159

int tetmax=70;

double vxp(float vx,float vy);
double vxp(float vx,float vy)
{
  //return (-c*vx*(pow(vx,2)+pow(vy,2)))/(m*(sqrt(pow(vx,2)+pow(vy,2))));
  return (-c*vx*vx)/m;
}

double vyp(float vx,float vy);
double vyp(float vx,float vy)
{
  //return (-g*(c*vy*(pow(vx,2)+pow(vy,2))))/(m*(sqrt(pow(vx,2)+pow(vy,2))));
  return (-g*((-c*vy*vy)/m));
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

  double tiempo2[N];
  double velx2[N];
  double vely2[N];
  double posx2[N];
  double posy2[N];

  float delta=0.001;
  //Colocando las condiciones iniciales
  tiempo[0]=0.0;
  velx[0]=v*cos((tet*pi)/180);
  vely[0]=v*sin((tet*pi)/180);
  posx[0]=0.0;
  posy[0]=0.0;

  velx[0]=v*cos((tet*pi)/180)+0.5*delta*(-(c*pow(velx[0],2))/m);
  vely[0]=v*sin((tet*pi)/180)+0.5*delta*(-g-(c*pow(vely[0],2))/m);

  ofstream archivo ("datosODE1.dat");
  archivo.is_open();

  for (int i=1;i<N;i++)
  {
    double norma_v=sqrt(velx[i-1]*velx[i-1]+vely[i-1]*vely[i-1]);

    velx[i]=velx[i-1]+delta*(-(c*norma_v*velx[i-1])/m);
    vely[i]=vely[i-1]+delta*(-g-(c*norma_v*vely[i-1])/m);
    posx[i]=posx[i-1]+velx[i-1]*delta;
    posy[i]=posy[i-1]+vely[i-1]*delta;
    tiempo[i]=tiempo[i-1]+delta;
    //cout<<tiempo[i]<<","<<posx[i]<<","<<posy[i]<<","<<velx[i]<<","<<vely[i]<<endl;
    archivo <<tiempo[i]<<","<<posx[i]<<","<<posy[i]<<","<<velx[i]<<","<<vely[i]<<endl;
  }

  archivo.close();


//Para los casos en los que varia el angulo
ofstream file ("datosODE2.dat");
file.is_open();

  for (float l=10;l<=tetmax;l+=10)
  {
    //cout<<l<<endl;
    velx2[0]=v*cos((l*pi)/180);
    vely2[0]=v*sin((l*pi)/180);
    velx2[0]=v*cos((l*pi)/180)+0.5*delta*(-(c*pow(velx2[0],2))/m);
    vely2[0]=v*sin((l*pi)/180)+0.5*delta*(-g-(c*pow(vely2[0],2))/m);
    posx2[0]=0.0;
    posy2[0]=0.0;
    tiempo2[0]=0.0;

    for (int k=1;k<=N;k++)
    {
      double norma_v2=sqrt(velx2[k-1]*velx2[k-1]+vely2[k-1]*vely2[k-1]);

      velx2[k]=velx2[k-1]+delta*(-(c*norma_v2*velx2[k-1])/m);
      vely2[k]=vely2[k-1]+delta*(-g-(c*norma_v2*vely2[k-1])/m);

      posx2[k]=posx2[k-1]+velx2[k-1]*delta;
      posy2[k]=posy2[k-1]+vely2[k-1]*delta;

      tiempo2[k]=tiempo2[k-1]+delta;
      //cout<<tiempo[k]<<","<<posx[k]<<","<<posy[k]<<","<<velx[k]<<","<<vely[k]<<endl;
      file<<tiempo2[k]<<","<<posx2[k]<<","<<posy2[k]<<","<<velx2[k]<<","<<vely2[k]<<endl;
    }
  }
file.close();
  return 0;
}
