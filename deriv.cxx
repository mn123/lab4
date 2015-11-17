#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}

void func(double* p, const int N, const double dx, const double xmin, double x){
  for(int i=0; i<N; i++){
      x=xmin+i*dx;
      p[i]=exp(-x*x);
  }
}

void deriv(double* p, const int N, const double dx, double x, double y, double z){
  y=p[0];
  p[0]=(p[1])/(2*dx);
  for (int i=1; i<(N-1); i++){
      z=p[i];
      p[i]=(p[i+1]-y)/(2*dx);
      y=z;
  }
  p[N-1]=(-y)/(2*dx);
}
  
int main(){
  const int N = 500;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);
  double x,y,z;
  // call to function which fills array p here
  func(p,N,dx,xmin,x);
  
  // call to functio which calculates the derivative
  deriv(p,N,dx,x,y,z);
  print(p,N,dx,xmin);

  return 0;
}
