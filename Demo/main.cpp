#include <iostream>
#include "estring.h"
using namespace std;

int main()
{

  estring e1 = "hi this is hi and hi but wait there is another hi here or hi there World!";
  estring  t = "name";


  cout << e1.e_includes("World!") << endl;
  cout << e1.indexOf("hi") << endl;
  cout << t << "d"  << endl;
  cout << t.padStart(20, "1234567890") << endl;

  return 0;
}
