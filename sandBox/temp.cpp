#include <iostream>
using namespace std;

double a(double b, double c)
{
  return b - c;
}

int main()
{
   float x = a(4.0, 3.0);
   float y = a(7.0, 5.0);
   cout << a(x, y) << endl;
   return 0;
}
