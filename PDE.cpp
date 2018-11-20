#include <iostream>
#include <cmath>
#include <cstdlib>
#include <math.h>
#include <fstream>
using namespace std;

//Condiciones iniciales
float k=1.62;
float cp=820;
float p=2.71;
float constante=k/(cp*p);
int N=10000;
int tini_vari=100.0;
int tini_calc=10;
double t[50];
float delta=10;
float deltat=0.5*delta/constante;

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

caso1();
caso2();
caso3();
  return 0;
}
//----------------------------------------------------------------------------------------------------------------------//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------//----------------------------------------------------------------------------------------------------------------------
void caso1()
//Tomando como referencia la ecuacion dada por Landau en la pagina 423
{
  for (int i=0;i<50;i++)
  {
    for (int j=0;j<50;j++)
    {
      //Aplicando la ecuacion del circulo
      int circulo=pow(float(i)-24,2)+pow(float(j)-24,2);
      if(circulo<=25)//si el radio es menor a 5
      {
        temp1[i][j]=tini_vari;
      }
      if(circulo>25)
      {
        temp1[i][j]=tini_calc;
      }

    }
  }
  ofstream ar1 ("datosPDEC11.dat");
  ar1.is_open();

    for(int i=0; i<50; i++)
    {
      for(int j=0; j<50; j++)
      {

        ar1<<temp1[i][j]<<" ";
      }
      ar1<<"\n";
    }
    ar1.close();

for(int t=0;t<50;t++)
{

  for (int i=1;i<49;i++)
  {
    for (int j=1;j<49;j++)
    {

      int circulo=pow(float(i)-24,2)+pow(float(j)-24,2);

      if(circulo>25)
      { //Arreglando la ecuacion de landau para dos dimensiones
        temp_fu1[i][j]=temp1[i][j]+(constante*deltat)*((temp1[i+1][j]+temp1[i-1][j]-2*temp1[i][j])/pow(delta,2)+(temp1[i][j+1]+temp1[i][j-1]-2*temp1[i][j])/pow(delta,2));

      }
      if(circulo<=25)
      {
        temp_fu1[i][j]=100;
      }
      for (int h=0;h<50;h++)
      {
        temp1[0][h]=tini_calc;
      }
      for (int h=0;h<50;h++)
      {
        temp1[h][0]=tini_calc;
      }
      for (int h=0;h<50;h++)
      {
        temp1[49][h]=tini_calc;
      }
      for (int h=0;h<50;h++)
      {
      temp1[h][49]=tini_calc;
      }
    }

  }

  for(int i=0; i<50; i++)
  {
    for(int j=0; j<50; j++)
    {
      temp1[i][j]=temp_fu1[i][j];
    }
  }
}
ofstream ar12 ("datosPDEC12.dat");
ar12.is_open();

  for(int i=0; i<50; i++)
  {
    for(int j=0; j<50; j++)
    {
      ar12<<temp_fu1[i][j]<<" ";
    }
    ar12<<"\n";
  }
  ar12.close();


//deido a que se presento una dificultad a la hora de crar el for y las iteraciones se copia y pega codigo
for(int t=0;t<100;t++)
{

  for (int i=1;i<49;i++)
  {
    for (int j=1;j<49;j++)
    {

      int circulo=pow(i-24,2)+pow(j-24,2);

      if(i!=1 and i!=50 and j!=1 and j!=50 and circulo>25)
      { //Arreglando la ecuacion de landau para dos dimensiones
        temp_fu1[i][j]=temp1[i][j]+(constante*deltat)*((temp1[i+1][j]+temp1[i-1][j]-2*temp1[i][j])/pow(delta,2)+(temp1[i][j+1]+temp1[i][j-1]-2*temp1[i][j])/pow(delta,2));

      }
      if(circulo<=25)
      {
        temp1[i][j]=tini_vari;
      }
      for (int h=0;h<50;h++)
      {
        temp1[0][h]=tini_calc;
      }
      for (int h=0;h<50;h++)
      {
        temp1[h][0]=tini_calc;
      }
      for (int h=0;h<50;h++)
      {
        temp1[49][h]=tini_calc;
      }
      for (int h=0;h<50;h++)
      {
      temp1[h][49]=tini_calc;
      }
    }

  }

  for(int i=0; i<50; i++)
  {
    for(int j=0; j<50; j++)
    {
      temp1[i][j]=temp_fu1[i][j];
    }
  }
}
ofstream ar13 ("datosPDEC13.dat");
ar13.is_open();

  for(int i=0; i<50; i++)
  {
    for(int j=0; j<50; j++)
    {
      ar13<<temp_fu1[i][j]<<" ";
    }
    ar13<<"\n";
  }
  ar13.close();



  for(int t=0;t<150;t++)
  {

    for (int i=1;i<49;i++)
    {
      for (int j=1;j<49;j++)
      {

        int circulo=pow(i-24,2)+pow(j-24,2);

        if(i!=1 and i!=50 and j!=1 and j!=50 and circulo>25)
        { //Arreglando la ecuacion de landau para dos dimensiones
          temp_fu1[i][j]=temp1[i][j]+(constante*deltat)*((temp1[i+1][j]+temp1[i-1][j]-2*temp1[i][j])/pow(delta,2)+(temp1[i][j+1]+temp1[i][j-1]-2*temp1[i][j])/pow(delta,2));

        }
        if(circulo<=25)
        {
          temp1[i][j]=tini_vari;
        }
        for (int h=0;h<50;h++)
        {
          temp1[0][h]=tini_calc;
        }
        for (int h=0;h<50;h++)
        {
          temp1[h][0]=tini_calc;
        }
        for (int h=0;h<50;h++)
        {
          temp1[49][h]=tini_calc;
        }
        for (int h=0;h<50;h++)
        {
        temp1[h][49]=tini_calc;
        }
      }

    }

    for(int i=0; i<50; i++)
    {
      for(int j=0; j<50; j++)
      {
        temp1[i][j]=temp_fu1[i][j];
      }
    }
  }
  ofstream ar14 ("datosPDEC14.dat");
  ar14.is_open();

    for(int i=0; i<50; i++)
    {
      for(int j=0; j<50; j++)
      {
        ar14<<temp_fu1[i][j]<<" ";
      }
      ar14<<"\n";
    }
    ar14.close();


//Cantidades
}

