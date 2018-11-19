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
float v=300;
float tet=45;
int N=17500;
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
  float delta=0.001;
  //Colocando las condiciones iniciales
  tiempo[0]=0.0;

  vely[0]=
  posx[0]=0.0;
  posy[0]=0.0;




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

  for (int l=10;l<=tetmax;l+=10)
  {
    velx[0]=v*cos(l);
    vely[0]=v*sin(l);
    velx[0]=v*cos(l)-0.5*delta*(vxp(velx[0],vely[0]));
    vely[0]=v*sin(l)-0.5*delta*(vyp(velx[0],vely[0]));

    for (int k=1;k<=N;k++)
    {
      double norma_v=sqrt(velx[k-1]*velx[k-1]+vely[k-1]*vely[k-1]);
      velx[k]=velx[k-1]+delta*(-(c*norma_v*velx[k-1])/m);
      vely[k]=vely[k-1]+delta*(-g-(c*norma_v*vely[k-1])/m);
      posx[k]=posx[k-1]+velx[k-1]*delta;
      posy[k]=posy[k-1]+vely[k-1]*delta;
      tiempo[k]=tiempo[k-1]+delta;
      //cout<<tiempo[k]<<","<<posx[k]<<","<<posy[k]<<","<<velx[k]<<","<<vely[k]<<endl;
      file<<tiempo[k]<<","<<posx[k]<<","<<posy[k]<<","<<velx[k]<<","<<vely[k]<<endl;
      file<<endl;
    }

  }
file.close();
  return 0;
}
