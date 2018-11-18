#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//Condiciones iniciales
float k=1.62;
double cp=820;
double p=2.71;
double v=k/(cp*p);
int N=100000;
int tini_vari=100;
int tini_calc=10;
double t[50];
double circulo=x*x+y*y;

//3 metodos, uno por cada caso
//Caso 1-Fronteras fijas
void caso1();
//caso 2- Fronteras abiertas
void caso2();
//Caso 3- Fronteras periodicas
voida caso3();

int main()
{

//Creando lamina junto con varilla
for (int i=1;i<=50;i++)
{
  for (int j=1;j<=50;j++)
  {
    //Aplicando la ecuacion del circulo
    if()
    {
      t[i,j]=tini_vari;
    }
    else
    {
      t[i,j]=tini_calc;
    }
  }
}




  return 0;
}

void caso1()
{
float temp[50][50];
float pasox=1.0;
float pasoy=1.0;
float delta=0.001;

//Creando la lamina junto con varilla, condiciones iniciales


}
