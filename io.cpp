#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
  int a;
  long int b;
  double c,d;
  cin>> a >> b >> c >> d;
  cout<<a<<endl;
  cout<<b<<endl;
  cout<<fixed<<setprecision(3)<<c<<endl;
  cout<<fixed<<setprecision(10)<<d<<endl;
  return 0;
}