//----------------------------------------------------------------------------------------------------------------------//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
void caso2()
{

  for (int i=0;i<50;i++)
  {
    for (int j=0;j<50;j++)
    {
      //Aplicando la ecuacion del circulo
      int circulo=pow(i-24,2)+pow(j-24,2);
      if(circulo<=25)//si el radio es menor a 5
      {
        temp2[i][j]=tini_vari;
      }
      if(circulo>25)
      {
        temp2[i][j]=tini_calc;
      }
    }
  }
  //////////_-------------primer grupo de iteraciones
for(int t=0;t<500;t++)
{//Se realizan los desde 1 a 49 debido a que las fronteras presentan un error
  for (int i=1;i<49;i++)
  {
    for (int j=1;j<49;j++)
    {

      int circulo=pow(float(i)-24,2)+pow(float(j)-24,2);

      if(circulo>25)
      { //Arreglando la ecuacion de landau para dos dimensiones
        temp_fu2[i][j]=temp2[i][j]+(constante*deltat)*((temp2[i+1][j]+temp2[i-1][j]-2*temp2[i][j])/pow(delta,2)+(temp2[i][j+1]+temp2[i][j-1]-2*temp2[i][j])/pow(delta,2));
      }
      if(circulo<=25)
      {
        temp_fu2[i][j]=tini_vari;
      }

      for(int k=0;k<50;k++)
      {
        temp2[0][k] = temp_fu2[1][k];
        temp2[49][k] = temp_fu2[48][k];
      }
      for(int l=1;l<49;l++)
      {
        temp2[l][0] = temp_fu2[l][1];
        temp2[l][49] = temp_fu2[l][48];
      }

    }
  }
}

for(int i=0; i<50; i++)
{
  for(int j=0; j<50; j++)
  {
    temp2[i][j]=temp_fu2[i][j];
  }
}

//Actualizando tiempo
ofstream ar22 ("datosPDEC22.dat");
ar22.is_open();
  for(int i=0; i<50; i++)
  {
    for(int j=0; j<50; j++)
    {
      ar22<<temp_fu2[i][j]<<" ";
    }
    ar22<<"\n";
  }
  ar22.close();

    //////////_-------------segundo  grupo de iteraciones

  for(int t=0;t<800;t++)
  {//Se realizan los desde 1 a 49 debido a que las fronteras presentan un error
    for (int i=1;i<49;i++)
    {
      for (int j=1;j<49;j++)
      {

        int circulo=pow(float(i)-24,2)+pow(float(j)-24,2);

        if(circulo>25)
        { //Arreglando la ecuacion de landau para dos dimensiones
          temp_fu2[i][j]=temp2[i][j]+(constante*deltat)*((temp2[i+1][j]+temp2[i-1][j]-2*temp2[i][j])/pow(delta,2)+(temp2[i][j+1]+temp2[i][j-1]-2*temp2[i][j])/pow(delta,2));
        }
        if(circulo<=25)
        {
          temp_fu2[i][j]=tini_vari;
        }
        for(int k=0;k<50;k++)
        {
          temp2[0][k] = temp_fu2[1][k];
          temp2[49][k] = temp_fu2[48][k];
        }
        for(int l=1;l<49;l++)
        {
          temp2[l][0] = temp_fu2[l][1];
          temp2[l][49] = temp_fu2[l][48];
        }

      }
    }
  }

  for(int i=0; i<50; i++)
  {
    for(int j=0; j<50; j++)
    {
      temp2[i][j]=temp_fu2[i][j];
    }
  }

  //Actualizando tiempo
  ofstream ar23 ("datosPDEC23.dat");
  ar23.is_open();
    for(int i=0; i<50; i++)
    {
      for(int j=0; j<50; j++)
      {
        ar23<<temp_fu2[i][j]<<" ";
      }
      ar23<<"\n";
    }
    ar23.close();

  //////////_-------------tercer  grupo de iteraciones
  for(int t=0;t<1200;t++)
  {//Se realizan los desde 1 a 49 debido a que las fronteras presentan un error
    for (int i=1;i<49;i++)
    {
      for (int j=1;j<49;j++)
      {

        int circulo=pow(float(i)-24,2)+pow(float(j)-24,2);

        if(circulo>25)
        { //Arreglando la ecuacion de landau para dos dimensiones
          temp_fu2[i][j]=temp2[i][j]+(constante*deltat)*((temp2[i+1][j]+temp2[i-1][j]-2*temp2[i][j])/pow(delta,2)+(temp2[i][j+1]+temp2[i][j-1]-2*temp2[i][j])/pow(delta,2));
        }
        if(circulo<=25)
        {
          temp_fu2[i][j]=tini_vari;
        }
        for(int k=0;k<50;k++)
        {
          temp2[0][k] = temp_fu2[1][k];
          temp2[49][k] = temp_fu2[48][k];
        }
        for(int l=1;l<49;l++)
        {
          temp2[l][0] = temp_fu2[l][1];
          temp2[l][49] = temp_fu2[l][48];
        }

      }
    }
  }

  for(int i=0; i<50; i++)
  {
    for(int j=0; j<50; j++)
    {
      temp2[i][j]=temp_fu2[i][j];
    }
  }

  //Actualizando tiempo
  ofstream ar24 ("datosPDEC24.dat");
  ar23.is_open();
    for(int i=0; i<50; i++)
    {
      for(int j=0; j<50; j++)
      {
        ar24<<temp_fu2[i][j]<<" ";
      }
      ar24<<"\n";
    }
    ar24.close();


}




