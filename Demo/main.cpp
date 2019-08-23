#include <iostream>
#include "estring.h"
using namespace std;

int main()
{

  estring x = "The quick brown fox jumps over the lazy dog.";
  estring  t = "name";
  int x2 = 0;

  cout << estring::toString(x2) << endl; // '15'
  cout << estring::toString(x2, 2) << endl; // '1111'
  cout << estring::toString(x2, 8) << endl; // '17'
  cout << estring::toString(x2, 16) << endl; // 'f'

//  cout << (e1 == t) << endl;
 // cout << x.slice(31)<< endl; // "the lazy dog."

  cout << x.slice(4, 19) << endl; // "quick brown fox"

 // cout << x.slice(-4)<< endl; // "dog."

  cout << x.slice(-9, -5)<< endl;
  cout << x.replace("fox", "dog") << endl;
  cout << estring::toString(255, 16) << endl;

  return 0;
}
