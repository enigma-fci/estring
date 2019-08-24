#include <iostream>
#include "estring.h"
using namespace std;

int main()
{
  // constructor
  estring test1 = "this is test one";
  estring test2 = test1;
  cout << "------------------constructor------------------" << endl;
  cout << "test1: " << test1 << endl;
  cout << "test2: " << test2 << endl;

  // assignment operator
  test1 = "this is the new value of test";
  test2 = test1;
  cout << "------------------assignment operator------------------" << endl;
  cout << "test1: " << test1 << endl;
  cout << "test2: " << test2 << endl;

  // array index operator
  cout << "------------------array index operator------------------" << endl;
  cout << "test1[0]: " << test1[0] << endl;
  cout << "test1[1]: " << test1[1] << endl;
  cout << "test1[2]: " << test1[2] << endl;
  cout << "test1[100]: " << test1[100] << endl;
  cout << "test1[-10]: " << test1[-10] << endl;
  cout << "test1[-50]: " << test1[-50] << endl;

  // += operator
  test1 = "this is the new value of test";
  cout << "------------------+= operator------------------" << endl;
  cout << "test1: " << test1 << endl;
  test1 += " and we add text by +=";
  cout << "new test1: " << test1 << endl;

  // == operator
  test2 = "this is test 2";
  cout << "------------------== operator------------------" << endl;
  cout << "test1 == test2: " << (test1 == test2) << endl;
  cout << "test2 == \'this is test 2\':" << (test2 == "this is test 2") << endl;

  // != operator
  cout << "------------------!= operator------------------" << endl;
  cout << "test1 != test2: " << (test1 != test2) << endl;
  cout << "test2 != \'this is test 2\':" << (test2 != "this is test 2") << endl;

  // cin >> & cout <<
  cout << "------------------cin cout------------------" << endl;
  cout << "Enter test1 and test 2" << endl;
  cin >> test1 >> test2;
  cout << "test1: " << test1 << endl;
  cout << "test2: " << test2 << endl;

  // length
  cout << "------------------length------------------" << endl;
  cout << "test1: " << test1.length() << endl;
  cout << "test2: " << test2.length() << endl;

  // indexOf
  cout << "------------------index of------------------" << endl;
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "index of \'a\': " << test1.indexOf("a") << endl;
  cout << "index of \'b\': " << test1.indexOf("b") << endl;
  cout << "index of \'c\': " << test1.indexOf("c") << endl;
  cout << "index of \'d\': " << test1.indexOf("d") << endl;
  cout << "index of \'cat\': " << test1.indexOf("cat") << endl;

  // lastIndexOf
  cout << "------------------last index of------------------" << endl;
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "last index of \'a\': " << test1.lastIndexOf("a") << endl;
  cout << "last index of \'b\': " << test1.lastIndexOf("b") << endl;
  cout << "last index of \'c\': " << test1.lastIndexOf("c") << endl;
  cout << "last index of \'d\': " << test1.lastIndexOf("d") << endl;
  cout << "last index of \'cat\': " << test1.lastIndexOf("cat") << endl;

  // count
  cout << "------------------count------------------" <<endl;
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "count of \'cat\': " << test1.count("cat") << endl;
  cout << "count of \'hi\': " << test1.count("hi") << endl;
  cout << "count of \'a\': " << test1.count("a") << endl;
  cout << "count of \'b\': " << test1.count("b") << endl;

  // char Code At
  cout << "------------------char code at------------------" << endl;
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "char code at index 0: " << test1.charCodeAt(0) << endl;
  cout << "char code at index 2: " << test1.charCodeAt(2) << endl;
  cout << "char code at index -3: " << test1.charCodeAt(-3) << endl;
  cout << "char code at index 100: " << test1.charCodeAt(100) << endl;


  // char At
  cout << "------------------char at------------------" << endl;
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "char at index 0: " << test1.charAt(0) << endl;
  cout << "char at index 2: " << test1.charAt(2) << endl;
  cout << "char at index -3: " << test1.charAt(-3) << endl;
  cout << "char at index 100: " << test1.charAt(100) << endl;


  // includes
  cout << "------------------includes------------------" << endl;
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "does it includes \'cat\': " << test1.includes("cat") << endl;
  cout << "does it includes \'dog\': " << test1.includes("dog") << endl;
  cout << "does it includes \'hi\': " << test1.includes("hi") << endl;
  cout << "does it includes \'a\': " << test1.includes("a") << endl;
  cout << "does it includes \'b\': " << test1.includes("b") << endl;
  cout << "does it includes \'c\': " << test1.includes("c") << endl;

  // // endsWith
  cout << "------------------endsWith------------------" << endl;
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "does it endsWith \'cat\': " << test1.endsWith("cat") << endl;
  cout << "does it endsWith \'dog\': " << test1.endsWith("dog") << endl;
  cout << "does it endsWith \'hi\': " << test1.endsWith("hi") << endl;
  cout << "does it endsWith \'a\': " << test1.endsWith("a") << endl;
  cout << "does it endsWith \'b\': " << test1.endsWith("b") << endl;
  cout << "does it endsWith \'c\': " << test1.endsWith("c") << endl;




  return 0;
}
