#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

void implicita(float y0, float deltaw, float *M, float w);
float explicita(float y0, float deltaw);
void escribe(string filename,float* z, int delta);

int main()
{
float y0=1;
float w=0.1;
float deltaw=0.1;
float delta= deltaw/w;
float intera=4/w;
float interi=0;
float *arreglo = NULL;
float *z=NULL;
int div=intera/delta;
arreglo =new float[div];
	
implicita(y0,deltaw,arreglo,div);
escribe("datos.dat",arreglo,div);
	
deltaw=0.01;
delta= deltaw/w;
div=intera/delta;
y0=1;
float *arreglo1 = NULL;
arreglo1 =new float[div];
implicita(y0,deltaw,arreglo1,div);
escribe("datos1.dat",arreglo1,div);
return 0;
}

void implicita(float y0, float deltaw, float *M, float div)
{
    for(int i=0; i<div ;i++)
    {
        M[i]=y0;
		y0=y0-deltaw*y0;
    } 
}
float explicita(float y0, float deltaw)
{
	return y0/(1-deltaw*y0);
}

void escribe(string filename,float* z, int delta){
  ofstream outfile;
  outfile.open(filename);
  for (int i=0; i < delta; i++)
  {
    outfile << z[i] << endl;
  }
  outfile.close();
}