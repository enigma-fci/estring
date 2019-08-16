#ifndef ESTRING_H
#define ESTRING_H

#include <iostream>

using namespace std;

class estring
{
  private:
    char *str;
  public:
    // constructors
    estring();
    estring(const char str[]);

    // assignment operator overloading
    void operator = (const char str[]);
    void operator = (const estring& str);

    // array index operator overloading
    char operator[] (int index);

    // equality operator overloading
    bool operator == (const char str[]);
    bool operator == (const estring& str);
    friend bool operator == (const char str[],const estring& ob);

    // plus equal operator overloading
    void operator += (const char str[]);
    void operator += (const estring& str);

    // cin >> & cout << overloading
    friend ostream & operator << (ostream &out, const estring &str);
    friend istream & operator >> (istream &in,  estring &str);
    
    ~estring();
};

#endif // ESTRING_H
