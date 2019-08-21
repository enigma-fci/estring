#include <iostream>
#include "estring.h"
using namespace std;

int main()
{

  estring e1 = "hi is hi";
  estring  t = "name";

  cout << (e1 == t) << endl;
  cout << e1.erase(2, 5) << endl;

  return 0;
}
