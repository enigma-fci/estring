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
  cout << endl;

  // assignment operator
  test1 = "this is the new value of test";
  test2 = test1;
  cout << "------------------assignment operator------------------" << endl;
  cout << "test1: " << test1 << endl;
  cout << "test2: " << test2 << endl;
  cout << endl;

  // array index operator
  cout << "------------------array index operator------------------" << endl;
  cout << "test1[0]: " << test1[0] << endl;
  cout << "test1[1]: " << test1[1] << endl;
  cout << "test1[2]: " << test1[2] << endl;
  cout << "test1[100]: " << test1[100] << endl;
  cout << "test1[-10]: " << test1[-10] << endl;
  cout << "test1[-50]: " << test1[-50] << endl;
  cout << endl;

  // plus operator
  cout << "------------------plus operator------------------" << endl;
  test1 = "this is test 1";
  test2 = "this is test 2";
  cout << "test 1 " << test1 << endl;
  cout << "test 2 " << test2 << endl;
  cout << "test1 + hi: " << test1 + "hi" << endl;
  cout << "hi + test1: " << "hi" + test1 << endl;
  cout << "test1 + and + test2: " << test1 + " and " + test2 << endl;
  cout << endl;

  // += operator
  test1 = "this is the new value of test";
  cout << "------------------+= operator------------------" << endl;
  cout << "test1: " << test1 << endl;
  test1 += " and we add text by +=";
  cout << "new test1: " << test1 << endl;
  cout << endl;

  // == operator
  test2 = "this is test 2";
  cout << "------------------== operator------------------" << endl;
  cout << "test1 == test2: " << (test1 == test2) << endl;
  cout << "test2 == \'this is test 2\': " << (test2 == "this is test 2") << endl;
  cout << endl;

  // != operator
  cout << "------------------!= operator------------------" << endl;
  cout << "test1 != test2: " << (test1 != test2) << endl;
  cout << "test2 != \'this is test 2\': " << (test2 != "this is test 2") << endl;
  cout << endl;

  // cin >> & cout <<
  cout << "------------------cin cout------------------" << endl;
  cout << "Enter test1 and test 2" << endl;
  cin >> test1 >> test2;
  cout << "test1: " << test1 << endl;
  cout << "test2: " << test2 << endl;
  cout << endl;

  // length
  cout << "------------------length------------------" << endl;
  cout << "test1: " << test1.length() << endl;
  cout << "test2: " << test2.length() << endl;
  cout << endl;

  // indexOf
  cout << "------------------index of------------------" << endl;
  cout << "in test1: \'" << test1 << '\'' << endl;
  cout << "index of \'a\': " << test1.indexOf("a") << endl;
  cout << "index of \'b\': " << test1.indexOf("b") << endl;
  cout << "index of \'c\': " << test1.indexOf("c") << endl;
  cout << "index of \'d\': " << test1.indexOf("d") << endl;
  cout << "index of \'cat\': " << test1.indexOf("cat") << endl;
  cout << endl;

  // lastIndexOf
  cout << "------------------last index of------------------" << endl;
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "last index of \'a\': " << test1.lastIndexOf("a") << endl;
  cout << "last index of \'b\': " << test1.lastIndexOf("b") << endl;
  cout << "last index of \'c\': " << test1.lastIndexOf("c") << endl;
  cout << "last index of \'d\': " << test1.lastIndexOf("d") << endl;
  cout << "last index of \'cat\': " << test1.lastIndexOf("cat") << endl;
  cout << endl;

  // count
  cout << "------------------count------------------" <<endl;
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "count of \'cat\': " << test1.count("cat") << endl;
  cout << "count of \'hi\': " << test1.count("hi") << endl;
  cout << "count of \'a\': " << test1.count("a") << endl;
  cout << "count of \'b\': " << test1.count("b") << endl;
  cout << endl;

  // char Code At
  cout << "------------------char code at------------------" << endl;
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "char code at index 0: " << test1.charCodeAt(0) << endl;
  cout << "char code at index 2: " << test1.charCodeAt(2) << endl;
  cout << "char code at index -3: " << test1.charCodeAt(-3) << endl;
  cout << "char code at index 100: " << test1.charCodeAt(100) << endl;
  cout << endl;

  // char At
  cout << "------------------char at------------------" << endl;
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "char at index 0: " << test1.charAt(0) << endl;
  cout << "char at index 2: " << test1.charAt(2) << endl;
  cout << "char at index -3: " << test1.charAt(-3) << endl;
  cout << "char at index 100: " << test1.charAt(100) << endl;
  cout << endl;

  // includes
  cout << "------------------includes------------------" << endl;
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "does it includes \'cat\': " << test1.includes("cat") << endl;
  cout << "does it includes \'dog\': " << test1.includes("dog") << endl;
  cout << "does it includes \'hi\': " << test1.includes("hi") << endl;
  cout << "does it includes \'a\': " << test1.includes("a") << endl;
  cout << "does it includes \'b\': " << test1.includes("b") << endl;
  cout << "does it includes \'c\': " << test1.includes("c") << endl;
  cout << endl;

  // endsWith
  cout << "------------------endsWith------------------" << endl;
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "does it endsWith \'cat\': " << test1.endsWith("cat") << endl;
  cout << "does it endsWith \'dog\': " << test1.endsWith("dog") << endl;
  cout << "does it endsWith \'hi\': " << test1.endsWith("hi") << endl;
  cout << "does it endsWith \'a\': " << test1.endsWith("a") << endl;
  cout << "does it endsWith \'b\': " << test1.endsWith("b") << endl;
  cout << "does it endsWith \'c\': " << test1.endsWith("c") << endl;
  cout << endl;

  // pad start
  cout << "------------------pad start------------------" << endl;
  test1 = "test";
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "pad start test1 with 012345689: " << test1.padStart(10, "0123456789") << endl;
  cout << endl;

  // pad end
  cout << "------------------pad end------------------" << endl;
  test1 = "test";
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "pad end test1 with 012345689: " << test1.padEnd(10, "0123456789") << endl;
  cout << endl;

  // trim
  cout << "------------------trim------------------" << endl;
  test1 = "                      test                ";
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "trim test1: \'" << test1.trim() << '\'' << endl;
  cout << endl;

  // trim right
  cout << "------------------trim right------------------" << endl;
  test1 = "                      test                      ";
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "trim right test1: \'" << test1.trimRight() << '\'' << endl;
  cout << endl;

  // to lower case
  cout << "------------------to lower case------------------" << endl;
  test1 = "Hi tHiS Is TeSt 1";
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "to lower case test1: " << test1.toLoweCase() << endl;
  cout << endl;

  // to upper case
  cout << "------------------to upper case------------------" << endl;
  test1 = "Hi tHiS Is TeSt 1";
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "to upper case test1: " << test1.toUpperCase() << endl;
  cout << endl;

  // slice
  cout << "------------------slice------------------" << endl;
  test1 = "The quick brown fox jumps over the lazy dog.";
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "slice from 31 test1: \'" << test1.slice(31) << '\'' << endl;
  cout << "slice from 4 to 19 test1: \'" << test1.slice(4, 19) << '\'' << endl;
  cout << "slice from -4 test1: \'" << test1.slice(-4) << '\'' << endl;
  cout << "slice from -9 to -5 test1: \'" << test1.slice(-9, -5) << '\'' << endl;
  cout << "test 1: \'" << test1 << '\'' << endl;
  cout << endl;

  // substring
  cout << "------------------substring------------------" << endl;
  test1 = "The quick brown fox jumps over the lazy dog.";
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "substring from 31 test1: \'" << test1.slice(31) << '\'' << endl;
  cout << "substring from 4 to 19 test1: \'" << test1.slice(4, 19) << '\'' << endl;
  cout << "test 1: \'" << test1 << '\'' << endl;
  cout << endl;

  // repeat
  cout << "------------------repeat------------------" << endl;
  test1 = "Hi this is test 1.";
  cout << "in test 1: " << test1 << endl;
  cout << "repeat test1 1 time: " << test1.repeat(1) << endl;
  cout << "repeat test1 2 times: " << test1.repeat(2) << endl;
  cout << "repeat test1 3 times: " << test1.repeat(3) << endl;
  cout << "test 1: \'" << test1 << '\'' << endl;
  cout << endl;

  // reverse
  cout << "------------------reverse------------------" << endl;
  test1 = "this is test text for reverse method";
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "reverse test1: " << test1.reverse() << endl;
  cout << endl;

  // replace
  cout << "------------------replace------------------" << endl;
  test1 = "this is test text for replace method";
  cout << "in test 1: \'" << test1 << '\'' << endl;
  cout << "replace each is with \' what \' test1: " << endl;
  cout << test1.replace("is", " what ") << endl;
  cout << endl;

  // to string
  cout << "------------------to string------------------" << endl;
  int var = 15;
  cout << "in var: " << var << endl;
  cout << "to string : " << estring::toString(var) << endl;
  cout << "to string binary : " << estring::toString(var, 2) << endl;
  cout << "to string octal : " << estring::toString(var, 8) << endl;
  cout << "to string hexadecimal : " << estring::toString(var, 16) << endl;
  cout << endl;


  return 0;
}