//----------------------------------------------------------------------------------------------------------------------//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
void caso3()
{

  for (int i=0;i<50;i++)
  {
    for (int j=0;j<50;j++)
    {
      //Aplicando la ecuacion del circulo
      int circulo=pow(i-24,2)+pow(j-24,2);
      if(circulo<=25)//si el radio es menor a 5
      {
        temp3[i][j]=tini_vari;
      }

      else
      {
        temp3[i][j]=tini_calc;
      }
    }
  }
for (int t=0;t<4000;t++)
{
  for (int i=1;i<49;i++)
  {
    for (int j=1;j<49;j++)
    {

      int circulo=pow(i-24,2)+pow(j-24,2);

      if(circulo>25)
      { //Arreglando la ecuacion de landau para dos dimensiones
        temp_fu3[i][j]=temp3[i][j]+(((constante*deltat)/pow(delta,2))*((temp3[i+1][j]+temp3[i-1][j]-2*temp3[i][j])+(temp3[i][j+1]+temp3[i][j-1]-2*temp3[i][j])));
      }
      if(circulo<25)
      {
        temp_fu3[i][j]=tini_vari;
      }

      for(int m=0; m<50; m++)
      {
					temp_fu3[0][m] = temp_fu3[49][m];
			}
			for(int n=0; n<50; n++)
      {
				temp_fu3[n][0] = temp_fu3[n][49];
			}

    }
  }
}
for(int i=0; i<50; i++)
{
  for(int j=0; j<50; j++)
  {
    temp3[i][j]=temp_fu3[i][j];
  }
}
//Actualizando tiempo
ofstream ar32 ("datosPDEC32.dat");
ar32.is_open();
  for(int i=0; i<50; i++)
  {
    for(int j=0; j<50; j++)
    {
      ar32<<temp_fu2[i][j]<<" ";
    }
    ar32<<"\n";
  }
  ar32.close();
///////----------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
  for (int t=0;t<8000;t++)
  {
    for (int i=1;i<49;i++)
    {
      for (int j=1;j<49;j++)
      {

        int circulo=pow(i-24,2)+pow(j-24,2);

        if(circulo>25)
        { //Arreglando la ecuacion de landau para dos dimensiones
          temp_fu3[i][j]=temp3[i][j]+(((constante*deltat)/pow(delta,2))*((temp3[i+1][j]+temp3[i-1][j]-2*temp3[i][j])+(temp3[i][j+1]+temp3[i][j-1]-2*temp3[i][j])));
        }
        if(circulo<25)
        {
          temp3[i][j]=tini_vari;
        }

        for(int m=0; m<50; m++)
        {
  					temp_fu3[0][m] = temp_fu3[49][m];
  			}
  			for(int n=0; n<50; n++)
        {
  				temp_fu3[n][0] = temp_fu3[n][49];
  			}

      }
    }
  }
  for(int i=0; i<50; i++)
  {
    for(int j=0; j<50; j++)
    {
      temp3[i][j]=temp_fu3[i][j];
    }
  }
  //Actualizando tiempo
  ofstream ar33 ("datosPDEC33.dat");
  ar33.is_open();
    for(int i=0; i<50; i++)
    {
      for(int j=0; j<50; j++)
      {
        ar33<<temp_fu2[i][j]<<" ";
      }
      ar33<<"\n";
    }
    ar33.close();

    ///////----------------------------------------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------------------------------------------------------------------------

    for (int t=0;t<12000;t++)
    {
      for (int i=1;i<49;i++)
      {
        for (int j=1;j<49;j++)
        {

          int circulo=pow(i-24,2)+pow(j-24,2);

          if(circulo>25)
          { //Arreglando la ecuacion de landau para dos dimensiones
            temp_fu3[i][j]=temp3[i][j]+(((constante*deltat)/pow(delta,2))*((temp3[i+1][j]+temp3[i-1][j]-2*temp3[i][j])+(temp3[i][j+1]+temp3[i][j-1]-2*temp3[i][j])));
          }
          if(circulo<25)
          {
            temp3[i][j]=tini_vari;
          }

          for(int m=0; m<50; m++)
          {
              temp_fu3[0][m] = temp_fu3[49][m];
          }
          for(int n=0; n<50; n++)
          {
            temp_fu3[n][0] = temp_fu3[n][49];
          }

        }
      }
    }
    for(int i=0; i<50; i++)
    {
      for(int j=0; j<50; j++)
      {
        temp3[i][j]=temp_fu3[i][j];
      }
    }
    //Actualizando tiempo
    ofstream ar34 ("datosPDEC34.dat");
    ar34.is_open();
      for(int i=0; i<50; i++)
      {
        for(int j=0; j<50; j++)
        {
          ar34<<temp_fu2[i][j]<<" ";
        }
        ar34<<"\n";
      }
      ar34.close();


}
