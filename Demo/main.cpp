#include <iostream>
#include "estring.h"
using namespace std;

int main()
{

  estring e1 = "Hello World!";
  estring e2("Hello World!");
  char x [] = "sdsa";


  cout << e1.e_includes("world!") << endl;
  cout << e1[-1] << endl;

  return 0;
}
