#include <iostream>
#include <cmath>
#include <cstdlib>
#include <math.h>
using namespace std;

//Condiciones iniciales
float k=1.62;
double cp=820;
double p=2.71;
double constante=k/(cp*p);
int N=100000;
int tini_vari=100.0;
int tini_calc=10;
double t[50];
float delta=1.0;
float deltat=0.001;

//3 metodos, uno por cada caso
//Caso 1-Fronteras fijas
void caso1();
//caso 2- Fronteras abiertas
void caso2();
//Caso 3- Fronteras periodicas
void caso3();

float temp1[50][50];
float temp_fu1[50][50];

float temp2[50][50];
float temp_fu2[50][50];

float temp3[50][50];
float temp_fu3[50][50];

int main()
{

//Creando lamina junto con varilla
for (int i=1;i<=50;i++)
{
  for (int j=1;j<=50;j++)
  {
    //Aplicando la ecuacion del circulo
    int circulo=pow(i-25,2)+pow(i-25,2);
    if(circulo<=25)//si el radio es menor a 5
    {
      temp1[i][j]=tini_vari;
      temp2[i][j]=tini_vari;
      temp3[i][j]=tini_vari;
    }
    else
    {
      temp1[i][j]=tini_calc;
      temp2[i][j]=tini_vari;
      temp3[i][j]=tini_vari;
    }
  }
}
  return 0;
}

void caso1()
//Tomando como referencia la ecuacion dada por Landau en la pagina 423
{

  for (int i=1;i<=50;i++)
  {
    for (int j=1;j<=50;j++)
    {
      temp_fu1[i][j]=temp1[i][j];
      int circulo=pow(i-25,2)+pow(i-25,2);

      if(i!=1 and i!=50 and j!=50 and circulo<25)
      { //Arreglando la ecuacion de landau para dos dimensiones
        temp_fu1[i][j]=temp1[i][j]+(((constante*deltat)/pow(delta,2))*((temp1[i+1][j]+temp1[i-1][j]-2*temp1[i][j])+(temp1[i][j+1]+temp1[i][j-1]-2*temp1[i][j])));

      }

    }
  }
  //Actualizando tiempo
  for(int i=0; i<50; i++)
  {
    for(int j=0; j<50; j++)
    {
      temp1[i][j] = temp_fu1[i][j];
    }
  }
}


void caso2()
{
  for (int i=1;i<=50;i++)
  {
    for (int j=1;j<=50;j++)
    {
      temp_fu2[i][j]=temp2[i][j];
      int circulo=pow(i-25,2)+pow(i-25,2);

      if(i!=1 and i!=50 and j!=50 and circulo<25)
      { //Arreglando la ecuacion de landau para dos dimensiones
        temp_fu2[i][j]=temp2[i][j]+(((constante*deltat)/pow(delta,2))*((temp2[i+1][j]+temp2[i-1][j]-2*temp2[i][j])+(temp2[i][j+1]+temp2[i][j-1]-2*temp2[i][j])));

      }
      for(int k=1;k<=50;k++)
      {
				temp_fu2[1][k] = temp_fu2[2][k];
				temp_fu2[50][k] = temp_fu2[49][k];
			}
			for(int l=1;l<=50;l++)
      {
				temp_fu2[l][1] = temp_fu2[l][2];
				temp_fu2[l][49] = temp_fu2[l][48];
    }
  }
//Actualizando tiempo
  for(int i=0; i<50; i++)
  {
    for(int j=0; j<50; j++)
    {
      temp2[i][j] = temp_fu2[i][j];
    }
  }
}
}


void caso3()
{
  for (int i=1;i<=50;i++)
  {
    for (int j=1;j<=50;j++)
    {
      temp_fu3[i][j]=temp3[i][j];
      int circulo=pow(i-25,2)+pow(i-25,2);

      if(i!=1 and i!=50 and j!=50 and circulo<25)
      { //Arreglando la ecuacion de landau para dos dimensiones
        temp_fu3[i][j]=temp3[i][j]+(((constante*deltat)/pow(delta,2))*((temp3[i+1][j]+temp3[i-1][j]-2*temp3[i][j])+(temp3[i][j+1]+temp3[i][j-1]-2*temp3[i][j])));
      }


      for(int m=1; m<=50; m++)
      {
					temp_fu3[0][m] = temp_fu3[50][m];
			}
			for(int n=1; n<=50; n++)
      {
				temp_fu3[n][0] = temp_fu3[n][49];
			}

    }
  }
  //actualizando el tiempo
  for(int i=0; i<50; i++)
  {
    for(int j=0; j<50; j++)
    {
      temp3[i][j] = temp_fu3[i][j];
    }
  }
}
