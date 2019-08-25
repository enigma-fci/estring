#include <iostream>
#include "estring.h"
using namespace std;

int main()
{
  // constructor
  estring test1 = "this is test one";
  estring test2 = test1;
  cout << "------------------constructor------------------" << endl
       << "test1: " << test1 << endl
       << "test2: " << test2 << endl
       << endl;

  // assignment operator
  test1 = "this is the new value of test";
  test2 = test1;
  cout << "------------------assignment operator------------------" << endl
       << "test1: " << test1 << endl
       << "test2: " << test2 << endl
       << endl;

  // array index operator
  cout << "------------------array index operator------------------" << endl
       << "test1[0]: " << test1[0] << endl
       << "test1[1]: " << test1[1] << endl
       << "test1[2]: " << test1[2] << endl
       << "test1[100]: " << test1[100] << endl
       << "test1[-10]: " << test1[-10] << endl
       << "test1[-50]: " << test1[-50] << endl
       << endl;

  // += operator
  test1 = "this is the new value of test";
  cout << "------------------+= operator------------------" << endl
       << "test1: " << test1 << endl;
  test1 += " and we add text by +=";
  cout << "new test1: " << test1 << endl
       << endl;

  // == operator
  test2 = "this is test 2";
  cout << "------------------== operator------------------" << endl
       << "test1 == test2: " << (test1 == test2) << endl
       << "test2 == \'this is test 2\': " << (test2 == "this is test 2") << endl
       << endl;

  // != operator
  cout << "------------------!= operator------------------" << endl
       << "test1 != test2: " << (test1 != test2) << endl
       << "test2 != \'this is test 2\': " << (test2 != "this is test 2") << endl
       << endl;

  // cin >> & cout <<
  cout << "------------------cin cout------------------" << endl
       << "Enter test1 and test 2" << endl;
  cin >> test1 >> test2;
  cout << "test1: " << test1 << endl
       << "test2: " << test2 << endl
       << endl;

  // length
  cout << "------------------length------------------" << endl
       << "test1: " << test1.length() << endl
       << "test2: " << test2.length() << endl
       << endl;

  // indexOf
  cout << "------------------index of------------------" << endl
       << "in test1: \'" << test1 << '\'' << endl
       << "index of \'a\': " << test1.indexOf("a") << endl
       << "index of \'b\': " << test1.indexOf("b") << endl
       << "index of \'c\': " << test1.indexOf("c") << endl
       << "index of \'d\': " << test1.indexOf("d") << endl
       << "index of \'cat\': " << test1.indexOf("cat") << endl
       << endl;

  // lastIndexOf
  cout << "------------------last index of------------------" << endl
       << "in test 1: \'" << test1 << '\'' << endl
       << "last index of \'a\': " << test1.lastIndexOf("a") << endl
       << "last index of \'b\': " << test1.lastIndexOf("b") << endl
       << "last index of \'c\': " << test1.lastIndexOf("c") << endl
       << "last index of \'d\': " << test1.lastIndexOf("d") << endl
       << "last index of \'cat\': " << test1.lastIndexOf("cat") << endl
       << endl;

  // count
  cout << "------------------count------------------" <<endl
       << "in test 1: \'" << test1 << '\'' << endl
       << "count of \'cat\': " << test1.count("cat") << endl
       << "count of \'hi\': " << test1.count("hi") << endl
       << "count of \'a\': " << test1.count("a") << endl
       << "count of \'b\': " << test1.count("b") << endl
       << endl;

  // char Code At
  cout << "------------------char code at------------------" << endl
       << "in test 1: \'" << test1 << '\'' << endl
       << "char code at index 0: " << test1.charCodeAt(0) << endl
       << "char code at index 2: " << test1.charCodeAt(2) << endl
       << "char code at index -3: " << test1.charCodeAt(-3) << endl
       << "char code at index 100: " << test1.charCodeAt(100) << endl
       << endl;

  // char At
  cout << "------------------char at------------------" << endl
       << "in test 1: \'" << test1 << '\'' << endl
       << "char at index 0: " << test1.charAt(0) << endl
       << "char at index 2: " << test1.charAt(2) << endl
       << "char at index -3: " << test1.charAt(-3) << endl
       << "char at index 100: " << test1.charAt(100) << endl
       << endl;

  // includes
  cout << "------------------includes------------------" << endl
       << "in test 1: \'" << test1 << '\'' << endl
       << "does it includes \'cat\': " << test1.includes("cat") << endl
       << "does it includes \'dog\': " << test1.includes("dog") << endl
       << "does it includes \'hi\': " << test1.includes("hi") << endl
       << "does it includes \'a\': " << test1.includes("a") << endl
       << "does it includes \'b\': " << test1.includes("b") << endl
       << "does it includes \'c\': " << test1.includes("c") << endl
       << endl;

  // endsWith
  cout << "------------------endsWith------------------" << endl
       << "in test 1: \'" << test1 << '\'' << endl
       << "does it endsWith \'cat\': " << test1.endsWith("cat") << endl
       << "does it endsWith \'dog\': " << test1.endsWith("dog") << endl
       << "does it endsWith \'hi\': " << test1.endsWith("hi") << endl
       << "does it endsWith \'a\': " << test1.endsWith("a") << endl
       << "does it endsWith \'b\': " << test1.endsWith("b") << endl
       << "does it endsWith \'c\': " << test1.endsWith("c") << endl
       << endl;

  // pad start
  cout << "------------------pad start------------------" << endl;
  test1 = "test";
  cout << "in test 1: \'" << test1 << '\'' << endl
       << "pad start test1 with 012345689: " << test1.padStart(10, "0123456789") << endl
       << endl;

  // pad end
  cout << "------------------pad end------------------" << endl;
  test1 = "test";
  cout << "in test 1: \'" << test1 << '\'' << endl
       << "pad end test1 with 012345689: " << test1.padEnd(10, "0123456789") << endl
       << endl;

  // trim
  cout << "------------------trim------------------" << endl;
  test1 = "                      test                ";
  cout << "in test 1: \'" << test1 << '\'' << endl
       << "trim test1: \'" << test1.trim() << '\'' << endl
       << endl;

  // trim right
  cout << "------------------trim right------------------" << endl;
  test1 = "                      test                      ";
  cout << "in test 1: \'" << test1 << '\'' << endl
       << "trim right test1: \'" << test1.trimRight() << '\'' << endl
       << endl;

  // to lower case
  cout << "------------------to lower case------------------" << endl;
  test1 = "Hi tHiS Is TeSt 1";
  cout << "in test 1: \'" << test1 << '\'' << endl
       << "to lower case test1: " << test1.toLoweCase() << endl
       << endl;

  // to upper case
  cout << "------------------to upper case------------------" << endl;
  test1 = "Hi tHiS Is TeSt 1";
  cout << "in test 1: \'" << test1 << '\'' << endl
       << "pad start test1 with 012345689: " << test1.toUpperCase() << endl
       << endl;

  // slice
  cout << "------------------slice------------------" << endl;
  test1 = "The quick brown fox jumps over the lazy dog.";
  cout << "in test 1: \'" << test1 << '\'' << endl
       << "slice from 31 test1: \'" << test1.slice(31) << '\'' << endl
       << "slice from 4 to 19 test1: \'" << test1.slice(4, 19) << '\'' << endl
       << "slice from -4 test1: \'" << test1.slice(-4) << '\'' << endl
       << "slice from -9 to -5 test1: \'" << test1.slice(-9, -5) << '\'' << endl
       << "in test 1: \'" << test1 << '\'' << endl
       << endl;

  // reverse
  cout << "------------------reverse------------------" << endl;
  test1 = "this is test text for reverse method";
  cout << "in test 1: \'" << test1 << '\'' << endl
       << "reverse test1: " << test1.reverse() << endl
       << endl;

  // replace
  cout << "------------------replace------------------" << endl;
  test1 = "this is test text for replace method";
  cout << "in test 1: \'" << test1 << '\'' << endl
       << "replace each is with \' what \' test1: " << endl
       << test1.replace("is", " what ") << endl
       << endl;

  // to string
  cout << "------------------to string------------------" << endl;
  int var = 15;
  cout << "in var: " << var << endl
       << "to string : " << estring::toString(var) << endl
       << "to string binary : " << estring::toString(var, 2) << endl
       << "to string octal : " << estring::toString(var, 8) << endl
       << "to string hexadecimal : " << estring::toString(var, 16) << endl
       << endl;

  return 0;
}
